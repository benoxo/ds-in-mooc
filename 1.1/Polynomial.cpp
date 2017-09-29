#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXK 1e7

clock_t start, stop;
double duration;

double f(int n, double a[], double x);
double f2(int n, double a[], double x);
void time_cal(clock_t);

int main() {
	double a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	
	start = clock();
	for (int i = 0; i < MAXK; i++) {
		f(4, a, 1.0);
	}
	time_cal(start);
	
	start = clock();
	for (int i = 0; i < MAXK; i++) {
		f2(4, a, 1.0);
	}
	time_cal(start);
	return 0;
}

void time_cal(clock_t start) {
	stop = clock();
	duration = (double)(stop-start)/CLK_TCK/MAXK;
	printf("tick2=%d\n", stop-start);
	printf("duration2=%6.2e\n", duration);
}

double f(int n, double a[], double x) {
	int i = 1;
	double sum = a[0];
	for (; i <=n; i++) {
		sum += a[i] * pow(x, i);
	}
	return sum;
}

double f2(int n, double a[], double x) {
	int i = n;
	double sum = a[n];
	for (; i > 0; i--) {
		sum = a[i-1] + x * sum;
	}
	return sum;
}
