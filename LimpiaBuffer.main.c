#include <stdio.h>

int main(void)
{
    char res;
    do {
        printf("Si o no? [s/n]: ");
        char buff[255];
        fgets(buff, 255, stdin);
        res = buff[0];
        setbuf(stdin, NULL);
    } while (res == 's' || res == 'S');
    return 0;
}