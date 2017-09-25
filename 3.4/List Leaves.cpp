#include "stdio.h"

#define MAXSIZE 11
struct TreeNode {
	int left; 
	int right;
}Tree[MAXSIZE];

int Read() {
	int N;
	char l, r;
	int root = -1;
	int check[MAXSIZE] = {0}; 
	scanf("%d\n", &N);
	// ����ڵ����� 
	for (int i = 0; i < N; i++) {
		scanf("%c %c\n", &l, &r);
		if (l == '-') {
			Tree[i].left = -1;
		} else {
			Tree[i].left = l - '0';
			check[Tree[i].left] = 1;
		}
		if (r == '-') {
			Tree[i].right = -1;
		} else {
			Tree[i].right = r - '0';
			check[Tree[i].right] = 1;
		}
	}
	// �ҵ�ͷ���
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			root = i;break;
		}
	}
	return root;
}

void PrintLeaves(int root) {
	int queue[MAXSIZE];
	int head = 0, rear = 0;
	int cur;
	if (root > -1) {
		queue[rear++] = root;
		// ���в���������������Һ��ӽڵ㶼�ǿգ����ӡ�ýڵ� 
		while (head != rear) {
			cur = queue[head++];
			if (Tree[cur].left != -1) {
				queue[rear++] = Tree[cur].left;
			}
			if (Tree[cur].right != -1) {
				queue[rear++] = Tree[cur].right;
			}
			if (Tree[cur].left == -1 && Tree[cur].right == -1) {
				if (head == rear) {
					printf("%d", cur);
				} else {
					printf("%d ", cur);
				}
			}
		}
	}
}

int main() {
	freopen("llinput.txt", "r", stdin); 
	int root;
	root = Read();
	PrintLeaves(root);
}
