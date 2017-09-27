#include <stdio.h>
#include <string.h>

#define MAXSIZE 31
int preorder[MAXSIZE];
int inorder[MAXSIZE];
int N;

void ReadIn() {
	int stack[N];
	int top = 0;
	char op[10];
	int val;
	int rear1 = 0;	// ǰ������������һ��λ��
	int rear2 = 0;	// ��������������һ��λ�� 
	for (int i = 0; i < 2*N; i++) {
		scanf("%5s %d", op, &val);
		if (!strcmp(op, "Push")) {
			stack[top++] = val;
			preorder[rear1++] = val;
		} else {
			inorder[rear2++] = stack[--top];
		}
	}
}

int IndexInArr(int a, int arr[], int start, int end) {
	int i;
	for (i = start; i <= end; i++) {
		if (arr[i] == a) {
			return i;
		}
	}
	return -1;
}

void PrintPost(int &head, int in_l, int in_r) {
	if (head > N) { return; }
	if (in_l > in_r) { head--; return; }
	int curroot = preorder[head]; 
	if (in_l < in_r) {
		int in_mid = IndexInArr(preorder[head], inorder, in_l, in_r);
		PrintPost(++head, in_l, in_mid-1);
		PrintPost(++head, in_mid+1, in_r);
	}
	if (curroot == preorder[0]) {
		printf("%d", curroot);
	} else {
		printf("%d ", curroot);
	}
}


int main() {
	freopen("ttainput.txt", "r", stdin);
	scanf("%d", &N);
	ReadIn();
	int head = 0;	// ��ǰ������ĵ�һ�����ݿ�ʼ 
	PrintPost(head, 0, N-1);
}
