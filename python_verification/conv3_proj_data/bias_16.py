#coding:utf-8 
#作用是将bias 划分为16进制的数据

lvtxt="./conv3_proj_bias.txt"
save_txt="./bias_16.dat"


savetxt = open(save_txt, 'w')  # 读取写入的文件

lvresult = open(lvtxt)  # 从lvresult.txt 获取
#修改文件，按照硬件运算的顺序进行计算
lvdata = lvresult.readlines()  # 所有的驻点的坐标
lvdata_len = len(lvdata)
print(lvdata_len)

end_result=[]
for i in range (lvdata_len):
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

	end_result.append(temp4)

# print(len(end_result))
# for i in range (32):
# 	for j in range(16):
# 		temp5=end_result[i+j*32]
# 		savetxt.write(str(temp5))
# 		savetxt.write("\n")

for i in range(len(end_result)):
	temp5=end_result[i]
	savetxt.write(str(temp5))
	savetxt.write("\n")

