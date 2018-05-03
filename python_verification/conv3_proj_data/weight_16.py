#coding:utf-8 
#作用是将数据分为上下两个部分，按照每一行64位的模式进行存储 ，每32行表示256个数据
lvtxt="./conv3_proj_weights.txt"
save_1_txt="./weight16_1.dat"
save_2_txt="./weight16_2.dat"
save_txt="./weight16.dat"

#save1txt = open(save_1_txt, 'w')  # 读取写入的文件
#save2txt = open(save_2_txt, 'w')  # 读取写入的文件
savetxt = open(save_txt, 'w')  # 读取写入的文件

CHANNELS=128
OUT_CHANNELS=256
WIDTH=48
DEPTH=32



PE_NUMBER=16

lvresult = open(lvtxt)  # 从lvresult.txt 获取
lvdata = lvresult.readlines()  # 所有的驻点的坐标
lvdata_len = len(lvdata)
print(lvdata_len)


result_weight=[]

# 转化为16 进制的数据
j=0
for i in range (lvdata_len):
	j=j+1
	temp1= [(t1.strip()) for t1 in lvdata[i].split()]
	temp2=int(temp1[0]) #16进制的数字
	if temp2>=0: 
		temp3=hex(temp2).replace('0x','')
		if temp2 <16:
			temp4="%s%s"%("0",temp3)
		else:
			temp4="%s"%(temp3)
		#print(temp4)
	else:
		temp2=temp2+256
		temp3=hex(temp2).replace('0x','')
		temp4="%s"%(temp3)
		#print("0",temp4)
	result_weight.append(temp4)

# #计算的是逻辑 即如何把权值数据存储到 uram的问题
# 	if (j<=65536)&(j>0):
# 		save1txt.write(str(temp4))
# 		if j%8==0:
# 			save1txt.write("\n")
# 		print(j,temp4)
# 	elif (j>65536)&(j<=131072):
# 		save2txt.write(str(temp4))
# 		if j%8==0:
# 			save2txt.write("\n")
# 		print(j,temp4)
# 		if j==131072:
# 			j=0






#数据的存储方式 
print(len(result_weight))
count=0
for m in range(OUT_CHANNELS*8/CHANNELS): #channel_out*8/channel_in
	for s in range(CHANNELS/8):# channel_in/8
		for k in range (CHANNELS):#channel_in
			count=count+1   # k+m*channel_in+s*channel_out*8
			print(count,k+m*CHANNELS+s*OUT_CHANNELS*8,result_weight[k+m*CHANNELS+s*OUT_CHANNELS*8])
			savetxt.write(result_weight[k+m*CHANNELS+s*OUT_CHANNELS*8])
			if ((k+1)%8==0):
				savetxt.write("\n")
			# if(m<8):
			# 	save1txt.write(result_weight[k+m*256+s*4096])
			# 	if ((k+1)%8==0):
			# 		save1txt.write("\n")
			# elif(m>=8)&(m<16):
			# 	save2txt.write(result_weight[k+m*256+s*4096])
			# 	if ((k+1)%8==0):
			# 		save2txt.write("\n")




