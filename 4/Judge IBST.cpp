#include <cstdio>
#include <cstdlib>

typedef struct Node {
	int val;
	Node *left, *right;
	int flag;	// �����ж�ĳ���ڵ��Ƿ��Ѿ������� 
} Node, *Tree;

/**
 * �ж�L�������Ƿ��ܹ�����ͬһ�ö�����������
 * ������õ����ȸ��ݵ�һ�����й���һ������
 * �ڷֱ���������н����жϿ��Ƿ������㹹�������Ľṹ 
 */ 

Tree CreateTree(int);				// �������������� 
void InsertBST(int val, Tree &t);	// ����ڵ� 
void ResetFlag(Tree);				// ��������flagΪ0 
bool JudgeIBST(Tree, int L);		// �ж��Ƿ�ͬһ���������� 
bool Check(Tree &t, int val);		// �ж�ĳ���ڵ��Ƿ������ѹ����Ķ����� 

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
	bool flag = true;	// ����Ƿ�ͬһ��BST 
	while (N--) {
		scanf("%d", &val);
		if (flag && !Check(t, val)) {	// ��ÿ���ڵ�����жϣ�flag������·�Ѿ���ΪͬһBST֮����ж� 
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
