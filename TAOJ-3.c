/*
���A2�Ӿ�� a , b�A�M��ڭ̼g�X�Ҧ�����a,b�������ơC�A�����ȬO��X0��9�o�Q�Ӫ��ԧB�Ʀr�U�g�F�X���C
�Ҧp�Ga=1024,b=1032�A�A�n�g���o�ǼƱN�|�O�G

1024 1025 1026 1027 1028 1029 1030 1031 1032

�`�@�A�g�F10��0�A10��1�A7 ��2�A3 ��3......�C


Input
��J�t���h������C�C������@�C�A�t��2�Ӿ�� a,b�C�] 1 <=  a <=  b <= 10^8�^

���J a=0�A b=0�ɡA�N���J�����C


Output
��C����J��X�@�C�A�t��10�Ӿ�ơ]��ƶ��H�@�Ů���j�^�C�N���A�g�X�Ҧ�����a,b�������ƮɡA
���ԧB�Ʀr0~9  �U�X�{������
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
