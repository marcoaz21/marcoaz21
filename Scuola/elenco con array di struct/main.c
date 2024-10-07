/*
COMPLETARE
manca Search
mancano i test per Delete e Search
mancano le funzioni Cerca
manca l'utizzo del Menu con la chiamata alle funzioni corrispondenti

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 30 // lunghezza massima delle stringhe
#define DIM 5  // dimensione massima dell'elenco

typedef struct st_persona
{
    char nome[LEN];
    char cognome[LEN]; // il cognome supponiamolo unico
    unsigned char eta;
    bool occupato; // flag per segnare se il posto è libero o no
} Persona;

// PROTOTYPES (PROTOTIPI DELLE FUNZIONI)
// i prototipi sono le signature (intestazioni) delle funzioni
// definendo i prototipi l'ordine di chiamata delle funzioni non conta più

// --- Funzioni di Logica ---
bool isFull(unsigned dim, Persona elenco[]);
bool Add(unsigned dim, Persona elenco[], Persona nuova);        // inserimento
bool Delete(unsigned dim, Persona elenco[], char cognome[]);    // cancella
Persona Search(unsigned dim, Persona elenco[], char cognome[]); // cercare
// TODO: modificare

// --- FUNZIONI di UI---
void Inserisci(unsigned dim, Persona elenco[]);
void Cancella(unsigned dim, Persona elenco[]);
void Cerca(unsigned dim, Persona elenco[], char cercato[]); // inserimento
void Stampa(unsigned dim, Persona elenco[]);                // visualizzare tutto l'elenco

bool isFull(unsigned dim, Persona elenco[])
{
    for (int i = 0; i < dim; i++)
    {
        if (!elenco[i].occupato)
            return false;
    }

    return true;
}

Persona Search(unsigned dim, Persona elenco[], char cognome[])
{

    for (int i = 0; i < dim; i++)
    {
        //if (elenco->cognome[i] == cognome)
            i == DIM;
    }
}

bool Add(unsigned dim, Persona elenco[], Persona nuova)
{
    if (isFull(dim, elenco))
        return false;

    for (int i = 0; i < dim; i++)
    {
        if (!elenco[i].occupato)
        {
            elenco[i] = nuova;
            elenco[i].occupato = true;
            break;
        }
    }

    return true;
}

bool Delete(unsigned dim, Persona elenco[], char cognome[])
{

    for (int i = 0; i < dim; i++)
    {
        // se l'elemento è libero ed anche se le stringhe sono uguali
        if (elenco[i].occupato && strcmp(elenco[i].cognome, cognome) == 0)
        {
            elenco[i].occupato = false;
            return true; // terminiamo la funzione poichè abbiamo trovato l'elemento
        }
    }

    return false; // NON abbiamo trovato l'elemento quindi la cancellazione è impossibile
}

void Stampa(unsigned dim, Persona elenco[])
{
    for (int i = 0; i < dim; i++)
    {
        if (elenco[i].occupato)
        {
            printf("\n cognome:%s", elenco[i].cognome);
            printf("\n nome:%s", elenco[i].nome);
            printf("\n eta:%d", elenco[i].eta);
            printf("\n============================");
        }
    }
}

void Inserisci(unsigned dim, Persona elenco[])
{
    Persona nuova;

    if (isFull(dim, elenco))
        printf("\n ELENCO PIENO !");
    else
    {
        printf("\n inserire cognome");
        scanf("%s", nuova.cognome);
        printf("\n inserire nome");
        scanf("%s", nuova.nome);
        printf("\n inserire eta");
        scanf("%d", nuova.eta);
        Add(dim, elenco, nuova);
    }
}

void Cancella(unsigned dim, Persona elenco[])
{
    char cognome[LEN];

    printf("\n inserire cognome");
    scanf("%s", cognome);

    if (Delete(dim, elenco, cognome))
    {
        printf("\n Cancellato");
    }
    else
    {
        printf("\n Impossibile cancellare");
    }
}

void Init(unsigned dim, Persona elenco[])
{
    for (int i = 0; i < dim; i++)
    {
        elenco[i].occupato = false;
    }
}

int Menu(unsigned dim, Persona elenco[])
{
    int scelta;

    do
    {

        do
        {
            system("clear"); // sotto windows fare system("cls")
            printf("\n1: Inserisci");
            printf("\n2: Cerca");
            printf("\n3: Cancella");
            printf("\n4: Visualizza elenco");
            printf("\n0: ESCI");

            printf("\n--->");
            scanf("%d", &scelta);
        } while (scelta < 0 || scelta > 4);

        switch (scelta)
        {
        case 1:
            add(dim, elenco);
            break;
        case 2:
            search(dim, elenco);
            break;
        case 3:
            delete (dim, elenco);
            break;
        case 4:
            Stampa(dim, elenco);
            break;
        }
        
    } while (scelta != 0);

    printf("\n\nBYE BYE");
}

void TEST_Add()
{
    Persona elenco[DIM];

    Init(DIM, elenco);

    Persona p;

    strcpy(p.cognome, "Bianchi");
    strcpy(p.nome, "Giacomino");
    p.eta = 17;

    Add(DIM, elenco, p);

    Stampa(DIM, elenco);
}

void TEST_isFull()
{
    Persona elenco[DIM];

    Init(DIM, elenco);

    Persona p;
    for (int i = 0; i < 4; i++)
    {
        strcpy(p.cognome, "Bianchi");
        strcpy(p.nome, "Giacomino");
        p.eta = 5 + i;
        Add(DIM, elenco, p);
    }

    Stampa(DIM, elenco);

    if (isFull(DIM, elenco))
        printf("\n Pieno");
    else
        printf("\n NON pieno");

    strcpy(p.cognome, "Verdi");
    strcpy(p.nome, "Maria");
    p.eta = 60;
    Add(DIM, elenco, p);
    Stampa(DIM, elenco);
    if (isFull(DIM, elenco))
        printf("\n Pieno");
    else
        printf("\n NON pieno");

    /*
    strcpy(p.cognome,"Verdi");
    strcpy(p.nome,"Maria");
    p.eta=62;
    Add(DIM, elenco, p);
    Stampa(DIM, elenco);
    if(isFull(DIM, elenco)) printf("\n Pieno");
    else printf("\n NON pieno");

    strcpy(p.cognome,"Verdi");
    strcpy(p.nome,"Maria");
    p.eta=68;
    Add(DIM, elenco, p);
    Stampa(DIM, elenco);
    if(isFull(DIM, elenco)) printf("\n Pieno");
    else printf("\n NON pieno");
    */
}

void TEST()
{
    // TEST_Add();
    // TEST_isFull();
}

void test_search()
{
    Persona elenco[DIM];
    char cerc[] = "rossi";
    init(DIM, elenco);
    int cont;
    TEST_Add();

    for (int i = 0; i < DIM; i++)
    {
        for (int y = 0; y < LEN; y++)
        {
            if (elenco->cognome[LEN] == cerc)
            {
                cont = LEN;
                y == LEN;
                i == DIM;
            }
        }
    }

    printf("la persona %s è alla posizione %d", cerc, cont);
}




int main()
{
    int scelta;
    Persona elenco[DIM];

    Init(DIM, elenco);

    test_search();

    return 0;
}