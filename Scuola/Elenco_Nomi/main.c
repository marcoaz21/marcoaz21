#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 5
#define LET 100

typedef struct st_dati
{
 char nome[LET];
 char cognome[LET];
 unsigned int data;
} dati;




//PROTOTYPE UI
int menu();
void load_people(dati per[]); 
void near(dati per[]);
void print_list(dati per[]);
void print_persona(char nome[NAME][LET],  char cognome[NAME][LET], char data[NAME][LET], int i);
void modify(dati per[]);
void delet(dati per[]);
void fine();
//PROTOTYPE LOGIC
int get_free(dati per[]);
int near_item( char item[LET],dati per[]);
int edit_name(char name[LET], char new_name[LET], char new_cognome[LET], unsigned int new_data,dati per[] );
int get_index( char name[LET],dati per[]);
int delete_name( char name[LET],dati per[]);




//--------------------LOGIC------------------------------------

void clear()
{
  system( "clear" );
}

int get_free(dati per[NAME])
{

  for(int i=0; i<NAME; i++)
    {
      if(per[i].nome[0]=='\0') return i;
    }
  return -1; 
}

int near_item(char item[LET],dati per[NAME])
{

  for(int i=0;i<NAME;i++)
    {
      if(strcmp(per[i].nome,item)==0)
        return i;  
    }
  return -1;
}

int edit_name(char name[LET], char new_name[LET], char new_cognome[LET], unsigned int new_data,dati per[NAME])
{

  clear();
  int pos=get_index(name,per);
  if(pos!=-1)
  {
    strcpy(per[pos].nome,new_name);
    strcpy(per[pos].cognome,new_cognome);
  }

  return 0;
}


int get_index(char name[LET],dati per[NAME])
{

  for(int i=0;i<NAME;i++)
    {
      if(strcmp(per[i].nome,name)==0)return i;
    }
  return -1;
}

int delete_name(char name[LET],dati per[NAME])
{

  clear();
  int pos=get_index(name,per);
 if(pos!=-1) 
    per[pos].nome[0]='\0';
      per[pos].cognome[0]='\0';
        per[pos].data='\0';

   return pos;
}

//------------UI---------------------



int menu()
{
  int choice;
    printf("1- Carica persona \n");
    printf("2- elimina persona \n");
    printf("3- modifica persona \n");
    printf("4- mostra elenco persone \n");
    printf("5- cerca un persona nell'elenco \n");
    printf("6- Esci \n");
    scanf(" %d", &choice );
    fflush(stdin);
    return choice;
  }

void load_people(dati per[NAME])
{
  //dati per = (*per);
  clear();
  int pos=get_free(per);
  if(pos!=-1)
  {

  printf("inserisci il nome: \n");
  scanf("%s",per[pos].nome);

    printf("inserisci il cognome: \n");
    scanf("%s",per[pos].cognome);

      printf("inserisci l'età: \n");
      scanf("%d",&per[pos].data);

    //print_persona(per.nome, per.cognome, per.data, pos);
    fflush(stdin); 

  }

}
 void near(dati per[NAME])
{

  clear();
    char item[LET];
    printf("che nome stai cercando?: ");
    scanf(" %s", item);
    fflush(stdin);
    int found = near_item(item,per);
    if(found != -1)
      printf("il nome %s sta nella posizione %d \n", item, found+1);
    if(found == -1)
    {
      printf("il nome %s non è presente nell'elenco \n",item);
    } 
  }



void print_list(dati per[NAME])
{
  //dati per = (*per);

    clear();
    for(int i=0; i<NAME; i++)
      {
        if(per[i].nome[0] != '\0')
        {
            printf("%s-", per[i].nome);
            printf("%s-", per[i].cognome);
            printf("%d-\n", per[i].data);
        }
      }

  }

void modify(dati per[NAME])
{

  clear();
  char name[LET];
  char new_name[LET];
  char new_cognome[LET];
  int new_data;
  printf("che persona vuoi modificare? \n");
  scanf("%s",name);
  fflush(stdin);
    printf("inserisci il nuovo nome \n");
    scanf("%s",new_name);
      printf("inserisci il nuovo cognome \n");
      scanf("%s",new_cognome);
        printf("inserisci l'età \n");
        scanf("%s",new_data);
  fflush(stdin);
  edit_name(name,new_name,new_cognome,new_data, per);
  printf("il nome è stato modificato \n");
}

void delet(dati per[NAME])
{
  clear();
   char name[LET];
  printf("inserisci il nome da eliminare \n");
  scanf("%s",name);
  fflush(stdin);
  int call=delete_name(name,per);
  printf("il nome è stato eliminato \n");
}

void fine()
{
  printf("programma terminato");
}

int main()
{
  dati per[NAME];
  for(int i=0; i<NAME; i++)
       {
           per[i].nome[0]='\0';
           per[i].cognome[0]='\0';
           per[i].data='\0';
       }

    int choice;
  while(choice!=NAME+1)
  {
    choice=menu();

      switch(choice)
      { 
        case 1: 
          load_people(per);
          break;

        case 2:
          delet(per);
          break;

        case 3:
          modify(per);
          break;

        case 4:
         print_list(per);
          break;

        case 5:
          near(per);
          break;

        case 6:
          fine();
          break;
      }
  }

  return 0;
}