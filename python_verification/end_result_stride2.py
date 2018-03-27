#coding:utf-8 
input_txt_1="./mem1.dat"
input_txt_2="./mem2.dat"
weight_txt="./conv4_proj_weights.txt"
bias_txt="./conv4_proj_bias.txt"


savetxt_1="./end_right/1.dat"
savetxt_2="./end_right/2.dat"
save1txt = open(savetxt_1, 'w')  # 读取写入的文件
save2txt = open(savetxt_2, 'w')  # 读取写入的文件

HIGHT=32 
WIDTH=48
CHANNELS_IN=256
CHANNELS_OUT=512

inputresult_1=open(input_txt_1)
inputresult_2=open(input_txt_2)
weightresult=open(weight_txt)
biasresult=open(bias_txt)

input_data_1=inputresult_1.readlines()
input_data_2=inputresult_2.readlines()
weight_data=weightresult.readlines()
bias_data=biasresult.readlines()

input_data_1_len=len(input_data_1)
input_data_2_len=len(input_data_2)
weight_data_len=len(weight_data)
bias_datal_len=len(bias_data)


result_1=[]
result_2=[]

sum_temp=0
count=0
count_temp=0
for i in range(WIDTH>>1): #24
	for j in range(HIGHT>>2):#8
		sum_temp=0
		for m in range(CHANNELS_OUT): #512
			bias = [(t2.strip()) for t2 in bias_data[m].split()]
			sum_temp=0
			for k in range(CHANNELS_IN): #256
				fmap_1 = [(t1.strip()) for t1 in input_data_1[k+(j+i*8)*256].split()]
				weight=[(t2.strip()) for t2 in weight_data[k+m*256].split()]
				sum_temp=sum_temp+int(fmap_1[0])*int(weight[0])
				# if(j==1)&(m==8):
				# 	print(fmap_1,weight,int(fmap_1[0])*int(weight[0]))
			# 	if(count<=16):
			# 		if(count_temp<3):
			# 			print("%d:%s",count_temp,weight)
			# 			count_temp=count_temp+1
			# count=count+1		
			# if(count<=16):
				
			# 	print(count,sum_temp,int(bias[0]))
			# 	count_temp=0
			result_1.append((sum_temp>>7)+int(bias[0]))
			#result_1.append(sum_temp>>7)
			


sum_temp=0
count=0
count_temp=0
for i in range(WIDTH>>1):
	for j in range(HIGHT>>2):
		for m in range(CHANNELS_OUT): #512
			bias = [(t2.strip()) for t2 in bias_data[m].split()]
			for k in range(CHANNELS_IN): #256
				#print("fmap",k+j*256+i*256*8)
				fmap_2 = [(t1.strip()) for t1 in input_data_2[k+(j+i*8)*256].split()]
				#print(int(fmap_1[0]))
				#print("weight",k+m*256)
				weight=[(t2.strip()) for t2 in weight_data[k+m*256].split()]
				sum_temp=sum_temp+int(fmap_2[0])*int(weight[0])
			# 	if(j==1)&(m==1):
			# 		print(fmap_2,weight)
			# # 	if(count<=16):
			# 		if(count_temp<3):
			# 			print("%d:%s",count_temp,weight)
			# 			count_temp=count_temp+1
			# count=count+1		
			# if(count<=16):
		

			# 	print(count,sum_temp,int(bias[0]))
			# 	count_temp=0
			result_2.append((sum_temp>>7)+int(bias[0]))
			#result_2.append(sum_temp>>7)
			sum_temp=0
#####按照顺序排序 32个间隔

#############
print(len(result_1))
print(len(result_2))


for i in range (len(result_1)):
	temp1 = result_1[i]
	#temp2=int(temp1[0])  #16进制的数字
	temp3="%s%s"%(temp1,"\n")
	save1txt.write(str(temp3))

for i in range (len(result_2)):
	temp1 = result_2[i]
	#temp2=int(temp1[0])  #16进制的数字
	temp3="%s%s"%(temp1,"\n")
	save2txt.write(str(temp3))


		































# savetxt_1="./end_right/1.dat"
# savetxt_2="./end_right/2.dat"
# savetxt_3="./end_right/3.dat"
# savetxt_4="./end_right/4.dat"
# savetxt_5="./end_right/5.dat"
# savetxt_6="./end_right/6.dat"
# savetxt_7="./end_right/7.dat"
# savetxt_8="./end_right/8.dat"
# savetxt_9="./end_right/9.dat"
# savetxt_10="./end_right/10.dat"
# savetxt_11="./end_right/11.dat"
# savetxt_12="./end_right/12.dat"
# savetxt_13="./end_right/13.dat"
# savetxt_14="./end_right/14.dat"
# savetxt_15="./end_right/15.dat"
# savetxt_16="./end_right/16.dat"

# savetxt_17="./end_right/17.dat"
# savetxt_18="./end_right/18.dat"
# savetxt_19="./end_right/19.dat"
# savetxt_20="./end_right/20.dat"
# savetxt_21="./end_right/21.dat"
# savetxt_22="./end_right/22.dat"
# savetxt_23="./end_right/23.dat"
# savetxt_24="./end_right/24.dat"
# savetxt_25="./end_right/25.dat"
# savetxt_26="./end_right/26.dat"
# savetxt_27="./end_right/27.dat"
# savetxt_28="./end_right/28.dat"
# savetxt_29="./end_right/29.dat"
# savetxt_30="./end_right/30.dat"
# savetxt_31="./end_right/31.dat"
# savetxt_32="./end_right/32.dat"