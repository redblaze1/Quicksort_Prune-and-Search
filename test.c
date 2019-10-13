#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

//datatype
struct rand_num_data
{
    unsigned long long int num;
    bool is_sorted;
};

//data
bool had_swaped, toexit;
int i, find, tmpswap, count2, count3;
struct rand_num_data data[SIZE], *start, *end, *tmpaddr, *count, *pr;

#define printarr pr = data;for( i=0; i<SIZE; i++ ){printf("%lld ",pr->num);if(i+1 != SIZE)pr++;}printf("\n");

int main(){
    //init
    srand(time(NULL));
    i = 0;
    start = data;
    while(i < SIZE){
        start->num = rand()%100;
        start->is_sorted = false;
        ++i;
        ++start;
    }
    
    printf("陣列初始值: ");
    printarr;

    start = data;
    tmpaddr = data+1;
    count = data;
    end = data+SIZE-1;
    printf("請輸入要陣列幾資料: ");
    scanf("%d", &find);
    if(find > SIZE){
        printf("要找的數不能大於陣列長度\n");
        return 0;
    }

quicksort:
    //quicksort (need init: count, tmpaddr, start)
    while( !toexit ){
        if ( !(tmpaddr - end) ){
            toexit = true;
            printf("沒有小於%lld的數了離開\n",start->num);
        }
        //check is_sorted
        if( !(tmpaddr->is_sorted) ){
            //if not sorted, find > pivot num, if found it, than swap
            // count3++;
            // printf("檢查次數: %d\n", count3);
            if ( start->num > tmpaddr->num ){
                printf("交換前: ");
                printarr;
                had_swaped = true;
                count++;
                printf("start: %lld, end: %lld, 要交換的數: %lld, 被交換的數: %lld\n", start->num, end->num, tmpaddr->num, count->num);
                //swap
                tmpswap = tmpaddr->num;
                tmpaddr->num = count->num;
                count->num = tmpswap;
                printf("交換後: ");
                printarr;
            }
        } else {
            printf("找到後面%lld已排序完,離開\n",tmpaddr->num);
            break;
        }
        tmpaddr++;
    }
    toexit = false;

    //if had been sorted, swap "start" and "final swap num"
    if(had_swaped){
        tmpswap = start->num;
        start->num = count->num;
        count->num = tmpswap;
        count->is_sorted = true;
        printarr;

        //Prune and Search
        if( count - data > find ){
            end = count -1;
            tmpaddr = start +1;
            count = start;
        } else if( count - data < find ){
            start = count+1;
            if(start - data == SIZE-1)
                goto rt;
            tmpaddr = start +1;
            count = start;
        } else {
            printf("data[%ld]: %lld\n", count - data, count->num );
            printarr;
            return 0;
        }

        had_swaped = false;
        goto quicksort;
    }
    start->is_sorted = true;
    if( start - data == find ){
rt:
        printf("data[%ld]: %lld\n", start - data, start->num );
        printarr;
        return 0;
    }
    if( start == end ){
        goto rt;
    }
    tmpaddr = start+1;
    count = start;
    start++;

    goto quicksort;
}
