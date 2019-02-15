#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

    struct task{

        char category[128];


        int priority;


        char name[128];


        struct task *next;


    };

    struct task *head_task;


    struct categories{

        char name[128];


        struct categories *next;


    };

    struct categories *head_category;


    void add_task( char task_name[] , char task_category[], int task_priority , struct task *head_task );
    int valid_category( char category[] , struct categories *head_category );
    void create_category( char category[] , struct categories *head_category );
    void delete_category( char category[] , struct categories *head_category );
    void modify_category( char category1[], char category2[] , struct categories *head_category );
    void modify_task_category( char category1[] , char category2[] , struct task *head_task );
    void display_tasks( struct task *head_task );
    void display_by_category( char category[] , struct task *head_task );
    void display_by_priority( int priority , struct task *head_task );
    void remove_task( char task_name[] , struct task *head_task );


#endif // FUNCTIONS_H_INCLUDED
