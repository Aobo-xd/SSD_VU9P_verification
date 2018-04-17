# --*-- coding:utf-8 --*--

data_train=open('test.txt','r')
train_line=data_train.readlines()
train_line_len=len(train_line)
#print(train_line_len)


#############先进行数据的简化工作
train_trans=[]
train_trans_temp=[]
train_trans_temp_flv=[]
t=0
for i in range(train_line_len):
    temp1= [(t1.strip()) for t1 in train_line[i].split()]
    
    if(t!=0):
        if(temp1[2]==temp_time):        
            train_trans_temp.append(temp1)
            if(temp1[1]not in train_trans_temp_flv):
                train_trans_temp_flv.append(temp1[1])
        if(temp1[2]!=temp_time)|(i==train_line_len-1):
            
            #print(train_trans_temp)
            for j in range(len(train_trans_temp_flv)):
                #print(j,train_trans_temp_flv[j])
                count_temp=0
                for t in range(len(train_trans_temp)):
                    temp3= train_trans_temp[t]
                    temp4= [(t2.strip()) for t2 in temp3[2].split('-')]
                    time_temp="%s%s%s"%(temp4[0],temp4[1],temp4[2])
                    if(train_trans_temp_flv[j]==temp3[1]):
                        count_temp=count_temp+1
                #print("count_temp",train_trans_temp_flv[j],count_temp,time_temp)
                str_temp="%s%s%s%s%s"%(train_trans_temp_flv[j]," ",count_temp," ",time_temp);
                train_trans.append(str_temp)

            # for j in range(len(train_trans_temp_flv)):
            #     print(train_trans_temp_flv[j])
                #temp2= [(t2.strip()) for t2 in train_trans_temp[j].split()]
            train_trans_temp=[]
            train_trans_temp_flv=[]
            t=0
        
    if(t==0):
        #print(i)
        temp_time=temp1[2]
        train_trans_temp.append(temp1)
        train_trans_temp_flv.append(temp1[1])
        t=t+1
        #print(train_trans_temp)

#print(train_trans)
for i in range(len(train_trans)):
    temp1= [(t1.strip()) for t1 in train_trans[i].split()]
    print(temp1[2])
    #print(temp1[2][0:4])
    if(temp1[2][0:4]=='2015'):
        print(((int(temp1[2][0:4])-2015)*356)+(int(temp1[2][4:6])*30)+(int(temp1[2][6:8])))



