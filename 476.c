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

float rectangle_TL_x[memory];
float rectangle_TL_y[memory];

float rectangle_DR_x[memory];
float rectangle_DR_y[memory];

float point_x[memory];
float point_y[memory];

int rectangle_count = 0;  // !!! starts from '1'
int point_count = 1;      // !!! starts from 1

int contain[memory];      //1,2,...
int containing_numbers=0; //1,2,...

int position(int point_serial){
    for(int k=0;k<=containing_numbers;k++){
        contain[k]=0;
    }
    containing_numbers=0;

    for(int i=1;i<=rectangle_count;i++){
        if(rectangle_TL_x[i]<point_x[point_serial] && point_x[point_serial]<rectangle_DR_x[i]){
            if(rectangle_DR_y[i]<point_y[point_serial] && point_y[point_serial]<rectangle_TL_y[i]){
                containing_numbers++;
                contain[containing_numbers] = i;

            #if(DBG==2)
                printf("X: %f<%f<%f\n",rectangle_TL_x[i],point_x[point_serial],rectangle_DR_x[i]);
                printf("Y: %f<%f<%f\n",rectangle_DR_y[i],point_y[point_serial],rectangle_TL_y[i]);
                printf("\nPoint %d is included in %d\n",point_serial,i);
                printf("containing_numbers is %d\n",containing_numbers);
            #endif

            }else{
                //
            }
        }else{
                //
        }
    }

    return containing_numbers;
}

int main(void){
//===========================================================reading in rectangle
    int read_in_sequence=0;   //separate r or * from float

    int fill_in_sequence = 0; //starts from 0,1,2,3

    int rectangle_read_in_state = 1;
    do{
        if(read_in_sequence==0 || read_in_sequence==5){      //first letter
            int read_char = getchar();
            if(read_char=='*'){             // '*'->EXIT
                rectangle_read_in_state=0;
            }else if(read_char=='r'){       // 'r'
                fill_in_sequence=0;
                rectangle_count++; //onto next rectangle
            }
            read_in_sequence=1;//onto next
        }else{                                            //numbers
            float rectangle_read_in;
            scanf("%f",&rectangle_read_in);

        #if(DBG==1)
            printf("the number is %f\n",rectangle_read_in);
        #endif

            switch(fill_in_sequence){
            case 0:
                rectangle_TL_x[rectangle_count] = rectangle_read_in;
                break;
            case 1:
                rectangle_TL_y[rectangle_count] = rectangle_read_in;
                break;
            case 2:
                rectangle_DR_x[rectangle_count] = rectangle_read_in;
                break;
            case 3:
                rectangle_DR_y[rectangle_count] = rectangle_read_in;
                break;
            }
            fill_in_sequence++;//0,1,2,3   -->TL_x,TL_y,DR_x,DR_y
            read_in_sequence++;//0,1,2,3,4 -->r/*, number 1,2,3,4
        }
    }while(rectangle_read_in_state == 1);

#if(DBG==1)
    for(int i=1;i<=rectangle_count;i++){
        printf("Rectangle %d: (%f,%f) to (%f,%f)\n",//-->next line
               i,rectangle_TL_x[i],rectangle_TL_y[i],rectangle_DR_x[i],rectangle_DR_y[i]);
    }
#endif

//===========================================================reading in point
    int point_sequence = 0;
    int exit_point = 0;

    int point_read_in_state = 1;
    do{
        float point_read_in;
        scanf("%f",&point_read_in);
        if(exit_point == 1 && 9999.9-point_read_in<0.1){
            point_read_in_state = 0;
        }else if(exit_point == 1 && 9999.9-point_read_in>1){
            exit_point=0;
        }else if(9999.9-point_read_in<0.1){
            exit_point=1;
        }else{
            if(point_sequence == 0){
                point_x[point_count] = point_read_in;
                point_sequence = 1;
            }else if(point_sequence ==1){
                point_y[point_count] = point_read_in;
                point_sequence = 0;
#if(DBG==1)
                printf("point count:%d\n",point_count);
#endif
                point_count++;
            }
        }

    }while(point_read_in_state == 1);

#if(DBG==1)
    for(int i=1;i<=point_count;i++){
        printf("Point %d: (%f,%f)\n",i,point_x[i],point_y[i]);
    }
#endif
//===========================================================verifying position
    for(int i=1;i<point_count;i++){
        int figure_numbers = position(i);

        if(figure_numbers==0){
           printf("Point %d is not contained in any figure\n",i);
        }else if(figure_numbers==1){
           printf("Point %d is contained in figure %d\n",i,contain[1]);
        }else{
            for(int j=1;j<=figure_numbers;j++){
                printf("Point %d is contained in figure %d\n",i,contain[j]);
            }
        }
    }


    return 0;
}
