/*
input
��J���Ĥ@�C���@�Ӿ��n�A�N���X�մ��ո�ơC���U�ӨC�մ��ո�Ʀ�2�C�A
�U��1�ӥ���ơ]A�BF�^�AA�N���T�]A<=9�^�AF�N���W�v�C
�Ĥ@�C�H�ΦU�մ��ո�ƶ��Ҧ��@�ťզ�C�аѦ�Sample input�C

Output
�C�մ��ո�ƽп�XF�Ӫi�A�C�Ӫi���T���������׬�A�C�i�����O�H��"����"�����e�Ҳզ��C
�C�Ӫi�����H�@�ťզ���j�}�ӡC
���ո�ƶ��]�H�@�ťզ���}�C

//===============================================
Sample input

2

3
2

5
3

Sample Output

1
22
333
22
1

1
22
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1

*//////////////////////////////////////////////////////////////////
#include<stdio.h>
#define memory 1000

int total_inputs = 0;
int wave_height[memory];
int wave_frequency[memory];

int wave(int height){
    int counter;

    printf("\n");

    for(int i=1;i<=height;i++){
        counter=0;
        while(counter<i){
            counter++;
            printf("%d",i);
        }
        printf("\n");
    }

    for(int i=height-1;i>0;i--){
        counter=0;
        while(counter<i){
            counter++;
            printf("%d",i);
        }
        printf("\n");
    }
}

int main(void){
    scanf("%d",&total_inputs);

    for(int i=0;i<total_inputs;i++){
        scanf("%d",&wave_height[i]);
        scanf("%d",&wave_frequency[i]);
     }

     for(int i=0;i<total_inputs;i++){
        for(int times=0;times<wave_frequency[i];times++){
            wave(wave_height[i]);
        }
     }

     return 0;
}
