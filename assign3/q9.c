#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* reverseListIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;
    }
    return prev;
}

struct Node* reverseListRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return rest;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* inputList(int n) {
    struct Node* head = NULL;
    int data;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertNode(head, data);
    }
    return head;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    struct Node* head = inputList(n);

    head = reverseListIterative(head);
    printf("Linked List Reversed Iteratively:\n");
    printList(head);

    head = reverseListRecursive(head);
    printf("Linked List Reversed Recursively:\n");
    printList(head);

    return 0;
}
