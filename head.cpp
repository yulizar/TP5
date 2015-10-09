#include <iostream>
#include <windows.h>
#include "head.h"

void createList(List &L) {
    L.first = NULL;
    L.last  = NULL;
}

address alokasi (infotype x) {
    address P;
    P = new elmlist;
    P->info =x;
    P->next= NULL;
    P->prev= NULL;
    return P;
}

void inputData (infotype &x) {
    cout<<"Masukkan id barang   : ";cin>>x.id;
    cout<<"Masukkan nama barang : ";cin>>x.nama;
    cout<<"Masukkan total barang: ";cin>>x.total;
    cout<<"Masukkan harga barang: ";cin>>x.harga;
    cout<<endl;
}

void insertFirst(List &L, address P)
{
    if ((L.first != NULL) && (L.last != NULL)) {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
        L.last->next = L.first;
        L.first->prev= L.last;
    }
    else {
        L.first = P;
        L.last  = P;
        prev(P) = L.last;
        next(P) = L.first;
    }
}

void insertData(List &L) {
    address P;
    infotype x;

    cout<<"Masukkan ID yang ingin anda masukkan untuk di cek : ";
    cin>>x.id;
    cout<<"Masukkan nama yang ingin anda masukkan untuk di cek : ";
    cin>>x.nama;
    cout<<endl;
    P = findElm(L,x);
    if (P == NULL) {
        cout<<"Data belum ada "<<endl;
        inputData(x);
        P=alokasi(x);
        insertFirst(L,P);
    }
    else {
        cout<<"Data sudah ada"<<endl;
    }
}

address findElm(List L, infotype x){
    address P = first(L);
    if (L.first == NULL) return NULL;
    do {
        if(Info(P).id == x.id){
            return P;
        }
        P = next(P);
    }while(P != L.first);
    return NULL;
}

void printInfo(List L) {
    address P;
    P = L.first;

    do {
        if (L.first == NULL) break;
        cout<<P->info.id<<endl;
        cout<<P->info.nama<<endl;
        cout<<P->info.total<<endl;
        cout<<P->info.harga<<endl;
        P = next(P);
    } while (P != L.first);
}

void findEkstrim(List &L) {
    int i,j;
    i=0;j=1;
    address P;
    P = L.first;

    do {
        j++;
        if (P->info.total > i) {
            i=P->info.total;
        }
        P= P->next;
    }while (P != L.first);
    cout<<"Nilai ekstrimnya : "<<i<<endl;
}

float countAvg(List &L) {
    address P;
    int i=0, j=0;
    float k;
    P=L.first;

    do {
        j++;
        i= i+ P->info.total;
    }while (P != L.first) ;
    k=i/j;
    return k;
}
