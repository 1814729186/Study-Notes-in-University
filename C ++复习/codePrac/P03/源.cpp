#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXH 5005
//精度
#define JD 0.0001L
/*
假山：长宽1 cm，高x cm正四棱锥

放入L cm^3的水，水位高度
正四棱台： V = h*(R1*R1 + R2*R2 + R1*R2) / 3;

假设加上Lcm^3的水后，水面高度为 H,对于每一个棱锥高度为hi 
则有：m*n*H = L + V1 + V2
V1表示高度不及H的四棱锥的体积和 V1 = segma ( hi / 3 )
V2表示高度超过H的四棱锥的体积和 V2 = segma (H*(1 + (1-H/h)*(1-H/h) + (1-H/h)) / 3.0)
V1和V2中的元素本身就和H有关，因此需要做出假设，并使用后验方式进行测试
 解三次方程？
后验思路：将高度进行排序，对两个高度的每一个区间执行上述操作，然后求出H，观察是否在区间内，如果是，则采用，如果不是，则弃用
三次方程本人尚没有求解思路
	采用类似二分的思想，先设置H的最高和最低区间，用二分查找的方式依次改变H的值，直到精度符合需求

*/
double getH(vector<double> &heights,double L) {
	//这里使用有序的heights
	double low = 0, high = MAXH;
	double H, curL;
	int size = heights.size(); //m*n
	int index=0;
	while(1) {
		H = (low + high) / 2.0;
		//cout << low << " " << high << endl;
		index = 0;
		//L = m*n*H - V1 - V2
		curL = size * H;
		while (index <size &&heights[index] <= H) {
			curL -= (heights[index++] / 3.0);
		}
		while (index < size) {
			curL -= (H*( 1 + (1 - H/heights[index]) * (1 - H / heights[index]) + 1 - H / heights[index]) / 3.0);
			index++;
		}
		if (abs(curL - L) <= JD) return H;
		else {
			if (curL > L) {//curL太大，表示假设的H太大
				high = H;
			}
			else {
				low = H;
			}
		}
	} 
}

//使用盛金公式求解三次方程
double getH_S(vector<double>& heights, double L) {
	// aH^3 + bH^2 + cH + d = 0;
	double a=0, b=0, c=0, d=0;
	double low = 0, high = 0;
	double deltaA, deltaB, deltaC; //重根判别式
	double delta; //判别式
	int index;
	double H1, H2, H3;
	for (int i = 0; i <= heights.size(); i++) {
		low = high; high =i<heights.size()? heights[i]:MAXH; //确定范围
		index = 0;
		a = 0; b = 0; d = L; c = -(int)heights.size(); //初始化
		while (index < i) {
			d += heights[index ++] / 3.0;
		} //d计算完毕
		while (index < heights.size()) {
			c += 1.0;
			b -= 1.0 / heights[index];
			a += 1.0 / (heights[index] * heights[index] * 3.0);
			index++;
		}
		//使用盛金公式求解三次方程
		deltaA = b * b - 3.0 * a * c;
		deltaB = b * c - 9.0 * a * d;
		deltaC = c * c - 3.0 * b * d;
		delta = deltaB * deltaB - 4.0 * deltaA * deltaC;
		if (deltaA == deltaB && deltaA == 0) {
			H1 = (-c) / b;
			if (H1 <= high && H1 >= low) return H1;
		}
		else if (delta > 0) {
			//求解三次方根
			double Y1 = deltaA * b + 3.0 / 2.0 * a * (-deltaB + sqrt(deltaB * deltaB - 4.0 * deltaA * deltaC));
			double Y2 = deltaA * b + 3.0 / 2.0 * a * (-deltaB + sqrt(deltaB * deltaB + 4.0 * deltaA * deltaC));
			H1 = (-b - exp(log(Y1) / 3.0) - exp(log(Y2) / 3.0)) / (3.0 * a);//后两个是虚根，不做考虑
			if (H1 <= high && H1 >= low) return H1;
		}
		else if (delta == 0.0) {
			double K = deltaB / deltaA;
			H1 = -b / a + K;
			H2 = -K / 2;
			if (H1 <= high && H1 >= low) return H1;
			if (H2 <= high && H2 >= low) return H2;
		}
		else {
			double θ = acos( (2.0*deltaA*b - 3.0*a*deltaB) / (2.0* sqrt(deltaA*deltaA*deltaA)) );
			H1 = (-b - 2.0 * sqrt(deltaA) * cos(θ / 3.0)) / (3.0 * a);
			if (H1 <= high && H1 >= low) return H1;
			H2 = (-b + sqrt(deltaA) * (cos(θ / 3.0) + sqrt(3.0) * sin(θ / 3.0))) / (3.0 * a);
			if (H2 <= high && H2 >= low) return H2;
			H3 = (-b + sqrt(deltaA) * (cos(θ / 3.0) - sqrt(3.0) * sin(θ / 3.0))) / (3.0 * a);
			if (H3 <= high && H3 >= low) return H3;
		}
	}
	return -1.0;
}


int main() {
	int m, n, q;
	double l;
	cin >> m>>n;
	double height;
	vector<double> heights;
	for (int i = 0; i < m * n; i++) {
		cin >> height;
		heights.push_back(height);
	}
	sort(heights.begin(), heights.end());
	vector<double> Ls;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l;
		Ls.push_back(l);
	}
	for (int i = 0; i < q; i++) {
		printf_s("%.4lf\t%.4lf\n", getH_S(heights, Ls[i]),getH(heights,Ls[i]));
	}
	return 0;
}
/*
1 1
937
6
198 77 206 74 304 54

2 2
476 671 305 926
9
272 2235 515 2542 713 62 100 1004 108
*/