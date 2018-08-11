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






// ��������ļ���mat�Ľṹ��
void read_fmap_from_file(string fileName, vector<Mat> &fmap_mat, int height, int width, int channel_in) {
	ifstream fmap_in(fileName);
	if (!fmap_in) {
		cout << "error " << endl;
		system("pause");
		return;
	}
	//��������fmap
	vector< vector<int> > fmap;
	for (int i = 0; i < channel_in/40; ++i) {  //����ͨ�� ����ά�Ŀռ���
		vector<int> one_fmap;
		for (int j = 0; j < height*width*40; ++j) { //�������ݵ�λ��
			int temp;
			fmap_in >> temp;
			if (temp < 0) {  //����relu�Ĳ���
				temp = 0;
			}
			one_fmap.push_back(temp);
		}
		fmap.push_back(one_fmap);
	}

	//������vector���͵�fmapת��ΪMat����
	for (vector< vector<int> >::iterator iter = fmap.begin(); iter != fmap.end(); ++iter) {
		vector<int> one_fmap;
		one_fmap = *iter;
		Mat a(one_fmap);
		Mat b = a.reshape(0, height); //��Ϊ�������ʮ�����ϵ�����
		fmap_mat.push_back(b.clone());
	}
}

/////conv8
void read_fmap_from_file_8(string fileName, vector<Mat> &fmap_mat, int height, int width, int channel_in) {
	ifstream fmap_in(fileName);
	if (!fmap_in) {
		cout << "error " << endl;
		system("pause");
		return;
	}
	//��������fmap
	vector< vector<int> > fmap;
	for (int i = 0; i < channel_in/40; ++i) {
		vector<int> one_fmap;
		for (int j = 0; j < height*(width + 1)*40; ++j) {
			int temp;
			if ((j>= width * 40)&&(j<(width + 1) * 40)) //��Ϊ���һ���� ���м�0�Ĳ���
			{
				//cout << j << endl;
				temp = 0;
			}
			if ((j >= ((height*width)+1) * 40) && (j<height*(width+1) * 40)) //��Ϊ���һ���� ���м�0�Ĳ���
			{
				//cout << j << endl;
				temp = 0;
			}
			else {  //������ȡ����
				fmap_in >> temp;
				if (temp < 0) {  //����relu�Ĳ���
					temp = 0;
				}
			}
			one_fmap.push_back(temp);
		}
		fmap.push_back(one_fmap);
	}

	//������vector���͵�fmapת��ΪMat����
	for (vector< vector<int> >::iterator iter = fmap.begin(); iter != fmap.end(); ++iter) {
		vector<int> one_fmap;
		one_fmap = *iter;
		Mat a(one_fmap);
		Mat b = a.reshape(0, height); //���������Զ�����
		fmap_mat.push_back(b.clone());
	}
}



void split2x2_256(Mat &image, string fileName1, string fileName2) { //���ݴ�2x2������ ��ȡ����1x4�����ݽ�
	ofstream fp1(fileName1);
	ofstream fp2(fileName2);
	int height = image.rows;
	int width = image.cols;
	//part1
	cout << height/4<<" "<<width/80 << endl;
	/////д�����ݵı�ͷ///////
	fp1 <<"memory_initialization_radix = 16;" << endl;
	fp1 <<"memory_initialization_vector =" << endl;

	int number_temp = 0;
	int sum_number = 0;
	int flag = 0;
	for (int i = 0; i < width/80 ; ++i) {
		for (int j = 0; j < height/4; ++j) {
			cout << " �� ��" << i * 80 << " " << j * 2 << endl;
			Mat fmap2x2 = image(Rect(i * 80, j*2 , 80, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
						for (int mm = 0; mm < 10; ++mm) {
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm +1);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm +2);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm +3);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm +40);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm +41);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm +42);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm +43);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm +1);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm +2);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm +3);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm +40);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm +41);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm +42);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm +43);

							number_temp = number_temp + 1;
							sum_number = sum_number + 1;
							if (number_temp == 2) {
								//cout << number_temp << endl;
								fp1 << ",";
								number_temp = 0;
							}
						}
					//fp1 << endl;
					
			}
		}
	}
	cout << "part1:number:"<<sum_number<< endl;
	//part2
	/////д�����ݵı�ͷ///////
	fp2 << "memory_initialization_radix = 16;" << endl;
	fp2 << "memory_initialization_vector =" << endl;
	number_temp = 0;
	sum_number = 0;
	for (int i = 0; i < width/80; ++i) {
		for (int j = 0; j < height / 4; ++j) {
			cout <<" �� ��"<<i*80<<" "<< j * 2 + height / 2 << endl;
			Mat fmap2x2 = image(Rect(i * 80, j*2 + height / 2, 80, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
						for (int mm = 0; mm < 10; ++mm) {
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 1);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 2);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 3);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 40);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 41);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 42);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 43);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 1);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 2);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 3);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 40);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 41);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 42);
							fp2 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 43);
							number_temp = number_temp + 1;
							sum_number = sum_number + 1;
							if (number_temp == 2) {
								//cout << number_temp << endl;
								fp2 << ",";
								number_temp = 0;
							}
						}
					//fp1 << endl;			
			}
		}
	}
	cout << "part2:number:" << sum_number << endl;
	fp2.close();
}

//void split2x2_256_conv_8(Mat &image, string fileName1) {
//	ofstream fp1(fileName1);
//	int height = image.rows;
//	int width = image.cols;
//	//part1
//	cout << height << " " << width << endl;
//	/////д�����ݵı�ͷ///////
//	fp1 << "memory_initialization_radix = 16;" << endl;
//	fp1 << "memory_initialization_vector =" << endl;
//	int number_temp = 0;
//	for (int i = 0; i < width ; ++i) {
//		for (int j = 0; j < height / 2 ; ++j) {
//			Mat fmap2x2 = image(Rect(i * 2, j * 2, 2, 2));
//			vector<Mat> fmap2x2_vector;
//			split(fmap2x2, fmap2x2_vector);
//			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {        //�����Ƶ�����
//					for (int kk = 0; kk < 2; ++kk) {
//						for (int mm = 0; mm < 2; ++mm) {
//							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(kk, mm);
//						}
//					}
//					//fp1 << endl;
//					number_temp = number_temp + 1;
//					if (number_temp == 8) {
//						//cout << number_temp << endl;
//						fp1 << ",";
//						number_temp = 0;
//					}
//				}
//			}
//		}
//	fp1 << ";";
//}

//�ڰ˲�����ݵ����
void split2x2_conv8_result(Mat &image, string fileName1, int select = 0) {
	ofstream fp1(fileName1);
	int height = image.rows;
	int width = image.cols;
	//cout << height << ' ' << width << endl;
	//part1
	cout << height << " " << width << endl;
	/////д�����ݵı�ͷ///////
	fp1 << "memory_initialization_radix = 16;" << endl;
	fp1 << "memory_initialization_vector =" << endl;
	int number_temp = 0;
	int sum_number = 0;
	for (int i = 0; i < width/80; ++i) {
		for (int j = 0; j < height/2; ++j) {
			Mat fmap2x2 = image(Rect(i * 80, j*2, 80, 2));
			vector<Mat> fmap2x2_vector;
			split(fmap2x2, fmap2x2_vector);
			for (size_t k = 0; k < fmap2x2_vector.size(); ++k) {
				if (select == 1) {
						for (int mm = 0; mm < 10; ++mm) {
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 1);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 2);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 3);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 40);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 41);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 42);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(0, 4 * mm + 43);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 1);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 2);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 3);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 40);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 41);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 42);
							fp1 << setfill('0') << setw(3) << hex << fmap2x2_vector[k].at<int>(1, 4 * mm + 43);
							number_temp = number_temp + 1;
							sum_number = sum_number + 1;
							//cout << number_temp << endl;
							if (number_temp == 2) {
								//cout << number_temp << endl;
								fp1 << ",";
								number_temp = 0;
							}
					}
					//fp1 << endl;
					
					
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
	cout << "8 number:" << sum_number << endl;
	fp1.close();
}

int main()
{
	int height, width, channel_number;
	string fileName1;


	vector<Mat> fmap_mat; 
	Mat padding_fmap;
	//////////////////////////////////////
	///////////////conv_3_2///////////////
	height = CONV_3_2_CONF_HEIGHT;
	width = CONV_3_2_CONF_WIDTH;
	channel_number = CONV_3_2_LOC_OUT_CHANNEL_NUMBER;

	fileName1 = "H:\\data\\20180521\\conv3_2_mbox_priorbox_output.txt";

	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_number);  //����ͼ��Ķ�ȡ

	merge(fmap_mat, padding_fmap);
	//for (int i = 0;i < 16;i++)
	//{
	//	cout << fmap_mat[i] << endl;
	//}


	split2x2_256(padding_fmap, "H:\\data\\prior_box\\conv3_2_mbox_priorbox_output_1.coe", "H:\\data\\prior_box\\conv3_2_mbox_priorbox_output_2.coe");

	fmap_mat.clear();
	padding_fmap.release();

	//////////////////////////////////////
	///////////////conv_4_2///////////////
	height = CONV_4_2_CONF_HEIGHT;
	width = CONV_4_2_CONF_WIDTH;
	channel_number = CONV_4_2_LOC_OUT_CHANNEL_NUMBER;

	fileName1 = "H:\\data\\20180521\\conv4_2_mbox_priorbox_output.txt";

	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_number);  //����ͼ��Ķ�ȡ

	merge(fmap_mat, padding_fmap);


	split2x2_256(padding_fmap, "H:\\data\\prior_box\\conv4_2_mbox_priorbox_output_1.coe", "H:\\data\\prior_box\\conv4_2_mbox_priorbox_output_2.coe");

	fmap_mat.clear();
	padding_fmap.release();

	//////////////////////////////////////
	///////////////conv_5_2///////////////
	height = CONV_5_2_CONF_HEIGHT;
	width = CONV_5_2_CONF_WIDTH;
	channel_number = CONV_5_2_LOC_OUT_CHANNEL_NUMBER;

	fileName1 = "H:\\data\\20180521\\conv5_2_mbox_priorbox_output.txt";

	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_number);  //����ͼ��Ķ�ȡ

	merge(fmap_mat, padding_fmap);


	split2x2_256(padding_fmap, "H:\\data\\prior_box\\conv5_2_mbox_priorbox_output_1.coe", "H:\\data\\prior_box\\conv5_2_mbox_priorbox_output_2.coe");

	fmap_mat.clear();
	padding_fmap.release();


	//////////////////////////////////////
	///////////////conv_6///////////////
	height = CONV_6_CONF_HEIGHT;
	width = CONV_6_CONF_WIDTH;
	channel_number = CONV_6_LOC_OUT_CHANNEL_NUMBER;

	fileName1 = "H:\\data\\20180521\\conv6_mbox_priorbox_output.txt";

	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_number);  //����ͼ��Ķ�ȡ

	merge(fmap_mat, padding_fmap);


	split2x2_256(padding_fmap, "H:\\data\\prior_box\\conv6_mbox_priorbox_output_1.coe", "H:\\data\\prior_box\\conv6_mbox_priorbox_output_2.coe");

	fmap_mat.clear();
	padding_fmap.release();


	//////////////////////////////////////
	///////////////conv_7///////////////
	height = CONV_7_CONF_HEIGHT;
	width = CONV_7_CONF_WIDTH;
	channel_number = CONV_7_LOC_OUT_CHANNEL_NUMBER;

	fileName1 = "H:\\data\\20180521\\conv7_mbox_priorbox_output.txt";

	read_fmap_from_file(fileName1, fmap_mat, height, width, channel_number);  //����ͼ��Ķ�ȡ

	merge(fmap_mat, padding_fmap);


	split2x2_256(padding_fmap, "H:\\data\\prior_box\\conv7_mbox_priorbox_output_1.coe", "H:\\data\\prior_box\\conv7_mbox_priorbox_output_2.coe");

	fmap_mat.clear();
	padding_fmap.release();


	//////////////////////////////////////
	///////////////conv_8///////////////
	height = CONV_8_CONF_HEIGHT;
	width = CONV_8_CONF_WIDTH;
	channel_number = CONV_8_LOC_OUT_CHANNEL_NUMBER;

	fileName1 = "H:\\data\\20180521\\conv8_mbox_priorbox_output.txt";

	read_fmap_from_file_8(fileName1, fmap_mat, height, width, channel_number);  //����ͼ��Ķ�ȡ

	merge(fmap_mat, padding_fmap);


	split2x2_conv8_result(padding_fmap, "H:\\data\\prior_box\\conv8_mbox_priorbox_output.coe",1);

	fmap_mat.clear();
	padding_fmap.release();

	system("pause");
};