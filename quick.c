#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* getTail(struct Node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

struct Node* partition(struct Node* head, struct Node* tail) {
    struct Node* pivot = head;
    struct Node* pre = head;
    struct Node* curr = head;

    while (curr != tail->next) {
        if (curr->data < pivot->data) {
            int temp = curr->data;
            curr->data = pre->next->data;
            pre->next->data = temp;
            pre = pre->next;
        }
        curr = curr->next;
    }
    
    int currData = pivot->data;
    pivot->data = pre->data;
    pre->data = currData;
    
    return pre;
}

void quickSortHelper(struct Node* head, struct Node* tail) {
    if (head == NULL || head == tail) {
        return;
    }
    struct Node* pivot = partition(head, tail);
    quickSortHelper(head, pivot);
    quickSortHelper(pivot->next, tail);
}

struct Node* quickSort(struct Node* head) {
    struct Node* tail = getTail(head);
    quickSortHelper(head, tail);
    return head;
}

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(30);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(20);
    head->next->next->next->next = createNode(5);

    head = quickSort(head);
    printList(head);

    return 0;
}
