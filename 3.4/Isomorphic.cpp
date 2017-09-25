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
	char l, r;				// 总结点数、暂时存放左右节点坐标 
	int check[MAXSIZE] = {0};	// 用来判断根节点坐标 
	int root = -1;				// 根节点坐标 
	scanf("%d\n", &N);
	// 读入节点，使用char类型，因为有'-'字符 
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
	// 确定跟节点的坐标 
	for (int i = 0; i < N; ++i) {
		if (!check[i]) {
			root = i; break;
		}
	} 
	return root;
}

// 判断是否同构
bool Isomorphic(int root1, int root2) {
	if (root1 == -1 && root2 == root1) {	// 如果两棵树的节点都是空节点，返回同构 
		return true;
	}
	char elem1 = Tree1[root1].elem;			// 否则比较节点的值 
	char elem2 = Tree2[root2].elem;
	if(Tree1[root1].elem == Tree2[root2].elem) {// 如果节点的值相同，则比较左右子树的值 
		int child1_l = Tree1[root1].left;
		int child1_r = Tree1[root1].right;
		int child2_l = Tree2[root2].left;
		int child2_r = Tree2[root2].right;
		bool c1 = Isomorphic(child1_l, child2_l) && Isomorphic(child1_r, child2_r);// 1、2的左右子树分别同构 
		bool c2 = Isomorphic(child1_l, child2_r) && Isomorphic(child1_r, child2_l);// 1、2的左右子树交叉同构 
		return c1 || c2;	// 满足上面两个条件之一，则认为这两个节点同构。否则认为不同构 
	}
	return false;			// 如果两个节点值不相同，则不同构 
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
