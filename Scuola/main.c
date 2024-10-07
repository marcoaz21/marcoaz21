#include <stdio.h>
#include <stdlib.h>




//------CODA==FINE
//------TESTA==INIZIO

typedef struct Nodo{
    int numero;
    struct Nodo* next;
    struct Nodo* prev;
} Nodo;

typedef struct List{
    Nodo* testa;
    Nodo* coda;
}Lista;

Nodo* creanodo (int numero){
    Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
    nodo->next = NULL;
    nodo->prev = NULL;
    nodo->numero=numero;
    return nodo;
}


//-----------LOGICA--------------

   void inserisci_nodo(Nodo** lista, int valore) {
    Nodo* nuovo_nodo = creanodo(valore);
    if (*lista == NULL) {
        *lista = nuovo_nodo;
        nuovo_nodo->next = *lista; // Collega il nodo a se stesso
    } else {
        Nodo* ultimo_nodo = *lista;
        while (ultimo_nodo->next != *lista) {
            ultimo_nodo = ultimo_nodo->next;
        }
        ultimo_nodo->next = nuovo_nodo;
        nuovo_nodo->next = *lista;
    }
}



Nodo *find (Lista *lista, int valore) 
{
  Nodo *tmp = lista->testa->next;

  while (tmp != NULL) // tmp
  {
    if (tmp->numero == valore) {
      return tmp;
    }
    tmp = tmp->next;
  }

  return NULL;
}

//------------------UI-----------


void clean()
{
    system("clear");
}


void insertTail_ui (Lista*lista)
{
clean();
    int numero;
    printf("Inserisci numero ");
    scanf ("%d", &numero);
    insertTail (numero , lista);
    
}


void insertHead_ui (Lista*lista)
{
    clean();
    int numero;
    printf("Inserisci numero  ");
    scanf ("%d", &numero);
    insertHead (numero , lista);
    
}


void Print(Lista *lista) 
{
  clean();
  Nodo *tmp = lista->testa->next;;

  printf("\n LISTA: ");

  while (tmp != NULL) {
    printf("| %d | ", tmp->numero);
    tmp = tmp->next;
  }

  printf("FINE\n");

}


void find_ui(Lista *lista) 
{
    clean();

  int valore;

  printf("\nChe numero stai cercando?  ");

  scanf("%d", &valore);

  Nodo *ptn = find(lista, valore);

  if (ptn != NULL)
    printf("\n trovato");
  else
    printf("\n non trovato");

}


void delete_ui(Lista *lista )
{
    clean();
  int valore;

  printf("\nChe numero vuoi eliminare?  ");

  scanf("%d", &valore);

  Nodo *ptn = find(lista, valore);

  if (ptn != NULL){
    printf("\n trovato ed eliminato  ");
    free(ptn);
  }
  else
  
    printf("\n non trovato e non eliminato  ");

}


void modify_ui(Lista* lista ){
    
    clean();
    
    int valore;
    int modificato;
    
    printf("Che numero vuoi modificare?  ");
    
    scanf("%d", &valore);

  Nodo *ptn = find(lista, valore);

  if (ptn != NULL){
    printf("\n trovato,come vuoi modificarlo?  ");
    scanf("%d" , &modificato);
    ptn ->numero = modificato;
  }
  else
  
    printf("\n non trovato e non modificato");



}


int menu() {
  int choice;
  printf("\n1- Carica valore in coda \n");
  printf("\n2- Carica valore in testa \n");
  printf("\n3- mostra elenco valori \n");
  printf("\n4- cerca valore \n");
  printf("\n5- elimina valore \n");
  printf("\n6- modifica valore \n");
  printf("\n7- Esci \n\n");
  scanf(" %d", &choice);
  fflush(stdin);
  return choice;
}


int main() {
    
    Lista* lista= (Lista *)malloc(sizeof(Lista));
    Nodo* tmp= creanodo(0);
    lista->testa=tmp;
    lista->coda=tmp;    
    
    int choice;
    
    while (choice != 7) {
    choice = menu();

    switch (choice) {
        
      case 1:
        insertTail_ui(lista);
        break;

      case 2:
        insertHead_ui(lista);
        break;
     
      case 3:
        Print(lista);
        break;
      
      case 4:
        find_ui (lista);
        break;

      case 5:
        delete_ui(lista);
        break;
        
      case 6:
        modify_ui(lista);
        break;
       
    }
  }
  return 0;
}