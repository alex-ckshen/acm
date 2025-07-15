/*

有 n 個人圍成一個圓圈等待處決。從第一個人開始跳過 k – 1 個人，第 k 個人被處決。然後再跳過 k – 1 個人，第 k 個人又
被處決。淘汰的程序繞著圓圈進行，(隨著被處決的人的移除，圓圈會越變越小)，直到最後只剩一個人為止。
已知圓圈中的人數及 k。你必須找最後倖存的人的號碼。

Input
第一行有一個整數 t (0< t <=100)，代表有幾組測試資料。接下來的 t 行每行有兩個整數n (0 < n <= 105) 及 k (0 < k <=109)。

Output
每組測試的輸出格式為 "Case i: a"，其中 "i" 為測資編號，"a" 則為圓圈中倖存的人 (請參考範例)。
================================================================
Sample Input 
4
6 3
8 6
11 99
23 13
================================================================
Sample Output
Case 1: 1
Case 2: 1
Case 3: 5
Case 4: 12

*////////////////////////////////////////////////////////////////
#include<stdio.h>
#define DBG 0

int total;
int n[106];
int k[110];


int counting(int read_in){
    int original_count = n[read_in];
    int skip = k[read_in]-1;

    int people_left = original_count;
    int current_eliminating = 1;
    int current_list[106];

    int out_of_loop = 0;

    int serial=1;
    for(int i=0;i<original_count;i++){
        current_list[i]=serial;

        serial++;
    }

    while(people_left != 1){
        current_eliminating = current_eliminating + skip;
        //printf("%d is current_eliminating 1\n",current_eliminating);
        while(current_eliminating>people_left){
            current_eliminating = current_eliminating - people_left;
            //printf("%d is current_eliminating 2\n",current_eliminating);
        }

        for(int i = current_eliminating-1 ;i<people_left;i++){
            current_list[i]=current_list[i+1];
        }
        people_left=people_left-1;

        #if(DBG==1)
        for(int i=0;i<people_left;i++){printf("%d ",current_list[i]);}
        printf("\n");
        #endif
    }

    return current_list[0];
}

int main(void){
    scanf("%d",&total);
    for(int i=0;i<total;i++){
        scanf("%d",&n[i]);
        scanf("%d",&k[i]);
    }

    for(int i=0;i<total;i++){
        printf("Case %d: %d\n",i+1,counting(i));
    }

    return 0;
}
