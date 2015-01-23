#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stack"
using std::stack;

void splitNumber(int n, int C[][11], int j) {
  static int A[11] = {0};
  stack<int> s1;
  int i=0;
  while (n/10) {
    int rem = n%10;
    s1.push(rem);
    n = n/10;
  }
  s1.push(n);
  while (!s1.empty()) {
    C[j][i] = s1.top();
    i++;
    s1.pop();
  }
  C[j][i] = -1;
}

int merge(int A[11]) {
  int i=0,num=0,j;
  for (;i<11;i++) {
    if (A[i] == -1)
      break;
  }
  int k=0;
  for (j = i-1; j>=0; j--,k++) {
    num += pow(10, k)*A[j];
  }
  return num;
}

int swapandmerge(int A[11], int index_i,int index_j) {
  int temp = A[index_j];
  A[index_j] = A[index_i];
  A[index_i] = temp;
  
  int ret = merge(A);
  temp = A[index_j];
  A[index_j] = A[index_i];
  A[index_i] = temp;
  return ret;
}

int main() {
  int t,i=0,j=0,k=0;
  scanf("%d", &t);
  int A[t];
  for (;i<t;i++) {
    scanf("%d", &A[i]);
  }
  int Min[t][2];
  int Max[t][2];
  int C[t][11];

  for (i=0;i<t;i++) {
    int min_val=0, max_val=0;
    
    splitNumber(A[i], C, i);
    min_val = A[i];
    max_val = A[i];

    for (j=0;C[i][j]>=0;j++) {
      int min_element = C[i][j];
      int max_element = C[i][j];

      for (k=j+1;C[i][k]>=0;k++) {

          int temp_min = swapandmerge(C[i], j, k);
          if (!min_val || min_val > temp_min) {
            if ((j==0 && C[i][k] != 0) || j != 0) {
              Min[i][1] = k;
              Min[i][0] = j; 
              min_val = temp_min;
            }
          }

          int temp_max = swapandmerge(C[i], j, k); 
          if (!max_val || max_val < temp_max) {
            Max[i][1] = k;
            Max[i][0] = j;
            max_val = temp_max;
          }
      }
      
    }
  }

  for (i=0;i<t;i++) {
    int min_num=0, max_num=0;

    if ((Min[i][0] != Min[i][1]) && Min[i][0] <= 9 && Min[i][1] <= 9) {
      min_num = swapandmerge(C[i], Min[i][0], Min[i][1]);
    }

    if ((Max[i][0] != Max[i][1]) && Max[i][0] <= 9 && Max[i][1] <= 9) {
      max_num = swapandmerge(C[i], Max[i][0], Max[i][1]);
    }
    printf("Case #%d: ", (i+1));

    if (min_num)
      printf("%d ", min_num);
    else
      printf("%d ", merge(C[i]));

    if (max_num)
      printf("%d", max_num);
    else
      printf("%d", merge(C[i]));
    printf("\n");
  }
  return 0;
}

