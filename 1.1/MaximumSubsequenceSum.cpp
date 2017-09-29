#include <stdio.h>

int MSS(int[], int);
int MSS1(int[], int);
int MSS2(int[], int);
int MaxSubseqSum3(int[], int);

int main() {
	freopen("in.txt", "r", stdin);
	int n;
	int a[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	printf("%d", MSS(a, n));
	return 0;
}

int MSS(int seq[], int n) {
	int thisSum=0, maxSum=0;
	for (int i = 0; i < n; i++) {
		thisSum += seq[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
		} else if (thisSum < 0) {
			thisSum = 0;
		}
	}
	return maxSum;
}

int MSS1(int seq[], int n) {
	int maxSum = 0;
	int i,j,k,thisSum;
	for (i = 0; i < n; i++) {
		for (j = i;j < n; j++) {
			thisSum = 0;
			for (k = i; k < j; k++) {
				thisSum += seq[k];
			}
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

int MSS2(int seq[], int n) {
	int maxSum = 0;
	int i,j,k,thisSum;
	for (i = 0; i < n; i++) {
		thisSum = 0;
		for (j = i;j < n; j++) {
			thisSum += seq[j];
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

int Max3( int A, int B, int C )
{ /* ����3�������е����ֵ */
//    return A > B ? A > C ? A : C : B > C ? B : C;
	A < B ? A = B:0;
	A < C ? A = C:0;
	return A;
}
 
int DivideAndConquer( int List[], int left, int right )
{ /* ���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/
 
    int LeftBorderSum, RightBorderSum;
    int center, i;
 
    if( left == right )  { /* �ݹ����ֹ����������ֻ��1������ */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }
 
    /* ������"��"�Ĺ��� */
    center = ( left + right ) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );
 
    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */
 
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */
 
    /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}
 
int MaxSubseqSum3( int List[], int N )
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
    return DivideAndConquer( List, 0, N-1 );
}
