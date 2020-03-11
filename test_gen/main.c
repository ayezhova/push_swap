#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

void make_test(int num)
{
    FILE *fd;
    int i;
    int j;
    int num_array[num];
    int cur;
    int in;
    
    i = 0;
    srand(time(0));
    memset(num_array, -1, num);
    fd = fopen("../test.txt", "w");
    while (i < num)
    {
        j = 0;
        in = 0;
        cur = rand() % (3 * num);
        while (j < i)
        {
            if (num_array[j] == cur)
                in = 1;
            j++;
        }
        if (in == 0)
        {
            fprintf(fd, "%d ", cur);
            i++;
        }
    }
    fclose(fd);
    
}

int main(int ar, char **av)
{
    int num;
    
    if (ar == 1 || atoi(av[1]) == 0 )
    {
        printf("Usage: ./test_gen [num]\n");
        printf("To use with other files, after creating test.txt file: ./swapper -csvn \"$(< test.txt)\"\n");
        return 1;
    }
    num = atoi(av[1]);
    make_test(num);
    return 0;
}