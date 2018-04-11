# -*- coding:utf-8 -*-
# -------------------------------------------------------------------------------
# Name:        Object bounding box label tool
# Purpose:     Label object bboxes for ImageNet Detection data
# Author:      wangaobo
# Created:     07/04/2017

#
# -------------------------------------------------------------------------------
from __future__ import division
from Tkinter import *
import tkMessageBox
from PIL import Image, ImageTk
import os
import glob
import random

w0 = 1;  # 图片原始宽度
h0 = 1;  # 图片原始高度

# colors for the bboxes
COLORS = ['red', 'blue', 'yellow', 'pink', 'cyan', 'green', 'black']
# 指定缩放后的图像大小
# 从放外面的txt里面获得文件位置，label位置，缩放大小，默认的数字
file_object = open('./config0.txt', 'r')
line=file_object.readline()
lines=line.split(' ')
picturepath=lines[0]
labelpath=lines[1]
wh_ratio=int(lines[2])
cltype=lines[3]
print lines

class LabelTool():
    def __init__(self, master):
        # set up the main frame
        self.parent = master
        self.parent.title("LabelTool")
        self.frame = Frame(self.parent)
        self.frame.pack(fill=BOTH, expand=1)
        #x 横向填充（默认,各组件自上而下）， y竖向填充（各组件自左往右），both都填充
        #1 父外框大小改变时，自动扩充大小，0为false
        self.parent.resizable(width=TRUE, height=TRUE)
        # 设置窗口是否可以变化长/宽，False不可变，True可变，默认为True
        # initialize global state
        self.imageDir = ''
        self.imageList = []
        self.egDir = ''
        self.egList = []
        self.outDir = ''
        self.cur = 0
        self.total = 0
        self.category = 0
        self.imagename = ''
        self.labelfilename = ''
        self.tkimg = None
        self.w0=0
        self.h0=0
        self.w2=1
        self.h2=1
        self.cltype=cltype#默认得出的是car类型
        self.realcltype=''

        # initialize mouse state
        self.STATE = {}
        self.STATE['click'] = 0
        self.STATE['x'], self.STATE['y'] = 0, 0

        # reference to bbox
        self.bboxIdList = []
        self.bboxId = None
        self.bboxList = []
        self.hl = None
        self.vl = None

        self.x1=0
        self.y1=0
        self.x2=0
        self.y2=0
        #获得相对应的class




        # ----------------- GUI stuff ---------------------
        # dir entry & load
        self.label = Label(self.frame, text="Image show:")
        #label文本或图片显示
        self.label.grid(row=0, column=0,sticky=E)
        self.label = Label(self.frame, text="class name:")
        self.label.grid(row=0, column=1,sticky=E)
        self.entry = Entry(self.frame)
        self.entry.grid(row=0, column=3,sticky=N)
        self.ldBtn = Button(self.frame,width=15, text="Classent", command=self.Classent)  # 改成确认加上的例子
        self.ldBtn.grid(row=0, column=4, sticky=W + E)
        self.ldBtn = Button(self.frame,width=15, text="Person", command=self.Person)#改成确认加上的例子
        self.ldBtn.grid(row=1, column=3, sticky=W + E)
        self.ldBtn = Button(self.frame,width=15, text="House", command=self.House)  # 改成确认加上的例子
        self.ldBtn.grid(row=1, column=4, sticky=W + E)
        self.ldBtn = Button(self.frame,width=15, text="Disaster", command=self.Disaster)  # 改成确认加上的例子
        self.ldBtn.grid(row=2, column=3, sticky=W + E)



        #grid是布局
#你可以使用sticky选项去指定对齐方式，可以选择的值有：N/S/E/W，分别代表上/下/左/右。如果你想让label靠左显示，你可以设置stricky的值为W。
        # main panel for labeling
        #self.mainPanel = Canvas(self.frame, cursor='tcross')
        self.mainPanel = Canvas(self.frame,width=900,height=600, cursor='tcross') 
      #  self.mainPanel = Canvas(self.frame,cursor='tcross') 

        vbar=Scrollbar(self.mainPanel)                       #与之前的一样
        hbar=Scrollbar(self.mainPanel,orient=HORIZONTAL)

        vbar.pack(side=RIGHT,fill=Y)  
        hbar.pack(side=BOTTOM,fill=X)
        self.mainPanel.pack(side=TOP,fill=BOTH,expand=YES)

        vbar.config(command=self.mainPanel.yview)
        hbar.config(command=self.mainPanel.xview)
        self.mainPanel.config(yscrollcommand=vbar.set)
        self.mainPanel.config(xscrollcommand=hbar.set)
    #    self.mainPanel.config(width=900,height=600)

###################################################################################################


#下面是正常的类型
#########################################################################################################
        #显示的大小
        #Canvas类似于一个画板，可以在上面绘制各种图形和进行图形编辑

        self.mainPanel.bind("<Button-1>", self.mouseClick)

        #bind 的作用就是mouseClick,和<Button-1>的时间映射在一起
        self.mainPanel.bind("<Motion>", self.mouseMove)
        self.parent.bind("<Escape>", self.cancelBBox)  # press <Espace> to cancel current bbox
        self.parent.bind("s", self.cancelBBox)
        self.parent.bind("a", self.prevImage)  # press 'a' to go backforward
        self.parent.bind("d", self.nextImage)  # press 'd' to go forward
        self.mainPanel.grid(row=1, column=1, rowspan=5, sticky=W + N)
        #rowspan设置为包含多行的单元格

        # showing bbox info & delete bbox
        self.listbox = Listbox(self.frame, width=30, height=12)
        self.listbox.grid(row=3, column=3,columnspan=2,sticky=N)
        #显示数据

        self.btnDel = Button(self.frame, text='Delete', command=self.delBBox)
        self.btnDel.grid(row=4, column=3,columnspan=2, sticky=W + E + N)
        self.btnClear = Button(self.frame, text='ClearAll', command=self.clearBBox)
        self.btnClear.grid(row=5, column=3,columnspan=2, sticky=W + E + N)

        # control panel for image navigation
        #expand: 当设置为true，部件扩展填充，否则不能使用任何部件的母公司空间.
        #fill: 确定是否部件填补打包机分配任何额外的空间，或保持其自己的最小尺寸：无（默认）和X（只填写水平）Y（只填写垂直），或两者兼而有之（填充横向和纵向）.
        #side: 决定哪方父widget包对TOP（默认），下，左，或右.

        self.ctrPanel = Frame(self.frame)
        self.ctrPanel.grid(row=7, column=1, columnspan=2, sticky=W + E)
        self.prevBtn = Button(self.ctrPanel, text='<< Prev', width=10, command=self.prevImage)
        self.prevBtn.pack(side=LEFT, padx=5, pady=3)        #columnspan选项可以指定控件跨越多列显示，而rowspan选项同样可以指定控件跨越多行显示。

        self.nextBtn = Button(self.ctrPanel, text='Next >>', width=10, command=self.nextImage)
        self.nextBtn.pack(side=LEFT, padx=5, pady=3)
        self.progLabel = Label(self.ctrPanel, text="Progress:     /    ")#显示有多少张，以及现在处理了多少张
        self.progLabel.pack(side=LEFT, padx=5)
        self.tmpLabel = Label(self.ctrPanel, text="Go to Image No.")
        self.tmpLabel.pack(side=LEFT, padx=5)
        self.idxEntry = Entry(self.ctrPanel, width=5)#文本编辑的地方
        self.idxEntry.pack(side=LEFT)
        self.goBtn = Button(self.ctrPanel, text='Go', command=self.gotoImage)
        self.goBtn.pack(side=LEFT)

        # example pannel for illustration
        self.egPanel = Frame(self.frame, border=10) #放画布的地方
        self.egPanel.grid(row=1, column=0, rowspan=5, sticky=N)
        self.tmpLabel2 = Label(self.egPanel, text="Examples:")
        self.tmpLabel2.pack(side=TOP, pady=5)
        self.saveBtn = Button(self.egPanel, text='save', width=10,command=self.saveImage)
        self.saveBtn.pack(side=TOP, pady=10)

        #加上滑动轮
      #  self.hang=Scrollbar(orient=HORIZONTAL)
       # self.hang.grid(row=6,column=1,sticky=W+N)
        #self.mainPanel.config(xscrollcommand=self.hang.set)
        #self.hang.config(command=self.mainPanel.xview)
    #    self.sl = Scrollbar(self.mainPanel,orient = HORIZONTAL)  
     #   self.sl.set(0.1,1)  
      #  self.sl.pack() 
       # self.delete.det();


        # display mouse position
        self.disp = Label(self.ctrPanel, text='')
        self.disp.pack(side=RIGHT)

        self.frame.columnconfigure(1, weight=1)
        self.frame.rowconfigure(4, weight=1)

        # for debugging

    ##        self.setImage()
        self.loadDir()


    def loadDir(self):

        ##        if not os.path.isdir(s):
        ##            tkMessageBox.showerror("Error!", message = "The specified dir doesn't exist!")
        ##            return
        # get image list
        self.imageDir = os.path.join(picturepath)#进入的是相对应的./image/003的位置
        print(self.imageDir)
        self.imageList = glob.glob(os.path.join(self.imageDir, '*.jpg'))
        if len(self.imageList) == 0:
            print 'No .jpg images found in the specified dir!'
            return
        else:
            print 'num=%d' % (len(self.imageList))

        # default to the 1st image in the collection
        self.cur = 1
        self.total = len(self.imageList)

        # set up output dir
        self.outDir = os.path.join(labelpath)
        if not os.path.exists(self.outDir):
            os.mkdir(self.outDir)

        self.loadImage()
        print '%d images loaded from %s' % (self.total, picturepath)

    def loadImage(self):
        # load image
        imagepath = self.imageList[self.cur - 1]
        pil_image = Image.open(imagepath)

        # get the size of the image
        # 获取图像的原始大小
        self.w0,self.h0 = pil_image.size#获得图片的原始大小

        fullsize=(0,0,self.w0,self.h0) #
        self.mainPanel.config(scrollregion=fullsize) #可滚动的大小区域




        self.w2=int(self.w0/wh_ratio)#wh_ratio是大小为1，即这是可浏览的大小
        self.h2=int(self.h0/wh_ratio)# 这是可浏览的的大小
        print self.w2,self.h2

        # 缩放到指定大小
        pil_image = pil_image.resize((self.w2,self.h2), Image.ANTIALIAS)

        # pil_image = imgresize(w, h, w_box, h_box, pil_image)
        self.img = pil_image

        self.tkimg = ImageTk.PhotoImage(pil_image)  

      #  self.mainPanel.config(width=self.tkimg.width(), height=self.tkimg.height())#调节框的大小的作用
        self.mainPanel.create_image(0, 0, image=self.tkimg, anchor=NW)  #真实的情况
        self.progLabel.config(text="%04d/%04d" % (self.cur, self.total))
        #张数的提示


        # load labels
        self.clearBBox()
        self.imagename = os.path.split(imagepath)[-1].split('.')[0]
        labelname = self.imagename + '.txt'
        self.labelfilename = os.path.join(self.outDir, labelname)
        bbox_cnt = 0
        if os.path.exists(self.labelfilename):
            with open(self.labelfilename) as f:
                for (i, line) in enumerate(f):
                    if i == 0:
                        bbox_cnt = int(line.strip())
                        continue
                    print line
                    tmp = [(t.strip()) for t in line.split()]
                    # self.bboxList.append(tuple(tx))
                    self.bboxList.append(tuple(tmp))
                    tmp[0] = int(tmp[0])
                    tmp[1] = int(tmp[1])
                    tmp[2] = int(tmp[2])
                    tmp[3] = int(tmp[3])

                    tx0 = int(tmp[0] /wh_ratio)
                    ty0 = int(tmp[1] /wh_ratio)
                    tx1 = int(tmp[2]/ wh_ratio)
                    ty1 = int(tmp[3]/wh_ratio)
                    print "tx0, ty0, tx1, ty1"
                    print tx0, ty0, tx1, ty1

                    tmpId = self.mainPanel.create_rectangle(tx0, ty0, tx1, ty1, \
                                                            width=2, \
                                                            outline=COLORS[(len(self.bboxList) - 1) % len(COLORS)])
                 #   print 'tmpId:',tmpId
                    self.bboxIdList.append(tmpId)

                    self.listbox.insert(END, '(%.2f,%.2f) (%.2f,%.2f) %s' % (tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]))
                   # print tmp[4]
                    # self.listbox.insert(END, '(%d, %d) -> (%d, %d)' %(tmp[0], tmp[1], tmp[2], tmp[3]))
                    self.listbox.itemconfig(len(self.bboxIdList) - 1,
                                            fg=COLORS[(len(self.bboxIdList) - 1) % len(COLORS)])

    def saveImage(self):
        # print "-----1--self.bboxList---------"
        print self.bboxList
        # print "-----2--self.bboxList---------"
        with open(self.labelfilename, 'w') as f:
            f.write('%d\n' % len(self.bboxList))
            for bbox in self.bboxList:
                f.write(' '.join(map(str,bbox))+'\n')
        print 'Image No. %d saved' % (self.cur)

    def mouseClick(self, event):
        if self.STATE['click'] == 0:
            if event.x<0:
                event.x=0
            elif event.y<0:
                event.y = 0
            elif event.x>self.w2:
                event.x=self.w2
            elif event.y>self.h2:
                event.y = self.h2
            self.STATE['x'], self.STATE['y'] = event.x, event.y
        else:
            if event.x < 0:
                event.x = 0
            elif event.y < 0:
                event.y = 0
            elif event.x > self.w2:
                event.x = self.w2
            elif event.y > self.h2:
                event.y = self.h2
            x1, x2 = min(self.STATE['x'], event.x), max(self.STATE['x'], event.x)
            y1, y2 = min(self.STATE['y'], event.y), max(self.STATE['y'], event.y)

            x1, x2 = x1*wh_ratio,x2*wh_ratio;
            y1, y2 = y1*wh_ratio,y2*wh_ratio;

            self.x1,self.y1,self.x2,self.y2=x1,y1,x2,y2;
            self.realcltype = self.cltype
            self.bboxList.append((self.x1, self.y1, self.x2, self.y2, self.realcltype))
            self.bboxIdList.append(self.bboxId)
            self.bboxId = None
            self.listbox.insert(END, '(%.2f, %.2f) (%.2f, %.2f) %s' % (self.x1, self.y1, self.x2, self.y2, self.realcltype))
            self.listbox.itemconfig(len(self.bboxIdList) - 1, fg=COLORS[(len(self.bboxIdList) - 1) % len(COLORS)])
        self.STATE['click'] = 1 - self.STATE['click']

    def mouseMove(self, event):
        self.disp.config(text='x: %.2f, y: %.2f' % (event.x / self.w2, event.y / self.h2))
        if self.tkimg:
            if self.hl:
                self.mainPanel.delete(self.hl)
            self.hl = self.mainPanel.create_line(0, event.y, self.tkimg.width(), event.y, width=2)
            if self.vl:
                self.mainPanel.delete(self.vl)
            self.vl = self.mainPanel.create_line(event.x, 0, event.x, self.tkimg.height(), width=2)
        if 1 == self.STATE['click']:
            if self.bboxId:
                self.mainPanel.delete(self.bboxId)
            self.bboxId = self.mainPanel.create_rectangle(self.STATE['x'], self.STATE['y'], \
                                                          event.x, event.y, \
                                                          width=2, \
                                                          outline=COLORS[len(self.bboxList) % len(COLORS)])
    def Classent(self):
        self.bboxList.pop()
        self.listbox.delete(END)
        self.realcltype=self.entry.get()
        self.bboxList.append((self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.insert(END, '(%.2f, %.2f) (%.2f, %.2f) %s' % (self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.itemconfig(len(self.bboxIdList) - 1, fg=COLORS[(len(self.bboxIdList) - 1) % len(COLORS)])
    def Person(self):
        self.bboxList.pop()
        self.listbox.delete(END)
        self.realcltype ='Person'
        self.bboxList.append((self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.insert(END, '(%.2f, %.2f) (%.2f, %.2f) %s' % (self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.itemconfig(len(self.bboxIdList) - 1, fg=COLORS[(len(self.bboxIdList) - 1) % len(COLORS)])
    def House(self):
        self.bboxList.pop()
        self.listbox.delete(END)
        self.realcltype ='House'
        self.bboxList.append((self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.insert(END, '(%.2f, %.2f) (%.2f, %.2f) %s' % (self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.itemconfig(len(self.bboxIdList) - 1, fg=COLORS[(len(self.bboxIdList) - 1) % len(COLORS)])
    def Disaster(self):
        self.bboxList.pop()
        self.listbox.delete(END)
        self.realcltype = 'Disaster'
        self.bboxList.append((self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.insert(END, '(%.2f, %.2f) (%.2f, %.2f) %s' % (self.x1, self.y1, self.x2, self.y2, self.realcltype))
        self.listbox.itemconfig(len(self.bboxIdList) - 1, fg=COLORS[(len(self.bboxIdList) - 1) % len(COLORS)])

    def cancelBBox(self, event):
        if 1 == self.STATE['click']:
            if self.bboxId:
                self.mainPanel.delete(self.bboxId)
                self.bboxId = None
                self.STATE['click'] = 0

    def delBBox(self):
        sel = self.listbox.curselection()
        if len(sel) != 1:
            return
        idx = int(sel[0])
        self.mainPanel.delete(self.bboxIdList[idx])
        self.bboxIdList.pop(idx)
        self.bboxList.pop(idx)
        self.listbox.delete(idx)

    def clearBBox(self):
        for idx in range(len(self.bboxIdList)):
            self.mainPanel.delete(self.bboxIdList[idx])
        self.listbox.delete(0, len(self.bboxList))
        self.bboxIdList = []
        self.bboxList = []


    def prevImage(self, event=None):
        self.saveImage()
        if self.cur > 1:
            self.cur -= 1
            self.loadImage()

    def nextImage(self, event=None):
        self.saveImage()
        if self.cur < self.total:
            self.cur += 1
            self.loadImage()

    def gotoImage(self):
        idx = int(self.idxEntry.get())
        if 1 <= idx and idx <= self.total:
            self.saveImage()
            self.cur = idx
            self.loadImage()

            ##    def setImage(self, imagepath = r'test2.png'):
            ##        self.img = Image.open(imagepath)
            ##        self.tkimg = ImageTk.PhotoImage(self.img)
            ##        self.mainPanel.config(width = self.tkimg.width())
            ##        self.mainPanel.config(height = self.tkimg.height())
            ##        self.mainPanel.create_image(0, 0, image = self.tkimg, anchor=NW)

    def imgresize(w, h, w_box, h_box, pil_image):
        '''
        resize a pil_image object so it will fit into
        a box of size w_box times h_box, but retain aspect ratio
        '''
        f1 = 1.0 * w_box / w  # 1.0 forces float division in Python2
        f2 = 1.0 * h_box / h
        factor = min([f1, f2])
        # print(f1, f2, factor) # test
        # use best down-sizing filter
        width = int(w * factor)
        height = int(h * factor)
        return pil_image.resize((width, height), Image.ANTIALIAS)


if __name__ == '__main__':
    root = Tk()
    tool = LabelTool(root)
    print 'ok1'
    root.mainloop()
    print 'ok'
