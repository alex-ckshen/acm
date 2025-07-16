/*
input
輸入的第一列有一個整數n，代表有幾組測試資料。接下來每組測試資料有2列，
各有1個正整數（A、F），A代表振幅（A<=9），F代表頻率。
第一列以及各組測試資料間皆有一空白行。請參考Sample input。

Output
每組測試資料請輸出F個波，每個波振幅的水平高度為A。波本身是以其"高度"的內容所組成。
每個波之間以一空白行分隔開來。
測試資料間也以一空白行分開。

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
