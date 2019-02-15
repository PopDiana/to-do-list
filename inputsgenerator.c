#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    char a[5] = "tgdpr";
    char line[128] , priority[2];
    int random_number , i , j , category_number , command_number , task_number;

    char *randstring( size_t length ){

        static char charset[] = "abcdefghijklmnopqrstuvwxyz";
        char *randomString = NULL;

        if ( length ){
            randomString = malloc( sizeof(char) * (length +1) );

            if ( randomString ){
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
        FILE *file_pointer = fopen( "input.txt" , "w" );
        if(file_pointer != NULL){
            time_t t;
            srand( (unsigned) time(&t) );

            for( i=1 ; i<=50 ; i++ ){
                random_number = rand()%5 + 0;
                fputc( a[ random_number ] , file_pointer );
                fputc( '\n' , file_pointer );
                if( a[ random_number ]=='t' ){
                    for( j=1 ; j<=20 ; j++ ){
                        fputs( randstring(rand()%10 + 5) , file_pointer );
                        fputc( '\n' , file_pointer );
                        category_number = rand()%100 +1;
                        FILE *file_pointer2 = fopen( "categories1.txt" , "r" );
                        if( file_pointer2 != NULL ){
                            while( fgets( line , sizeof line , file_pointer2 ) != NULL && category_number > 0){
                                category_number--;
                            }
                            fclose( file_pointer2 );

                        }
                        fputs( line , file_pointer );
                        itoa( rand()% 3 +1 , priority ,10);
                        fputs( priority , file_pointer );
                        fputc( '\n' , file_pointer );
                    }

                    fputs( " \n" , file_pointer );

                }else if( a[ random_number ] == 'g' ){
                    command_number = rand()% 3 + 1;
                    if( command_number == 1 ){
                        fputc( 'c' , file_pointer );
                        fputc( '\n' , file_pointer );
                        fputs( randstring(rand()%10 + 5) , file_pointer );
                        fputc( '\n' , file_pointer );
                    }else{
                        if( command_number == 2 ){
                            fputc( 'e' , file_pointer );
                            fputc( '\n' , file_pointer );
                            category_number = rand()%100 +1;
                            FILE *file_pointer2 = fopen( "categories1.txt" , "r" );
                            if( file_pointer2 != NULL ){
                                while( fgets( line ,sizeof line , file_pointer2 ) != NULL && category_number > 0){
                                    category_number--;
                                }
                                fclose( file_pointer2 );
                            }
                            fputs( line , file_pointer );

                        }else{
                            fputc( 'm' , file_pointer );
                            fputc( '\n' , file_pointer );
                            category_number = rand()%100 +1;
                            FILE *file_pointer2 = fopen( "categories1.txt" , "r" );
                            if( file_pointer2 != NULL ){
                                while( fgets( line , sizeof line , file_pointer2 ) != NULL && category_number > 0 ){
                                    category_number--;
                                }
                                fclose( file_pointer2 );
                            }
                            fputs( line , file_pointer );
                            fputs( randstring(rand()% 10 +5) , file_pointer );
                            fputc( '\n' , file_pointer );
                        }
                    }

                }else if( a[ random_number ] == 'd' ){
                    command_number = rand()% 2 + 1;

                    if( command_number == 1 ){
                        fputc( 'a' , file_pointer );
                        fputc( '\n' , file_pointer );
                    }else{
                        fputc( 'g' , file_pointer );
                        fputc( '\n' , file_pointer );
                        category_number = rand()%100 +1;
                        FILE *file_pointer2 = fopen( "categories1.txt" , "r" );
                        if( file_pointer2 != NULL ){
                            while( fgets( line , sizeof line , file_pointer2 ) != NULL && category_number > 0 ){
                                category_number--;
                            }
                            fclose( file_pointer2) ;
                        }

                        fputs( line , file_pointer );
                    }

                }else if ( a[random_number] == 'p' ){
                    command_number = rand()% 2 + 1;
                    if( command_number == 1 ){
                        fputc( 'i' , file_pointer );
                    }else{
                        fputc( 'd' , file_pointer );
                    }
                    fputc( '\n' , file_pointer );
                }else if( a[ random_number ] == 'r' ){
                    FILE *file_pointer3 = fopen( "tasks1.txt" , "r" );
                    if( file_pointer3 != NULL ){
                        while( task_number > 0 && fgets( line , sizeof line , file_pointer3 ) != NULL ){
                            task_number--;
                        }
                        fclose( file_pointer3 );
                    }
                    fputs( line , file_pointer );
                }
            }

            fputs( "x\n" , file_pointer );

        }else{
            printf( "Could not generate random inputs.\n" );
        }
        fclose( file_pointer );

        return 0;
    }
