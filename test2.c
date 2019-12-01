#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char *argv[] ) {
        int i;

        printf( "argc:     %d\n", argc );
        printf( "argv[0]:  %s\n", argv[0] );

        if ( argc == 1 ) {
                printf( "No arguments were passed.\n" );
        } else {
                printf( "Arguments:\n" );

                for ( i = 1; i < argc; ++i ) {
                        printf( "  %d. %s\n", i, argv[i] );
                }
        }
        int a[100];
        int j, temp;
        for (i=0;i<100;i++)
        {
            a[i]=rand();
        }
        for (i=0;i<99;i++)
        {
            for(j=0;j<100-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        printf("sorted array a=\n");
        for(i=0;i<100;i++)
        {
            printf("%d \n", a[i]);
        }


        return 0;
}
