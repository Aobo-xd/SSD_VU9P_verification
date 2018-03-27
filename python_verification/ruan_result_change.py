#coding:utf-8 
# 这个是根据通道方向来的
# lvtxt="./conv4_proj_output.txt"
# lvresult = open(lvtxt)  # 从lvresult.txt 获取
# lvdata = lvresult.readlines()  # 所有的驻点的坐标
# lvdata_len = len(lvdata)
# print(lvdata_len)


# save_1_txt="./end_right/out_ruan_1.dat"
# save_2_txt="./end_right/out_ruan_2.dat"

# save1txt = open(save_1_txt, 'w')  # 读取写入的文件
# save2txt = open(save_2_txt, 'w')  # 读取写入的文件

# for s in range(24):#
# 	for m in range(16): #
# 		for k in range (512):#256
# 			print(k*384+m*24+s)
# 			temp1= [(t1.strip()) for t1 in lvdata[k*384+m*24+s].split()]
# 			temp2=temp1[0] #16进制的数字
# 			if(m<8):
# 				save1txt.write(temp2)
# 				save1txt.write("\n")
# 			elif(m>=8)&(m<16):
# 				save2txt.write(temp2)
# 				save2txt.write("\n")

HEIGHT=32
WEIGHT=48

lvtxt="./conv4_proj_output.txt"
lvresult = open(lvtxt)  # 从lvresult.txt 获取
lvdata = lvresult.readlines()  # 所有的驻点的坐标
lvdata_len = len(lvdata)
print(lvdata_len)


save_1_txt="./end_right/out_2_ruan_1.dat"
save_2_txt="./end_right/out_2_ruan_2.dat"

save1txt = open(save_1_txt, 'w')  # 读取写入的文件
save2txt = open(save_2_txt, 'w')  # 读取写入的文件

for s in range(WEIGHT>>2):#
	for m in range(HEIGHT>>2): #
		for k in range (512):#256
			print(k,2*m,2*s,k*384+2*m*24+2*s)
			temp1= [(t1.strip()) for t1 in lvdata[k*384+2*m*24+2*s].split()]
			temp2=temp1[0] #16进制的数字
			temp3= [(t1.strip()) for t1 in lvdata[k*384+2*m*24+(2*s+1)].split()]
			temp4=temp3[0] #16进制的数字
			temp5= [(t1.strip()) for t1 in lvdata[k*384+(2*m+1)*24+2*s].split()]
			temp6=temp5[0] #16进制的数字
			temp7= [(t1.strip()) for t1 in lvdata[k*384+(2*m+1)*24+(2*s+1)].split()]
			temp8=temp7[0] #16进制的数字
			if(m<4):
				save1txt.write(temp2)
				save1txt.write("\n")
				save1txt.write(temp4)
				save1txt.write("\n")
				save1txt.write(temp6)
				save1txt.write("\n")
				save1txt.write(temp8)
				save1txt.write("\n")
			elif(m>=4)&(m<8):
				save2txt.write(temp2)
				save2txt.write("\n")
				save2txt.write(temp4)
				save2txt.write("\n")
				save2txt.write(temp6)
				save2txt.write("\n")
				save2txt.write(temp8)
				save2txt.write("\n")