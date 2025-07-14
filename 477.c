/*
Sample Input----------------------------------
r 8.5 17.0 25.5 -8.5
c 20.2 7.3 5.8
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9

Sample Output----------------------------------
Point 1 is contained in figure 3
Point 2 is contained in figure 3
Point 2 is contained in figure 5
Point 3 is contained in figure 5
Point 3 is contained in figure 6
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 5 is contained in figure 2
Point 6 is contained in figure 4

*///////////////////////////////////////////////
#include<stdio.h>
#define memory 100

#define DBG 0

float rectangle_TL_x[memory];
float rectangle_TL_y[memory];
float rectangle_DR_x[memory];
float rectangle_DR_y[memory];
float circle_x[memory];
float circle_y[memory];

float radius[memory];

float point_x[memory];
float point_y[memory];

int point_count = 1;        //start from 1
int figure_count = 0;       //start from 1
int figure_type[memory];    //0 is rectangle , 1 is circle
int rectangles_including[memory];//=rectangle count
int circles_including[memory];   //=circle_count


int containing_list[memory];//1,2,...



int position(int point_number){
    int total_containing_count = 0;
    for(int i=0;i<memory;i++){
        containing_list[i]=0;
    }


    float point_position_x = point_x[point_number];
    float point_position_y = point_y[point_number];

    for(int figure_number = 1; figure_number<=figure_count; figure_number++){

        if(figure_type[figure_number] == 0){                      //rectangle
            if(rectangle_TL_x[rectangles_including[figure_number]]<point_position_x && point_position_x<rectangle_DR_x[rectangles_including[figure_number]]
            &&
            rectangle_DR_y[rectangles_including[figure_number]]<point_position_y && point_position_y<rectangle_TL_y[rectangles_including[figure_number]]){
                total_containing_count++;
                containing_list[total_containing_count]=figure_number;

            }else{
                //
            }
        }else if(figure_type[figure_number] == 1){                //circle
            int sqrt_distance_x = (circle_x[circles_including[figure_number]]-point_position_x)*(circle_x[circles_including[figure_number]]-point_position_x);
            int sqrt_distance_y = (circle_y[circles_including[figure_number]]-point_position_y)*(circle_y[circles_including[figure_number]]-point_position_y);
            int sqrt_radius = radius[circles_including[figure_number]]*radius[circles_including[figure_number]];

            if(sqrt_distance_x+sqrt_distance_y<sqrt_radius){
                    //printf("%d+%d>%d\n",sqrt_distance_x,sqrt_distance_y,sqrt_radius);
                    total_containing_count++;
                    containing_list[total_containing_count]=figure_number;

                }else{
                    //
                }
            }
        }

    return total_containing_count;
}

int main(void){
    for(int clear=0;clear<memory;clear++){
        rectangle_TL_x[clear] = 0;
        rectangle_TL_y[clear] = 0;
        rectangle_DR_x[clear] = 0;
        rectangle_DR_y[clear] = 0;
        circle_x[clear] = 0;
        circle_y[clear] = 0;
        radius[clear] = 0;
        point_x[clear] = 0;
        point_y[clear] = 0;
        figure_type[clear] = 0;
        rectangles_including[clear] = 0;
        circles_including[clear] = 0;
        containing_list[clear] = 0;
    }
//===========================================================reading in
    int read_in_status=0;   //separate r or * or c from float
    int fill_in_sequence = 0;
    int state = 3;    //0 stop ; 1 r ; 2 c ; 3 defult

    rectangles_including[0]=0;
    rectangles_including[0]=0;

    do{
        if(read_in_status == 0){      //first letter
            int read_char = getchar();
            if(read_char=='*'){
                state=0;
            }else if(read_char=='r'){

                figure_count++;

                figure_type[figure_count] = 0;
                rectangles_including[figure_count] = rectangles_including[figure_count-1]+1;
                circles_including[figure_count] = circles_including[figure_count-1];


                state = 1;
                fill_in_sequence = 0;     //0,1,2,3 for rectangle
                read_in_status=1;

            }else if(read_char=='c'){

                figure_count++;

                figure_type[figure_count] = 1;
                circles_including[figure_count] = circles_including[figure_count-1]+1;
                rectangles_including[figure_count] = rectangles_including[figure_count-1];

                state = 2;
                fill_in_sequence = 0;     //0,1,2 for circle
                read_in_status=1;

            }
        }else{                                            //numbers
            float figure_read_in;
            scanf("%f",&figure_read_in);

        #if(DBG==1)
            printf("\nNo.%d , %d read in: %f\n",figure_count,fill_in_sequence,figure_read_in);
        #endif

            if(state == 1){      //rectangle starts from 0,1,2,3

                switch(fill_in_sequence){
                case 0:
                    rectangle_TL_x[rectangles_including[figure_count]] = figure_read_in;
                    break;
                case 1:
                    rectangle_TL_y[rectangles_including[figure_count]] = figure_read_in;
                    break;
                case 2:
                    rectangle_DR_x[rectangles_including[figure_count]] = figure_read_in;
                    break;
                case 3:
                    rectangle_DR_y[rectangles_including[figure_count]] = figure_read_in;

                    read_in_status = 0;
                    break;
                }
                fill_in_sequence++;//0,1,2,3   -->TL_x,TL_y,DR_x,DR_y

            }else if(state == 2){   //circle starts from 0,1,2

                switch(fill_in_sequence){
                case 0:
                    circle_x[circles_including[figure_count]] = figure_read_in;
                    break;
                case 1:
                    circle_y[circles_including[figure_count]] = figure_read_in;
                    break;
                case 2:
                    radius[circles_including[figure_count]] = figure_read_in;

                    read_in_status = 0;
                    break;
                }
                fill_in_sequence++;

            }

        #if(DBG==1)
                printf("read in status %d\n",read_in_status);
                printf("currently there are %d rectangles and %d circles\n",
                       rectangles_including[figure_count],circles_including[figure_count]);
        #endif

        }
    }while(state != 0);

#if(DBG==1)
    for(int i=1;i<=rectangles_including[figure_count];i++){
        printf("Rectangle %d: (%f,%f) to (%f,%f)\n",//-->next line
               i,rectangle_TL_x[i],rectangle_TL_y[i],rectangle_DR_x[i],rectangle_DR_y[i]);
    }

    for(int i=1;i<=circles_including[figure_count];i++){
        printf("Circle %d: O(%f,%f), r= %f\n",//-->next line
               i,circle_x[i],circle_y[i],radius[i]);
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
            point_count=point_count-1;
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

    for(int i=1;i<=point_count;i++){
        int figure_numbers = position(i);

        if(figure_numbers==0){
           printf("Point %d is not contained in any figure\n",i);
        }else if(figure_numbers==1){
           printf("Point %d is contained in figure %d\n",i,containing_list[1]);
        }else{
            for(int j=1;j<=figure_numbers;j++){
                printf("Point %d is contained in figure %d\n",i,containing_list[j]);
            }
        }
    }


    return 0;
}
