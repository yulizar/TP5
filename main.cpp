#include <iostream>
#include "head.h"
using namespace std;

infotype x;

int main()
{
    address P;
    List L;
    float i;

    createList(L);
    inputData(x);
    P=alokasi(x);
    insertFirst(L,P);

    insertData(L);

    printInfo(L);
    findEkstrim(L);
    i=countAvg(L);
    cout<<"Nilai rata-rata nya adalah : "<<i<<endl;
    return 0;
}
