#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	int next;
} Node;

typedef struct SList {
	Node nodes[100000];
	int first;
}*List;

int N, K;

List ReadNodes() {
	int pos, value, next, i;
	List l = (List)malloc(sizeof(SList));
	scanf("%d %d %d", &l->first, &N, &K);
	i = N;
	while (i--) {
		scanf("%d %d %d", &pos, &value, &next);
		l->nodes[pos].value = value;
		l->nodes[pos].next = next;
	}
	return l;
}

void Print(List l) {
	int pos = l->first;
	while (pos >= 0) {
		if (l->nodes[pos].next == -1) {
			printf("%05d %d %d\n", pos, l->nodes[pos].value, l->nodes[pos].next);
		} else {
			printf("%05d %d %05d\n", pos, l->nodes[pos].value, l->nodes[pos].next);
		}
		pos = l->nodes[pos].next;
	}
}

//void Reverse2(List l) {
//	int pos = -1, pre=-1, next = l->first;	// 分别指向当前节点，前一个节点，后一个节点 
//	int FirstNodePos = next;	// 当前反转的第一个节点 
//	int LastNodePos = -1;		// 上次反转的第一个节点 
//	int i = K;					// 控制反转次数 
//	int circle = N / K;			// 循环次数 
//	int flag = 1;				// 控制是否为第一次以反转，如果为第一次，则修改first指向 
//	while (circle-- > 0) {
//		i = K;
//		while (i--) {
//			pre = pos;	 
//			pos = next;
//			next = l->nodes[next].next;
//			l->nodes[pos].next = pre;
//		}
//		if (flag) {
//			l->first = pos;		// 将first指向现在的第一节点 
//			flag = 0;
//		} else {
//			l->nodes[LastNodePos].next = pos;	// 不是第一次循环，则将上一次反转后的最后一个节点的next指向此次反转后的第一节点 
//		}
//		l->nodes[FirstNodePos].next = next;		// 将此次反转后的最后一个节点指向下一次循环的第一个节点，防止断链 
//		LastNodePos = FirstNodePos;
//		FirstNodePos = next;
//	}
//}

void Reverse(List l) {
	int stack[100000];
	int top = 0;
	int i = K;
	int cur = l->first, rear = cur, fix;
	int flag = 1;
	while (cur > -1) {
		while (i-- && cur > -1) {
			stack[top++] = cur;
			cur = l->nodes[cur].next;
		}
		if (i > -1) {
			break;
		}
		if (flag) {
			l->first = stack[top-1];
			flag = 0;
		} else {
			l->nodes[rear].next = stack[top-1];
		}
		while (++i < K) {
			fix = stack[--top];
			if (top) {
				l->nodes[fix].next = stack[top-1];	
			} else {
				rear = fix;
				l->nodes[fix].next = cur;
			}
		}
	}
}

int main() {
	freopen("rllinput.txt", "r", stdin);
	List l = ReadNodes();
	Reverse(l);
	Print(l);
}
