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
