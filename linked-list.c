#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node {
    int infomation;
    struct Node *next;
};

void sortedInsert(struct Node **head_ref, struct Node *new_node) {
    struct Node *current;
    if (*head_ref == NULL || (*head_ref)->infomation >= new_node->infomation) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL &&
               current->next->infomation < new_node->infomation) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *new_node = NULL;
    int input;

    while (scanf("%d", &input),input != -1) {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

        new_node->infomation = input;
        new_node->next = NULL;

        sortedInsert(&head, new_node);
    }
    for(;head; head = head->next){
        printf("%d\n", head->infomation);
    }
    
    return 0;
}