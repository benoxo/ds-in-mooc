#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct TreeNode{
	char elem;
	int left;
	int right;
}Tree1[MAXSIZE], Tree2[MAXSIZE];

int ReadTree(struct TreeNode t[]) {
	int N;
	char l, r;				// �ܽ��������ʱ������ҽڵ����� 
	int check[MAXSIZE] = {0};	// �����жϸ��ڵ����� 
	int root = -1;				// ���ڵ����� 
	scanf("%d\n", &N);
	// ����ڵ㣬ʹ��char���ͣ���Ϊ��'-'�ַ� 
	for (int i = 0; i < N; i++) {
		scanf("%c %c %c\n", &t[i].elem, &l, &r);
		if (l == '-') {
			t[i].left = -1;
		} else {
			t[i].left = l - '0';
			check[t[i].left] = 1;
		}
		if (r == '-') {
			t[i].right = -1;
		} else {
			t[i].right = r - '0';
			check[t[i].right] = 1;
		}
	}
	// ȷ�����ڵ������ 
	for (int i = 0; i < N; ++i) {
		if (!check[i]) {
			root = i; break;
		}
	} 
	return root;
}

// �ж��Ƿ�ͬ��
bool Isomorphic(int root1, int root2) {
	if (root1 == -1 && root2 == root1) {	// ����������Ľڵ㶼�ǿսڵ㣬����ͬ�� 
		return true;
	}
	char elem1 = Tree1[root1].elem;			// ����ȽϽڵ��ֵ 
	char elem2 = Tree2[root2].elem;
	if(Tree1[root1].elem == Tree2[root2].elem) {// ����ڵ��ֵ��ͬ����Ƚ�����������ֵ 
		int child1_l = Tree1[root1].left;
		int child1_r = Tree1[root1].right;
		int child2_l = Tree2[root2].left;
		int child2_r = Tree2[root2].right;
		bool c1 = Isomorphic(child1_l, child2_l) && Isomorphic(child1_r, child2_r);// 1��2�����������ֱ�ͬ�� 
		bool c2 = Isomorphic(child1_l, child2_r) && Isomorphic(child1_r, child2_l);// 1��2��������������ͬ�� 
		return c1 || c2;	// ����������������֮һ������Ϊ�������ڵ�ͬ����������Ϊ��ͬ�� 
	}
	return false;			// ��������ڵ�ֵ����ͬ����ͬ�� 
}


int main() {
	freopen("input.txt", "r", stdin);
	int root1 = ReadTree(Tree1);
	int root2 = ReadTree(Tree2);
	if (Isomorphic(root1, root2)) {
		printf("Yes");
	} else {
		printf("No");
	}
}
