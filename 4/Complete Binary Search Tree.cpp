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

Tree CreateTreeBST(int a[], int start, int end);	// 创建完全二叉查找树 
int FindRoot(int start, int end);	// 给定首尾，确定该树的根节点 
Node* CreateNode(int val);		// 创建新结点 
void TravelLevelOrder(Tree);	// 层序遍历并输出

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
// 给定首尾，确定该树的根节点 
int FindRoot(int start, int end) {
	int n = end - start + 1;			// 总结点数 
	int height = (int)log2(n+1);		// 该完全二叉树除去最后一层的满二叉树的高度 
	int maxsize = pow(2, height) - 1;	// 满二叉树的结点总数 
	int remains = n - maxsize;			// 计算出最后一层的结点数 
	int half = pow(2, height-1);		// 最后一层的总容量的一半 
	remains = remains < half ? remains : half; 
	return start + remains + (maxsize+1)/2 - 1;	// 确定根节点的index 
}
// 创建完全二叉搜索树 
Tree CreateTreeBST(int a[], int start, int end) {
	if (start > end) {
		return NULL;
	}
	Tree t;
	int index = FindRoot(start, end);	// 找到根节点的位置 
	t = CreateNode(a[index]);			// 创建根节点 
	t->left = CreateTreeBST(a, start, index-1);	// 绑定左子树 
	t->right = CreateTreeBST(a, index+1, end);	// 绑定右子树 
	return t;
}

Node* CreateNode(int val) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

// 层序遍历并输出 
void TravelLevelOrder(Tree t) {
	if (!t) return;
	Node* a[MAXSIZE];	// 用作队列存储结点 
	a[0] = t;			// 存入第一个结点 
	int front = 0, rear = 1;	// 队首和队尾 
	while (front < rear) {		// 如果队列不空 
		t = a[front++];			// 获取第一个结点 
		if (t->left) a[rear++] = t->left;		// 存入该结点的左孩子 
		if (t->right) a[rear++] = t->right;		// 存入该结点的右孩子
		if (front == 1) printf("%d", t->val);	// 打印该结点的值 
		else printf(" %d", t->val);
	}
}
