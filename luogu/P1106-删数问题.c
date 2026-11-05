#include <stdio.h>
#include <stdlib.h>

struct Node;
struct Node{
    short data;
    struct Node *next;
};
typedef struct Node Node;

Node* createNode(int value){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    return p;
}

Node* tailInsert(Node *tail, int val){
    Node *newp = createNode(val);
    tail->next = newp;
    return newp;
}

bool delete_one_num(Node *head, int num){
    Node *prev = head;
    Node *cur = head->next;
    while(cur->next!=NULL){
        if(cur->data == num){
            Node *next = cur->next;
            free(cur);
            prev->next=next;
            return true;
        }
        Node *p = cur->next;
        prev = cur;
        cur = p;
    }
    if(cur->data == num){
        prev->next = NULL;
        free(cur);
        return true;
    }
    return false;
}
// 348787 4
Node* delete(Node *cur, int k){
    Node *p = cur->next;
    for(int i=1;i <= k;i++){
        if(cur->data > p->data){
            k -= i;
            cur = p;
            break;
        }
        p = p->next;
    }
    printf("runing 1 time\n");
    if(cur->next != NULL && k != 0) delete(cur->next, k);
    return cur;
}

void printList(Node *head)
{
    Node *p = head->next;
    while(p != NULL)
    {
        printf("%d", p->data);
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
    free(q);
}

int main(void)
{
    Node *head = createNode(0); // 头节点，data无意义
    Node *tail = head;
    char c;
    while((c = getchar()) != '\n' && c != EOF){
        if(c >= '0' && c <= '9') tail = tailInsert(tail, c - '0');
    }
    int k;
    scanf("%d", &k);
    head = delete(head, k);
    printList(head);
    freeList(head);
    return 0;
}