void InsertionSort( ElementType A[], int N )
{ /* �������� */
     int P, i;
     ElementType Tmp;
      
     for ( P=1; P<N; P++ ) {
         Tmp = A[P]; /* ȡ��δ���������еĵ�һ��Ԫ��*/
         for ( i=P; i>0 && A[i-1]>Tmp; i-- )
             A[i] = A[i-1]; /*������������������Ԫ�رȽϲ�����*/
         A[i] = Tmp; /* �Ž����ʵ�λ�� */
     }
}

void ShellSort( ElementType A[], int N )
{ /* ϣ������ - ��Sedgewick�������� */
     int Si, D, P, i;
     ElementType Tmp;
     /* ����ֻ�г�һС�������� */
     int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
      
     for ( Si=0; Sedgewick[Si]>=N; Si++ ) 
         ; /* ��ʼ������Sedgewick[Si]���ܳ����������г��� */
 
     for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
         for ( P=D; P<N; P++ ) { /* ��������*/
             Tmp = A[P];
             for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
                 A[i] = A[i-D];
             A[i] = Tmp;
         }
}

void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}
  
void PercDown( ElementType A[], int p, int N )
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    ElementType X;
 
    X = A[p]; /* ȡ��������ŵ�ֵ */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= A[Child] ) break; /* �ҵ��˺���λ�� */
        else  /* ����X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}
 
void HeapSort( ElementType A[], int N ) 
{ /* ������ */
     int i;
       
     for ( i=N/2-1; i>=0; i-- )/* �������� */
         PercDown( A, i, N );
      
     for ( i=N-1; i>0; i-- ) {
         /* ɾ�����Ѷ� */
         Swap( &A[0], &A[i] ); /* ������7.1 */
         PercDown( A, 0, i );
     }
}


/* �鲢���� - �ݹ�ʵ�� */
 
/* L = �����ʼλ��, R = �ұ���ʼλ��, RightEnd = �ұ��յ�λ��*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
     int LeftEnd, NumElements, Tmp;
     int i;
      
     LeftEnd = R - 1; /* ����յ�λ�� */
     Tmp = L;         /* �������е���ʼλ�� */
     NumElements = RightEnd - L + 1;
      
     while( L <= LeftEnd && R <= RightEnd ) {
         if ( A[L] <= A[R] )
             TmpA[Tmp++] = A[L++]; /* �����Ԫ�ظ��Ƶ�TmpA */
         else
             TmpA[Tmp++] = A[R++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
     }
 
     while( L <= LeftEnd )
         TmpA[Tmp++] = A[L++]; /* ֱ�Ӹ������ʣ�µ� */
     while( R <= RightEnd )
         TmpA[Tmp++] = A[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */
          
     for( i = 0; i < NumElements; i++, RightEnd -- )
         A[RightEnd] = TmpA[RightEnd]; /* �������TmpA[]���ƻ�A[] */
}
 
void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{ /* ���ĵݹ������� */ 
     int Center;
      
     if ( L < RightEnd ) {
          Center = (L+RightEnd) / 2;
          Msort( A, TmpA, L, Center );              /* �ݹ������ */ 
          Msort( A, TmpA, Center+1, RightEnd );     /* �ݹ����ұ� */  
          Merge( A, TmpA, L, Center+1, RightEnd );  /* �ϲ������������� */ 
     }
}
 
void MergeSort( ElementType A[], int N )
{ /* �鲢���� */
     ElementType *TmpA;
     TmpA = (ElementType *)malloc(N*sizeof(ElementType));
      
     if ( TmpA != NULL ) {
          Msort( A, TmpA, 0, N-1 );
          free( TmpA );
     }
     else printf( "�ռ䲻��" );
}


/* �鲢���� - ѭ��ʵ�� */
/* ����Merge�����ڵݹ�汾�и��� */
 
/* length = ��ǰ�������еĳ���*/
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{ /* �����鲢������������ */
     int i, j;
       
     for ( i=0; i <= N-2*length; i += 2*length )
         Merge( A, TmpA, i, i+length, i+2*length-1 );
     if ( i+length < N ) /* �鲢���2������*/
         Merge( A, TmpA, i, i+length, N-1);
     else /* ���ֻʣ1������*/
         for ( j = i; j < N; j++ ) TmpA[j] = A[j];
}
 
void Merge_Sort( ElementType A[], int N )
{ 
     int length; 
     ElementType *TmpA;
      
     length = 1; /* ��ʼ�������г���*/
     TmpA = malloc( N * sizeof( ElementType ) );
     if ( TmpA != NULL ) {
          while( length < N ) {
              Merge_pass( A, TmpA, N, length );
              length *= 2;
              Merge_pass( TmpA, A, N, length );
              length *= 2;
          }
          free( TmpA );
     }
     else printf( "�ռ䲻��" );
}
