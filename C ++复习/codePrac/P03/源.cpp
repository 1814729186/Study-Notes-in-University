#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXH 5005
//����
#define JD 0.0001L
/*
��ɽ������1 cm����x cm������׶

����L cm^3��ˮ��ˮλ�߶�
������̨�� V = h*(R1*R1 + R2*R2 + R1*R2) / 3;

�������Lcm^3��ˮ��ˮ��߶�Ϊ H,����ÿһ����׶�߶�Ϊhi 
���У�m*n*H = L + V1 + V2
V1��ʾ�߶Ȳ���H������׶������� V1 = segma ( hi / 3 )
V2��ʾ�߶ȳ���H������׶������� V2 = segma (H*(1 + (1-H/h)*(1-H/h) + (1-H/h)) / 3.0)
V1��V2�е�Ԫ�ر���ͺ�H�йأ������Ҫ�������裬��ʹ�ú��鷽ʽ���в���
 �����η��̣�
����˼·�����߶Ƚ������򣬶������߶ȵ�ÿһ������ִ������������Ȼ�����H���۲��Ƿ��������ڣ�����ǣ�����ã�������ǣ�������
���η��̱�����û�����˼·
	�������ƶ��ֵ�˼�룬������H����ߺ�������䣬�ö��ֲ��ҵķ�ʽ���θı�H��ֵ��ֱ�����ȷ�������

*/
double getH(vector<double> &heights,double L) {
	//����ʹ�������heights
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
			if (curL > L) {//curL̫�󣬱�ʾ�����H̫��
				high = H;
			}
			else {
				low = H;
			}
		}
	} 
}

//ʹ��ʢ��ʽ������η���
double getH_S(vector<double>& heights, double L) {
	// aH^3 + bH^2 + cH + d = 0;
	double a=0, b=0, c=0, d=0;
	double low = 0, high = 0;
	double deltaA, deltaB, deltaC; //�ظ��б�ʽ
	double delta; //�б�ʽ
	int index;
	double H1, H2, H3;
	for (int i = 0; i <= heights.size(); i++) {
		low = high; high =i<heights.size()? heights[i]:MAXH; //ȷ����Χ
		index = 0;
		a = 0; b = 0; d = L; c = -(int)heights.size(); //��ʼ��
		while (index < i) {
			d += heights[index ++] / 3.0;
		} //d�������
		while (index < heights.size()) {
			c += 1.0;
			b -= 1.0 / heights[index];
			a += 1.0 / (heights[index] * heights[index] * 3.0);
			index++;
		}
		//ʹ��ʢ��ʽ������η���
		deltaA = b * b - 3.0 * a * c;
		deltaB = b * c - 9.0 * a * d;
		deltaC = c * c - 3.0 * b * d;
		delta = deltaB * deltaB - 4.0 * deltaA * deltaC;
		if (deltaA == deltaB && deltaA == 0) {
			H1 = (-c) / b;
			if (H1 <= high && H1 >= low) return H1;
		}
		else if (delta > 0) {
			//������η���
			double Y1 = deltaA * b + 3.0 / 2.0 * a * (-deltaB + sqrt(deltaB * deltaB - 4.0 * deltaA * deltaC));
			double Y2 = deltaA * b + 3.0 / 2.0 * a * (-deltaB + sqrt(deltaB * deltaB + 4.0 * deltaA * deltaC));
			H1 = (-b - exp(log(Y1) / 3.0) - exp(log(Y2) / 3.0)) / (3.0 * a);//���������������������
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
			double �� = acos( (2.0*deltaA*b - 3.0*a*deltaB) / (2.0* sqrt(deltaA*deltaA*deltaA)) );
			H1 = (-b - 2.0 * sqrt(deltaA) * cos(�� / 3.0)) / (3.0 * a);
			if (H1 <= high && H1 >= low) return H1;
			H2 = (-b + sqrt(deltaA) * (cos(�� / 3.0) + sqrt(3.0) * sin(�� / 3.0))) / (3.0 * a);
			if (H2 <= high && H2 >= low) return H2;
			H3 = (-b + sqrt(deltaA) * (cos(�� / 3.0) - sqrt(3.0) * sin(�� / 3.0))) / (3.0 * a);
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