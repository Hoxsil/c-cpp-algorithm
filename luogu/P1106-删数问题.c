#include <stdio.h>
#include <stdlib.h>

struct Node;
struct Node{
    short data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node Node;

Node* createNode(int value){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void headInsert(Node *head, int val)
{
    Node *newp = createNode(val);
    newp->next = head->next;
    head->next = newp;
}

void printList(Node *head)
{
    Node *p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void freeList(Node *head)
{
    Node *p, *q;
    p = head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
}

int main(void)
{
    Node *head = createNode(0); // 头节点，data无意义
    char c;
    while((c = getchar()) != '\n' && c != EOF){
        printf("%c", c);
        if(c >= '0' && c <= '9') headInsert(head, c - '0');
    }
    printf("\n");
    printList(head);
    freeList(head);
    return 0;
}