#include <cstdio>
#include <cstdlib>

typedef struct Node {
	int val;
	Node *left, *right;
	int flag;	// 用来判断某个节点是否已经遍历过 
} Node, *Tree;

/**
 * 判断L个序列是否能构建出同一棵二叉搜索树，
 * 这里采用的是先根据第一个序列构建一棵树，
 * 在分别对其他序列进行判断看是否能满足构建的树的结构 
 */ 

Tree CreateTree(int);				// 构建搜索二叉树 
void InsertBST(int val, Tree &t);	// 插入节点 
void ResetFlag(Tree);				// 重置所有flag为0 
bool JudgeIBST(Tree, int L);		// 判断是否同一二叉搜索树 
bool Check(Tree &t, int val);		// 判断某个节点是否满足已构建的二叉树 

int main() {
	freopen("JIinput.txt", "r", stdin);
	int N, L;
	Tree t;
	scanf("%d", &N);
	while(N) {
		scanf("%d", &L);
		t = CreateTree(N);
		for (int i = 0; i < L; i++) {
			if (JudgeIBST(t, N)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			ResetFlag(t);
		}
		free(t);
		scanf("%d", &N);
	}
}

Tree CreateTree(int N) {
	int val;
	Tree t = NULL;
	while (N--) {
		scanf("%d", &val);
		InsertBST(val, t);	
	}
	return t;
}

void InsertBST(int val, Tree &t) {
	if (!t) {
		t = (Tree)malloc(sizeof(Node));
		t->val = val;
		t->left = NULL;
		t->right = NULL;
		t->flag = 0;
	} else if (val < t->val) {
		InsertBST(val, t->left);
	} else if (val > t->val) {
		InsertBST(val, t->right);
	}
}

bool JudgeIBST(Tree t, int N) {
	int val;
	bool flag = true;	// 标记是否同一棵BST 
	while (N--) {
		scanf("%d", &val);
		if (flag && !Check(t, val)) {	// 对每个节点进行判断，flag用来短路已经不为同一BST之后的判断 
			flag = !flag;
		}
	}
	return flag;
}

bool Check(Tree &t, int val) {
	if (!t) return false;
	if (t->val == val) {
		t->flag = !t->flag;
		return t->flag;
	} else if (t->flag) {
		if (t->val > val) {
			Check(t->left, val);
		} else if (t->val < val) {
			Check(t->right, val);
		}	
	} else {
		return false;
	}
}

void ResetFlag(Tree t) {
	if (!t) return;
	t->flag = 0;
	ResetFlag(t->right);
	ResetFlag(t->left);
}
