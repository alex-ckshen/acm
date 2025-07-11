/*
1.輸入 n
2.印出 n
3.如果 n = 1 結束
4.如果 n 是奇數 那麼 n=3*n+1
5.否則 n=n/2
6.GOTO 2
給一個輸入 n ,透過以上的演算法我們可以得到一個數列
此數列的長度稱為n的cycle-length。
對任2個整數i&j，介於i&j（包含i&j）之間的數所產生的數列中
最大的 cycle length 是多少

Sample Input----------------------------
1 10
10 1
100 200
201 210
900 1000

Sample Output----------------------------
1 10 20
10 1 20
100 200 125
201 210 89
900 1000 174
*///////////////////////////////////////////////////////////////

#include<stdio.h>

#define memory 100
#define input_count 10

#define DBG 0

int raw_input[memory];

int min_input[memory];
int max_output[memory];
int cycle_length[memory];

int sequence = 0;       //number count (1,2,...)
int all_sequence = 0;   //number count (1,2,...)


int get_cycle_length(int n){

    int continue_loop = 1;
    int cycle_length_count = 0;

    do{
        if(n==1){
            cycle_length_count++;
            continue_loop = 0;
        }else if(n%2 == 0){//2n
            n = n/2;
            cycle_length_count++;
        }else{       //2n+1
            n = 3*n+1;
            cycle_length_count++;
        }
    }while(continue_loop == 1);

    return cycle_length_count;
}




int main(void){
//==============================================get raw input
    for(int i=0; i<=memory; i++){
        raw_input[i]=0;
    }

    int save_input;
    int raw_input_state = 1;

    int numbers_entered = 0;
    while(raw_input_state == 1){

        #if(DBG==1)
        printf("\starting sequence %d\n",all_sequence);
        #endif

        scanf("%d",&save_input);
        raw_input[all_sequence] = save_input;
        all_sequence++;

        #if(DBG==1)
        for(int i=0;i<=10;i++){
            printf("%d ",raw_input[i]);
        }
        #endif

        numbers_entered++;
        if(numbers_entered == input_count){

            #if(DBG==1)
            printf("\nexiting\n");
            #endif

            raw_input_state = 0;
        }else{

            #if(DBG==1)
            printf("\non to sequence %d\n",all_sequence);
            #endif

        }
    }


//==============================================separate sequence

    sequence = (all_sequence+1)/2;

    #if(DBG==1)
    printf("separated sequence %d\n",sequence);
    #endif

    for(int i=0; i<sequence; i++){     //sequence:1,2,...;clear:0,1,2,...
        min_input[i] = 0;
        max_output[i] = 0;
    }

    for(int i=0; i<sequence; i++){               //seperated->raw
        min_input[i] = raw_input[2*i];       //0->0 ; 1->2 ; ...
        max_output[i] = raw_input[2*i+1];    //0->1 ; 1->3 ; ...
    }

//==============================================get cycle length

    for(int i=0; i<=sequence; i++){
        cycle_length[i]=0;
    }

    int read_in = 0;            //for computer (0,1,2,...)
    while(read_in < sequence){

        if(min_input[read_in] < max_output[read_in]){
            for(int i=min_input[read_in];i<=max_output[read_in];i++){

            int temp_cycle_length = get_cycle_length(i);

            if(temp_cycle_length > cycle_length[read_in]){
                cycle_length[read_in] = temp_cycle_length;
            }

            #if(DBG==2)
            printf("currently checking %d\n",i);
            printf("cycle length is %d\n",temp_cycle_length);
            printf("current MAX cycle length is %d\n",cycle_length[read_in]);
            #endif

            }
        }

        if(min_input[read_in] > max_output[read_in]){
            for(int i=max_output[read_in];i<=min_input[read_in];i++){

            int temp_cycle_length = get_cycle_length(i);

            if(temp_cycle_length > cycle_length[read_in]){
                cycle_length[read_in] = temp_cycle_length;
            }

            #if(DBG==2)
            printf("currently checking %d\n",i);
            printf("cycle length is %d\n",temp_cycle_length);
            printf("current MAX cycle length is %d\n",cycle_length[read_in]);
            #endif

            }
        }
        read_in++;
    }

//==============================================print results
    for(int i=0;i<sequence;i++){
        printf("%d %d %d\n",min_input[i],max_output[i],cycle_length[i]);
    }

    return 0;
}
