#coding:utf-8
#将数据的组织方式改变 从长 宽 通道 到 通道 宽 长 （这里是变成2X2的块）
#作用是将目标分成上下两个部分
lvtxt="./conv7_sum_input_1.txt"
save_1_txt="./pool_1.dat"
save_2_txt="./pool_2.dat"

save1txt = open(save_1_txt, 'w')  # 读取写入的文件
save2txt = open(save_2_txt, 'w')  # 读取写入的文件



HIGHT=4
WIDTH=6
CHANNELS=256


lvresult = open(lvtxt)  # 从lvresult.txt 获取
lvdata = lvresult.readlines()  # 所有的驻点的坐标
lvdata_len = len(lvdata)
print(lvdata_len)
#print(lvdata)

count=0
for i in range(WIDTH/2):
	for j in range(HIGHT/2):
		for k in range(CHANNELS):
			#temp1 = lvdata[i+j*WIDTH+k*WIDTH*HIGHT]
			temp1_1 = [(t1.strip()) for t1 in lvdata[2*i+2*j*WIDTH+k*WIDTH*HIGHT].split()]
			temp1_2 = [(t2.strip()) for t2 in lvdata[2*i+1+2*j*WIDTH+k*WIDTH*HIGHT].split()]
			temp1_3 = [(t3.strip()) for t3 in lvdata[2*i+(2*j+1)*WIDTH+k*WIDTH*HIGHT].split()]
			temp1_4 = [(t4.strip()) for t4 in lvdata[2*i+1+(2*j+1)*WIDTH+k*WIDTH*HIGHT].split()]

			temp2_1=int(temp1_1[0])
			temp2_2=int(temp1_2[0])
			temp2_3=int(temp1_3[0])
			temp2_4=int(temp1_4[0])

			temp3_1="%s%s"%(temp2_1,"\n")
			temp3_2="%s%s"%(temp2_2,"\n")
			temp3_3="%s%s"%(temp2_3,"\n")
			temp3_4="%s%s"%(temp2_4,"\n")

			#print(temp3)
			#print(i,j,k,i+j*WIDTH+k*WIDTH*HIGHT,temp2,temp3)
			if j<HIGHT/4 :
				save1txt.write(str(temp3_1))
				save1txt.write(str(temp3_2))
				save1txt.write(str(temp3_3))
				save1txt.write(str(temp3_4))
			else:
				save2txt.write(str(temp3_1))
				save2txt.write(str(temp3_2))
				save2txt.write(str(temp3_3))
				save2txt.write(str(temp3_4))