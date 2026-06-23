#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
// What makes a ball look like it's rolling instead of sliding?

void ft_circle()
{
    struct winsize w;
    int d_x = 0;
    int d_y = 0;
    int radius = 5;
    int center_x, center_y, r;
    int i ,j;
    int d = 0;
    int distanc_a,distanc_b,center;
    int x=0,y=0;
    

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
    
    int r_c = 0;
    int row = 0;
    int col = 0;
    // char *character = malloc(sizeof(char)*5);
    
    char character[] = {'#','%','*','~','.'};
    // char temp;
    char marker = '|';
    int place_marker = 0 ;
    // int dev = 5/2;
    int check = 1;
    while(1)
    {
    // printf("------>topp\n");
    // printf("Rows: %d\n", w.ws_row);
    // printf("Columns: %d\n", w.ws_col);
        row = 0;
        col = 0;
        while(row < w.ws_row)
        {
            // printf("%d here\n",row);
            col = 0;
            arr[row] = malloc(sizeof(char)*w.ws_col);
            while(col < w.ws_col)
            {
                // printf("heere raduios:%d\n",col);
                arr[row][col]= ' ';
                col+=1;
            }
            row+=1;
        }
        // printf("nap :%d",r);
        // printf("--->top\n");

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
        // printf("------>now\n");
        // printf("row :%d,col:%d\n",row, col);
        while (i <= r)
        {
            y=0;
            j = -r_c;
            // printf("here");
            // arr[x] = malloc(sizeof(char)*w.ws_col);
            while(j <= r_c)
            {
                distanc_a = i - center_x;
                distanc_b = j - center_y;
                
                
                d = sqrt(pow(distanc_a,2)+pow(distanc_b,2));
                
                // printf("heere-- %d\n",d);
                // printf("i: %d, j: %d\n",i,j);
                // x = radius+center_x+i+center_y;
                // y = radius+center_y+j+center_x;
                x = radius+center_x+i;
                y = radius+center_y+j;
                // printf("x:%d, y:%d\n",x,y);
                // printf("-debug ->->i: %d, j: %d,  x:%d, y:%d\n",i,j,radius+center_x+i+center_y,radius+center_y+j+center_x);
                // printf("-debug ->->i: %d, j: %d,  x:%d, y:%d\n",i,j,x,y);
                // printf("x: %d, y: %d\n",x,y);
                if ((x >= w.ws_row) || (y>= w.ws_col))
                break;
                // ['#','%','*','~','.'];
                // this not correct 
                if(d >= place_marker)
                {
                    arr[x][y] = marker;
                }
                else if((d <= 1) && (j > 0))
                {
                    arr[x][y] = character[3];
                }
                else if ((d <= 3) && (j >= 0))
                {
                    arr[x][y] = character[2];
                }
                else if(d <= 4)
                {
                    arr[x][y] = character[1];
                }
                else if((d <= radius) && (j < 0))
                {
                    arr[x][y] = character[0];
                }
                else if((d <= radius) && (j > 0))
                {
                    arr[x][y] = character[4];
                    // printf("herreeeeeeeeeee :%c\n",character[4]);
                }
                else
                    arr[x][y] = ' ';
                    // printf("dot .> x:%d, y:%d\n",x,y);
                
                // printf("----> x:%d, y:%d\n",x,y);
                    // printf("       "); half of moon
                j+=1;
            }
            printf("\n");
            i +=1;
            x+=1;
        }
        // printf("there is the problem");
        // h = 0;
        // temp = 0;
        // temp = character[0];
        // if(h == 4)
        //     h = 2;
        // if(h+2 == 5)
        // {
        //     character[h] = character[h+1];
        //     h = h+1;
        // }
        // while (h <= 5)
        // {
        //     if(h == 4)
        //         h = 2;
        //     if((h == dev) && (h+2 == 5))
        //         character[h] = character[h+1];
            
        //     h+=1;
        // }
        // printf("------------------------------------>");
        // h = 0;
        // while (h <= 5)
        // {
        //     printf("\nthe prefect %c h:%d\n",character[h],h);
        //     h+=1;
        // }
        
        // printf("here :%c\n",character[0]);
   
        
        
        
        // {'#','%','*','~','.'};
        row = 0;
        col = 0;
        while(row < w.ws_row)
        {
            col = 0;
            while(col < w.ws_col)
            {
                printf("%c",arr[row][col]);
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
        if (place_marker < (radius-1))
        {
            place_marker +=1;
        }
        else
        {
            place_marker = (-radius +1);
    
        }
        printf("\n here --------> place mark: %d",place_marker);
        // else if((place_marker <= radius) && (radius != 0))
        // {
        //     printf("---------->\n");
        //     place_marker -= 1;
        //     check = 0;
        // }

        // printf("\e[H\e[2J\e[3J");
    //     // d_y -= 1;
    //     d_x +=1;

        // free(arr);
        sleep(1); 
    }
    
}



int main(void)
{
    ft_circle();
    return 0;
}




// distanc_a = i - 0;
// distanc_b = j - 0;
// // printf("the distance :%d\n",distanc_a);


// d = sqrt(pow(distanc_a,2)+pow(distanc_b,2));
// if (d <= radius)
//     printf(".");
// else
//     printf(" ");
// if (d <= radius)
//     printf("+");
// else
//     printf("     ");