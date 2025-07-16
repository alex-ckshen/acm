/*
Input
測試資料每筆一行，每行至少有一個字。

Output
輸出每一行的word數。

//=======================================================
Sample input

Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...

//=======================================================
Sample Output

2
7
10
9
*//////////////////////////////////////////////////////////////////
#include<stdio.h>
#define memory 1000

int keep_read_in = 1;

int current_letter;
int previous_letter=0;

int already_entered = 0;

int symbol_list[14] = {33,33,34,38,39,40,41,42,43,44,46,58,59,63};

int word_count[memory];
int line_count = 1;

//' ' = 32
//'!' = 33
//'"' = 34
//'&' = 38
//''' = 39
//'(' = 40
//')' = 41
//'*' = 42
//'+' = 43
//',' = 44
//'.' = 46
//':' = 58
//';' = 59
//'?' = 63

//A~Z : 65~90
//a~z : 97~122

int check_word(int current,int previous){
    int state = 0;      //1:potential,2:counting++

        printf("currently %d\npreviously %d\n",current,previous);
    for(int i=0;i<14;i++){
        if(current==symbol_list[i]){
            state=1;
        printf("state is %d\n",state);
        }
    }

    if(state==1){
        if(65<=previous&&previous<=90){       //A~Z
            word_count[line_count]++;
        }else if(97<=previous&&previous<=122){//a~z
            word_count[line_count]++;
        }
    }
}

int main(void){
    do{
        current_letter = getchar();
        if(already_entered == 1 && current_letter=='\n'){
            keep_read_in = 0;
        }else{
            if(current_letter=='\n'){
                line_count++;
                already_entered++;
                printf("line count %d\n", line_count);
            }else{
                already_entered=0;
                check_word(current_letter,previous_letter);
                previous_letter=current_letter;
            }
        }

    }while (keep_read_in==1);

    for(int i=1;i<line_count;i++){
        printf("%d\n",word_count[i]);

    }
    return 0;
}
