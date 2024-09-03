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

int areIdentical(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->data == key) {
            count++;
        }
        head = head->next;
    }
    return count;
}

int haveSameElements(struct Node* head1, struct Node* head2) {
    struct Node* temp = head1;
    while (temp != NULL) {
        if (countOccurrences(head1, temp->data) != countOccurrences(head2, temp->data)) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

struct Node* inputList(int n) {
    struct Node* head = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertNode(head, data);
    }
    return head;
}

int main() {
    int n1, n2, choice;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);
    list1 = inputList(n1);

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);
    list2 = inputList(n2);

    do {
        printf("\nMenu:\n");
        printf("1. Check if both lists are identical (same elements and arrangement)\n");
        printf("2. Check if both lists have the same elements (order doesn't matter)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (areIdentical(list1, list2)) {
                    printf("The lists are identical.\n");
                } else {
                    printf("The lists are not identical.\n");
                }
                break;
            case 2:
                if (haveSameElements(list1, list2)) {
                    printf("The lists have the same elements.\n");
                } else {
                    printf("The lists do not have the same elements.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
