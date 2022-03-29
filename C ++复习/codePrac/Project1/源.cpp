#include <stdio.h>
#include <iostream>
using namespace std;


double V() {
	double h = 937;
	double H = 472;
	double L=198;
	return L + H * (1 + (H / h) * (H / h) + (H / h)) / 3.0;
}

int main() {
	cout <<V();
}