#作用是将数据分为上下两个部分，按照每一行64位的模式进行存储 ，每32行表示256个数据
lvtxt="./conv4_proj_weights.txt"
save_1_txt="./weight10_1.dat"
save_2_txt="./weight10_2.dat"


save1txt = open(save_1_txt, 'w')  # 读取写入的文件
save2txt = open(save_2_txt, 'w')  # 读取写入的文件

lvresult = open(lvtxt)  # 从lvresult.txt 获取
lvdata = lvresult.readlines()  # 所有的驻点的坐标
lvdata_len = len(lvdata)
print(lvdata_len)

j=0
for i in range (lvdata_len):
	j=j+1
	temp1= [(t1.strip()) for t1 in lvdata[i].split()]
	temp2=int(temp1[0]) #16进制的数字
	if (j<=256)&(j>0):
		temp3="%s%s"%(temp2,"\n")
		save1txt.write(str(temp3))
		print(temp2)
	elif (j>256)&(j<=512):
		temp3="%s%s"%(temp2,"\n")
		save2txt.write(str(temp3))
		print(temp2)
		if j==512:
			j=0
