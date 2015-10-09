#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <iostream>
#define next(P) P->next
#define prev(P) P->prev
#define Info(P) P->info
#define first(L) L.first
using namespace std;

struct infotype {
    int id, harga, total;
    string nama;
};

typedef struct elmlist *address;

struct elmlist {
   infotype info;
   address next;
   address prev;
};

struct List {
   address first;
   address last;
};

void createList(List &);
address alokasi (infotype );
void inputData (infotype &);
void insertFirst (List &, address);
void insertData (List &);
address findElm (List , infotype );
void printInfo (List );
void findEkstrim(List &);
float countAvg(List &);

#endif // HEAD_H_INCLUDED
