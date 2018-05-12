#include <stdio.h>
#include <stdlib.h>

struct node 
{
    char d ;
    struct node * next ;
}
node;

struct node* addnew (struct node* header)
{
    struct node* addnew = malloc(sizeof(node));
    addnew->d = 'k';
    addnew->next = header;
    header = addnew;
    
    return header;
}

void printList(struct node* header)
{
    struct node *current = header;

    while (current != NULL)
    {
        printf("%c\n", current->d);
        current = current->next;
    }
}

int main ()
{
    struct node* header = malloc(sizeof(node));
    struct node* second = malloc(sizeof(node));
    struct node* third = malloc(sizeof(node));

    header->d = 'a';
    header->next = second;

    second->d = 'b';
    second->next = third;

    third->d = 'c';
    third->next = NULL;

    header = addnew(header);
    
    printList(header);
}


