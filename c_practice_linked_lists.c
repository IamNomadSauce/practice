#include <stdio.h>
#include <stdlib.h>

struct Trend {
  struct Trend* trendstart;
};

// void swap(int* a, int* b) {
//   printf("A |%d|\n",*a);
//   int tmp = *b;
//   // printf("\ntmp |%d|\n", tmp);
//   *b = *a;
//   // printf("\nB |%d|\n", *b);
//   *a = tmp;
//   // printf("\nA |%d|\n", *a);
// }
//
// int main() {
//   int x = 5, y = 10;
//   printf("Before: x = %d, y = %d\n", x, y);
//   swap(&x, &y);
//   printf("After: x = %d, y = %d\n", x, y);
//   return 0;
// }

struct Node {
  int data;
  struct Node* next;
};


void printList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void prepend(struct Node** head, int value) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = *head;
  *head = newNode;
}

void append(struct Node** head, int value) {
  // printf("node %d\n", value);
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  struct Node* current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
}

void deleteByValue(struct Node** head, int value) {

  struct Node* current = *head;
  printf("current %d\nNext %d\n", current->data, ++current->data);
  while (current != NULL) {
    printf("val %d\n", current->data);
    if (current->data == value) {
      printf("Found Value! %d\n", value);

      // return;
    }
    current = current->next;
  }
}

int main() {
  struct Node* head = NULL;
  // prepend(&head, 1);
  // prepend(&head, 2);
  // prepend(&head, 3);
  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 5);
  append(&head, 7);
  append(&head, 8);
  append(&head, 3);
  append(&head, 0);
  printList(head);

  deleteByValue(&head, 2);

  return 0;
}

