#coding:utf-8
#作用是将目标的数据分为两个部分，按照硬件读写的方式给与数据，每次数据都是从从每一个数据的256的位置相给与的
lvtxt="./conv3_proj_input.txt"
save_1_txt="./mem1_16.dat"
save_2_txt="./mem2_16.dat"

save1txt = open(save_1_txt, 'w')  # 读取写入的文件
save2txt = open(save_2_txt, 'w')  # 读取写入的文件


HIGHT=64
WIDTH=96
CHANNELS=128


lvresult = open(lvtxt)  # 从lvresult.txt 获取
lvdata = lvresult.readlines()  # 所有的驻点的坐标
lvdata_len = len(lvdata)
print(lvdata_len)
#print(lvdata)

count=0
for i in range(WIDTH):
	for j in range(HIGHT):
		for k in range(CHANNELS):
			temp1 = lvdata[i+j*WIDTH+k*WIDTH*HIGHT]
			#temp1 = [(t1.strip()) for t1 in lvdata[i+j*48+k*48*32].split()]
			temp2=hex(int(temp1[0])).replace('0x','')  #16进制的数字
			#temp2=int(temp1[0])  #10进制的数字
			temp3="%s%s"%(temp2,"\n")
			#print(temp3)
			if ((i%2==0)&(j%2==0)):
				print(i,j,k,i+j*WIDTH+k*WIDTH*HIGHT,temp2,temp3)
				if j<HIGHT/2 :
					save1txt.write(str(temp3))
				else:
					save2txt.write(str(temp3))











# for lvdatalen in range(lvdata_len):
# 	print(lvdata[lvdatalen])

# 	temp1 = [(t1.strip()) for t1 in lvdata[lvdatalen].split()]
