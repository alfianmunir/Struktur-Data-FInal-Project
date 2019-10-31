#include "dreamingADream.h"



int main()
{
    Resto R;
    ListEdge E;
    firstpramusaji(R) = NULL;
    lastP(R) = NULL;
    firsttamu(R) = NULL;
    lastT(R) = NULL;
    firstE(E) = NULL;
    lastE(E) = NULL;
    createResto(R);
    infotype x, tamus, pramus;
    adrPram P;
    adrTam Q;
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    insertpramusaji(R,x);
//    x = 'sayyid';
//    inserttamu(R,x);
//    x = 'sayyid';
//    inserttamu(R,x);
//    x = 'sayyid';
//    inserttamu(R,x);
//    x = 'sayyid';
//    inserttamu(R,x);
//    x = 'sayyid';
//    inserttamu(R,x);
    int pil;
    while (pil!=0){
        system("CLS");
        cout<<endl;
        cout<<"               Aplikasi Restoran"<<endl;
        cout<<"  =============================================== "<<endl;
        cout<<" 1. Tambah pramusaji."<<endl;
        cout<<" 2. Tambah tamu."<<endl;
        cout<<" 3. Hapus pramusaji."<<endl;
        cout<<" 4. Hapus tamu."<<endl;
        cout<<" 5. Tambah layanan"<<endl;
        cout<<" 6. Daftar pramusaji."<<endl;
        cout<<" 7. Daftar tamu."<<endl;
        cout<<"  =============================================== "<<endl;
        cout<<" 8. Pramusaji teraktif."<<endl;
        cout<<" 9. Pramusaji terpasif."<<endl;
        cout<<" 10. Daftar tamu dari pramusaji tertentu."<<endl;
        cout<<" 11. Tamu yang paling banyak dilayani pramusaji."<<endl;
        cout<<"  =============================================== "<<endl;
        cout<<" 0.  KELUAR"<<endl;
        cout<<"  =============================================== "<<endl;
        cout<<"     Masukan pilihan : ";
        cin>>pil;
        switch (pil){
        case 1 :
            cout<<" Tambahkan Nama Pramusaji : "; cin>>x;
            P = createNewPramusaji(x);
            insertpramusaji(R,P);
            cout<<" Berhasil ditambahkan\n";
            getch();
            break;
        case 2 :
            cout<<" Tambahkan Nama Tamu : "; cin>>x;
            Q = createNewTamu(x);
            inserttamu(R,Q);
            getch();
            break;
        case 3 :
            cout<<" Masukan Nama Pramusaji Yang Akan Dihapus : "; cin>>x;
            P = searchPramusaji(R,x);
            if (Q!=NULL){
                deletepramusaji(R,E,P);
                cout<<" Nama Tamu Pramusaji Dihapus"<<endl;
            } else {
                cout<<" Nama Pramusaji tidak ada"<<endl;}
            getch();
            break;
        case 4 :
            cout<<" Masukan Nama Tamu Yang Akan Dihapus : "; cin>>x;
            Q = searchTamu(R,x);
            if (Q!=NULL){
                deletetamu(R,E,Q);
                cout<<" Nama Tamu Telah Dihapus"<<endl;
            } else {
                cout<<" Nama tamu tidak ada"<<endl;
            }
            getch();
            break;
        case 5 :
            cout<<" DAFTAR PELAYANAN";
            cout<<endl<<"   Pelayan "<<endl;
            printPramusaji(R);
            cout<<endl<<"   Tamu "<<endl;
            printTamu(R);
            cout<<endl<<" Nama Pramusaji : "; cin>>pramus;
            cout<<" Nama Tamu : "; cin>>tamus;
            Melayani(R,E,tamus,pramus);
            cout<<endl<<" Completed"<<endl;
            getch();
            break;
        case 6 :
            cout<<" Nama Pramusaji"<<endl;
            printPramusaji(R);
            getch();
            break;
        case 7 :
            cout<<" Nama Tamu"<<endl;
            printTamu(R);
            getch();
            break;
        case 8 :
            cout<<" Pramusaji Yang Paling Banyak Melayani"<<endl;
            tampilPramusajiAktif(R);
            getch();
            break;
        case 9 :
            cout<<" Pramusaji Yang Paling Sedikit Melayani"<<endl;
            tampilPramusajiPasif(R);
            getch();
            break;
        case 10 :
            cout<<" Masukan Nama Pramusaji : "; cin>>pramus;
            cout<<endl<<" Nama Tamu yang dilayani oleh "<<pramus<<endl;
            tampilTamuPramusaji(R,E,pramus);
            getch();
            break;
        case 11 :
            cout<<" Tamu Yang Paling Banyak Dilayani"<<endl;
            tampilTamuManja(R);
            getch();
            break;
        default :
            cout<<" Masukan Nomor Lain\n";
            getch();
        }
        }
        return 0;
//    case 5 :
//        P = ;
//        cout<<"Pramusaji teraktif adalah "<<info(nama( ))<<endl;
    }


