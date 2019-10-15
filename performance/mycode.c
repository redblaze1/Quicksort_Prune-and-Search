#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10000000
#define FIND 5000000

//datatype
struct rand_num_data
{
    unsigned long long int num;
    bool is_sorted;
};

//data
bool had_swaped, toexit;
int i, find, tmpswap, countnum;
struct rand_num_data data[SIZE], *start, *end, *tmpaddr, *count, *pr;

#define printarr pr = data;for( i=0; i<SIZE; i++ ){printf("%lld ",pr->num);if(i+1 != SIZE)pr++;}printf("\n");

int main(){
    //init
    srand(time(NULL));
    i = 0;
    start = data;
    while(i < SIZE){
        start->num = rand();
        start->is_sorted = false;
        ++i;
        ++start;
    }

    start = data;
    tmpaddr = data+1;
    count = data;
    end = data+SIZE-1;
    find = FIND;
    // printf("請輸入要陣列幾資料: ");
    // scanf("%d", &find);
    // if(find >= SIZE){
    //     printf("要找的數不能大於陣列長度\n");
    //     return 0;
    // }

quicksort:
    //quicksort (need init: count, tmpaddr, start)
    while( !toexit ){
        if ( !(tmpaddr - end) ){
            toexit = true;
            // printf("沒有小於%lld的數了離開\n",start->num);
        }
        //check is_sorted
        if( !(tmpaddr->is_sorted) ){
            //if not sorted, find > pivot num, if found it, than swap
            if ( start->num > tmpaddr->num ){
                // printf("交換前: ");
                // printarr;
                had_swaped = true;
                count++;
                // printf("startnum: %lld, endnum: %lld, 要交換的數: %lld, 被交換的數: %lld\n", start->num, end->num, tmpaddr->num, count->num);
                //swap
                tmpswap = tmpaddr->num;
                tmpaddr->num = count->num;
                count->num = tmpswap;
                // printf("交換後: ");
                // printarr;
            }
        } else {
            // printf("找到後面%lld已排序完,離開\n",tmpaddr->num);
            break;
        }
        tmpaddr++;
    }
    toexit = false;
    countnum++;

    //if had been sorted, swap "start" and "final swap num"
    if(had_swaped){
        tmpswap = start->num;
        start->num = count->num;
        count->num = tmpswap;
        count->is_sorted = true;

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
            printf("data[%ld]: %lld\n", count - data - 1, (count - 1)->num );
            printf("data[%ld]: %lld\n", count - data, count->num );
            printf("data[%ld]: %lld\n", count - data + 1, (count + 1)->num );
            printf("定位了%d次\n",countnum);
            return 0;
        }

        had_swaped = false;
        goto quicksort;
    }
    //if not swaped, than let start is_sorted and init, after init than goto quicksort
    start->is_sorted = true;
    if( start - data == find ){
rt:
        printf("data[%ld]: %lld\n", start - data - 1, (start - 1)->num );
        printf("data[%ld]: %lld\n", start - data, start->num );
        printf("data[%ld]: %lld\n", start - data + 1, (start + 1)->num );
        printf("定位了%d次\n",countnum);
        return 0;
    }
    start++;
    if( start == end ){
        goto rt;
    }
    tmpaddr = start+1;
    count = start;

    goto quicksort;
}
