#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

     void initialize_list( char task_file_name[] );
     void update_list( char task_file_name[] );
     void initialize_categories( char categories_file[] );
     void update_categories( char categories_file[] );
     void read_commands( );


    void initialize_list( char task_file_name[] ){

        head_task = (struct task*)malloc(sizeof( struct task));
        head_task->next = NULL;
        FILE *file_pointer = fopen( task_file_name , "r" );
        if( file_pointer != NULL ){
            char line [128];
            char task_name[128];
            char task_category[128];
            int task_priority;
            while ( fgets ( line , sizeof line , file_pointer ) != NULL ){
                strcpy( task_name , line );
                if( fgets ( line , sizeof line , file_pointer ) != NULL ){
                    strcpy( task_category , line );
                }
                if( fgets ( line , sizeof line , file_pointer ) != NULL){
                    task_priority = atoi( line );
                }
                add_task( task_name , task_category , task_priority , head_task );

            }
            fclose ( file_pointer );
        }else{
            printf("Could not initialize list\n");
        }
    }


    void update_list( char task_file_name[] ){
        struct task *iterator = head_task->next;
        FILE *file_pointer = fopen( task_file_name , "w" );
        if( file_pointer != NULL ){
            char priority[2];
            while(iterator->next != NULL){
                fputs( iterator->name , file_pointer );
                fputs( iterator->category , file_pointer );
                itoa( iterator->priority , priority , 10 );
                fputs( priority , file_pointer );
                fputc( '\n' , file_pointer );
                iterator = iterator->next;
            }
                fputs( iterator->name , file_pointer );
                fputs( iterator->category , file_pointer );
                itoa( iterator->priority , priority , 10 );
                fputs( priority , file_pointer );
                fputc( '\n' , file_pointer );

                fclose( file_pointer );
        }else{
            printf( "Could not update list\n" );
        }

    }


    void initialize_categories( char categories_file[] ){
        head_category = (struct categories*)malloc(sizeof(struct categories));
        head_category->next = NULL;
        FILE *file_pointer = fopen( categories_file , "r" );
        if( file_pointer != NULL ){
            char line[128];
            while( fgets ( line , sizeof line , file_pointer ) != NULL ){
                struct categories *new_element = malloc(sizeof(struct categories));
                struct categories *iterator = head_category;
                struct categories *last_element;

                while ( iterator->next != NULL){
                      iterator = iterator->next;
                }
                last_element = iterator;
                last_element->next = new_element;
                strcpy( new_element->name , line);
                new_element->next = NULL;
            }

            fclose( file_pointer );
        }else{
            printf( "Could not initialize categories\n" );
        }
    }


    void update_categories( char categories_file[] ){
        struct categories *iterator = head_category->next;
        FILE *file_pointer = fopen( categories_file , "w" );
        if( file_pointer != NULL ){
            while(iterator->next != NULL){
                fputs( iterator->name , file_pointer );
                iterator = iterator->next;
            }
                fputs( iterator->name , file_pointer );

                fclose( file_pointer );
        }else{
            printf( "Could not update categories\n" );
        }
    }



    void read_commands( ){

            fputs( "To-do list : " , stdout );
            fputs( "Type 't' to enter a task, 'd' to display tasks, " , stdout );
            fputs( "'g' - category ,\n 'p' - priority , " , stdout );
            fputs( "'r' to remove a task and 'x' to exit\n\n\n" , stdout );

            char line [128];
            while ( fgets ( line , sizeof line , stdin ) != NULL ){
                fputc( '\n' , stdout );
                if( strcmp( line , "t\n" ) == 0 ){
                    char task_name[128];
                    char task_category[128];
                    int task_priority;
                    fputs( "\nEnter a task : \n" , stdout );
                    while ( fgets ( line , sizeof line , stdin ) != NULL ){
                        if( strcmp( line , " \n" ) != 0 ){
                            strcpy( task_name , line );
                            fputs( "Task : " , stdout );
                            fputs( task_name , stdout );
                            fputs( "\nEnter a category : \n" , stdout );
                            if( fgets ( line , sizeof line , stdin ) != NULL ){
                                strcpy( task_category , line );
                                fputs( "Category : " , stdout);
                                if( valid_category ( task_category , head_category ) == 0 ){
                                    create_category( task_category , head_category );
                                }
                                fputs( task_category , stdout );
                           }
                            do{
                                fputs( "\nEnter priority of the task(between 1 - 3) : \n" , stdout );
                                if( fgets ( line , sizeof line , stdin ) != NULL ){
                                    task_priority = atoi( line );
                                }
                            }while( 3 < task_priority || 1 > task_priority );
                            fputs( "Priority : " , stdout );
                            fputs( line , stdout );
                            add_task( task_name , task_category , task_priority , head_task );
                       }else{
                           fputs( "\nNot a valid task \n" , stdout );
                           break;
                        }
                        fputs( "\nEnter a task : \n" , stdout );
                    }
                }else if( strcmp( line , "g\n" ) == 0 ){
                    fputs( "Category:\n" , stdout );
                    fputs( "'c' - create category\n" , stdout );
                    fputs( "'e' - delete category\n" , stdout );
                    fputs( "'m' - modify a category\n" , stdout );
                    if( fgets ( line , sizeof line , stdin ) != NULL ){
                        if( strcmp( line , "c\n" ) == 0 ){
                            fputs( "\nEnter the category you wish to create : \n" , stdout );
                            if( fgets ( line , sizeof line , stdin ) != NULL ){
                                //fputs( line , stdout );
                                create_category( line , head_category );
                            }
                        }else if (strcmp( line , "e\n" ) == 0){
                            fputs( "\nEnter the category you wish to delete : \n" , stdout );
                            if( fgets ( line , sizeof line , stdin ) != NULL ){
                                //fputs( line , stdout );
                                delete_category( line , head_category );
                                modify_task_category( line, "-\n" , head_task );
                            }
                        }else if( strcmp( line , "m\n" ) == 0){
                            char category[128];
                            fputs( "\nEnter the category you wish to modify:\n" , stdout );
                            if( fgets ( line , sizeof line , stdin ) != NULL ){
                                strcpy( category , line );
                                //fputs( line , stdout );
                                fputs( "\nChange name into : \n" , stdout );
                                if( fgets ( line , sizeof line , stdin ) != NULL){
                                    //fputs( line , stdout );
                                    modify_category( category , line , head_category );
                                    modify_task_category( category , line , head_task );
                                    fputs( "\nCategory modified\n" , stdout );
                                }

                            }
                        }
                    }
                }else if( strcmp( line , "d\n" ) == 0){
                    fputs( "Display:\n" , stdout );
                    fputs( "'a' - all\n" , stdout );
                    fputs( "'g' - by category\n" , stdout );
                    if( fgets ( line , sizeof line , stdin ) != NULL ){
                        if( strcmp( line , "a\n" ) == 0 ){
                            display_tasks( head_task );
                        }else if( strcmp( line , "g\n" ) == 0){
                            fputs( "\nEnter a valid category : \n" , stdout );
                                if( fgets ( line , sizeof line , stdin ) != NULL ){
                                    if( valid_category( line , head_category ) == 1 ){
                                    display_by_category( line , head_task );
                                   }else{
                                       fputs( "\nNot a valid category\n" , stdout );
                                   }
                                }
                        }
                    }
                }else if( strcmp( line , "p\n" ) == 0 ){
                    fputs( "Priority:\n" , stdout );
                    fputs( "'i' - display increasingly\n" , stdout );
                    fputs( "'d' - display decreasingly\n" , stdout );
                    if( fgets ( line , sizeof line , stdin ) != NULL ){
                        if( strcmp ( line , "i\n" ) == 0 ){
                            display_by_priority( 1 , head_task );
                            display_by_priority( 2 , head_task );
                            display_by_priority( 3 , head_task );
                        }else if( strcmp( line , "d\n" ) == 0){
                            display_by_priority( 3 , head_task );
                            display_by_priority( 2 , head_task );
                            display_by_priority( 1 , head_task );
                        }
                    }
                }else if( strcmp( line , "r\n" ) == 0){
                    fputs( "\nEnter a task to remove :\n" , stdout );
                    if( fgets ( line , sizeof line , stdin ) != NULL ){
                        //fputs( line , stdout );
                        remove_task( line , head_task );
                    }
                }else if( strcmp( line , "x\n" ) == 0){
                    fputs( "\nExit \n" , stdout );
                    break;
                }else{
                    fputs("Enter a valid command \n" , stdout);
                }
                fputs( "\nEnter a command : \n" , stdout );
            }
    }


    int main(){

        initialize_list( "tasks.txt" );

        initialize_categories( "categories.txt" );

        read_commands( );

        update_list( "tasks.txt" );

        update_categories( "categories.txt" );

        return 0;
    }
