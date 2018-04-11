# -*- coding:utf-8 -*-
import os;
filepath="G:/tset/dataset/all/Annotation/labels/";
filepath1="G:/tset/dataset/all/Annotation/labels1/";#label的位置
filepath2="G:/tset/dataset/all/JPEGImages/";#picture的位置
pathDir=os.listdir(filepath) #在文件下读取相应的文件
pathDir1=os.listdir(filepath1) #在文件下读取相应的文件
pathDir2=os.listdir(filepath2) #在文件下读取相应的文件
count=0
for allDir in pathDir:
	imagename = os.path.split(allDir)[-1].split('.')[0]
	namecounttemp='%08d'%(count+1)
	labelname = filepath1+namecounttemp+".txt"#写入文档的位置
	print filepath2+str(imagename)+".jpg"
	print filepath2+str(namecounttemp)+".jpg"
	#os.rename(filepath2+str(imagename)+".jpg",filepath2+str(namecounttemp)+".jpg");#将图像的名字进行更改
	os.rename(filepath2+str(imagename)+".jpg",filepath2+str(namecounttemp)+".jpg"); 
	count=count+1
	
	print allDir  #文件名
	file_object = open(filepath+allDir)
	lines = file_object.readlines() #逐行读
	output = open(labelname, 'w') #打开写入文件
	output.write('%d\n'%len(lines))#写入行数
	for line in lines:
		#list1=line.split('')
		print line
		list1=[(t.strip()) for t in line.split()]
		print list1[0]
		print list1[1]
		print list1[2]
		print list1[3]
		print list1[4]
		print list1[5]
		output.write(list1[2])
		output.write(' ')
		output.write(list1[3])
		output.write(' ')
		output.write(list1[4])
		output.write(' ')
		output.write(list1[5])
		output.write(' ')
		output.write(list1[1])
		output.write('\n')

		#output.write("%s %s %s %s %s\n",list1[2],list1[3],list1[4],list1[5],list1[1])
		#output.write('%s\n',list1[1])
