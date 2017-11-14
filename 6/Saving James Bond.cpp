#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>

typedef struct Point {
	int X;
	int Y;
} Point, *PtrToPoint;

Point points[100];
bool visited[100];

bool IfLand(int s, int jumpLen);
bool DFS(int s, int N, int jumpLen);
bool IfSafe(int N, int jumpLen);
bool CouldJump(int a, int b, int jumpLen);



int main() {
	freopen("sjbinput.txt", "r", stdin);
	int N, jumpLen, x, y;
	scanf("%d %d", &N, &jumpLen);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		points[i].X = x;
		points[i].Y = y;
	}
	
	if (IfSafe(N, jumpLen)) {
		printf("Yes");
	} else {
		printf("No");
	}
 }
 
 
bool IfLand(int s, int jumpLen) {
	PtrToPoint p = points + s;
	if (p->X + jumpLen >= 50 ||
		p->X - jumpLen <= -50 ||
		p->Y + jumpLen >= 50 ||
		p->Y - jumpLen <= -50) {
			return true;
		} else {
			return false;
		}
}

bool CouldJump(int a, int b, int jumpLen) {
	PtrToPoint p1 = points + a;
	PtrToPoint p2 = points + b;
	if (pow(p1->X-p2->X, 2) + pow(p1->Y - p2->Y, 2) <= pow(jumpLen, 2)) {
		return true;
	} else {
		return false;
	}
}

bool CouldFirstJump(int a, int jumpLen) {
	PtrToPoint p = points + a;
	if (pow(p->X, 2) + pow(p->Y, 2) <= pow(jumpLen+15, 2)) {
		return true;
	} else {
		return false;
	}
}

bool IfSafe(int N, int jumpLen) {
	if (jumpLen >= 50) {
		return true;
	}
	for (int i = 0; i < N; i++) {
		PtrToPoint p = points + i;
		if (!visited[i] && CouldFirstJump(i, jumpLen)) {
			if (DFS(i, N, jumpLen)) {
				return true;
			}
		}
	}
	return false;
}
bool DFS(int s, int N, int jumpLen) {
	visited[s] = true;
	bool answer = false; 
	if (IfLand(s, jumpLen)) {
		answer = true;
	} else {
		for (int i = 0; i < N; i++) {
			if (!visited[i] && CouldJump(s, i, jumpLen)) {
				if (DFS(i, N, jumpLen)) {
					answer = true;
				}
				
			}
		}
	}
	return answer;
} 
