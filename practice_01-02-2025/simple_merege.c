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

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

void split(Node* head, Node** left, Node** right) {
    Node* fast = head->next;
    Node* slow = head;

    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** head_ref) {
    Node* head = *head_ref;
    if (!head || !head->next) return;

    Node* left;
    Node* right;

    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *head_ref = merge(left, right);
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

    mergeSort(&head);

    printf("Sorted Linked List (Merge Sort):\n");
    printList(head);

    return 0;
}
