#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10000000
#define FIND 5000000

int find, data[SIZE], *numaddr, count = 0;

void swap(int *a, int *b){
 int temp = *a;
 *a = *b;
 *b = temp;
}
void quicksort(int *data, int left, int right){

 int pivot, i, j;
 if (left >= right) { return; }
 pivot = data[left];
 i = left + 1;
 j = right;
 while (1)
 {
 while (i <= right)
 {
 if (data[i] > pivot)
 {
 break;
 }
 i = i + 1;
 }
 while (j > left)
 {
 if (data[j] < pivot)
 {
 break;
 }
 j = j - 1;
 }
 if (i > j) { break; }
 swap(&data[i], &data[j]);
 }
 swap(&data[left], &data[j]);
 //紀錄成功定位的次數
 count++;

 quicksort(data, left, j - 1);
 quicksort(data, j + 1, right);
 }
int main(){
 //init
 srand(time(NULL));
 int i = 0;
 numaddr = data;
 while(i < SIZE){
 *numaddr = rand();
 ++numaddr;
 ++i;
 }
//  printf("請輸入要第幾筆資料: ");
//  scanf("%d", &find);
find = FIND;
//  if(find >= SIZE){
//         printf("要找的數不能大於陣列長度\n");
//         return 0;
// }

 // 執行快速排序法
 quicksort(data, 0, SIZE - 1);
 printf("data[%d]: %d\n", find-1, data[find-1]);
 printf("第%d 的陣列data 為: %d\n", find, data[find]);
 printf("data[%d]: %d\n", find+1, data[find+1]);
 printf("定位了%d次\n",count);
}