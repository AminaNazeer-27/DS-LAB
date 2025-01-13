#include<stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

struct Node* createNode(int data) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   newNode->prev = NULL;
   return newNode;
}

void insertAtBegining(struct Node** head, int data) {
   struct Node* newNode = createNode(data);
   newNode->next = *head;
   if (*head != NULL) {
      (*head)->prev = newNode;
   }
   *head = newNode;
}

void deleteAtBegining(struct Node** head) {
   if (*head == NULL) {
      printf("List is empty\n");
      return;
   }
   struct Node* temp = *head;
   *head = (*head)->next;
   if (*head != NULL) {
      (*head)->prev = NULL;
   }
   free(temp);
}

void printlist(struct Node* head) {
   struct Node* temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main() {
   struct Node* head = NULL;
   int choice, data;

   while (1) {
      printf("\nDoubly LinkedList Operations:\n");
      printf("1. Insert at Beginning\n");
      printf("2. Delete at Beginning\n");
      printf("3. Print List\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            printf("Enter the data to insert at beginning: ");
            scanf("%d", &data);
            insertAtBegining(&head, data);
            break;
         case 2:
            deleteAtBegining(&head);
            break;
         case 3:
            printf("Current List: ");
            printlist(head);
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid Choice. Please try again.\n");
      }
   }
   return 0;
}
