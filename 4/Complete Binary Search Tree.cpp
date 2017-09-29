#include <cstdio>
#include <cstdlib>
#include <cmath>

#define MAXSIZE 1000

typedef struct Node {
	int val;
	Node *left, *right;
}Node, *Tree;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

Tree CreateTreeBST(int a[], int start, int end);	// ������ȫ��������� 
int FindRoot(int start, int end);	// ������β��ȷ�������ĸ��ڵ� 
Node* CreateNode(int val);		// �����½�� 
void TravelLevelOrder(Tree);	// ������������

int main() {
	freopen("CBSinput.txt", "r", stdin);
	int N;
	int a[MAXSIZE];
	Tree t;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", a+i);
	}
	qsort(a, N, sizeof(int), compare);
	t = CreateTreeBST(a, 0, N-1);
	TravelLevelOrder(t);
	return 0;
} 
// ������β��ȷ�������ĸ��ڵ� 
int FindRoot(int start, int end) {
	int n = end - start + 1;			// �ܽ���� 
	int height = (int)log2(n+1);		// ����ȫ��������ȥ���һ������������ĸ߶� 
	int maxsize = pow(2, height) - 1;	// ���������Ľ������ 
	int remains = n - maxsize;			// ��������һ��Ľ���� 
	int half = pow(2, height-1);		// ���һ�����������һ�� 
	remains = remains < half ? remains : half; 
	return start + remains + (maxsize+1)/2 - 1;	// ȷ�����ڵ��index 
}
// ������ȫ���������� 
Tree CreateTreeBST(int a[], int start, int end) {
	if (start > end) {
		return NULL;
	}
	Tree t;
	int index = FindRoot(start, end);	// �ҵ����ڵ��λ�� 
	t = CreateNode(a[index]);			// �������ڵ� 
	t->left = CreateTreeBST(a, start, index-1);	// �������� 
	t->right = CreateTreeBST(a, index+1, end);	// �������� 
	return t;
}

Node* CreateNode(int val) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

// ������������ 
void TravelLevelOrder(Tree t) {
	if (!t) return;
	Node* a[MAXSIZE];	// �������д洢��� 
	a[0] = t;			// �����һ����� 
	int front = 0, rear = 1;	// ���׺Ͷ�β 
	while (front < rear) {		// ������в��� 
		t = a[front++];			// ��ȡ��һ����� 
		if (t->left) a[rear++] = t->left;		// ����ý������� 
		if (t->right) a[rear++] = t->right;		// ����ý����Һ���
		if (front == 1) printf("%d", t->val);	// ��ӡ�ý���ֵ 
		else printf(" %d", t->val);
	}
}
