#include <cstdio>
#include <cstdlib>
#include <memory.h>

#define MAX 10001

typedef struct VNode {
	int V;
	VNode* Next;
} VNode, *PVNode;
PVNode gragh[MAX];

bool visited[MAX];

void InitGragh(int N);
int BFS(int s, int N);
void Insert(int v, int n);
void CalDegree(int i, int N);

int main() {
	freopen("sdtinput.txt","r", stdin); 
	int N, M, a, b;
	scanf("%d %d", &N, &M);
	InitGragh(N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		Insert(a, b);
		Insert(b, a);
	}
	for (int i = i; i <= N; i++) {
		CalDegree(i, N);
	}
	return 0;
} 

void InitGragh(int N) {
	while (N--) {
		gragh[N] = NULL;
	}
}

int BFS(int s, int N) {
	int count = 1, degree = 0, last = s, tail;
	visited[s] = true;
	int queue[MAX];
	queue[0] = s;
	int front = 0, rear = 1;
	while (front != rear) {
		int el = queue[front++];
		PVNode ptr = gragh[el];
		while (ptr) {
			if (!visited[ptr->V]) {
				queue[rear++] = ptr->V;
				visited[ptr->V] = true; count++;
				tail = ptr->V;
			}
			ptr = ptr->Next;
		}
		if (el == last) {
			last = tail; degree++;
		}
		if (degree == 6) {
			break;
		}
	}
	return count;
} 

void CalDegree(int i, int N) {
	memset(visited, false, (MAX)*sizeof(bool));
	int count = BFS(i, N);
	printf("%d: %.2f\%\n", i, (double)count/N*100);
}

void Insert(int v, int n) {
	PVNode node = (PVNode)malloc(sizeof(VNode));
	node->V = n;
	node->Next = gragh[v];
	gragh[v] = node;
}
