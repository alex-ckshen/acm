/*
Input
每組測試資料1列，有2個整數，代表Hashmat及敵人的士兵數或反之。這些數不會超過2^63。

Output
對每組測試資料請輸出Hashmat與敵人士兵數目的差（正數）。
================================================================
Sample Input
10 12
14 10
================================================================
Sample Output
2
4

*////////////////////////////////////////////////////////////////
#include<stdio.h>


long long int i;
long long int j;

int main(void){
    while(1){
        if(scanf("%lld %lld",&i,&j)==2){
            if(i>j){
                printf("%lld\n",i-j);
            }else if(i<j){
                printf("%lld\n",j-i);
            }else{
                printf("0\n");
            }
        }else{
            break;
        }

    }
}
