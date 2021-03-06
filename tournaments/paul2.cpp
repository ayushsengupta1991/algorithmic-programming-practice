#include "stdio.h"
#include "stdlib.h"
#include "iostream"

bool checkSum(int *A,int *B, int *C, int n, int targetP, int targetC, int targetF) {
  if (targetC == 0 && targetP == 0 && targetF == 0)
    return true;
  if (n == 0 && (targetP != 0 || targetC != 0 || targetF != 0))
    return false;

  if ((A[n-1] > targetP) || (B[n-1] > targetC) || (C[n-1] > targetF))
    return checkSum(A, B, C, n-1, targetP, targetC, targetF);

  return (checkSum(A, B, C, n-1, targetP, targetC, targetF) || checkSum(A, B, C, n-1, targetP-A[n-1], targetC-B[n-1], targetF-C[n-1]));
}

int main() {
  int t=0,i=0,j=0;
  scanf("%d", &t);
  int G[t][3];
  int P[t][20],C[t][20],F[t][20];  
  int n=0;
  for (;i<t;i++) {
    scanf("%d %d %d", &G[i][0], &G[i][1], &G[i][2]);
    scanf("%d", &n);
    
    for (j=0;j<n;j++) {
      scanf("%d %d %d", &P[i][j], &C[i][j], &F[i][j]);
    }
  }
  
  for (i=0;i<t;i++) {
    if (checkSum(P[i], C[i], F[i], n, G[i][0], G[i][1], G[i][2])) {
      printf("Case #%d: yes\n", (i+1));
    }
    else 
      printf("Case #%d: no\n", (i+1));
  }
  return 0;
}



