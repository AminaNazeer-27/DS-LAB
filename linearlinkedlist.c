#include<stdio.h>
#include<stdlib.h>

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

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode;
    newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Element %d inserted at the beginning\n", data);
}

void deleteAtBeginning(struct Node** head) {
    struct Node* temp;
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = *head;
    printf("Element %d deleted from the beginning\n", temp->data);
    *head = (*head)->next;
    free(temp);
}

void traverseList(struct Node* head) {
    struct Node* temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Delete from beginning\n");
        printf("3. Traverse list\n");
        printf("4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                deleteAtBeginning(&head);
                break;

            case 3:
                traverseList(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
