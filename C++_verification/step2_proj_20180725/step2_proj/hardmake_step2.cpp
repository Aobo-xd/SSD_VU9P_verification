#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
//#include <string>
#include <iterator>
#include <iomanip>
#include "param.h"

using namespace std;
using namespace cv;


// 读文件中的bias
void read_bias_from_file(string fileName, vector<int>& bias_vector, int channel_out) {
	//读取bias
	ifstream bias_in(fileName);
	if (!bias_in) {
		cout << "bias error" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < channel_out; ++i) {
		int data;
		bias_in >> data;
		bias_vector.push_back(data);
	}
}
//读文件中的weights
void read_weight_from_file(string fileName, vector< vector<int> >& weight, int channel_in, int channel_out) {
	ifstream weight_in(fileName);
	//读入所有的weights
	for (int i = 0; i < channel_in*channel_out; ++i) {
		vector<int> one_weight;
		for (int j = 0; j < 9; ++j) {
			int temp;
			weight_in >> temp;
			one_weight.push_back(temp);
		}
		weight.push_back(one_weight);
	}
}

void  writeWeightToFile(vector< vector<int> >& weight, string fileName, int channel_in, int channel_out, int PE_number) {
	ofstream fp(fileName);
	int base = 0;
	for (int n = 0; n < PE_number * 2; ++n) {
		for (int i = 0; i < channel_out / (PE_number * 2); ++i) {
			for (int k = 0; k < channel_in; ++k) {
				vector<int> a = weight[base + i * PE_number * 2 * channel_in + k];
				for (int m = 0; m < 9; ++m) {
					if (a[m] < 0) {
						fp << setfill('0') << setw(2) << hex << 256 + a[m];
						//weight_uart << setfill('0') << setw(2) << hex << 256 + a[m] << endl;
						char temp = a[m];
					//	weight_uart.write(&temp, 1);
					}
					else {
						fp << setfill('0') << setw(2) << hex << a[m];
						//weight_uart << setfill('0') << setw(2) << hex << a[m] << endl;
						char temp = a[m];
					//	weight_uart.write(&temp, 1);
					}
				}
				fp << endl;
			}
		}
		base += channel_in;
	}
	fp.close();
}

// 写bias到文件中
void writeBiasToFile(vector<int> &bias, string fileName) {
	ofstream fp(fileName);
	for (size_t i = 0; i < bias.size(); ++i) {
		if (bias[i] < 0) {
			fp << setfill('0') << setw(2) << hex << 256 + bias[i] << endl;
			//bias_uart << setfill('0') << setw(2) << hex << 256 + bias[i]<< endl;
			char temp = bias[i];
			//bias_uart.write(&temp, 1);
		}
		else {
			fp << setfill('0') << setw(2) << hex << bias[i] << endl;
			//bias_uart << setfill('0') << setw(2) << hex << bias[i]<< endl;
			char temp = bias[i];
			//bias_uart.write(&temp, 1);
		}
	}
	fp.close();
}

// 从外面读文件到mat的结构中
void read_fmap_from_file(string fileName, vector<Mat> &fmap_mat, int height, int width, int channel_in) {
	ifstream fmap_in(fileName);
	if (!fmap_in) {
		cout << "error " << endl;
		system("pause");
		return;
	}
	//读入所有fmap
	vector< vector<int> > fmap;
	for (int i = 0; i < channel_in; ++i) {
		vector<int> one_fmap;
		for (int j = 0; j < height*width; ++j) {
			int temp;
			fmap_in >> temp;
			if (temp < 0) {  //进行relu的操作
				temp = 0;
			}
			one_fmap.push_back(temp);
		}
		fmap.push_back(one_fmap);
	}

	//将所有vector类型的fmap转换为Mat类型
	for (vector< vector<int> >::iterator iter = fmap.begin(); iter != fmap.end(); ++iter) {
		vector<int> one_fmap;
		one_fmap = *iter;
		Mat a(one_fmap);
		Mat b = a.reshape(0, height);
		fmap_mat.push_back(b.clone());
	}
}
//输出文件的写
void read_fmap_from_file_norelu(string fileName, vector<Mat> &fmap_mat, int height, int width, int channel_in) {
	ifstream fmap_in(fileName);
	if (!fmap_in) {
		cout << "error " << endl;
		system("pause");
		return;
	}
	//读入所有fmap
	vector< vector<int> > fmap;
	for (int i = 0; i < channel_in; ++i) {
		vector<int> one_fmap;
		for (int j = 0; j < height*width; ++j) {
			int temp;
			fmap_in >> temp;
			one_fmap.push_back(temp);
		}
		fmap.push_back(one_fmap);
	}

	//将所有vector类型的fmap转换为Mat类型
	for (vector< vector<int> >::iterator iter = fmap.begin(); iter != fmap.end(); ++iter) {
		vector<int> one_fmap;
		one_fmap = *iter;
		Mat a(one_fmap);
		Mat b = a.reshape(0, height);
		fmap_mat.push_back(b.clone());
	}
}
// 从外面读文件到mat的结构中
void read_fmap_from_file_8(string fileName, vector<Mat> &fmap_mat, int height, int width, int channel_in) {
	ifstream fmap_in(fileName);
	if (!fmap_in) {
		cout << "error " << endl;
		system("pause");
		return;
	}
	//读入所有fmap
	vector< vector<int> > fmap;
	for (int i = 0; i < channel_in; ++i) {
		vector<int> one_fmap;
		for (int j = 0; j < height*(width+1); ++j) {
			int temp;
			if ((j + 1) % (width+1) == 0) //当为最后一个的 进行加0的操作
			{
			//	cout << j << endl;
				temp = 0;
			}
			else {  //正常的取数据
				fmap_in >> temp;
				if (temp < 0) {  //进行relu的操作
					temp = 0;
				}
			}			
			one_fmap.push_back(temp);
		}
		fmap.push_back(one_fmap);
	}

	//将所有vector类型的fmap转换为Mat类型
	for (vector< vector<int> >::iterator iter = fmap.begin(); iter != fmap.end(); ++iter) {
		vector<int> one_fmap;
		one_fmap = *iter;
		Mat a(one_fmap);
		Mat b = a.reshape(0, height); //根据数量自动推算
		fmap_mat.push_back(b.clone());
	}
}
void read_fmap_from_file_8_norelu(string fileName, vector<Mat> &fmap_mat, int height, int width, int channel_in) {
	ifstream fmap_in(fileName);
	if (!fmap_in) {
		cout << "error " << endl;
		system("pause");
		return;
	}
	//读入所有fmap
	//cout << channel_in<< height<< width + 1 << endl;
	vector< vector<int> > fmap;
	for (int i = 0; i < channel_in; ++i) {
		vector<int> one_fmap;
		for (int j = 0; j < height*(width + 1); ++j) {
			int temp;
			if ((j + 1) % (width + 1) == 0) //当为最后一个的 进行加0的操作
			{
				//cout << j << endl;
				temp = 0;
			}
			else {  //正常的取数据
				fmap_in >> temp;
			}
			one_fmap.push_back(temp);
		}
		fmap.push_back(one_fmap);
	}

	//将所有vector类型的fmap转换为Mat类型
	for (vector< vector<int> >::iterator iter = fmap.begin(); iter != fmap.end(); ++iter) {
		vector<int> one_fmap;
		one_fmap = *iter;
		Mat a(one_fmap);
		Mat b = a.reshape(0, height); //根据数量自动推算
		fmap_mat.push_back(b.clone());
	}
}

//padding 输出
//第八层的数据的输出
void split2x2_conv8_result_32(Mat &image, string fileName1, int select = 0) {
	ofstream fp1(fileName1);
	int height = image.rows;
	int width = image.cols;
	//cout << height << ' ' << width << endl;
	//part1
	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < height / 2; ++j) {
			Mat fmap2x2 = image(Rect(i * 2, j * 2, 2, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
				if (select == 1) {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							if (fmap2x2_vector[k].at<int>(kk, mm) < 0) {
								fp1 << setfill('0') << setw(2) << hex << 256 + fmap2x2_vector[k].at<int>(kk, mm);
							}
							else {
								fp1 << setfill('0') << setw(2) << hex << fmap2x2_vector[k].at<int>(kk, mm);
							}
						}
					}
					fp1 << endl;
				}
				else {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							fp1 << fmap2x2_vector[k].at<int>(kk, mm) << endl;
						}
					}
				}
			}
		}
	}
	fp1.close();
}


//第八层的数据的输出
void split2x2_conv8_result(Mat &image, string fileName1, int select = 0) {
	ofstream fp1(fileName1);
	int height = image.rows;
	int width = image.cols;
	//cout << height << ' ' << width << endl;
	//part1
	int number_temp = 0;
	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < height / 2; ++j) {
			Mat fmap2x2 = image(Rect(i * 2, j * 2, 2, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
				if (select == 1) {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							if (fmap2x2_vector[k].at<int>(kk, mm) < 0) {
								fp1 << setfill('0') << setw(2) << hex << 256 + fmap2x2_vector[k].at<int>(kk, mm);
							}
							else {
								fp1 << setfill('0') << setw(2) << hex << fmap2x2_vector[k].at<int>(kk, mm);
							}
						}
					}
					//fp1 << endl;
					number_temp = number_temp + 1;
					if (number_temp == 8) {
						//cout << number_temp << endl;
						fp1 << endl;
						number_temp = 0;
					}
				}
				else {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							fp1 << fmap2x2_vector[k].at<int>(kk, mm) << endl;
						}
					}
				}
			}
		}
	}
	fp1.close();
}
//将mat为2x2的块 变成硬件的结构   结果写入到外面
void split2x2(Mat &image, string fileName1, string fileName2, int select = 0, bool conv1_1_flag = false) {
	ofstream fp1(fileName1), fp2(fileName2);
	int height = image.rows;
	int width = image.cols;
	//part1
	//cout << height<< width << endl;
	int number_temp=0;
	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < height / 2 - height / 4; ++j) {
			Mat fmap2x2 = image(Rect(i * 2, j * 2, 2, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
				if (select == 1) {
						for (int kk = 0; kk < 2; ++kk) {
							for (int mm = 0; mm < 2; ++mm) {
								if (fmap2x2_vector[k].at<int>(kk, mm) < 0) {
									if (conv1_1_flag == false) //不是第一层，数据用8bit表示
										fp1 << setfill('0') << setw(2) << hex << 256 + fmap2x2_vector[k].at<int>(kk, mm);
									else //是第一层，数据用12bit表示
										fp1 << setfill('0') << setw(3) << hex << 4096 + fmap2x2_vector[k].at<int>(kk, mm);
								}
								else {
									if (conv1_1_flag == false) //不是第一层，数据用8bit表示
										fp1 << setfill('0') << setw(2) << hex << fmap2x2_vector[k].at<int>(kk, mm);
									else
										fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(kk, mm);
								}
							}
						}
						////cout << number_temp << endl;
						//fp1<< endl;
						number_temp = number_temp + 1;
						if (number_temp == 8) {
							fp1 << endl;
							number_temp = 0;
						}
						
				}
				else {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							fp1 << fmap2x2_vector[k].at<int>(kk, mm) << endl;
						}
					}
				}
			}
		}
	}
	//part2
	number_temp = 0;
	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < height / 4; ++j) {
			Mat fmap2x2 = image(Rect(i * 2, j * 2 + (height / 2 - height / 4) * 2, 2, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
				if (select == 1) {
						for (int kk = 0; kk < 2; ++kk) {
							for (int mm = 0; mm < 2; ++mm) {
								if (fmap2x2_vector[k].at<int>(kk, mm) < 0) {
									if (conv1_1_flag == false) //不是第一层，数据用8bit表示
										fp2 << setfill('0') << setw(2) << hex << 256 + fmap2x2_vector[k].at<int>(kk, mm);
									else //是第一层，数据用12bit表示
										fp2 << setfill('0') << setw(3) << hex << 4096 + fmap2x2_vector[k].at<int>(kk, mm);
								}
								else {
									if (conv1_1_flag == false) //不是第一层，数据用8bit表示
										fp2 << setfill('0') << setw(2) << hex << fmap2x2_vector[k].at<int>(kk, mm);
									else
										fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(kk, mm);
								}
							}
						}
				
				//cout << number_temp << endl;
				//fp2 << endl;
				number_temp = number_temp + 1;
				if (number_temp == 8) {
					fp2 << endl;
					number_temp = 0;
					}
				
				}
				else {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							fp2 << fmap2x2_vector[k].at<int>(kk, mm) << endl;
						}
					}
				}
			}
		}
	}

	fp1.close();
	fp2.close();
}
////////////下面的文件的 32bit 
void split2x2_32(Mat &image, string fileName1, string fileName2, int select = 0, bool conv1_1_flag = false) {
	ofstream fp1(fileName1), fp2(fileName2);
	int height = image.rows;
	int width = image.cols;
	//part1
	//cout << height<< width << endl;
	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < height / 2 - height / 4; ++j) {
			Mat fmap2x2 = image(Rect(i * 2, j * 2, 2, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
				if (select == 1) {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							if (fmap2x2_vector[k].at<int>(kk, mm) < 0) {
								if (conv1_1_flag == false) //不是第一层，数据用8bit表示
									fp1 << setfill('0') << setw(2) << hex << 256 + fmap2x2_vector[k].at<int>(kk, mm);
								else //是第一层，数据用12bit表示
									fp1 << setfill('0') << setw(3) << hex << 4096 + fmap2x2_vector[k].at<int>(kk, mm);
							}
							else {
								if (conv1_1_flag == false) //不是第一层，数据用8bit表示
									fp1 << setfill('0') << setw(2) << hex << fmap2x2_vector[k].at<int>(kk, mm);
								else
									fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(kk, mm);
							}
						}
					}
					////cout << number_temp << endl;
					fp1<< endl;

				}
				else {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							fp1 << fmap2x2_vector[k].at<int>(kk, mm) << endl;
						}
					}
				}
			}
		}
	}
	//part2
	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < height / 4; ++j) {
			Mat fmap2x2 = image(Rect(i * 2, j * 2 + (height / 2 - height / 4) * 2, 2, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
				if (select == 1) {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							if (fmap2x2_vector[k].at<int>(kk, mm) < 0) {
								if (conv1_1_flag == false) //不是第一层，数据用8bit表示
									fp2 << setfill('0') << setw(2) << hex << 256 + fmap2x2_vector[k].at<int>(kk, mm);
								else //是第一层，数据用12bit表示
									fp2 << setfill('0') << setw(3) << hex << 4096 + fmap2x2_vector[k].at<int>(kk, mm);
							}
							else {
								if (conv1_1_flag == false) //不是第一层，数据用8bit表示
									fp2 << setfill('0') << setw(2) << hex << fmap2x2_vector[k].at<int>(kk, mm);
								else
									fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(kk, mm);
							}
						}
					}
					fp2 << endl;

				}
				else {
					for (int kk = 0; kk < 2; ++kk) {
						for (int mm = 0; mm < 2; ++mm) {
							fp2 << fmap2x2_vector[k].at<int>(kk, mm) << endl;
						}
					}
				}
			}
		}
	}

	fp1.close();
	fp2.close();
}

void writeFmapToFile(Mat &fmap, string fileName1, string fileName2, bool conv2_2_1_2_flag = false) {
	split2x2(fmap, fileName1, fileName2, 1, conv2_2_1_2_flag);
}

// 主函数的过程
int main() {
	int height, width, channel_in, channel_out, PE_number;
	int fl_layer_in;
	int fl_layer_out;
	int fl_param;


	vector<Mat> fmap_mat;
	vector<Mat> result_out;
	vector<int> bias_vector;
	vector< vector<int> > weight;
	string fileName1, fileName2, fileName3, fileName4;
	Mat padding_fmap;
	Mat result_out_temp;

	/////////////abo




	//////////////////abo
	////////////////////////////////conv_3_2_conf//////////////////////////
	/****************************
	********conv_3_2_conf*********
	*****************************/
	height = CONV_3_2_CONF_HEIGHT;
	width = CONV_3_2_CONF_WIDTH;
	channel_in = CONV_3_2_CONF_CHANNEL_NUMBER;
	channel_out = CONV_3_2_CONF_OUT_CHANNEL_NUMBER;
	PE_number = CONV_3_2_CONF_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv3_2_mbox_conf_input.txt";
	fileName2 = "H:\\data\\20180424\\conv3_2_mbox_conf_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv3_2_mbox_conf_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv3_2_mbox_conf_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //输入图像  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	
	merge(fmap_mat, padding_fmap);

	
	merge(result_out, result_out_temp);
																		   //为FPGA提供相应数据
	writeWeightToFile(weight, "H:\\data\\result\\conv3_2_mbox_conf_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv3_2_mbox_conf_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv3_2_mbox_conf_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv3_2_mbox_conf_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv3_2_mbox_conf_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv3_2_mbox_conf_fmap_out_to_uram_2x2_2.dat", false);

	
	cout << "conv_3_2_conf" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();



	////////////////////////////////conv_4_2_conf//////////////////////////
	/****************************
	********conv_4_2_conf*********
	*****************************/
	height = CONV_4_2_CONF_HEIGHT;
	width = CONV_4_2_CONF_WIDTH;
	channel_in = CONV_4_2_CONF_CHANNEL_NUMBER;
	channel_out = CONV_4_2_CONF_OUT_CHANNEL_NUMBER;
	PE_number = CONV_4_2_CONF_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv4_2_mbox_conf_input.txt";
	fileName2 = "H:\\data\\20180424\\conv4_2_mbox_conf_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv4_2_mbox_conf_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv4_2_mbox_conf_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_in);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //输入图像  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);

	merge(result_out, result_out_temp);
	//为FPGA提供相应数据
	writeWeightToFile(weight, "H:\\data\\result\\conv4_2_mbox_conf_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv4_2_mbox_conf_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv4_2_mbox_conf_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv4_2_mbox_conf_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv4_2_mbox_conf_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv4_2_mbox_conf_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_4_2_conf" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();

	////////////////////////////////conv_5_2_conf//////////////////////////
	/****************************
	********conv_5_2_conf*********
	*****************************/
	height = CONV_5_2_CONF_HEIGHT;
	width = CONV_5_2_CONF_WIDTH;
	channel_in = CONV_5_2_CONF_CHANNEL_NUMBER;
	channel_out = CONV_5_2_CONF_OUT_CHANNEL_NUMBER;
	PE_number = CONV_5_2_CONF_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv5_2_mbox_conf_input.txt";
	fileName2 = "H:\\data\\20180424\\conv5_2_mbox_conf_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv5_2_mbox_conf_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv5_2_mbox_conf_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //输入图像  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);


	Mat input_fmap_extend_padding;
	copyMakeBorder(padding_fmap, input_fmap_extend_padding, 1, 1, 1, 1, BORDER_CONSTANT, 0);  //zero, padding = 1 

	cout << input_fmap_extend_padding.size() << endl;


	split2x2_32(input_fmap_extend_padding, "H:\\data\\mbox\\conv5_2_mbox_conf_in_padding_1.dat", "H:\\data\\mbox\\conv5_2_mbox_conf_in_padding_2.dat",1);  //将zero padding后的图写入文件








	//////结果的数据
	merge(result_out, result_out_temp);
	//为FPGA提供相应数据
	writeWeightToFile(weight, "H:\\data\\result\\conv5_2_mbox_conf_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv5_2_mbox_conf_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv5_2_mbox_conf_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv5_2_mbox_conf_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv5_2_mbox_conf_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv5_2_mbox_conf_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_5_2_conf" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();


	////////////////////////////////conv_6_conf//////////////////////////
	/****************************
	********conv_6_conf*********
	*****************************/
	height = CONV_6_CONF_HEIGHT;
	width = CONV_6_CONF_WIDTH;
	channel_in = CONV_6_CONF_CHANNEL_NUMBER;
	channel_out = CONV_6_CONF_OUT_CHANNEL_NUMBER;
	PE_number = CONV_6_CONF_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv6_mbox_conf_input.txt";
	fileName2 = "H:\\data\\20180424\\conv6_mbox_conf_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv6_mbox_conf_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv6_mbox_conf_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //从文件读特征图  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);
	//将2 3 256 的数据变为 2 4 256 的数据
	//为FPGA提供相应数据
	merge(result_out, result_out_temp);



	writeWeightToFile(weight, "H:\\data\\result\\conv6_mbox_conf_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv6_mbox_conf_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv6_mbox_conf_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv6_mbox_conf_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv6_mbox_conf_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv6_mbox_conf_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_6_conf" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();


	////////////////////////////////conv_7_conf//////////////////////////
	/****************************
	********conv_7_conf*********
	*****************************/
	height = CONV_7_CONF_HEIGHT;
	width = CONV_7_CONF_WIDTH;
	channel_in = CONV_7_CONF_CHANNEL_NUMBER;
	channel_out = CONV_7_CONF_OUT_CHANNEL_NUMBER;
	PE_number = CONV_7_CONF_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv7_mbox_conf_input.txt";
	fileName2 = "H:\\data\\20180424\\conv7_mbox_conf_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv7_mbox_conf_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv7_mbox_conf_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //从文件读特征图  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);
	//将2 3 256 的数据变为 2 4 256 的数据
	//为FPGA提供相应数据
	merge(result_out, result_out_temp);



	writeWeightToFile(weight, "H:\\data\\result\\conv7_mbox_conf_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv7_mbox_conf_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv7_mbox_conf_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv7_mbox_conf_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv7_mbox_conf_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv7_mbox_conf_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_7_conf" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();

	////////////////////////////////conv_8_conf//////////////////////////
	/****************************
	********conv_8_conf*********
	*****************************/
	height = CONV_8_CONF_HEIGHT;
	width = CONV_8_CONF_WIDTH;
	channel_in = CONV_8_CONF_CHANNEL_NUMBER;
	channel_out = CONV_8_CONF_OUT_CHANNEL_NUMBER;
	PE_number = CONV_8_CONF_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv8_mbox_conf_input.txt";
	fileName2 = "H:\\data\\20180424\\conv8_mbox_conf_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv8_mbox_conf_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv8_mbox_conf_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file_8(fileName1, fmap_mat, height, width, channel_in);  //从文件读特征图  读的时候进行relu的操作
	read_fmap_from_file_8_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作

	merge(fmap_mat, padding_fmap);
	//将2 3 256 的数据变为 2 4 256 的数据
	//为FPGA提供相应数据

	Mat input_fmap_extend_padding;
	copyMakeBorder(padding_fmap, input_fmap_extend_padding, 1, 1, 1, 1, BORDER_CONSTANT, 0);  //zero, padding = 1 

	cout << input_fmap_extend_padding.size() << endl;


	split2x2_conv8_result_32(input_fmap_extend_padding, "H:\\data\\mbox\\conv8_mbox_in_padding_1.dat",1);  //将zero padding后的图写入文件






	merge(result_out, result_out_temp);



	writeWeightToFile(weight, "H:\\data\\result\\conv8_mbox_conf_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv8_mbox_conf_bias.dat");
	//writeFmapToFile(padding_fmap, "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_conf_fmap_in_to_uram_2x2_1.dat", "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_conf_fmap_in_to_uram_2x2_2.dat", false);
	//writeFmapToFile(result_out_temp, "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_conf_fmap_out_to_uram_2x2_1.dat", "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_conf_fmap_out_to_uram_2x2_2.dat", false);
	split2x2_conv8_result(padding_fmap, "H:\\data\\result\\conv8_mbox_conf_fmap_in_to_uram_2x2_1.dat",1);
	split2x2_conv8_result(result_out_temp, "H:\\data\\result\\conv8_mbox_conf_fmap_out_to_uram_2x2_1.dat",1);

	cout << "conv_8_conf" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();

	///////////////////////////////////////////loc/////////////////////////////////////////////////
	////////////////////////////////conv_3_2_loc//////////////////////////
	/****************************
	********conv_3_2_loc*********
	*****************************/
	height = CONV_3_2_LOC_HEIGHT;
	width = CONV_3_2_LOC_WIDTH;
	channel_in = CONV_3_2_LOC_CHANNEL_NUMBER;
	channel_out = CONV_3_2_LOC_OUT_CHANNEL_NUMBER;
	PE_number = CONV_3_2_LOC_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv3_2_mbox_loc_input.txt";
	fileName2 = "H:\\data\\20180424\\conv3_2_mbox_loc_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv3_2_mbox_loc_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv3_2_mbox_loc_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //输入图像  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	//Mat padding_fmap;
	merge(fmap_mat, padding_fmap);

	//Mat result_out_temp;
	merge(result_out, result_out_temp);
	//为FPGA提供相应数据
	writeWeightToFile(weight, "H:\\data\\result\\conv3_2_mbox_loc_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv3_2_mbox_loc_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv3_2_mbox_loc_fmap_in_to_uram_2x2_1.dat", "H:\\\data\\result\\conv3_2_mbox_loc_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv3_2_mbox_loc_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv3_2_mbox_loc_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_3_2_loc" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();



	////////////////////////////////conv_4_2_loc//////////////////////////
	/****************************
	********conv_4_2_loc*********
	*****************************/
	height = CONV_4_2_LOC_HEIGHT;
	width = CONV_4_2_LOC_WIDTH;
	channel_in = CONV_4_2_LOC_CHANNEL_NUMBER;
	channel_out = CONV_4_2_LOC_OUT_CHANNEL_NUMBER;
	PE_number = CONV_4_2_LOC_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv4_2_mbox_loc_input.txt";
	fileName2 = "H:\\data\\20180424\\conv4_2_mbox_loc_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv4_2_mbox_loc_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv4_2_mbox_loc_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //输入图像  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);

	merge(result_out, result_out_temp);
	//为FPGA提供相应数据
	writeWeightToFile(weight, "H:\\data\\result\\conv4_2_mbox_loc_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv4_2_mbox_loc_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv4_2_mbox_loc_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv4_2_mbox_loc_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv4_2_mbox_loc_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv4_2_mbox_loc_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_4_2_loc" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();

	////////////////////////////////conv_5_2_loc//////////////////////////
	/****************************
	********conv_5_2_loc*********
	*****************************/
	height = CONV_5_2_LOC_HEIGHT;
	width = CONV_5_2_LOC_WIDTH;
	channel_in = CONV_5_2_LOC_CHANNEL_NUMBER;
	channel_out = CONV_5_2_LOC_OUT_CHANNEL_NUMBER;
	PE_number = CONV_5_2_LOC_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv5_2_mbox_loc_input.txt";
	fileName2 = "H:\\data\\20180424\\conv5_2_mbox_loc_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv5_2_mbox_loc_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv5_2_mbox_loc_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //输入图像  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);

	merge(result_out, result_out_temp);
	//为FPGA提供相应数据
	writeWeightToFile(weight, "H:\\data\\result\\conv5_2_mbox_loc_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv5_2_mbox_loc_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv5_2_mbox_loc_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv5_2_mbox_loc_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv5_2_mbox_loc_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv5_2_mbox_loc_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_5_2_loc" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();


	////////////////////////////////conv_6_loc//////////////////////////
	/****************************
	********conv_6_loc*********
	*****************************/
	height = CONV_6_LOC_HEIGHT;
	width = CONV_6_LOC_WIDTH;
	channel_in = CONV_6_LOC_CHANNEL_NUMBER;
	channel_out = CONV_6_LOC_OUT_CHANNEL_NUMBER;
	PE_number = CONV_6_LOC_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv6_mbox_loc_input.txt";
	fileName2 = "H:\\data\\20180424\\conv6_mbox_loc_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv6_mbox_loc_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv6_mbox_loc_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //从文件读特征图  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);
	//将2 3 256 的数据变为 2 4 256 的数据
	//为FPGA提供相应数据
	merge(result_out, result_out_temp);



	writeWeightToFile(weight, "H:\\data\\result\\conv6_mbox_loc_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv6_mbox_loc_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv6_mbox_loc_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv6_mbox_loc_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv6_mbox_loc_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv6_mbox_loc_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_6_loc" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();


	////////////////////////////////conv_7_loc//////////////////////////
	/****************************
	********conv_7_loc*********
	*****************************/
	height = CONV_7_LOC_HEIGHT;
	width = CONV_7_LOC_WIDTH;
	channel_in = CONV_7_LOC_CHANNEL_NUMBER;
	channel_out = CONV_7_LOC_OUT_CHANNEL_NUMBER;
	PE_number = CONV_7_LOC_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv7_mbox_loc_input.txt";
	fileName2 = "H:\\data\\20180424\\conv7_mbox_loc_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv7_mbox_loc_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv7_mbox_loc_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_in);  //从文件读特征图  读的时候进行relu的操作
	read_fmap_from_file_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);
	//将2 3 256 的数据变为 2 4 256 的数据
	//为FPGA提供相应数据
	merge(result_out, result_out_temp);



	writeWeightToFile(weight, "H:\\data\\result\\conv7_mbox_loc_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv7_mbox_loc_bias.dat");
	writeFmapToFile(padding_fmap, "H:\\data\\result\\conv7_mbox_loc_fmap_in_to_uram_2x2_1.dat", "H:\\data\\result\\conv7_mbox_loc_fmap_in_to_uram_2x2_2.dat", false);
	writeFmapToFile(result_out_temp, "H:\\data\\result\\conv7_mbox_loc_fmap_out_to_uram_2x2_1.dat", "H:\\data\\result\\conv7_mbox_loc_fmap_out_to_uram_2x2_2.dat", false);


	cout << "conv_7_loc" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();

	////////////////////////////////conv_8_loc//////////////////////////
	/****************************
	********conv_8_loc*********
	*****************************/
	height = CONV_8_LOC_HEIGHT;
	width = CONV_8_LOC_WIDTH;
	channel_in = CONV_8_LOC_CHANNEL_NUMBER;
	channel_out = CONV_8_LOC_OUT_CHANNEL_NUMBER;
	PE_number = CONV_8_LOC_PE_NUMBER;

	fileName1 = "H:\\data\\20180424\\conv8_mbox_loc_input.txt";
	fileName2 = "H:\\data\\20180424\\conv8_mbox_loc_bias.txt";
	fileName3 = "H:\\data\\20180424\\conv8_mbox_loc_weights.txt";
	fileName4 = "H:\\data\\20180424\\conv8_mbox_loc_output.txt";

	read_bias_from_file(fileName2, bias_vector, channel_out); //从文件读bias
	read_weight_from_file(fileName3, weight, channel_in, channel_out);//从文件读weights
	read_fmap_from_file_8(fileName1, fmap_mat, height, width, channel_in);  //从文件读特征图  读的时候进行relu的操作
	read_fmap_from_file_8_norelu(fileName4, result_out, height, width, channel_out);  //输出图像  读的时候进行relu的操作


	merge(fmap_mat, padding_fmap);
	//将2 3 256 的数据变为 2 4 256 的数据
	//为FPGA提供相应数据
	merge(result_out, result_out_temp);



	writeWeightToFile(weight, "H:\\data\\result\\conv8_mbox_loc_weight.dat", channel_in, channel_out, PE_number);
	writeBiasToFile(bias_vector, "H:\\data\\result\\conv8_mbox_loc_bias.dat");
	//writeFmapToFile(padding_fmap, "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_loc_fmap_in_to_uram_2x2_1.dat", "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_loc_fmap_in_to_uram_2x2_2.dat", false);
	//writeFmapToFile(result_out_temp, "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_loc_fmap_out_to_uram_2x2_1.dat", "D:\\code\\verilog\\C++_verification\\data\\result\\conv8_mbox_loc_fmap_out_to_uram_2x2_2.dat", false);
	split2x2_conv8_result(padding_fmap, "H:\\data\\result\\conv8_mbox_loc_fmap_in_to_uram_2x2_1.dat", 1);
	split2x2_conv8_result(result_out_temp, "H:\\data\\result\\conv8_mbox_loc_fmap_out_to_uram_2x2_1.dat", 1);

	cout << "conv_8_loc" << endl;
	//清空存储的数据
	fmap_mat.clear();
	result_out.clear();
	bias_vector.clear();
	weight.clear();
	padding_fmap.release();
	result_out_temp.release();


	system("pause");
}

