#include "dreamingADream.h"

void createResto (Resto &R){
    firstpramusaji(R) = NULL;
    firsttamu(R) = NULL;
    lastP(R) = NULL;
    lastT(R) = NULL;
}

adrEdge createEdge(infotype tam, infotype pra){
    return NULL;
}
adrPram createNewPramusaji(infotype x){
    adrPram P = new pramusaji;
    nama(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    jmltamu(P) = 0;
    tamnya(P) = NULL;

    return P;
}

adrTam createNewTamu(infotype x){
    adrTam P = new tamu;
    nama(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    jmlpram(P) = 0;
    pramnya(P) = NULL;

    return P;
}

void insertpramusaji(Resto &R, adrPram x){
    if(firstpramusaji(R) == NULL){
        firstpramusaji(R) = x;
        lastP(R) = x;
    } else {
//        next(lastP(R)) = x;
//        prev(x) = lastP(R);
//        lastP(R) = x;
        next(x) = firstpramusaji(R);
        prev(firstpramusaji(R)) = x;
        firstpramusaji(R) = x;
    }
}

void inserttamu(Resto &R, adrTam x){
    if(firsttamu(R) == NULL){
        firsttamu(R) = x;
        lastT(R) = x;
    } else {
//        next(lastT(R)) = x;
//        prev(x) = lastT(R);
//        lastT(R) = x;
        next(x)= firsttamu(R);
        prev(firsttamu(R)) = x;
        firsttamu(R) = x;
    }
}

void Melayani(Resto &R, ListEdge &E, infotype tamu, infotype pram){
    adrEdge P = new edge;
    adrPram Q = searchPramusaji(R,pram);
    adrTam T = searchTamu(R,tamu );
    next(P) = NULL;
    prams(P) = Q;
    tams(P) = T;
    if (jmlpram(T)<3){
         if (firstE(E)==NULL){
            firstE(E) = P;
            jmlpram(T) = jmlpram(T) + 1;
            jmltamu(Q) = jmltamu(Q) + 1;
        } else {
            next(P) = firstE(E);
            firstE(E) = P;
            jmlpram(T) = jmlpram(T) +1;
            jmltamu(Q) = jmltamu(Q) +1;
        }
    } else {
        cout<<" Sorry the guest has reached the maximum number of serve"<<endl;
    }

}

void deleteEdgeP(ListEdge &E, adrEdge P){
    adrEdge x;
    if (P == firstE(E)){
        firstE(E) = next(P);
        next(P) = NULL;
        prams(P) = NULL;
        jmlpram(tams(P)) = jmlpram(tams(P))-1;
        tams(P) = NULL;
    } else if (firstE(E)==lastE(E)){
        jmlpram(tams(P)) = jmlpram(tams(P))-1;
        tams(P) = NULL;
        firstE(E) = NULL;
        lastE(E) = NULL;
    } else if (P == lastE(E)){
        x = firstE(E);
        while (next(next(x))!=NULL){
            x = next(x);
        }
        next(x) = NULL;
        lastE(E) = x;
        prams(P) = NULL;
        jmlpram(tams(P)) = jmlpram(tams(P))-1;
        tams(P) = NULL;
    } else {
        x = firstE(E);
        while (next(x)!=P){
            x = next(x);
        }
        next(x) = next(P);
        prams(P) = NULL;
        jmlpram(tams(P)) = jmlpram(tams(P))-1;
        tams(P) = NULL;
    }
}

void deleteEdgeT(ListEdge &E, adrEdge P){
    adrEdge x;
    if (P == firstE(E)){
        firstE(E) = next(P);
        next(P) = NULL;
        tams(P) = NULL;
        jmltamu(prams(P))=jmltamu(prams(P))-1;
        prams(P) = NULL;
    } else if (firstE(E)==lastE(E)){
        jmltamu(prams(P)) = jmltamu(prams(P))-1;
        prams(P) = NULL;
        firstE(E) = NULL;
        lastE(E) = NULL;
    } else if (P == lastE(E)){
        x = firstE(E);
        while (next(next(x))!=NULL){
            x = next(x);
        }
        next(x) = NULL;
        lastE(E) = x;
        tams(P) = NULL;
        jmltamu(prams(P))=jmltamu(prams(P))-1;
        prams(P) = NULL;
    } else {
        x = firstE(E);
        while (next(x)!=P){
            x = next(x);
        }
        next(x) = next(P);
        tams(P) = NULL;
        jmltamu(prams(P))=jmltamu(prams(P))-1;
        prams(P) = NULL;
    }
}

void deletepramusaji(Resto &R, ListEdge &E, adrPram &x){
    adrEdge P;
    if(firstpramusaji(R) == NULL){
        cout<<" Tidak ada pramusaji"<<endl;
    }else if (firstpramusaji(R)==lastP(R)){
        firstpramusaji(R) = NULL;
        lastP(R) = NULL;
    } else if(firstpramusaji(R)== x){
        P = firstE(E);
        if (P != NULL){
            while (P!=NULL){
                if (prams(P) == x){
                    deleteEdgeP(E,P);
                }
                P = next(P);
            }
        }
        firstpramusaji(R) = next(x);
        prev(firstpramusaji(R)) = NULL;
        next(x) = NULL;
    } else if(x==lastP(R)){
        P = firstE(E);
        if (P != NULL){
            while (P!=NULL){
                if (prams(P) == x){
                    deleteEdgeP(E,P);
                }
                P = next(P);
            }
        }
        next(prev(x)) = NULL;
        lastP(R) = prev(x);
        prev(x) = NULL;
    } else {
        P = firstE(E);
        if (P != NULL){
            while (P!=NULL){
                if (prams(P) == x){
                    deleteEdgeP(E,P);
                }
                P = next(P);
            }
        }
        next(prev(x)) = next(x);
        prev(next(x)) = prev(x);
        next(x) =NULL;
        prev(x) =NULL;
    }

}

void deletetamu(Resto &R, ListEdge &E, adrTam &x){
    adrEdge P;
    if(firsttamu(R) == NULL){
        cout<<" Tidak ada tamu"<<endl;
    }else if (firsttamu(R)==lastT(R)){
        firsttamu(R) = NULL;
        lastT(R) = NULL;
    } else if(firsttamu(R) == x){
        P = firstE(E);
        if(P!=NULL){
            while (P!=NULL){
                if (tams(P) == x){
                    deleteEdgeT(E,P);
                }
                P = next(P);
            }
        }
        firsttamu(R) = next(x);
        next(x) = NULL;
        prev(firsttamu(R)) = NULL;
    }else if (lastT(R)==x){
        P = firstE(E);
        if(P!=NULL){
            while (P!=NULL){
                if (tams(P) == x){
                    deleteEdgeT(E,P);
                }
                P = next(P);
            }
        }
        next(prev(x)) = NULL;
        prev(x) = NULL;
        lastT(R) = x;
    }else {
        P = firstE(E);
        if(P!=NULL){
            while (P!=NULL){
                if (tams(P) == x){
                    deleteEdgeT(E,P);
                }
                P = next(P);
            }
        }
        next(prev(x)) = next(x);
        prev(next(x)) = prev(x);
        next(x) =NULL;
        prev(x) =NULL;
    }
}

void printPramusaji(Resto R){
    adrPram P = firstpramusaji(R);
    while (P!=NULL){
        cout<<" - "<<nama(P)<<" melayani : "<<jmltamu(P)<<" tamu"<<endl;
        P = next(P);
    }
}

void printTamu(Resto R){
    adrTam P = firsttamu(R);
    while (P!=NULL){
        cout<<" - "<<nama(P)<<" dilayani : "<<jmlpram(P)<<" pramusaji"<<endl;
        P = next(P);
    }
}

void tampilPramusajiAktif(Resto R){
    int mx = 0;
    adrPram P = firstpramusaji(R);
    while (P != NULL){
        if (jmltamu(P)>mx){
            mx = jmltamu(P);
        }
        P = next(P);
    }
    P = firstpramusaji(R);
    while (P != NULL){
        if (jmltamu(P)==mx){
            cout<<" - "<<nama(P)<<endl;
        }
        P = next(P);
    }
}
void tampilPramusajiPasif(Resto R){
    int mn;
    adrPram P = firstpramusaji(R);
    mn = jmltamu(P);
    while (P != NULL){
        if (jmltamu(P)<mn){
            mn = jmltamu(P);
        }
        P = next(P);
    }
    P = firstpramusaji(R);
    while (P != NULL){
        if (jmltamu(P)==mn){
            cout<<" - "<<nama(P)<<endl;
        }
        P = next(P);
    }
}
void tampilTamuPramusaji(Resto R, ListEdge E, infotype pramus){
    adrPram P = searchPramusaji(R,pramus);
    adrEdge Q = firstE(E);
    while (Q != NULL){
        if (prams(Q)==P){
            cout<<" - "<<nama(tams(Q))<<endl;
        }
        Q = next(Q);
    }
}
void tampilTamuManja(Resto R){
    int mx = 0;
    adrTam P = firsttamu(R);
    while (P != NULL){
        if (jmlpram(P)>mx){
            mx = jmlpram(P);
        }
        P = next(P);
    }
    P = firsttamu(R);
    while (P != NULL){
        if (jmlpram(P)==mx){
            cout<<" - "<<nama(P)<<endl;
        }
        P = next(P);
    }
}

adrPram searchPramusaji(Resto R, infotype x){
    adrPram Q = firstpramusaji(R);
    while(Q != NULL){
        if(nama(Q) == x){
            break;
        }else{
            Q = next(Q);
        }
    }
    return Q;
}

adrTam searchTamu(Resto R, infotype x){
    adrTam Q = firsttamu(R);
    while(Q != NULL){
        if(nama(Q) == x){
            break;
        }else{
            Q = next(Q);
        }
    }
    return Q;
}

