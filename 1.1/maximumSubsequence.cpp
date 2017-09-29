#include <stdio.h>

int MSS(int[], int);

int main() {
	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int seq[10000];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);	
	}
	MSS(seq, n); 
	return 0;
}

int MSS(int seq[], int n) {
	int thisSum=0, maxSum=-1, thisStart=0, start=0, stop=n-1;
	for (int i = 0; i < n; i++) {
		thisSum += seq[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
			start = thisStart;
			stop = i;
		} else if (thisSum < 0) {
			thisSum = 0;
			thisStart = i+1;
		}
	}
	if (maxSum < 0) {
		maxSum = 0;
	}
	printf("%d ", maxSum);
	printf("%d ", seq[start]);
	printf("%d", seq[stop]);
	return maxSum;
}
