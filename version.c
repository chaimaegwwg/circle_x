#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
// okay now the mission is rotate
// make arr that have the old data and new 
#define M_PI 3.14159265358979323846
void ft_circle()
{
    struct winsize w;
    int d_x = 0;
    int d_y = 0;
    int radius = 5;
    int coor_x = 0;
    int coor_y = 0;
    int value =0;
    int R = 5;

    int x_prim = 0, y_prim = 0, z_prim=0;
    double sin_prim = 0;
    double cos_prim = 0;
    int center_x, center_y, r;
    int i ,j;
    int d = 0;
    int distanc_a,distanc_b,center;
    int x=0,y=0;
    double marker_angle_degrees = 90.0;
    marker_angle_degrees = marker_angle_degrees * (M_PI / 180.0);
    double s = sin(marker_angle_degrees);
    double c = cos(marker_angle_degrees);

    // char **character = malloc(sizeof(char*)*6);
    // character[0][0] = "#";
    // char *character[7]= ['#','%','*','~','.'];
    // terminal size
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl error");
        return;
    }
    char **arr = malloc(sizeof(char*)*w.ws_row);
    if (arr == NULL)
    return;
    char **new_arr = malloc(sizeof(char*)*w.ws_row);
    if (arr == NULL)
    return;
    int z = 0;
    int r_c = 0;
    int row = 0;
    int col = 0;
    // char *character = malloc(sizeof(char)*5);
    
    char character[] = {'#','-','.','~','*'};
    // char temp;
    char marker = '|';
    int place_marker = 0 ;
    char *temp;
    marker_angle_degrees = 0;
    double theta = 0;
    row = 0;
    col = 0;
    while(row < w.ws_row)
    {
        // printf("%d here\n",row);
        col = 0;
        arr[row] = malloc(sizeof(char)*w.ws_col);
        new_arr[row] = malloc(sizeof(char)*w.ws_col);
        while(col < w.ws_col)
        {
            // printf("heere raduios:%d\n",col);
            arr[row][col]= ' ';
            new_arr[row][col]= ' ';   
            col+=1;
        }
        row+=1;
    }
    x=0;
    y=0;
    center_x = d_x;
    center_y = d_y;
    int center_z = 0;
    int dz = 0;

    r = radius+center_x;
    r_c = radius+center_y;
    // printf("center_x: %d,center_y:%d\n",center_x,center_y);
    i = -r,
    j = -r_c,
    distanc_a=0,
    distanc_b = 0;
    int e =0;
    while (i <= r)
    {

        e = -r_c;
        while (e <= r_c)
        {
            value = pow(r,2)- pow(i,2)-pow(e,2);
            // value = (pow(i,2)+pow(j,2));
            if (value < 0)
            {
                e +=1;
                continue;
            }
            j = sqrt(value);
            distanc_a = i - center_x;
            distanc_b = j - center_y;
            dz = e - center_z;
            
            d = sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
            // R = sqrt(pow(distanc_a, 2)+pow(distanc_b, 2))-pow(dz,2);
            
            x = radius+center_x+i;
            y = radius+center_y+j;
            z = radius + center_z + e;
            
            
            if ((x >= w.ws_row) || (y>= w.ws_col)|| (x >= w.ws_row))
            break;
            if(d <= 1)
            {
                // arr[x][y] = character[3];
                arr[x][y] = character[3];
            }
            else if (d <= 3)
            {
                // arr[x][y] = character[2];
                arr[x][z] = character[2];
            }
            else if(d <= 4)
            {
                // arr[x][y] = character[1];
                arr[x][z] = character[1];
            }
            else if(d <= radius)
            {
                // arr[x][y] = character[0];
                arr[x][z] = character[0];
            }
            else if(d <= radius)
            {
                // arr[x][y] = character[4];
                arr[x][z] = character[4];
                // printf("herreeeeeeeeeee :%c\n",character[4]);
            }
            else
                // arr[x][y] = ' ';
                arr[x][z] = ' ';

            j = -sqrt(value);
            distanc_a = i - center_x;
            distanc_b = j - center_y;
            dz = e - center_z;
            
            d = sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
            // d = -sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
            // d = sqrt(pow(distanc_a, 2)+pow(dz, 2));
            
            x = radius+center_x+i;
            y = radius+center_y+j;
            z = radius + center_z + e;
            
            
            if ((x >= w.ws_row) || (y>= w.ws_col)|| (x >= w.ws_row))
            break;
            if(d <= 1)
            {
                // arr[x][y] = character[3];
                arr[x][z] = character[3];
            }
            else if (d <= 3)
            {
                // arr[x][y] = character[2];
                arr[x][z] = character[2];
            }
            else if(d <= 4)
            {
                // arr[x][y] = character[1];
                arr[x][z] = character[1];
            }
            else if(d <= radius)
            {
                // arr[x][y] = character[4];
                arr[x][z] = character[4];
                // printf("herreeeeeeeeeee :%c\n",character[4]);
            }
            else if(d <= radius)
            {
                // arr[x][y] = character[4];
                arr[x][z] = character[4];
                // printf("herreeeeeeeeeee :%c\n",character[4]);
            }
            else
                // arr[x][y] = ' ';
                arr[x][z] = ' ';
            e +=1;
        }
   
        printf("\n");
        i +=1;
        x+=1;     
    }
    
    

    while(1)
    {

        x=0;
        y=0;
        center_x = d_x;
        center_y = d_y;
        r = radius+center_x;
        r_c = radius+center_y;
        // printf("center_x: %d,center_y:%d\n",center_x,center_y);
        i = -r,
        j = -r_c,
        distanc_a=0,
        distanc_b = 0;
        while (i <= r)
        {
            y=0;
            j = -r_c;
            // printf("here");
            // arr[x] = malloc(sizeof(char)*w.ws_col);
            while(j <= r_c)
            {
                y = 0;
                e = -r_c;
                while(e <= r_c)
                {
                    distanc_a = i - center_x;
                    distanc_b = j - center_y;
                    dz = e - center_z;
                    
                    // d = sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
                    d = sqrt(pow(distanc_a, 2)+pow(dz, 2));
                    
                    x = radius+center_x+i;
                    y = radius+center_y+j;
                    z = radius +center_z+e;
                    
                    // ['#','%','*','~','.'];
                    // theta = atan2(distanc_b,distanc_a);
                    theta = atan2(dz,distanc_a);
                    theta += marker_angle_degrees;
                    x_prim = center_x + (d *cos(theta));
                    z_prim = center_z + (d *sin(theta));
                    // y_prim = center_y + (d *sin(theta));
                    
                    x_prim = radius +center_x+ x_prim;
                    z_prim = radius +center_y + z_prim;
                    if ((x >= w.ws_row) || (z >= w.ws_col)|| (x_prim >= w.ws_row) || (z_prim>= w.ws_col) ||(z_prim < 0)||(x_prim<0))
                    break;
                    new_arr[x_prim][z_prim] = arr[x][z];
                    e +=1;

                }
                j+=1;
            }
            printf("\n");
            i +=1;
            x+=1;
           
        }
        
        // {'#','%','*','~','.'};
        row = 0;
        col = 0;
        while(row < w.ws_row)
        {
            col = 0;
            while(col < w.ws_col)
            {
                printf("%c",new_arr[row][col]);
                col+=1;
            }
            row+=1;
        }
        printf("x: %d, y%d\n",d_x*radius,d_y*radius);
        
        if (((d_y*radius) >= w.ws_col ) || ((d_x*radius) >= w.ws_row) || (d_x*radius < 0) || (d_y *radius< 0))
        {    
            printf("fine\n");
            printf("d_y *radius: %d\n",(d_y *radius));
            printf("Rows: %d\n", w.ws_row);
            printf("Columns: %d\n", w.ws_col);
            exit(0);
        }
        marker_angle_degrees += 1 %360;
        printf("\e[H\e[2J\e[3J");
        sleep(1); 
    }
    
}



int main(void)
{
    ft_circle();
    return 0;
}


//  while (i <= r)
//     {

//         e = -r_c;
//         while (e <= r_c)
//         {
//             value = pow(r,2)- pow(i,2)-pow(e,2);
//             if (value < 0)
//             {
//                 e +=1;
//                 continue;
//             }
            
//             j = sqrt(value);
//             distanc_a = i - center_x;
//             distanc_b = j - center_y;
//             dz = e - center_z;
            
//             d = sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
//             // d = -sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
//             // d = sqrt(pow(distanc_a, 2)+pow(dz, 2));
            
//             x = radius+center_x+i;
//             y = radius+center_y+j;
//             z = radius + center_z + e;
            
            
//             if ((x >= w.ws_row) || (y>= w.ws_col)|| (x >= w.ws_row))
//             break;
//             if(d <= 1)
//             {
//                 // arr[x][y] = character[3];
//                 arr[x][y] = character[3];
//             }
//             else if (d <= 3)
//             {
//                 // arr[x][y] = character[2];
//                 arr[x][z] = character[2];
//             }
//             else if(d <= 4)
//             {
//                 // arr[x][y] = character[1];
//                 arr[x][z] = character[1];
//             }
//             else if(d <= radius)
//             {
//                 // arr[x][y] = character[0];
//                 arr[x][z] = character[0];
//             }
//             else if(d <= radius)
//             {
//                 // arr[x][y] = character[4];
//                 arr[x][z] = character[4];
//                 // printf("herreeeeeeeeeee :%c\n",character[4]);
//             }
//             else
//                 // arr[x][y] = ' ';
//                 arr[x][z] = ' ';

//             j = -sqrt(value);
//             distanc_a = i - center_x;
//             distanc_b = j - center_y;
//             dz = e - center_z;
            
//             d = sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
//             // d = -sqrt(pow(distanc_a, 2)+pow(distanc_b, 2)+pow(dz, 2));
//             // d = sqrt(pow(distanc_a, 2)+pow(dz, 2));
            
//             x = radius+center_x+i;
//             y = radius+center_y+j;
//             z = radius + center_z + e;
            
            
//             if ((x >= w.ws_row) || (y>= w.ws_col)|| (x >= w.ws_row))
//             break;
//             if(d <= 1)
//             {
//                 // arr[x][y] = character[3];
//                 arr[x][z] = character[3];
//             }
//             else if (d <= 3)
//             {
//                 // arr[x][y] = character[2];
//                 arr[x][z] = character[2];
//             }
//             else if(d <= 4)
//             {
//                 // arr[x][y] = character[1];
//                 arr[x][z] = character[1];
//             }
//             else if(d <= radius)
//             {
//                 // arr[x][y] = character[4];
//                 arr[x][z] = character[4];
//                 // printf("herreeeeeeeeeee :%c\n",character[4]);
//             }
//             else if(d <= radius)
//             {
//                 // arr[x][y] = character[4];
//                 arr[x][z] = character[4];
//                 // printf("herreeeeeeeeeee :%c\n",character[4]);
//             }
//             else
//                 // arr[x][y] = ' ';
//                 arr[x][z] = ' ';
//             e +=1;
//         }
   
//         printf("\n");
//         i +=1;
//         x+=1;     
//     }
    
    