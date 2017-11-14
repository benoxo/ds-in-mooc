#include <cstdio>
#include <cstdlib>
#include "memory.h" 

#define MAXSIZE 10001

typedef int ElemType;
typedef int SetType;

int Find(SetType s[], ElemType e) {
	if (s[e] < 0) {
		return e;		
	} else {
		return s[e] = Find(s, s[e]);
	}
}

int Union(SetType s[], ElemType e1, ElemType e2) {
	int r1 = Find(s, e1);
	int r2 = Find(s, e2);
	if(s[r2] < s[r1]) {
		s[r2] += s[r1];
		s[r1] = r2;
	} else {
		s[r1] += s[r2];
		s[r2] = r1;
	}
}

int Check(SetType s[], ElemType e1, ElemType e2) {
	int r1 = Find(s, e1);
	int r2 = Find(s, e2);
	if (r1 == r2) {
		return 1;
	} else {
		return 0;
	} 
} 

int CountComponents(SetType s[], int N) {
	int n = 0;
	for(int i = 1; i <= N; i++) {
		if (s[i] < 0) n++;
	}
	return n;
}

int main() {
	freopen("FTinput.txt", "r", stdin);
	int N, c1, c2;
	char op;
	SetType s[MAXSIZE];
	memset(s, -1, sizeof(SetType)*MAXSIZE);
	scanf("%d\n", &N);
	scanf("%c", &op);
	while (op != 'S') {
		scanf("%d %d\n", &c1, &c2);
		if (op == 'I') {
			Union(s, c1, c2);
		} else if (op == 'C') {
			if (Check(s, c1, c2)) {
				printf("yes\n");
			} else {
				printf("no\n");
			}
		}
		scanf("%c", &op);
	}
	int nroot = CountComponents(s, N);
	if (nroot == 1) {
		printf("The network is connected.\n");
	} else {
		printf("There are %d components.\n", nroot);
	}
}





