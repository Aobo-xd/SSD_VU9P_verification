# --*-- coding:utf-8 --*--
import math
import random

random.seed(0)
def rand(a, b):
    return (b - a) * random.random() + a

def make_matrix(m, n, fill=0.0):
    mat = []
    for i in range(m):
        mat.append([fill] * n)
    return mat

def sigmoid(x):
    #print("sigmod",x)  #abo
    return 1.0 / (1.0 + math.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

class BPNeuralNetwork:
    def __init__(self):
        self.input_n = 0
        self.hidden_n = 0
        self.output_n = 0
        self.input_cells = []
        self.hidden_cells = []
        self.output_cells = []
        self.input_weights = []
        self.output_weights = []
        self.input_correction = []
        self.output_correction = []

    def setup(self, ni, nh, no):
        self.input_n = ni + 1
        self.hidden_n = nh
        self.output_n = no
        # init cells
        self.input_cells = [1.0] * self.input_n
        self.hidden_cells = [1.0] * self.hidden_n
        self.output_cells = [1.0] * self.output_n
        # init weights
        self.input_weights = make_matrix(self.input_n, self.hidden_n)
        self.output_weights = make_matrix(self.hidden_n, self.output_n)
        # random activate
        for i in range(self.input_n):
            for h in range(self.hidden_n):
                self.input_weights[i][h] = rand(-0.2, 0.2)
        for h in range(self.hidden_n):
            for o in range(self.output_n):
                self.output_weights[h][o] = rand(-2.0, 2.0)
        # init correction matrix
        self.input_correction = make_matrix(self.input_n, self.hidden_n)
        self.output_correction = make_matrix(self.hidden_n, self.output_n)

    def predict(self, inputs):
        # activate input layer
        for i in range(self.input_n - 1):
            self.input_cells[i] = inputs[i]#输入层输出值
        # activate hidden layer
        for j in range(self.hidden_n):
            total = 0.0
            for i in range(self.input_n):
                total += self.input_cells[i] * self.input_weights[i][j]#隐藏层输入值
            self.hidden_cells[j] = sigmoid(total)#隐藏层的输出值
        # activate output layer
        for k in range(self.output_n):
            total = 0.0
            for j in range(self.hidden_n):
                total += self.hidden_cells[j] * self.output_weights[j][k]
                #-----------------------------------------------
            # self.output_cells[k] = sigmoid(total)
            self.output_cells[k] =total#输出层的激励函数是f(x)=x
 #-----------------------------------------------
        return self.output_cells[:]

    def back_propagate(self, case, label, learn, correct):#x,y,修改最大迭代次数， 学习率λ， 矫正率μ三个参数.
        # feed forward
        self.predict(case)
        # get output layer error
        output_deltas = [0.0] * self.output_n
        #print("bp",output_deltas) #abo
        for o in range(self.output_n):
            error = label[o] - self.output_cells[o]
            #-----------------------------------------------
            # output_deltas[o] = sigmoid_derivative(self.output_cells[o]) * error
            output_deltas[o] = error
#-----------------------------------------------
        # get hidden layer error
        hidden_deltas = [0.0] * self.hidden_n
        for h in range(self.hidden_n):
            error = 0.0
            for o in range(self.output_n):
                error += output_deltas[o] * self.output_weights[h][o]
            hidden_deltas[h] = sigmoid_derivative(self.hidden_cells[h]) * error

        # update output weights
        for h in range(self.hidden_n):
            for o in range(self.output_n):
                change = output_deltas[o] * self.hidden_cells[h]
                self.output_weights[h][o] += learn * change + correct * self.output_correction[h][o]#？？？？？？？？？？
                self.output_correction[h][o] = change

        # update input weights
        for i in range(self.input_n):
            for h in range(self.hidden_n):
                change = hidden_deltas[h] * self.input_cells[i]
                self.input_weights[i][h] += learn * change + correct * self.input_correction[i][h]
                self.input_correction[i][h] = change
        # get global error
        error = 0.0
        for o in range(len(label)):
            error += 0.5 * (label[o] - self.output_cells[o]) ** 2
        return error

    def train(self, cases, labels, limit=10000, learn=0.05, correct=0.1):
        for j in range(limit):
            error = 0.0
            for i in range(len(cases)):
                label = labels[i]
                case = cases[i]
                error += self.back_propagate(case, label, learn, correct)
    def reflush(self,train_line,train_flush_case,train_flush_labels): #flush date
        train_line_len=len(train_line)
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
        for i in range(len(train_trans)):
            temp1= [(t1.strip()) for t1 in train_trans[i].split()]
            if(temp1[0]=="flavor1"):
                temp1_flag=1
            elif(temp1[0]=="flavor2"):
                temp1_flag=2
            elif(temp1[0]=="flavor3"):
                temp1_flag=3
            elif(temp1[0]=="flavor4"):
                temp1_flag=4
            elif(temp1[0]=="flavor5"):
                temp1_flag=5
            elif(temp1[0]=="flavor6"):
                temp1_flag=6
            elif(temp1[0]=="flavor7"):
                temp1_flag=7
            elif(temp1[0]=="flavor8"):
                temp1_flag=8
            elif(temp1[0]=="flavor9"):
                temp1_flag=9
            elif(temp1[0]=="flavor10"):
                temp1_flag=10
            elif(temp1[0]=="flavor11"):
                temp1_flag=11
            elif(temp1[0]=="flavor12"):
                temp1_flag=12
            elif(temp1[0]=="flavor13"):
                temp1_flag=13
            elif(temp1[0]=="flavor14"):
                temp1_flag=14
            elif(temp1[0]=="flavor15"):
                temp1_flag=15

           # print(temp1[2],temp1[0],temp1[1])
            time_flag=((int(temp1[2][0:4])-2015)*356)+((int(temp1[2][4:6])-1)*30)+(int(temp1[2][6:8]))
            train_flush_case.append([float(time_flag),float(temp1_flag)])
            train_flush_labels.append([float(temp1[1])])

    def reflush_case_end(self,test_data,test_data_out):
        for i in range(len(test_data)):
            #print(test_data[0][0][0:4])
            test_data_flag=((int(test_data[i][0][0:4])-2015)*356)+((int(test_data[i][0][4:6])-1)*30)+(int(test_data[i][0][6:8]))
            test_data_out.append([float(test_data_flag),float(test_data[i][1])])

    def test(self):
        case_end=[
        ['20150107','1'],
        ['20150107','2'],
        ['20150107','3'],
        ['20150107','4'],
        ['20150107','5'],
        ['20150107','6'],
        ['20150107','7'],
        ['20150107','8'],
        ['20150107','9'],
        ['20150107','10'],
        ['20150107','11']
        ]
        data_train=open('test.txt','r')
        train_line=data_train.readlines()

        train_flush_case=[]
        train_flush_labels=[]
        case_end_result=[]

    
        self.setup(2, 4, 1)
        self.reflush(train_line,train_flush_case,train_flush_labels)
        print(train_flush_case)
        print(train_flush_labels)
        self.train(train_flush_case, train_flush_labels, 10000, 0.05, 0.1)
        self.reflush_case_end(case_end,case_end_result)
        print(case_end_result)
        for case in case_end_result:
            print(self.predict(case))


if __name__ == '__main__':
    nn = BPNeuralNetwork()
    nn.test()
    

 