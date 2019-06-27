#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


    void add_task( char task_name[] , char task_category[] , int task_priority , struct task *head_task ){

        struct task *new_element = malloc(sizeof(struct task));

        struct task *iterator = head_task;

        struct task *last_element;


        while ( iterator->next != NULL ) {
            iterator = iterator->next;
        }
        last_element = iterator;
        last_element->next = new_element;
        strcpy( new_element->name , task_name );
        strcpy( new_element->category , task_category );
        new_element->priority = task_priority;
        new_element->next = NULL;
    }


    int valid_category( char category[] , struct categories *head_category ){

        struct categories *iterator = head_category->next;

        while( iterator->next != NULL ){
            if( strcmp( iterator->name , category ) == 0 ){
                return 1;
            }
            iterator = iterator->next;
        }
        if( strcmp( iterator->name , category ) == 0 ){
                return 1;
        }
        return 0;
    }


    void create_category( char category[] , struct categories *head_category ){

        struct categories *new_element = malloc(sizeof(struct categories));

        struct categories *iterator = head_category;

        struct categories *last_element;

        while ( iterator->next != NULL ){
            iterator = iterator->next;
        }
        last_element = iterator;
        last_element->next = new_element;
        strcpy( new_element->name , category );
        new_element->next = NULL;
        fputs ( "\nCategory created\n" , stdout );
    }

    void delete_category( char category[] , struct categories *head_category ){

        struct categories *iterator= head_category;

        struct categories *element = head_category;

        while( iterator->next->next != NULL){
            if( strcmp( iterator->next->name , category ) == 0 ){
                element = iterator->next;
                iterator->next = iterator->next->next;
                free( element );
                fputs ( "\nCategory deleted\n" , stdout );
                return;
            }
            iterator = iterator->next;
        }
        if( strcmp( iterator->next->name , category ) == 0 ){
            element = iterator->next;
            iterator->next = iterator->next->next;
            free( element );
            fputs ("\nCategory deleted\n" , stdout );
            return;
        }
        fputs( "\nCategory does not exist\n" , stdout );
    }


    void modify_category( char category1[] , char category2[] , struct categories *head_category ){

        struct categories *iterator = head_category->next;

        while( iterator->next !=  NULL ){
            if( strcmp( iterator->name , category1 ) == 0 ){
                strcpy( iterator->name , category2);
                break;
            }
            iterator = iterator->next;
        }
        if( strcmp( iterator->name , category1 ) == 0 ){
                strcpy( iterator->name , category2 );

        }
    }


    void modify_task_category( char category1[] , char category2[] , struct task *head_task ){

        struct task *iterator = head_task->next;

        while( iterator->next !=  NULL ){
            if( strcmp( iterator->category , category1 ) == 0 ){
                strcpy( iterator->category , category2 );
            }
            iterator = iterator->next;
        }
        if( strcmp( iterator->category , category1 ) == 0 ){
                strcpy( iterator->category , category2 );
            }
    }

    void display_tasks( struct task *head_task ){

        struct task *iterator = head_task->next;


            fputs( "\nDisplay all : \n" , stdout );
            fputs( "\nTO-DO LIST : \n" , stdout );
            char priority[2];

            while( iterator->next != NULL ){
                fputs( "\nTo do : " , stdout );
                fputs( iterator->name , stdout );
                fputs( "Category : " , stdout );
                fputs( iterator->category , stdout );
                fputs( "Priority : " , stdout);
                itoa( iterator->priority , priority , 10 );
                fputs( priority , stdout );
                fputc( '\n' , stdout );
                iterator = iterator->next;
            }
                fputs( "\nTo do : " , stdout );
                fputs( iterator->name , stdout );
                fputs( "Category : " , stdout );
                fputs( iterator->category , stdout );
                fputs( "Priority : " , stdout );
                itoa( iterator->priority , priority , 10 );
                fputs( priority , stdout );
                fputc( '\n' , stdout );


    }


    void display_by_category( char category[] , struct task *head_task ){

        struct task *iterator = head_task->next;

            char priority[10];

            fputs( "\nTASKS WITH CATEGORY : ", stdout );
            fputs( category , stdout );
            fputs( "\n\n" , stdout );
            while( iterator->next != NULL ){
                if( strcmp( iterator->category , category ) == 0 ){
                    fputs( "\nTo do : " , stdout );
                    fputs( iterator->name , stdout );
                    itoa( iterator->priority , priority , 10 );
                    fputs( "Priority : " , stdout );
                    fputs( priority , stdout );
                    fputc( '\n' , stdout );
                }
                iterator = iterator->next;
            }
            if( strcmp( iterator->category , category ) == 0 ){
                fputs( "\nTo do : " , stdout );
                fputs( iterator->name , stdout );
                itoa( iterator->priority , priority , 10 );
                fputs( "Priority : " , stdout );
                fputs( priority , stdout );
                fputc( '\n', stdout );
            }

    }


    void display_by_priority( int priority , struct task *head_task ){

        struct task *iterator = head_task->next;

                char P[128];

                fputs( "\nDISPLAY BY PRIORITY: " , stdout );
                itoa( priority , P , 10 );
                fputs( P , stdout );
                while( iterator->next != NULL ){
                    if( iterator->priority == priority ){
                        fputs( "\n\nTask : " , stdout );
                        fputs( iterator->name , stdout );
                        fputs( "Category : " , stdout );
                        fputs( iterator->category , stdout );


                    }
                    iterator = iterator->next;
                }
                if( iterator->priority == priority ){
                    fputs( "\n\nTask : " , stdout );
                    fputs(iterator->name , stdout );
                    fputs( "Category : " , stdout );
                    fputs( iterator->category , stdout );

                }

    }


    void remove_task( char task_name[] , struct task *head_task ){

        struct task *iterator = head_task;

        struct task *element = head_task;

        while( iterator->next->next != NULL ){
            if( strcmp( iterator->next->name , task_name ) == 0 ){
                element = iterator->next;
                iterator->next = iterator->next->next;
                free( element );
                fputs ("\nTask removed\n" , stdout);
                return;
            }
            iterator = iterator->next;
        }
        if(strcmp( iterator->next->name , task_name ) == 0 ){
            element = iterator->next;
            iterator->next = iterator->next->next;
            free( element );
            fputs ("\nTask removed\n" , stdout);
            return;
        }
    }


