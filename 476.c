/*
Sample Input-----------------------------------
r 8.5 17.0 25.5 -8.5
r 0.0 10.3 5.5 0.0
r 2.5 12.5 12.5 2.5
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9

Sample Output-----------------------------------
Point 1 is contained in figure 2
Point 2 is contained in figure 2
Point 2 is contained in figure 3
Point 3 is contained in figure 3
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 6 is not contained in any figure

*///////////////////////////////////////////////
#include<stdio.h>
#define memory 100

#define DBG 0

//X axle
int rectangle_L[memory];//left  //0
int rectangle_R[memory];//right //

//Y axle
int rectangle_U[memory];//up
int rectangle_D[memory];//down

//point
int point_X[memory];
int point_Y[memory];

// * ---> 42  (int)
// r ---> 114 (int)

int main(void){

    int rectangle_read_in_state = 1;
    do{
        int fill_in_reader = 0; //starts from 0,1,2,3

        float read_in;
        scanf("&f",&read_in);

        if(read_in == 42){
            //reading '*'
            rectangle_read_in_state = 0;
        }else if(read_in == 114){
            //reading 'r'
            fill_in_reader = 0;
        }else{
            switch(fill_in_reader)
        }
    }while(rectangle_read_in_state == 1);



    return 0;
}
