#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node;
struct Node{
    char data[25];
    struct Node *next;
};
typedef struct Node Node;

Node *head_node[101];
int head_node_num=0;

Node* createNode(char word[]){
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->data, word);
    p->next = NULL;
    return p;
}

bool check_a_equal_b(char word_a[], char word_b[]){
    int len_a=strlen(word_a);
    int len_b=strlen(word_b);
    if(len_a != len_b) return false;
    for(int i=0;i < len_a;i++) if(word_a[i] != word_b[i]) return false;
    return true;
}

Node* find_word_p(char word_a[]){
    for(int i=0;i <head_node_num;i++){
        if(check_a_equal_b(word_a, head_node[i]->data)){
            return head_node[i];
        }
        else{
            Node *cur = head_node[i]->next;
            while(cur != NULL && cur != head_node[i]){
                if(check_a_equal_b(cur->data, word_a)){
                    return cur;
                }
                cur = cur->next;
            }
        }
    }
    return NULL;
}

bool tryInsert(char word_a[], char word_b[]){
    Node *a = find_word_p(word_a);
    if(a == NULL) return false;
    if(a->next != NULL) return true;

    Node *b = find_word_p(word_b);
    if(b != NULL){
        a->next = b;
        return true;
    }
    a->next = createNode(word_b);
    return true;
}

Node* get_k_th_word(Node *head, int k){
    int round=0;
    // printf("%s->", head->data);
    Node *p = head->next;
    Node *prev = p;
    while(p != NULL && round <= k)
    {
        round++;
        // printf("%s->", p->data);
        prev = p;
        p = p->next;
    }
    // printf("end\n");
    // printf("last word:%s\n", prev->data);
    return prev;
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
    int t;
    scanf("%d", &t);
    for(int r=1;r <= t;r++){
        head_node_num = 0;
        int relay_time, word_num;
        scanf("%d%d", &relay_time, &word_num);
        relay_time--;
        for(int i=1;i <= word_num;i++){
            char word_a[25], word_b[25];
            scanf("%s%s", &word_a, &word_b);
            if(!tryInsert(word_a, word_b)){
                head_node[head_node_num] = createNode(word_a);
                Node *p = createNode(word_b);
                head_node[head_node_num]->next = p;
                head_node_num++;
            }
        }
        while(getchar() != '\n');
        char line[200];
        fgets(line, sizeof(line), stdin);
        char *word = strtok(line, " \n");
        printf("Case #%d: ", r);
        while(word != NULL){
            Node *p = find_word_p(word);
            if(p != NULL) printf("%s ", get_k_th_word(p, relay_time-1)->data);
            else{
                printf("%s ", word);
            }
            word = strtok(NULL, " \n");
        }
        printf("\n");
    }
    return 0;
}