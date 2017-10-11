#include <cstdio>
#include <cstdlib>

#define MINDATA -100000

typedef int ElemType;
typedef struct HNode {
	ElemType *Data;
	int Size;
	int Capacity;
} HNode, *Heap;
typedef Heap MinHeap;

MinHeap CreateHeap(int maxSize) {
	MinHeap h = (MinHeap)malloc(sizeof(HNode));
	h->Data = (ElemType*)malloc((maxSize+1)*sizeof(ElemType));
	h->Size = 0;
	h->Capacity = maxSize;
	h->Data[0] = MINDATA;
	return h;
}

void InsertHeap(ElemType e, MinHeap h) {
	int index = h->Size+1;
	int parent = index/2;
	while (e < h->Data[parent]) {
		h->Data[index] = h->Data[parent]; 
		index = parent;
		parent /= 2;
	}
	h->Data[index] = e;
	h->Size++;
}

void PrintPath(int index, MinHeap h) {
	while (index > 1) {
		printf("%d ", h->Data[index]);
		index /= 2;
	}
	printf("%d\n", h->Data[1]);
}

int main() {
	freopen("PIHinput.txt", "r", stdin);
	int N, M;
	ElemType e;
	int index;
	scanf("%d %d", &N, &M);
	MinHeap h = CreateHeap(N+1);
	while (N-- > 0) {
		scanf("%d", &e);
		InsertHeap(e, h);
	}
	while (M-- > 0) {
		scanf("%d", &index);
		PrintPath(index, h);
	}
	return 0;
}


