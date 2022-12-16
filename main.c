#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int value;
  struct Node *next;
}Node;

typedef struct Chain {
  Node *front;
  Node *rear;
}Chain;

Chain chain;

// Queue
void addNodeToEnd(int);
void deleteNodeFromStart();
void printLinkedListFromTheStart(Node *);
bool isEmpty();

//Menu
void menu(int*);

int main () {

  chain.front = chain.rear = NULL;
  int choice = 0, value = 0, position = 0;
  
  while (true) {
    menu(&choice);

    switch(choice) {
      case 1:
        printf("Enter your value: "), scanf("%d", &value);
    }

    switch (choice) {
      case 0:
        exit(0);
      case 1:
        addNodeToEnd(value);
      break;
      case 2:
        deleteNodeFromStart();
      break;
      case 3: {
        Node *current = chain.front;
        printLinkedListFromTheStart(current);
        printf("\n");
      } break;
      case 4: {
        if (isEmpty()) {
          printf("Your Queue is empty\n");
          break;
        }
        printf("You element in the front is: %d\n", chain.front->value);
      } break;
      case 5: {
        if (isEmpty()) {
          printf("Your Queue is empty\n");
          break;
        }
        printf("You element in the rear is: %d\n", chain.rear->value);
      }break;
      default:
        printf("Wrong choice");
    }
  }
  
  return 0;
}

void menu(int *choice) {
  do {
    printf("0.Exit\n");
    printf("1.Add new node in the tail\n");
    printf("2.Delete node in the head\n");
    printf("3.print the linked list from the start\n");
    printf("4.Get front\n");
    printf("5.Get rear\n");

    printf("> "), scanf("%d", choice);
  } while (!(*choice >= 0 && *choice < 6));
}

void addNodeToEnd(int v) {
  Node *newNode = (Node *) malloc(1);

  newNode->value = v;
  newNode->next = NULL;
  
  if (isEmpty()) {
    chain.front = chain.rear = newNode;
    return;
  }

  chain.rear->next = newNode;
  chain.rear = chain.rear->next;
}

void deleteNodeFromStart() {
  if (isEmpty()) {
    printf("Your linked list is Empty\n");
    return;
  }

  if (chain.front == chain.rear) {
    free(chain.front);
    chain.front = chain.rear = NULL;
    return;
  }
  
  Node *current = chain.front;
  chain.front = chain.front->next;

  free(current);
}

void printLinkedListFromTheStart(Node *current) {
  if (current == NULL) return;

  printf("%d ", current->value);

  printLinkedListFromTheStart(current->next);
}

bool isEmpty() {
  return !(chain.front && chain.rear);
}