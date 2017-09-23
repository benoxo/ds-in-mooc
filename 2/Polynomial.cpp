#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
	int conf;
	int expon;
	PolyNode* next;
}PolyNode, *Polynomail;

Polynomail Add(Polynomail Pa, Polynomail Pb);
Polynomail Multyply(Polynomail Pa, Polynomail Pb);
Polynomail MultyplyByNode(PolyNode* node, Polynomail p);
void Attach(int conf, int expon, Polynomail &p);		// 直接附加，默认已有序
Polynomail ReadPoly();
void PrintPoly(Polynomail p);

int main() {
	freopen("input.txt", "r", stdin);
	Polynomail pa = ReadPoly();
	Polynomail pb = ReadPoly();
//	PrintPoly(pa);
	Polynomail pc = Multyply(pa, pb);
	PrintPoly(pc);
	Polynomail pd = Add(pa, pb);
	PrintPoly(pd);
	return 0;
}

Polynomail ReadPoly() {
	int N, conf, expon;
	Polynomail p = (Polynomail)malloc(sizeof(PolyNode));
	p->next = NULL;
	Polynomail rear = p;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &conf, &expon);
		Attach(conf, expon, rear);
	}
	return p;
}

void Attach(int conf, int expon, Polynomail &rear) {
	if (conf==0) {
		return;
	}
	PolyNode* node = (PolyNode*)malloc(sizeof(PolyNode));
	node->conf = conf;
	node->expon = expon;
	node->next = NULL;
	rear->next = node;
	rear = node;
}

Polynomail Add(Polynomail pa, Polynomail pb) {
	Polynomail pc = (Polynomail)malloc(sizeof(PolyNode));
	pc->next = NULL;
	Polynomail rear = pc;
	pa = pa->next;
	pb = pb->next;
	while (pa && pb) {
		if (pa->expon > pb->expon) {
			Attach(pa->conf, pa->expon, rear);
			pa = pa->next;
		}
		else if (pa->expon < pb->expon) {
			Attach(pb->conf, pb->expon, rear);
			pb = pb->next;
		}
		else {
			Attach(pa->conf + pb->conf, pa->expon, rear);
			pa = pa->next;
			pb = pb->next;
		}
	}
	while (pa) {
		Attach(pa->conf, pa->expon, rear);
		pa = pa->next;
	}
	while (pb) {
		Attach(pb->conf, pb->expon, rear);
		pb = pb->next;
	}
	return pc;
}

Polynomail Multyply(Polynomail pa, Polynomail pb) {
	Polynomail pc = (Polynomail)malloc(sizeof(PolyNode));
	pc->next = NULL;
	pa = pa->next;
	while(pa) {
		Polynomail tmp = MultyplyByNode(pa, pb);
		pc = Add(tmp, pc);
		pa = pa->next;
	}
	return pc;
}

Polynomail MultyplyByNode(PolyNode* node, Polynomail p) {
	Polynomail pc = (Polynomail)malloc(sizeof(PolyNode)), rear;
	pc->next = NULL;
	rear = pc;
	p = p->next;
	while (p) {
		Attach(node->conf*p->conf, node->expon+p->expon, rear);
		p = p->next;
	}
	return pc;
}

void PrintPoly(Polynomail p) {
	if (p->next) {
		p = p->next;
		printf("%d %d", p->conf, p->expon);	
	} else {
		printf("0 0\n");
		return;
	}
	while (p->next) {
		p = p->next;
		printf(" %d %d", p->conf, p->expon);
	}
	printf("\n");
}
