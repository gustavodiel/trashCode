#include <stdio.h>
#include <time.h>

#define as ;while

int main(int argc, char const *argv[])
{

    int x = 10;
    while (x --> 0){
        printf( "oie");
    }
    x = 10;
    while (x --\
                \
                 \
                  \
                   > 0)
     printf("%d ", x);


    x = 10;

    do printf("Oieee\n") as (x --> 0);


    printf("Teste :3");
    printf("\r");
    printf("Teste :3");
    printf("\v");
    printf("Teste :3");
    printf("\r");
    int msec = 0, trigger = 100; /* 10ms */
    clock_t before = clock();
    int total = 10;
    int cnt = 0;
    do {

      clock_t difference = clock() - before;
      msec = difference * 1000 / CLOCKS_PER_SEC;
        if (msec >= trigger){
            msec = 0;
            printf("x");
            cnt ++;
        }

        if (cnt == total)
            break;

    } while ( msec < trigger );
    scanf("%c");
    return 0;
}