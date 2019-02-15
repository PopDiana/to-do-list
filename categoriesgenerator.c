#include <stdio.h>
#include <time.h>
#include <stdlib.h>

    char *randstring( size_t length ){

        static char charset[] = "abcdefghijklmnopqrstuvwxyz";
        char *randomString = NULL;

        if ( length ){
            randomString = malloc( sizeof(char) * (length +1));

            if ( randomString ){
                for ( int n = 0 ; n < length ; n++ ){
                    int key = rand() % (int)(sizeof(charset) -1);
                    randomString[ n ] = charset[ key ];
                }

                randomString[ length ] = '\0';
            }
        }

        return randomString;
    }

    int main(){
        FILE *fp = fopen( "categories.txt" , "w" );
        if( fp != NULL ){
            time_t t;
            srand( (unsigned) time(&t) );
            for( int i = 1 ; i <= 50 ; i++ ){
                fputs( randstring(rand()%5 + 10) , fp );
                fputc( '\n' , fp );
            }
            fclose( fp );
        }else{
            printf( "Could not generate the category list\n" );
        }

        return 0;
    }
