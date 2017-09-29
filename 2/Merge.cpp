#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct Node {
	ElementType Data;
	Node* Next;
}*PtrToNode, *List;

List Read() {
	int n;
	scanf("%d", &n);
	List l = (List)malloc(sizeof(Node));
	l->Next = NULL;
	Node* pr = l;
	for (; n>0; --n) {
		pr->Next = (Node *)malloc(sizeof(Node));
		pr->Next->Next = NULL;
		scanf("%d", &pr->Next->Data);
		pr = pr->Next;
	}
	return l;
}

void Print(List l) {
	if (l && l->Next) {
		l = l->Next;
		printf("\n%d", l->Data);
		l = l->Next;
	} else {
		printf("NULL\n");
		return;
	}
	while (l) {
		printf(" %d", l->Data);
		l = l->Next;
	}
	printf("\n");
}

List Merge( List L1, List L2 ){
	List m = (List)malloc(sizeof(struct Node));
	PtrToNode pr = m;
	PtrToNode p1 = L1->Next;
	PtrToNode p2 = L2->Next;
	while (p1 && p2) {
		if (p1->Data < p2->Data) {
			pr->Next = p1;
			p1 = p1->Next;
    	} else {
			pr->Next = p2;
			p2 = p2->Next;
    	}
    	pr = pr->Next;
  	}
	pr->Next = p1?p1:p2;
	L1->Next = NULL;
	L2->Next = NULL;
	return m;
}

int main() {
	freopen("in.txt", "r", stdin);
	List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
} 
