#include <stdio.h>

void PrintN1(int n);
void PrintN2(int n);

int main() {
	PrintN2(10000);
	return 0;
}

void PrintN1(int n) {
	int i = 1;
	for (;i <= n; i++) {
		printf("%d\n", i);
	}
}

void PrintN2(int n) {
	if (n) {
		PrintN2(n-1);
		printf("%d\n", n);
	}
}
