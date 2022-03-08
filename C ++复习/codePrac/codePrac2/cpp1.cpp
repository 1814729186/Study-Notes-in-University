#include "codePrac2.h"

const int va1=0;
int sleep(int times,const char* no) {
	printf("wait--%s\n",no);
	Sleep(times);
	return 0;
}
static time_t mt1 = time(NULL);
static unsigned int r1 = sleep(1000,"cpp1");
static time_t mt2 = time(NULL);
static unsigned int r2 = sleep(1000,"cpp1");
static time_t mt3 = time(NULL);
int main()
{
	printf("main begin\n");
	cout << mt1 << endl;
	cout << mt2 << endl;
	cout << mt3 << endl;
	return 0;
}
