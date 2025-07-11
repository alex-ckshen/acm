/*
Sample Input

1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5
1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5


Sample Output

*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
*DEC is the trademark of the Digital Equipment Corporation.

*//////////////////////////////////////////////////////////////////////

#include<stdio.h>
#define memory 1000
#define DBG 0

#define all_ascii 0

#define decode_number 7

main(void){
    #if (all_ascii==1)
    for(int i=33;i<=126;i++){
        printf("ascii %d is %c\n",i,i);
    }
    #endif


    char encripted_list[memory];
    char decoded_list[memory];

    int continue_state = 1;
    int input_serial = 0;

//==========================================input
    do{
        char input = getchar();

        if(input=='\r' || input=='\n'){
            continue_state = 0;
        }else{
            encripted_list[input_serial] = input;
            input_serial++;
        }
    }while(continue_state == 1);

 #if(DBG==1)
     for(int i=0;i<input_serial;i++){
        printf("%c\n",encripted_list[i]);
    }
 #endif

//==========================================decode
    for(int i=0;i<input_serial;i++){
        int char_to_int = encripted_list[i];

#if(DBG==2)
    printf("i is %d \nthe number is %d\nchar is %c\n",i,char_to_int,encripted_list[i]);
#endif

        decoded_list[i] = char_to_int - decode_number;
        printf("%c",decoded_list[i]);
#if(DBG==2)
    printf("%d-%d=%d, decoded char is %c\n",char_to_int,decode_number,decoded_list[i],decoded_list[i]);
#endif

    }

    return 0;
}
