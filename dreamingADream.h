#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

#define nama(G) G->nama
#define prev(P) P->prev
#define tamu(E) E->tamu
#define pramusaji(E) E->pramusaji
#define firsttamu(G) G.ListTamu
#define firstpramusaji(G) G.ListPramusaji
#define next(E) E->next
#define lastP(R) R.LastP
#define lastT(N) N.LastT
#define lastE(P) P.LastE
#define jmltamu(R) R->jmltam
#define jmlpram(R) R->jmlpram
#define pramnya(R) R->pramnya
#define tamnya(R) R->tamnya
#define firstE(Q) Q.First
#define prams(P) P->prams
#define tams(P) P->tams

typedef string infotype;
typedef struct tamu *adrTam;
typedef struct pramusaji *adrPram;
typedef struct edge *adrEdge;

struct tamu{
    infotype nama;
    adrTam next;
    adrTam prev;
    int jmlpram;
    adrEdge pramnya;
};

struct pramusaji{
    infotype nama;
    adrPram next;
    adrPram prev;
    int jmltam;
    adrEdge tamnya;
};

struct edge{
    adrPram prams;
    adrTam tams;
    adrEdge next;
};

struct Resto{
    adrPram ListPramusaji;
    adrTam ListTamu;
    adrPram LastP;
    adrTam LastT;

};
struct ListEdge{
    adrEdge First;
    adrEdge LastE;
};

void createResto (Resto &R);
adrEdge createEdge(infotype tam, infotype pra);
adrPram createNewPramusaji(infotype x);
adrTam createNewTamu(infotype x);
void insertpramusaji(Resto &R, adrPram x);
void inserttamu(Resto &R, adrTam x);
void Melayani(Resto &R,ListEdge &E, infotype tamu, infotype pram);
void deleteEdgeP(ListEdge &E, adrEdge P);
void deleteEdgeT(ListEdge &E, adrEdge P);
void deletepramusaji(Resto &R, ListEdge &E,adrPram &x);
void deletetamu(Resto &R, ListEdge &E, adrTam &x);
void printPramusaji(Resto R);
void printTamu(Resto R);
void tampilPramusajiAktif(Resto R);
void tampilPramusajiPasif(Resto R);
void tampilTamuPramusaji(Resto R, ListEdge E, infotype pramus);
void tampilTamuManja(Resto R);
adrPram searchPramusaji(Resto R, infotype x);
adrTam searchTamu(Resto R, infotype x);

