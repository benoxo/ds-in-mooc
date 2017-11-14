#include <stdio.h>
#include <stdlib.h>

#define MINDATA -10000
#define MAXSIZE 64
#define TNodeType int

typedef struct TNode{
	TNodeType Data;
	TNode* left;
	TNode* right;
}TNode, *HuffmanTree, *PtrToTNode;


typedef struct HNode{
	TNode* Data;
	int Size; 
}*Heap;
typedef Heap MinHeap;


MinHeap CreateMinHeap(int size); // 创建小顶堆 
void InsertMinHeap(MinHeap H, TNodeType e); // 向小顶堆中插入一个数据 
MinHeap ReadData(MinHeap H, int n); // 将数据插入小顶堆 
TNode DeleteHeap(MinHeap H); // 删除小顶堆中的元素（最小者） 
HuffmanTree Huffman(MinHeap H); // 创建Huffman树 
int WPL(HuffmanTree HTree); // 总权重 
bool IfBestTree(); // 是否为最优编码 
bool IfNodeOfBestTree(HuffmanTree t, TNode* n); // 是否为最优编码树的结点 

char C[MAXSIZE];
int F[MAXSIZE];

int main() {
	freopen("hcinput.txt","r",stdin);
	int N; // 结点总数
	scanf("%d\n", &N);
	MinHeap H = CreateMinHeap(N);
	H = ReadData(H, N); 
	HuffmanTree HTree = Huffman(H);
}

MinHeap CreateMinHeap(int size) {
	MinHeap H = (MinHeap)malloc(sizeof(HNode));
	H->Data = (TNode*)malloc((size+1)*sizeof(TNode));
	H->Size = 0;
	return H;
}

MinHeap ReadData(MinHeap H, int n) {
	while (n--) {
		scanf("%c %d ", &C[n], &F[n]);	// 读入一个结点
		InsertMinHeap(H, F[n]);
	}
}

void InsertMinHeap(MinHeap H, TNodeType e) {
	int pos = H->Size+1;
	while (H->Data[pos/2].Data > e){
		H->Data[pos] = H->Data[pos/2];
		pos = pos/2;
	}
	TNode elem;
	elem.Data = e;
	elem.left = NULL;
	elem.right = NULL;
	H->Data[pos] = elem;
	H->Size++;
}

TNode DeleteHeap(MinHeap H) {
	int pos = 1;
	TNode val = H->Data[1]; 
	TNode last = H->Data[H->Size];
	H->Size--;
	int child = pos*2;
	while (child <= H->Size) {
		if (child+1 <= H->Size && H->Data[child+1].Data > H->Data[child].Data) {
			child++;
		}
		if (H->Data[child].Data < last.Data) {
			H->Data[pos] = H->Data[child];
			pos = child;
			child = pos*2;
		} else {
			break;
		}
	}
	H->Data[pos] = last;
	return val;
}

HuffmanTree Huffman(MinHeap H) {
	HuffmanTree HTree;
	for (int i = 0; i < H->Size-1; i++) {
		
	}
} 















