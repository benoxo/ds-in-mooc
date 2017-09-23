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
//	int pos = -1, pre=-1, next = l->first;	// �ֱ�ָ��ǰ�ڵ㣬ǰһ���ڵ㣬��һ���ڵ� 
//	int FirstNodePos = next;	// ��ǰ��ת�ĵ�һ���ڵ� 
//	int LastNodePos = -1;		// �ϴη�ת�ĵ�һ���ڵ� 
//	int i = K;					// ���Ʒ�ת���� 
//	int circle = N / K;			// ѭ������ 
//	int flag = 1;				// �����Ƿ�Ϊ��һ���Է�ת�����Ϊ��һ�Σ����޸�firstָ�� 
//	while (circle-- > 0) {
//		i = K;
//		while (i--) {
//			pre = pos;	 
//			pos = next;
//			next = l->nodes[next].next;
//			l->nodes[pos].next = pre;
//		}
//		if (flag) {
//			l->first = pos;		// ��firstָ�����ڵĵ�һ�ڵ� 
//			flag = 0;
//		} else {
//			l->nodes[LastNodePos].next = pos;	// ���ǵ�һ��ѭ��������һ�η�ת������һ���ڵ��nextָ��˴η�ת��ĵ�һ�ڵ� 
//		}
//		l->nodes[FirstNodePos].next = next;		// ���˴η�ת������һ���ڵ�ָ����һ��ѭ���ĵ�һ���ڵ㣬��ֹ���� 
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
