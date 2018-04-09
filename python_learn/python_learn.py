import numpy as np #y引入的是模块的别名
'''
#20170721 学习的课程
def npSum():
	a=np.array([0,1,2,3,4])
	b=np.array([9,8,7,6,5])

	c=a**2+b**3
	print (c.ndim,c.shape,c.size,c.dtype,c.itemsize )
	return c
print (npSum())
'''
'''
ndarray 的科学计算库 广播功能  c/c++的工具
	实际的存储数据 描述的元数据（数据的维度，数据的类型）
	0开始 一般所有的元素相同 
	轴（axis）表示数据的维度的 秩（rank）轴的数量
	属性：
	1：.ndim 秩，轴的数量或维度的数量
	2：.shape 对象的尺度，n行m列
	3：.size 对象的个数  n*m的值
	4：.dtype 对象的数据类型
	5: .itemsize 每个对象的大小，以字节为单位

	元素类型：complex64 复数类型 实部和虚部都是32浮点数
	对程序规模的精细定义

	非同质的ndarray对象尽量少用
ndarray数组的创建方法：
	1.从python的列表，元祖等类型创建ndarray数组
	x=np.array(list/tuple)  可用dtype来指定对应的类型
	eg:x=np.array(list/tuple,dtype=np.float32)
	2.使用numpy中的函数创建ndarray类型
	np.arange(n) range()函数，返回ndarray类型，元素从0到n-1
	np.ones(shape) 根据shape生成一个全1数组，shape是元组类型  
	np.zeros(shape) 根据shape生成一个全0数组，shape是元祖类型
	np.full(shape,val) 根据shape生成一个数组，每个元素的值都是val
	np.eye(n) 创建一个正方的n*n的单位矩阵，对角线为1，其余为0

	np.ones_like(a) 根据数组a的形状生成一个全1数组
	np.zeros_like(a) 根据数组a的形状生成一个全0数组
	np.full_like(a,val) 根据数组a的形状生成一个数组，每个元素值都是val

	np.linspace() 根据起止数据等间距地填充数据，形成数组 （起始位置，最后一个位置，包含四个元素）
	     不限定的时候是浮点数，包括最后一个位置，(，，，endpoint=False) 结果是可为浮点数，不包最后一个数
	np.concatenate() 将两个或多个数组合并成一个新的数组
'''
#x=np.ones((2,3,4))  #从数组的最外层到最内层

'''
ndarrry 的数组的维度变换：
	.reshape(shape) 不改变数组元素，返回一个shape形状的数组，原数组不变
	.resize(shape) 与.reshape()功能一致，但修改原数组
	.swapaxes(ax1,ax2) 将数组n个维度中两个维度进行调换
	.flatten() 对数组进行降维，返回折叠后的一维数组，原数组不变
	#注意用什么改变原数组，什么不改变原数组
'''
'''
a=np.ones((2,3,4),dtype=np.int32)
print("a.reshape()",a.reshape((3,8))) # 没改变原数组,新生成数组
print("a",a)
print("a.resize()",a.resize((3,8))) # 改变原数组，不生成新数组
print("a",a)
'''
'''
ndarray数组的类型变换:
	new_a=a.astype(new_type)  #这个方法会创建原始的数组的拷贝，即使两个一样
ndarray数组向列表的转换：
	ls=a,tolist()

'''
'''
nadarry数组的操作：
	数组的所以和操作：
		索引：获取数组中特定位置元素的过程
		切片：获取数组元素子集的过程
	一维数组的：
		索引：原来的相同
		切片：a[起始编号：终止编号(不含)：步长，3元素冒号分割] 编号0开始从左递增，-1从右递减
	多维数组的：
		索引：a[,,] 每一个维度一个索引值，逗号分隔
		切片：：为从开始到最后  每个维度与一维数组相同 [:,:,::2] 可以使用步长跳跃切片
			 
'''
#a=np.arange(24).reshape((2,3,4))
#print (a)
'''
ndarray数组的运算:
	数组与标量之间的运算作用于数组的每一个元素;mean() 算平均值
	NumPy一元函数：对ndarray中的数据执行元素级运算的函数
		np.abs(x) np.fabs(x)       计算数组各元素的绝对值
		np.sqrt(x)                 计算数组各元素的平方根
		np.square(x)               计算数组各元素的平方
		np.log(x) np.log10(x)
		np.log2(x)                 计算数组各元素的自然对数、 10底对数和2底对数
		np.ceil(x) np.floor(x)     计算数组各元素的ceiling值 或 floor值
		np.rint(x)                 计算数组各元素的四舍五入值
		np.modf(x)                 将数组各元素的小数和整数部分以两个独立数组形式返回
		np.cos(x) np.cosh(x)
		np.sin(x) np.sinh(x)
		np.tan(x) np.tanh(x)       计算数组各元素的普通型和双曲型三角函数
		np.exp(x)                  计算数组各元素的指数值
		np.sign(x)                 计算数组各元素的符号值，1(+), 0, ‐1(‐)
	NumPy二元函数：
		+ ‐ * / **                 两个数组各元素进行对应运算
		np.maximum(x,y) np.fmax()
		np.minimum(x,y) np.fmin()  元素级的最大值/最小值计算
		np.mod(x,y)                元素级的模运算
		np.copysign(x,y)           将数组y中各元素值的符号赋值给数组x对应元素
		> < >= <= == !=            算术比较，产生布尔型数组
#注意原数组是否改变  
'''
'''
csv文件（Comma‐Separated Value,逗号分隔值）:
	np.savetxt(frame, array, fmt='%.18e', delimiter=None)  #写文件
		• frame : 文件、字符串或产生器，可以是.gz或.bz2的压缩文件
		• array : 存入文件的数组
		• fmt : 写入文件的格式，例如：%d %.2f %.18e(科学记数法)
		• delimiter : 分割字符串，默认是任何空格(数据间是空格)
	np.loadtxt(frame, dtype=np.float, delimiter=None， unpack=False) #读文件
		• frame : 文件、字符串或产生器，可以是.gz或.bz2的压缩文件
		• dtype : 数据类型，可选
		• delimiter : 分割字符串，默认是任何空格
		• unpack : 如果True，读入属性将分别写入不同变量
#csv文件只能有效的存储一维和二维的数据
'''
'''
a=np.arange(100).reshape(5,20)
np.savetxt('a.csv',a,fmt="%.1f",delimiter=',') #保存的文件

#help(np.loadtxt)
b=np.loadtxt('a.csv',delimiter=',')
print (b)
'''
'''
多维数组的存取：
	任意维度的数组：
		a.tofile(frame,sep='',format='%s') #写文件
			• frame : 文件、字符串
			• sep : 数据分割字符串，如果是空串，写入文件为二进制
			• format : 写入数据的格式
		np.fromfile(frame, dtype=float, count=‐1, sep='') #读文件
			• frame : 文件、字符串
			• dtype : 读取的数据类型
			• count : 读入元素个数，‐1表示读入整个文件
			• sep : 数据分割字符串，如果是空串，写入文件为二进制
		#该方法需要读取时知道存入文件时数组的维度和元素类型
		#可以通过元数据文件来存储额外信息
	Numpy的便捷文件存储：
		np.save(fname, array) 或 np.savez(fname, array)
			• fname : 文件名，以.npy为扩展名，压缩扩展名为.npz
			• array : 数组变量
		np.load(fname)
			• fname : 文件名，以.npy为扩展名，压缩扩展名为.npz

'''
'''
a=np.arange(100).reshape(5,10,2)
a.tofile('b.dat',format='%d')
c=np.fromfile("b.dat",dtype=np.int).reshape(5,2,10)
#print(c)
np.save('a.npy',a)
b=np.load("a.npy")
print (b)
'''
'''
Numpy的随机函数：
	NumPy的random子库：np.random.rand() np.random.randn() np.random.randint()
		rand(d0,d1,..,dn)    	   根据d0‐dn创建随机数数组，浮点数，[0,1)，均匀分布
		randn(d0,d1,..,dn)   	   根据d0‐dn创建随机数数组，标准正态分布
		randint(low[,high,shape])  根据shape创建随机整数或整数数组，范围是[low, high)
		seed(s) 				   随机数种子，s是给定的种子值

	    shuffle(a) 				   根据数组a的第1轴进行随排列，改变数组x
		permutation(a) 			   根据数组a的第1轴产生一个新的乱序数组，不改变数组x
		choice(a[,size,replace,p]) 从一维数组a中以概率p抽取元素，形成size形状新数组
		replace                    表示是否可以重用元素，默认为False

		uniform(low,high,size) 	   产生具有均匀分布的数组,low起始值,high结束值,size形状
		normal(loc,scale,size) 	   产生具有正态分布的数组,loc均值,scale标准差,size形状
		poisson(lam,size) 		   产生具有泊松分布的数组,lam随机事件发生率,size形状



Numpy的统计函数：
	NumPy直接提供的统计函数 np.*
	sum(a, axis=None) 			  	  根据给定轴axis计算数组a相关元素之和，axis整数或元组
	mean(a, axis=None) 			  	  根据给定轴axis计算数组a相关元素的期望，axis整数或元组
	average(a,axis=None,weights=None) 根据给定轴axis计算数组a相关元素的加权平均值
	std(a, axis=None)              	  根据给定轴axis计算数组a相关元素的标准差
	var(a, axis=None) 				  根据给定轴axis计算数组a相关元素的方差
	#axis=None 是统计函数的标配参数
'''
a=np.arange(15).reshape(3,5)
print (a)
print(np.mean(a,axis=1)) #axis的值是0的时候是横轴，为1的时候是纵轴
print(np.average(a,axis=0,weights=[10,5,1]))

