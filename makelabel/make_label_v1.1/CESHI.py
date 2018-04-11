# -*- coding:utf-8 -*-
from Tkinter import *
from PIL import Image, ImageTk
path="D:\\code\\pycharm\\py\\images\\88.jpg";
class LabelTool():
    def __init__(self, master):
    	self.parent = master
        self.parent.title("LabelTool")
        self.frame = Frame(self.parent)
        self.frame.pack(fill=BOTH, expand=1)
        #x 横向填充（默认,各组件自上而下）， y竖向填充（各组件自左往右），both都填充
        #1 父外框大小改变时，自动扩充大小，0为false
        self.parent.resizable(width=TRUE, height=TRUE)
        # 设置窗口是否可以变化长/宽，False不可变，True可变，默认为True

###########################GUI#################################
    	self.mainPanel = Canvas(self.frame,width=1000,height=600,cursor='tcross') 
    	self.mainPanel.pack(fill=BOTH,expand=YES)
    	
    	vbar=Scrollbar(self.mainPanel)                       #与之前的一样
    	hbar=Scrollbar(self.mainPanel,orient=HORIZONTAL)
    	vbar.pack(side=RIGHT,fill=Y)  
    	hbar.pack(side=BOTTOM,fill=X)
    	#self.mainPanel.pack(side=TOP,fill=BOTH,expand=YES)
    	vbar.config(command=self.mainPanel.yview)
    	hbar.config(command=self.mainPanel.xview)
    	self.mainPanel.config(yscrollcommand=vbar.set)
    	self.mainPanel.config(xscrollcommand=hbar.set)



    	pil_image = Image.open(path)
    	self.w0,self.h0 = pil_image.size#获得图片的原始大小

        fullsize=(0,0,self.w0,self.h0) #
        self.mainPanel.config(scrollregion=fullsize) #可滚动的大小区域


        self.img = pil_image

        self.tkimg = ImageTk.PhotoImage(pil_image)  

      #  self.mainPanel.config(width=self.tkimg.width(), height=self.tkimg.height())#调节框的大小的作用
        self.mainPanel.create_image(0, 0, image=self.tkimg, anchor=NW)  #真实的情况


        print vbar.get()

if __name__ == '__main__':
    root = Tk()
    tool = LabelTool(root)
    root.mainloop()