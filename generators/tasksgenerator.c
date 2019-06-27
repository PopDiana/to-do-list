#include <stdio.h>
#include <time.h>
#include <stdlib.h>

    char *randstring( size_t length ){

        static char charset[] = "abcdefghijklmnopqrstuvwxyz";
        char *randomString = NULL;

        if ( length ){
            randomString = malloc( sizeof(char) * (length +1) );

            if ( randomString ) {
                for ( int n = 0 ; n < length ; n++ ){
                    int key = rand() % (int)( sizeof(charset) -1 );
                    randomString[ n ] = charset[ key ];
                }

                randomString[ length ] = '\0';
            }
        }

        return randomString;
    }

    int main(){
        FILE *file_pointer1 = fopen( "tasks1.txt" , "w" );

        if( file_pointer1 != NULL ){

            time_t t;
            srand( (unsigned) time(&t) );
            int category_number;
            int i;
            char line[128],priority[2];

            for( i=1 ; i<= 100 ; i++ ){

                fputs( randstring(rand()%10 + 5) , file_pointer1 );
                fputc( '\n' , file_pointer1 );
                category_number = rand()%100 + 1;
                FILE *file_pointer2 = fopen( "categories1.txt" , "r" );

                if( file_pointer2 != NULL ){
                    while( fgets(line , sizeof line , file_pointer2 ) != NULL && category_number > 0 ){
                        category_number--;
                    }
                    fclose( file_pointer2 );
                }
                fputs( line,file_pointer1);

                itoa( rand()% 3 +1 , priority , 10 );
                fputs( priority , file_pointer1 );
                fputc( '\n' , file_pointer1 );

            }
            fclose( file_pointer1 );
        }else{
            printf( "Could not generate the task list\n" );
        }

        return 0;
    }
