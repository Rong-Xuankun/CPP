#include <stdio.h>

typedef int KeyType;
typedef struct {
  KeyType key;
  int data;
} RecType;

void DispSort(RecType R[], int n) {
  for (int i = 0; i < n; i++) printf("%2d", R[i].key);
  printf("\n");
}

void BinInsertSort(RecType R[], int n) {
  int i, j, low, high, mid;
  RecType tmp;
  for (i = 1; i < n; i++) {
    printf("i=%2d,移动%2d,", i, R[i].key);
    if (R[i].key < R[i - 1].key) {
      tmp = R[i];
      low = 0;
      high = i - 1;
      while (low <= high) {
        mid = (low + high) / 2;
        if (tmp.key < R[mid].key)
          high = mid - 1;
        else
          low = mid + 1;
      }
      for (j = i - 1; j >= high + 1; j--) R[j + 1] = R[j];
      R[high + 1] = tmp;
    }
    DispSort(R, n);
  }
}

void ShellSort(RecType R[], int n) {
  int i, j, d;
  RecType tmp;
  d = n / 2;
  while (d > 0) {
    printf("d=%2d,", d);
    for (i = d; i < n; i++) {
      tmp = R[i];
      j = i - d;
      while (j >= 0 && tmp.key < R[j].key) {
        R[j + d] = R[j];
        j = j - d;
      }
      R[j + d] = tmp;
    }
    DispSort(R, n);
    d = d / 2;
  }
}

int main() {
    RecType R1[] = {{5,0},{4,0},{7,0},{2,0},{6,0},{9,0},{1,0},{5,0},{0,0}};
    RecType R2[] = {{5,0},{4,0},{7,0},{2,0},{6,0},{9,0},{1,0},{5,0},{0,0}};
  printf("排序前的数据\n");
  DispSort(R1, 9);
  printf("折半排序:\n");
  BinInsertSort(R1, 9);
  printf("希尔排序:\n");
  ShellSort(R2, 9);
  return 0;
}