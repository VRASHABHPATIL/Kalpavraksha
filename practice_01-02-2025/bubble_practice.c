#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void bubbleSort(Node* head) {
    if (head == NULL) return;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* head = NULL;
    
    push(&head, 64);
    push(&head, 34);
    push(&head, 25);
    push(&head, 12);
    push(&head, 22);
    push(&head, 11);
    push(&head, 90);

    printf("Original Linked List:\n");
    printList(head);
    
    bubbleSort(head);

    printf("Sorted Linked List (Bubble Sort):\n");
    printList(head);

    return 0;
}
