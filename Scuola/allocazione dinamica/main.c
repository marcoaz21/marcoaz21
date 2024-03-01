#include <stdio.h>
#include <stdlib.h>

typedef struct st_struct
{
  int numero;
  struct st_struct *next;
  int trip;
} nodo;

// prototype logic
nodo *insertTail(nodo *list, int valore);
nodo *inserthead(nodo *list, int valore);
int search(int v,nodo *list);

// prototype UI
void carica_testa(nodo *list);
void carica_coda(nodo *list);
void print_list(nodo *list);
void clear();

nodo *insertTail(nodo *list, int valore)
{
  nodo *tmp;

  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = (nodo *)malloc(sizeof(nodo));
  tmp = tmp->next;
  // printf("test2");

  tmp->next = NULL;
  tmp->numero = valore;

  return list;
}

nodo *inserthead(nodo *list, int valore)
{
  nodo *tmp;
  tmp = (nodo *)malloc(sizeof(nodo *));
  tmp->next = valore;

  return tmp;
}

int search(int v,nodo *list)
{
  nodo *tmp = list->next;
 
  int i = 0;
  while (tmp != NULL)
  {
    i++;
    if (tmp == v)
      return i;
    tmp = tmp->next;
  }
  return -1;
}

//-------------------------UI-----------------------------------------------------------------------

void carica_testa(nodo *list)
{
  int num;
  printf("carica un numero ---> ");
  scanf("%d", &num);
  list = inserthead(list, num);
  clear();
}

void carica_coda(nodo *list)
{
  int num;
  printf("carica un numero ---> ");
  scanf("%d", &num);
  list = insertTail(list, num);
  clear();
}
void print_list(nodo *list)
{
  nodo *tmp = list->next;

  while (tmp != NULL)
  {
    printf("%d  ", tmp->numero);

    tmp = tmp->next;
  }
}

void cerca(nodo *list)
{
  nodo *tmp;
  int v;
  int call = 0;
  printf("\nche valore vuoi cercare\n");
  scanf("%d", &v);
  call = search(v);
  if (call != -1)
    printf("il numero %d è alla posizione %d\n",v, call );
  else
    printf("il numero %d non è presente in elenco",v);
}

void clear()
{
  system("clear");
}

int main()
{
  unsigned int scelta;
  nodo *list = (nodo *)malloc(sizeof(nodo));
  list->next = NULL;

  while (scelta != 4)
  {
    printf("\nche operazione vuoi fare?\n");
    printf("1-carica della coda\n");
    printf("2-carica della testa\n");
    printf("3-mostra la lista\n");
    printf("4 cerca nella lista\n");
    scanf("%d", &scelta);
    switch (scelta)
    {
    case 1:
      carica_coda(list);
      break;

    case 2:
      carica_testa(list);
      break;

    case 3:
      print_list(list);
      break;

    case 4:
      cerca(list);
      break;
    }
  }
}