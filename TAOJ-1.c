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
