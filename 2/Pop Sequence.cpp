#include <stdio.h>
#include <stdlib.h>

int stack[1001];
int top = 0;
int capacity;
int queue[1001];
int head = 0, rear;

void Read(int len) {
	int i = 0;
	for (; i < len; i++) {
		scanf("%d", queue+i);
	}
	rear = len;
}

void PushElems(int &maxInStack, int maxElem) {
	int i = maxInStack+1;
	for (; i <= maxElem; i++) {
		if (top >= capacity) {
			return;
		}
		stack[top++] = i;
	}
	if (maxElem > maxInStack) {
		maxInStack = maxElem; 
	}
}

bool Verify() {
	int elem, maxInStack = 0;
	while (head < rear) {
		elem = queue[head];
		PushElems(maxInStack, elem);
		if (stack[top-1] != elem) {
			return false;
		} else {
			top--;
			head++;
		}
	}
	return true;
}

void Init(int N) {
	top = 0;
	head = 0;
}

int main() {
	freopen("psinput.txt", "r", stdin);
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	capacity = M;
	while (K--) {
		Init(N);
		Read(N);
		if (Verify()) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
