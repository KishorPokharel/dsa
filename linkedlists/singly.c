#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* new_node(int data) {
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "[!] failed to allocate memory");
        exit(1);
    }
    node->data = data;
    return node;
}

struct List {
    struct Node* head;
    int length;
};

struct List* new_list() {
    struct Node* head = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL) {
        fprintf(stderr, "[!] failed to allocate memory");
        exit(1);
    }
    struct List* l = (struct List*)malloc(sizeof(struct List));
    l->head = head;
    l->length = 0;
    return l;
}

void prepend(struct List* l, int data) {
    struct Node* new = new_node(data);
    struct Node* second = l->head->next;
    l->head->next = new;  
    new->next = second;
    l->length++;
}

void append(struct List* l, int data) {
    struct Node* new = new_node(data);
    struct Node* current = l->head->next;
    int len = l->length;
    while(len > 1) {
        current = current->next;
        len--;
    }
    current->next = new;
    l->length++;
}

void print_list(struct List* l) {
    int len = l->length;
    struct Node* current = l->head->next;
    printf("[ ");
    while(len > 0) {
        printf("%d ", current->data);
        current = current->next;
        len--; 
    }
    printf("]\n");
}

int length(struct List* l) {
    return l->length;
}

int main() {
    struct List* l = new_list();
    prepend(l, 5);
    prepend(l, 4);
    print_list(l); // should print [ 4 5 ]
    append(l, 6);
    append(l, 7);
    prepend(l, 3);
    prepend(l, 2);
    prepend(l, 1);
    print_list(l); // should print [ 1 2 3 4 5 6 7 ]
    free(l);
    return 0;
}
