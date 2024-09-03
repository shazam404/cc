#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
    }
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 0) {
        insertAtFront(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
        if (temp == *head) {
            printf("Position out of range!\n");
            free(newNode);
            return;
        }
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == *head) {  
        free(temp);
        *head = NULL;
    } else {
        struct Node* tail = (*head)->prev;
        *head = (*head)->next;
        (*head)->prev = tail;
        tail->next = *head;
        free(temp);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* tail = (*head)->prev;
    if (tail == *head) {  
        free(tail);
        *head = NULL;
    } else {
        struct Node* newTail = tail->prev;
        newTail->next = *head;
        (*head)->prev = newTail;
        free(tail);
    }
}

void deleteAtPosition(struct Node** head, int position) {
    if (position < 0 || *head == NULL) {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (position == 0) {
        deleteAtFront(head);
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
        if (temp == *head) {
            printf("Position out of range!\n");
            return;
        }
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (*head == temp) {
        *head = temp->next;
    }
    free(temp);
}

void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at front\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Traverse the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtFront(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                printf("List elements: ");
                traverseList(head);
                break;
            case 8:
                while (head != NULL) {
                    deleteAtFront(&head);
                }
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
