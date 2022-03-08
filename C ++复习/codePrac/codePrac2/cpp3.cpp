#include <iostream>
#include<windows.h>
#include <time.h>
extern int sleep(int times, const char* no);
static time_t mt11 = time(NULL);
static unsigned int r11 = sleep(1000, "cpp3");
static time_t mt21 = time(NULL);
static unsigned int r12 = sleep(1000, "cpp3");
static time_t mt31 = time(NULL);