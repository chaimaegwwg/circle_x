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
    double new_x = 0;
    double new_z = 0;
    double s_center_x = 0,s_center_y = 0,s_center_z = 0;
    int camera_x = 0,camera_y=0,camera_z = 20;
    int R = 9, focal = 20;
    char **tmp;
    double tube_radius = 1.5;
    double x_prim = 0, y_prim = 0, z_prim=0,x_p=0 ,y_p = 0, z_p = 0;
    int screen_x = 0,screen_y=0;
    double sin_prim = 0;
    double cos_prim = 0;
    int center_x, center_y, r,old_screen_x=0,old_screen_y=0;
    double i ,j,e;
    double d = 0;
    double distanc_a,distanc_b,center;
    int x=0,y=0;
    double marker_angle_degrees = 0;
    marker_angle_degrees = marker_angle_degrees * (M_PI / 180.0);
    double s = sin(marker_angle_degrees);
    double c = cos(marker_angle_degrees);
    double angle_a = 0, angle_b = 0,angle=0;
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
    if (new_arr == NULL)
    return;
    int z = 0;
    int r_c = 0;
    int row = 0;
    int col = 0;
    // char *character = malloc(sizeof(char)*5);
    
    char character[] = {'#','-','.','~','*'};
    // char **temp;
    char marker = '|';
    int place_marker = 0 ;
    marker_angle_degrees = 0;
    double theta = 0;
    row = 0;
    col = 0;
    double **buffer_z = malloc(sizeof(double*)*w.ws_row);
    if (buffer_z == NULL)
    return;
    while(row < w.ws_row)
    {
        // printf("%d here\n",row);
        col = 0;
        arr[row] = malloc(sizeof(char)*w.ws_col);
        buffer_z[row] = malloc(sizeof(double)*w.ws_col);
        while(col < w.ws_col)
        {
            arr[row][col]= ' ';
            
            buffer_z[row][col]= 0;   
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
    i = -r,
    j = -r_c,
    distanc_a=0,
    distanc_b = 0;
    double r_local=0;
 
    angle = 0;
    double frame_angle = 0.0;
    double x1,y1,z1;
    while(1)
    {
    
        for(row = 0; row < w.ws_row; row++)
        {
            for(col = 0; col < w.ws_col; col++)
            {
                arr[row][col] = ' ';
                buffer_z[row][col] = 99999;

            }
        }
        x=0;
        y=0;
        center_x = d_x;
        center_y = d_y;
        r = radius+center_x;
        r_c = radius+center_y;
        
        angle=0;
        
        while(angle <= 2*M_PI)
        {
            s_center_x =R*cos(angle);
            s_center_y = R*sin(angle);
            r = R;
            r_c = R;
            i = -r,
            j = -r_c,
            distanc_a=0,
            distanc_b = 0;
            while (i <= r)
            {

                
                for(e = -r_c; e <= r_c; e++)
                {
                    // distanc_a = i + s_center_x ;
                    // distanc_b = j +s_center_y;
                    // dz = e +s_center_z;
                    distanc_a = (R + i) * cos(angle);
                    distanc_b = (R + i) * sin(angle);
                    dz        = e;
                    d = sqrt(i*i + e*e);
                         
                    x1 = distanc_a; 
                    y1 = distanc_b * cos(angle_a) - dz * sin(angle_a);
                    z1 = distanc_b * sin(angle_a) + dz * cos(angle_a);
                    
                    
                    x_prim = x1 * cos(angle_b) - y1 * sin(angle_b);
                    y_prim = x1 * sin(angle_b) + y1 * cos(angle_b);
                    z_prim = z1;

                    x_p = x_prim + camera_x;
                    y_p = y_prim + camera_y;
                    z_p = z_prim + camera_z;
                    
                    if(z_p <= 0 )
                    {
                        continue;
                    }
                    
                    screen_x = (w.ws_col / 2) + x_p * focal / z_p;
                    screen_y = (w.ws_row / 2) + (y_p * focal / z_p) *0.5;

                    if((screen_x >= w.ws_col) || (screen_y >= w.ws_row) ||( screen_x < 0) || (screen_y < 0))
                    {
                        continue;
                    }
                    // change the form of the donal d - 0.5 < 2.2
                    if(fabs(d - 1.5) < 2.2) 
                    {
                        if (z_p < buffer_z[screen_y][screen_x]) 
                        {
                            buffer_z[screen_y][screen_x] = z_p;
                            arr[screen_y][screen_x] = '.';
                        }
                    }   
                    else
                    {
                        continue;
                    }
                }
                i +=1;
            }
            angle +=0.1;
        }
        
        // {'#','%','*','~','.'};
        printf("\e[H\e[2J\e[3J");
        // printf("\e[H");
        row = 0;
        col = 0;
        while(row < w.ws_row)
        {
            col = 0;
            while(col < w.ws_col)
            {
                // printf("col:%d, row:%d\n",row,col);
                printf("%c",arr[row][col]);
                // printf("%c",arr[row][col]);
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
        // marker_angle_degrees += 1;
        // marker_angle_degrees = (int)marker_angle_degrees %360;
        
        angle_a += 0.04;
        angle_b += 0.02;
        // sleep(1); 
        usleep(30000);
    }
    
}



int main(void)
{
    ft_circle();
    return 0;
}





















