// filter2D_Demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
	Mat src, dst;
	Mat kernel;
	Point anchor;
	double delta;
	int ddepth;
	int kernel_size;
	const char* window_name = "filter2D Demo";

	int c;
	src = imread("H:\\opencv\\sources\\samples\\data\\chicky_512.png");
	if (!src.data)
	{
		return -1;
	}
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	anchor = Point(-1, -1);
	delta = 0;
	ddepth = -1;

	int ind = 0;
	while (1)
	{
		c = waitKey(500);
		if ((char)c == 27)
		{
			break;
		}
		kernel_size = 3 + 2 * (ind % 8);
		kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
		filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
		imshow(window_name, dst);
		ind++;
	}
	return 0;
}
/*
filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
src: 源图像
dst: 目标图像
ddepth: dst 的深度。若为负值（如  ），则表示其深度与源图像相等。
kernel: 用来遍历图像的核
anchor: 核的锚点的相对位置，其中心点默认为 (-1, -1) 。
delta: 在卷积过程中，该值会加到每个像素上。默认情况下，这个值为  。
BORDER_DEFAULT: 这里我们保持其默认值，更多细节将在其他教程中详解
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
