#作用是将目标的数据循环 output_channel/pe_number 个数据
read_1_txt="./mem1.dat"
read_2_txt="./mem2.dat"

save_1_txt="./mem1_xh.dat"
save_2_txt="./mem2_xh.dat"

save1txt = open(save_1_txt, 'w')  # 读取写入的文件
save2txt = open(save_2_txt, 'w')  # 读取写入的文件

HIGHT=32
WIDTH=48
CHANNELS=256
OUTPUT_CHANNEL =512
PE_NUMBER=16

read_1=open(read_1_txt)
read_2=open(read_2_txt)

read_1_data=read_1.readlines()
read_2_data=read_2.readlines()

read_1_len=len(read_1_data)
read_2_len=len(read_2_data)

count=0
point=0
#count2=0

for i in range(int(read_1_len*OUTPUT_CHANNEL/PE_NUMBER)):
	#print(i,count)
	if ((i!=0)&(i%256==0)):
		count=count+1
		if (count==32):
			print("break",i-(count-1)*256-point*31*256,i,count,point,read_1_data[i-count*256-point*31*256])
			save1txt.write(read_1_data[i-(count-1)*256-point*31*256])
			save2txt.write(read_2_data[i-(count-1)*256-point*31*256])
		else:
			print("break",i-count*256-point*31*256,i,count,point,read_1_data[i-count*256-point*31*256])
			save1txt.write(read_1_data[i-count*256-point*31*256])
			save2txt.write(read_2_data[i-count*256-point*31*256])			
		if(count==OUTPUT_CHANNEL/PE_NUMBER):
			count=0
			point=point+1
	else:
		#temp1 = [(t1.strip()) for t1 in read_1_data[i].split()]
		print(i-count*256-point*31*256,i,read_1_data[i-count*256-point*31*256])
		save1txt.write(read_1_data[i-count*256-point*31*256])
		save2txt.write(read_2_data[i-count*256-point*31*256])