#include <stdio.h>
#include <stdlib.h>

struct node { char c; struct node *next; };

void print_list(struct node* list){
    int i = 1;
    while (list){
        printf("node %d-- char = %c, next= %s \n", i++, list->c, list->next);
        list=list->next;
    }
}

struct node* insert_front(struct node* list, char new){
    struct node* newlist;
    newlist = malloc(sizeof(struct node));
    newlist->c=new;
    newlist->next=list;
    return newlist;
}

struct node* free_list(struct node* list){
    struct node *origin = list;
    while(list){
        struct node* nextlist= list->next;
        free(list);
        list= nextlist;
    }
    return origin;
}

int main(){ 
    struct node *n1, *n2, *n3, *n4;
    n1 = malloc(sizeof(struct node));
    n2 = malloc(sizeof(struct node));
    n3 = malloc(sizeof(struct node));
    n4 = malloc(sizeof(struct node));
    n1->c = 'R';
    n2->c = 'a';
    n3->c = 'w';
    n4->c = 'r';
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL; 
    print_list(n1);
    print_list( insert_front(n1, '!') );
    print_list( free_list(n1) );
    return 0;
}
