#include <cstdio>
#include <cstdlib>

#define ElemType int

typedef struct Node {
	ElemType val;
	Node *left, *right;
} Node, *Tree;

Tree Insert(Tree, ElemType);	// ����ڵ� 
Node* CreateNode(ElemType);		// �����½ڵ� 
int GetHeight(Tree);			// ��ȡ���ĸ߶� 
int Max(ElemType, ElemType);	
Tree LL(Tree);				// ������ 
Tree RR(Tree);				// ������ 
Tree LR(Tree);				// ����˫�� 
Tree RL(Tree);				// ����˫�� 

int main() {
	freopen("RATinput.txt", "r", stdin);
	int N;
	ElemType input;
	Tree t = NULL;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &input);
		t = Insert(t, input);
	}
	printf("%d", t->val);
}

Tree Insert(Tree t, ElemType val) {
	if (!t) {
		t = CreateNode(val);
	} else if (val < t->val) {
		t->left = Insert(t->left, val);
		if (GetHeight(t->left) - GetHeight(t->right) > 1) {
			if (val < t->left->val) {
				t = LL(t);
			} else {
				t = LR(t);
			}
		}
	} else if (val > t->val) {
		t->right = Insert(t->right, val);
		if (GetHeight(t->left) - GetHeight(t->right) < -1) {
			if (val < t->right->val) {
				t = RL(t);
			} else {
				t = RR(t);
			}
		}
	}
	return t;
}

Tree LL(Node *node) {
	Node *lchild = node->left;
	node->left = lchild->right;
	lchild->right = node;
	return lchild;
}

Tree RR(Node *node) {
	Node *rchild = node->right;
	node->right = rchild->left;
	rchild->left = node;
	return rchild;
}

Tree LR(Node *node) {
	node->left = RR(node->left);
	return LL(node);
}

Tree RL(Node *node) {
	node->right = LL(node->right);
	return RR(node);
}

Node* CreateNode(ElemType val) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int GetHeight(Tree t) {
	if (!t) {
		return 0;
	}
	return Max(GetHeight(t->left), GetHeight(t->right)) + 1;
}

int Max(ElemType a, ElemType b) {
	return a > b ? a : b;
}
