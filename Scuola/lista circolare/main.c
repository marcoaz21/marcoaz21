#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} node;

typedef struct list
{
  int counter;
  node *head;
} list;

list *createList()
{
  list *newList = (list *)malloc(sizeof(list));
  if (!newList)
    return NULL;

  newList->counter = 0;
  newList->head = NULL;

  return newList;
}

node *addNodeHead(list *List, int data)
{
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return NULL;

  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (List->head == NULL)
  {
    List->head = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  }
  else
  {
    node *temp = List->head;
    while (temp->next != List->head)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = List->head;
    newNode->prev = temp;
    List->head->prev = newNode;
    List->head = newNode;
  }

  List->counter++;

  return List->head;
}

node *addNodeTail(list *List, int data)
{
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return NULL;

  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (List->head == NULL)
  {
    List->head = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  }
  else
  {
    node *temp = List->head;
    while (temp->next != List->head)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = List->head;
    List->head->prev = newNode;
  }

  List->counter++;

  return List->head;
}

void printList(list *List)
{
  node *current = List->head;
  int i = 0;
  while (current != NULL)
  {
    printf("| ");
    printf("%d |", current->data);
    current = current->next;
    i++;
    if (i > List->counter)
      break;
  }
  printf("\n");
}

void deleteNode(list *List, int valore)
{
  node *current = List->head;
  int i = 1;
  while (current != NULL)
  {
    if (current->data == valore)
      return current;
    current = current->next;

    if (i > List->counter)
      break;
  }
  return NULL;
}

list *find(list *List, int valore)
{
  node *current = List->head;
  int i = 1;
  while (current != NULL)
  {
    if (current->data == valore)
      return current;
    current = current->next;

    if (i > List->counter)
      break;
  }
  return NULL;
}

 void modify(list *List , int old, int new)
 {
 node *current = List->head;
  int i = 1;
  while (current != NULL)
  {
    if (current->data == old)
    {
      current=new;
    }
    current = current->next;

    if (i > List->counter)
      break;
  }
  return NULL;
 }

//-----------UI----------------------------------------------------

void addNodeHead_ui(list *myList)
{
  int valore = 0;
  printf("carica valore in testa -->  ");
  scanf("/d", &valore);
  addNodeHead(myList, valore);
}

void addNodeTail_ui(list *myList)
{
  int valore = 0;
  printf("carica valore in coda -->  ");
  scanf("/d", &valore);
  addNodeTail(myList, valore);
}

void delete_ui(list *myList)
{
  int valore;
  printf("che valore vuoi  eliminare -->  ");
  scanf("%d", &valore);
  deleteNode(myList, valore);
}

void find_ui(list *myList)
{
  clean();

  int valore;

  printf("\nChe numero stai cercando?");

  scanf("%d", &valore);

  list *ptn = find(myList, valore);

  if (ptn != NULL)
    printf("\n trovato");
  else
    printf("\n non trovato");
}

void modify_ui(list* mylist)
{
 int valore;
 int new;

  printf("che valore vuoi modificare -> ");
  scanf("%d", &valore);
  printf("inserisci nuovo valore ->");
  scanf("%d",&new);

  modify(mylist,valore,new);
}

int menu()
{
  int choice;
  printf("\n1- Carica valore in testa \n");
  printf("\n2- Carica valore in coda \n");
  printf("\n3- mostra elenco valori \n");
  printf("\n4- elimina valore \n");
  printf("\n5- modifica valore \n");
  printf("\n6- Esci \n");
  scanf(" %d", &choice);
  fflush(stdin);
  return choice;
}

int main()
{
  list *myList = createList();
  int choice = 0;
  /*addNodeHead(myList, 10);
  addNodeHead(myList, 20);
  addNodeHead(myList, 30);

  addNodeTail(myList, 40);
  addNodeTail(myList, 50);
  addNodeTail(myList, 60);*/

  while (choice != 6)
  {
    choice = menu();

    switch (choice)
    {

    case 1:
      addNodeHead_ui(myList);
      break;

    case 2:
      addNodeTail_ui(myList);
      break;

    case 3:
      printList(myList);
      break;

    case 4:
      delete_ui(myList);
      break;

    case 5:
      find_ui(myList);
      break;

    case 6:
      modify_ui(myList);
      break;
    }
    //printList(myList);

    return 0;
  }
}