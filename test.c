#include <stdio.h>
int main()
{
    int num = 9;
    while (1)
    {
        printf("%d",num);
        printf("\e[H\e[2J\e[3J");

    }
    return 0;
    
}
// \e[H – home the cursor
// \e[2J – erase the entire screen
// \e[3J – erase saved lines
// getchar();