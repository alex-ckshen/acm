/*
Sample Input----------------------------------
r 8.5 17.0 25.5 -8.5
c 20.2 7.3 5.8
t -1.0 -1.0 10.1 2.2 .4 1.4
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
t 20.3 9.8 10.0 -3.2 17.5 -7.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
t -10.0 -10.0 10.0 25.0 30.0 -10.0
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9

Sample Output----------------------------------
Point 1 is contained in figure 4
Point 1 is contained in figure 9
Point 2 is contained in figure 4
Point 2 is contained in figure 7
Point 2 is contained in figure 9
Point 3 is contained in figure 7
Point 3 is contained in figure 8
Point 3 is contained in figure 9
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 5 is contained in figure 2
Point 5 is contained in figure 6
Point 5 is contained in figure 9
Point 6 is contained in figure 5
Point 6 is contained in figure 9

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

float raw_tryangle_ax[memory];
float raw_tryangle_ay[memory];
float raw_tryangle_bx[memory];
float raw_tryangle_by[memory];
float raw_tryangle_cx[memory];
float raw_tryangle_cy[memory];

float point_x[memory];
float point_y[memory];

int point_count = 1;        //start from 1
int figure_count = 0;       //start from 1
int figure_type[memory];       //1 r ; 2 c ; 3 t

int rectangles_including[memory];
int circles_including[memory];
int tryangles_including[memory];


//only required: top/left/right
int get_tryangles_point(int figure_serial,char to_get){//to_get : T / R / L
    char tryangle_points[3];
    int T = tryangles_including[figure_serial];

    /*===============================================
    get top ( Y axle )

             |---> a>c  ===>a
    ---> a>b |
             |---> a<c  ===>C

             |---> b>c  ===>b
    ---> a<b |
             |---> b<c  ===>c
    *///=============================================
    if(raw_tryangle_ay[T]>raw_tryangle_by[T]){
        if(raw_tryangle_ay[T]>raw_tryangle_cy[T]){tryangle_points[0] = 'a';}
        else{tryangle_points[0] = 'c';}
    }else{
        if(raw_tryangle_by[T]>raw_tryangle_cy[T]){tryangle_points[0] = 'b';}
        else{tryangle_points[0] = 'c';}
    }


    /*===============================================
    get side ( X axle )

      TOP  |      L<R
    -------------------------
           | ---> b<c
    ---> a |
           | ---> c<b
    -------------------------
           | ---> a<c
    ---> b |
           | ---> c<a
    -------------------------
           | ---> a<b
    ---> c |
           | ---> b<a
    *///=============================================
    switch(tryangle_points[0]){
    case 'a':
        if(raw_tryangle_bx[T]<raw_tryangle_cx[T]){tryangle_points[1]='b';tryangle_points[2]='c';}
        else{tryangle_points[1]='c';tryangle_points[2]='b';}
        break;
    case 'b':
        if(raw_tryangle_ax[T]<raw_tryangle_cx[T]){tryangle_points[1]='a';tryangle_points[2]='c';}
        else{tryangle_points[1]='c';tryangle_points[2]='a';}
        break;
    case 'c':
        if(raw_tryangle_ax[T]<raw_tryangle_bx[T]){tryangle_points[1]='a';tryangle_points[2]='b';}
        else{tryangle_points[1]='b';tryangle_points[2]='a';}
        break;
    }

    switch(to_get){
        case 'T':
            return tryangle_points[0];
            break;
        case 'R':
            return tryangle_points[1];
            break;
        case 'L':
            return tryangle_points[2];
            break;

    }
}
int get_tryangles_point_XY(int figure_serial,char X_or_Y,char to_get){
    int T = tryangles_including[figure_serial];
    char get;

    switch(X_or_Y){
    case 'X':
        switch (to_get){
        case 'T':
            get = get_tryangles_point(T,'T');
            break;
        case 'R':
            get = get_tryangles_point(T,'R');
            break;
        case 'L':
            get = get_tryangles_point(T,'L');
            break;
        }
        //====================
        switch(get){
        case 'a':
            return raw_tryangle_ax[T];
            break;
        case 'b':
            return raw_tryangle_bx[T];
            break;
        case 'c':
            return raw_tryangle_cx[T];
            break;
        }

        break;

    case 'Y':
        switch (to_get){
        case 'T':
            get = get_tryangles_point(T,'T');
        case 'R':
            get = get_tryangles_point(T,'R');
        case 'L':
            get = get_tryangles_point(T,'L');
        }
        //====================
        switch(get){
        case 'a':
            return raw_tryangle_ay[T];
            break;
        case 'b':
            return raw_tryangle_by[T];
            break;
        case 'c':
            return raw_tryangle_cy[T];
            break;
        }


        break;
    }
}

int temp_size_list_x[3];
int temp_size_list_y[3];
//0 is largest
char size(int total_figure, char x_or_y, char to_be_returned){
    int to_be_compared = tryangles_including[total_figure];
    for(int i=0;i<3;i++){
        char temp_size_list_x[3];
        char temp_size_list_y[3];
    }
    //=======================================for x
    if(raw_tryangle_ax[to_be_compared] > raw_tryangle_bx[to_be_compared]){
        if(raw_tryangle_bx[to_be_compared] > raw_tryangle_cx[to_be_compared]){  //a > b > c
            temp_size_list_x[0] = 'a'; temp_size_list_x[1] = 'b'; temp_size_list_x[2] = 'c';
        }else if(raw_tryangle_cx[to_be_compared] > raw_tryangle_ax[to_be_compared]){  //c > a > b
            temp_size_list_x[0] = 'c'; temp_size_list_x[1] = 'a'; temp_size_list_x[2] = 'b';
        }else{  //a > c > b
            temp_size_list_x[0] = 'a'; temp_size_list_x[1] = 'c'; temp_size_list_x[2] = 'b';
        }
    }else{
        if(raw_tryangle_ax[to_be_compared] > raw_tryangle_cx[to_be_compared]){  //b > a > c
            temp_size_list_x[0] = 'b'; temp_size_list_x[1] = 'a'; temp_size_list_x[2] = 'c';
        }else if(raw_tryangle_cx[to_be_compared] > raw_tryangle_bx[to_be_compared]){  //c > b > a
            temp_size_list_x[0] = 'c'; temp_size_list_x[1] = 'b'; temp_size_list_x[2] = 'a';
        }else{  //b > c > a
            temp_size_list_x[0] = 'b'; temp_size_list_x[1] = 'c'; temp_size_list_x[2] = 'a';
        }
    }
    //=======================================for y
    if(raw_tryangle_ay[to_be_compared] > raw_tryangle_by[to_be_compared]){
        if(raw_tryangle_by[to_be_compared] > raw_tryangle_cy[to_be_compared]){  //a > b > c
            temp_size_list_y[0] = 'a'; temp_size_list_y[1] = 'b'; temp_size_list_y[2] = 'c';
        }else if(raw_tryangle_cy[to_be_compared] > raw_tryangle_ay[to_be_compared]){  //c > a > b
            temp_size_list_y[0] = 'c'; temp_size_list_y[1] = 'a'; temp_size_list_y[2] = 'b';
        }else{  //a > c > b
            temp_size_list_y[0] = 'a'; temp_size_list_y[1] = 'c'; temp_size_list_y[2] = 'b';
        }
    }else{
        if(raw_tryangle_ay[to_be_compared] > raw_tryangle_cy[to_be_compared]){  //b > a > c
            temp_size_list_y[0] = 'b'; temp_size_list_y[1] = 'a'; temp_size_list_y[2] = 'c';
        }else if(raw_tryangle_cy[to_be_compared] > raw_tryangle_by[to_be_compared]){  //c > b > a
            temp_size_list_y[0] = 'c'; temp_size_list_y[1] = 'b'; temp_size_list_y[2] = 'a';
        }else{  //b > c > a
            temp_size_list_y[0] = 'b'; temp_size_list_y[1] = 'c'; temp_size_list_y[2] = 'a';
        }
    }
    //=======================================

        //for x-->s m l
        //for y--->s m l
        //small medium large
    if(x_or_y = 'x'){
        switch(to_be_returned){
            case 'l':
                return temp_size_list_x[0];
                break;
            case 'm':
                return temp_size_list_x[1];
                break;
            case 's':
                return temp_size_list_x[2];
                break;
        }
    }else if(x_or_y = 'y'){
        switch(to_be_returned){
            case 'l':
                return temp_size_list_y[0];
                break;
            case 'm':
                return temp_size_list_y[1];
                break;
            case 's':
                return temp_size_list_y[2];
                break;
        }

    }
}
//usage:
//size_to_x(int, size(int,x/y,s/m/l) )
//size_to_y(int, size(int,x/y,s/m/l) )
float size_to_x(int total_figure,int size_return){
    int serial=tryangles_including[total_figure];

    switch (size_return){
        case 'a':
            return raw_tryangle_ax[serial];
            break;
        case 'b':
            return raw_tryangle_bx[serial];
            break;
        case 'c':
            return raw_tryangle_cx[serial];
            break;
    }
}
float size_to_y(int total_figure,int size_return){
    int serial=tryangles_including[total_figure];

    switch (size_return){
        case 'a':
            return raw_tryangle_ay[serial];
            break;
        case 'b':
            return raw_tryangle_by[serial];
            break;
        case 'c':
            return raw_tryangle_cy[serial];
            break;
    }
}


float M;
int liner_value(float x1, float y1, float x2, float y2, float observe_x, float observe_y){
    float x_value = x1;
    float y_value = y1;
    float k;

    //y=M*x + k
    M=(y1-y2)/(x1-x2);
    k= y_value - M*x_value;

    #if(DBG==1)
    printf("m = %f\n",M);
    printf("k = %f\n",k);
    printf("k= y_value - M*x_value;\n");
    printf("%f-%f*%f=%f\n",y_value,M,x_value,k);
    #endif

    int F = observe_x - (1/M)*observe_y + (k/M);

    if(F>0){
        return(1);
    }else if(F<0){
        return(-1);
    }
}




int containing_list[memory];//1,2,...
int position(int point_number){
    int total_containing_count = 0;
    for(int i=0;i<memory;i++){
        containing_list[i]=0;
    }


    float point_position_x = point_x[point_number];
    float point_position_y = point_y[point_number];

    for(int figure_number = 1; figure_number<=figure_count; figure_number++){

        if(figure_type[figure_number] == 1){//=====================================rectangle
            if(rectangle_TL_x[rectangles_including[figure_number]]<point_position_x && point_position_x<rectangle_DR_x[rectangles_including[figure_number]]
            &&
            rectangle_DR_y[rectangles_including[figure_number]]<point_position_y && point_position_y<rectangle_TL_y[rectangles_including[figure_number]]){
                total_containing_count++;
                containing_list[total_containing_count]=figure_number;
            }

        }else if(figure_type[figure_number] == 2){//==============================circle
            float sqrt_distance_x = (circle_x[circles_including[figure_number]]-point_position_x)*(circle_x[circles_including[figure_number]]-point_position_x);
            float sqrt_distance_y = (circle_y[circles_including[figure_number]]-point_position_y)*(circle_y[circles_including[figure_number]]-point_position_y);
            float sqrt_radius = radius[circles_including[figure_number]]*radius[circles_including[figure_number]];

            if(sqrt_distance_x+sqrt_distance_y<sqrt_radius){
                    //printf("%d+%d>%d\n",sqrt_distance_x,sqrt_distance_y,sqrt_radius);
                    total_containing_count++;
                    containing_list[total_containing_count]=figure_number;
                }

        }else if(figure_type[figure_number] == 3){//==============================tryangle

            float top_x = get_tryangles_point_XY(figure_number,'X','T');
            float top_y = get_tryangles_point_XY(figure_number,'Y','T');
            float right_x = get_tryangles_point_XY(figure_number,'X','R');
            float right_y = get_tryangles_point_XY(figure_number,'Y','R');
            float left_x = get_tryangles_point_XY(figure_number,'X','L');
            float left_y = get_tryangles_point_XY(figure_number,'Y','L');

            int point_in_V = 0;
            int point_fully_in = 0;

            if(liner_value(top_x,top_y,left_x,left_y,point_position_x,point_position_y)>0
             && liner_value(top_x,top_y,right_x,right_y,point_position_x,point_position_y)<0
            ){point_in_V=1;}

            if(liner_value(left_x,left_y,right_x,right_y,point_position_x,point_position_y)>0
             && M<0){point_fully_in=1;}
            if(liner_value(left_x,left_y,right_x,right_y,point_position_x,point_position_y)<0
             && M>0){point_fully_in=1;}

             if(point_in_V == 1 &&point_fully_in == 1){
                    total_containing_count++;
                    containing_list[total_containing_count]=figure_number;
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
        raw_tryangle_ax[clear] = 0;
        raw_tryangle_ay[clear] = 0;
        raw_tryangle_bx[clear] = 0;
        raw_tryangle_by[clear] = 0;
        raw_tryangle_cx[clear] = 0;
        raw_tryangle_cy[clear] = 0;
        point_x[clear] = 0;
        point_y[clear] = 0;
        figure_type[clear] = 0;
        rectangles_including[clear] = 0;
        circles_including[clear] = 0;
        tryangles_including[clear] = 0;
        containing_list[clear] = 0;
    }
//===========================================================reading in
    int read_in_status=0;   //separate * or r or c or t from float
    int fill_in_sequence = 0;
    int state = 4;    //0 stop ; 1 r ; 2 c ; 3 t ; 4 default

    rectangles_including[0]=0;
    circles_including[0]=0;

    do{
        if(read_in_status == 0){      //first letter
            int read_char = getchar();
            if(read_char=='*'){//========================================

                state=0;

            }else if(read_char=='r'){//========================================

                figure_count++;
                figure_type[figure_count] = 1;

                rectangles_including[figure_count] = rectangles_including[figure_count-1]+1;// <---
                circles_including[figure_count] = circles_including[figure_count-1];
                tryangles_including[figure_count] = tryangles_including[figure_count-1];

                state = 1;
                fill_in_sequence = 0;     //0,1,2,3 for rectangle
                read_in_status=1;

            }else if(read_char=='c'){//========================================

                figure_count++;
                figure_type[figure_count] = 2;

                rectangles_including[figure_count] = rectangles_including[figure_count-1];
                circles_including[figure_count] = circles_including[figure_count-1]+1;      // <---
                tryangles_including[figure_count] = tryangles_including[figure_count-1];

                state = 2;
                fill_in_sequence = 0;     //0,1,2 for circle
                read_in_status=1;

            }else if(read_char=='t'){//========================================

                figure_count++;
                figure_type[figure_count] = 3;

                rectangles_including[figure_count] = rectangles_including[figure_count-1]+1;
                circles_including[figure_count] = circles_including[figure_count-1];
                tryangles_including[figure_count] = tryangles_including[figure_count-1]+1;      // <---
                state = 3;
                fill_in_sequence = 0;     //0,1,2,3,4,5 for tryangles
                read_in_status=1;

            }
        }else{                                            //numbers
            float figure_read_in;
            scanf("%f",&figure_read_in);

            if(state == 1){//====================================================

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

            }else if(state == 2){//====================================================

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

            }else if(state == 3){//====================================================

                switch(fill_in_sequence){
                case 0:
                    raw_tryangle_ax[tryangles_including[figure_count]] = figure_read_in;
                    break;
                case 1:
                    raw_tryangle_ay[tryangles_including[figure_count]] = figure_read_in;
                    break;
                case 2:
                    raw_tryangle_bx[tryangles_including[figure_count]] = figure_read_in;
                    break;
                case 3:
                    raw_tryangle_by[tryangles_including[figure_count]] = figure_read_in;
                    break;
                case 4:
                    raw_tryangle_cx[tryangles_including[figure_count]] = figure_read_in;
                    break;
                case 5:
                    raw_tryangle_cy[tryangles_including[figure_count]] = figure_read_in;

                    read_in_status = 0;
                    break;
                }

                fill_in_sequence++;

            }
        }
    }while(state != 0);

#if(DBG==1)
    for(int i=1;i<=rectangles_including[figure_count];i++){
        printf("Rectangle %d: (%f,%f) to (%f,%f)\n",
               i,rectangle_TL_x[i],rectangle_TL_y[i],rectangle_DR_x[i],rectangle_DR_y[i]);
    }

    for(int i=1;i<=circles_including[figure_count];i++){
        printf("Circle %d: O(%f,%f), r= %f\n",
               i,circle_x[i],circle_y[i],radius[i]);
    }

    for(int i=1;i<=tryangles_including[figure_count];i++){
        printf("Tryangle %d: A(%f,%f),B(%f,%f),C(%f,%f)\n",
               i,raw_tryangle_ax[i],raw_tryangle_ay[i],raw_tryangle_bx[i],
               raw_tryangle_by[i],raw_tryangle_cx[i],raw_tryangle_cy[i]);
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
