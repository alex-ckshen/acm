/*
給你2個整數 a , b，然後我們寫出所有介於a,b之間的數。你的任務是算出0～9這十個阿拉伯數字各寫了幾次。
例如：a=1024,b=1032，你要寫的這些數將會是：

1024 1025 1026 1027 1028 1029 1030 1031 1032

總共你寫了10個0，10個1，7 個2，3 個3......。


Input
輸入含有多筆測資。每筆測資一列，含有2個整數 a,b。（ 1 <=  a <=  b <= 10^8）

當輸入 a=0， b=0時，代表輸入結束。


Output
對每筆輸入輸出一列，含有10個整數（整數間以一空格分隔）。代表當你寫出所有介於a,b之間的數時，
阿拉伯數字0~9  各出現的次數
*/
#include<stdio.h>
#define memory 1000

long long int a;
long long int b;
long long int all_number[memory];

int loop_state = 1;

long long int all_char_list[memory];
int total_set=0;

int total_char_count=0;

int count_0 = 0;
int count_1 = 0;
int count_2 = 0;
int count_3 = 0;
int count_4 = 0;
int count_5 = 0;
int count_6 = 0;
int count_7 = 0;
int count_8 = 0;
int count_9 = 0;


int get_digit(int input){
    int times=0;
    int digit_count;

    int divided=input;
    while(divided>10){
        divided=divided/10;
        times++;
    }
    printf("times is %d\n",times);

    digit_count = times+1;

    for(int i=digit_count;i>0;i=i-1){
        int temp=digit_count/(10^i);
        all_char_list[total_char_count]=temp;
        digit_count=digit_count-(10^i)*temp;

        //printf("%d\n",digit_count);
        total_char_count++;
    }
}


int main(void){

    do{
        scanf("%d",&a);
        scanf("%d",&b);
        if(a==0 && b==0){
            loop_state=0;
        }else{
            int i = a;
            for(int k=0;k<=(b-a);k++){
                total_set++;
                if(i<b){
                    all_number[k]=i;
                    i++;
                }else if(i==b){
                    all_number[k]=i;
                }
            }
        }
    }while(loop_state==1);

    for(int i=0;i<total_set;i++){
        get_digit(all_number[i]);
        printf("i is %d and number is %d\n",i,all_number[i]);
        printf("total set is %d\n",total_set);

    }

    for(int i=0; i<=total_char_count;i++){
        int temp = all_char_list[i];

        switch(temp){
        case 0:
            count_0++;
            break;
        case 1:
            count_1++;
            break;
        case 2:
            count_2++;
            break;
        case 3:
            count_3++;
            break;
        case 4:
            count_4++;
            break;
        case 5:
            count_5++;
            break;
        case 6:
            count_6++;
            break;
        case 7:
            count_7++;
            break;
        case 8:
            count_8++;
            break;
        case 9:
            count_9++;
            break;
        }

    }


    printf("%d %d %d %d %d %d %d %d %d %d %d %d \n",count_0,count_1,count_2,count_3,count_4,count_5,count_6,count_7,count_8,count_9);



    return 0;
}
