#include <cstdio>
#include <cstdlib>
#include <memory.h>

#define MAXSIZE 11

int gragh[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE];

void Visit(int);
void ListComponents(int, int);
void DFS(int, int);
void BFS(int, int);

int main() {
	freopen("pinput.txt", "r", stdin); 
	memset(gragh, 0, sizeof(int)*MAXSIZE*MAXSIZE);
	int N, M, a, b;
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d", &a, &b);
		gragh[a][b] = 1;
		gragh[b][a] = 1;
	}
	ListComponents(1, N);
	ListComponents(0, N);
	return 0;
}

void Visit(int s) {
	printf("%d ", s);
}

void ListComponents(int opt, int N) {
	memset(visited, 0, sizeof(bool)*MAXSIZE);
	if (opt) {
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				printf("{ ");
				DFS(i, N);
				printf("}\n");
			}
		}
	} else {
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				printf("{ ");
				BFS(i, N);
				printf("}\n");
			}
		}	
	}
} 

void DFS(int s, int N) {
	Visit(s);
	visited[s] = true;
	for (int i = 0; i < N; i++) {
		if (gragh[s][i] == 1 && !visited[i]) {
			DFS(i, N);
		}
	}
}

void BFS(int s, int N) {
	int queue[MAXSIZE];
	int front=0, rear=0;
	queue[rear++] = s;
	Visit(s);
	visited[s] = true;
	while (front != rear) {
		int el = queue[front++];
		for (int i = 0; i < N; i++) {
			if (gragh[el][i] == 1 && !visited[i]) {
				Visit(i);
				visited[i] = true;
				queue[rear++] = i;
			}
		}
	}
}
