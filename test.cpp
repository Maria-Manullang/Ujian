#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;
void gotoxy(int x, int y){
  COORD coord;
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void garis(){
cout<<"====================================================="<<endl;
}

int main()
{
  int x,n,beli[100],jumlah[100],kode[100];
  char *merk[100],uk[100],jawab;
  long total[100], harga[100],diskon,akhir,bayar,kembalian,totally=0;

  do{
    system("cls");

        cout << "Program Penjualan" << endl;
        cout << "Banyak barang di beli\t:";cin>>n;

    for(x=1;x<=n;x++){
        cout<<"\nData ke-"<<x<<endl;
        cout<<"Kode Barang\t\t:";cin>>kode[x];
        cout<<"Ukuran Barang\t\t:";cin>>uk[x];

        if (kode[x]==1){
                merk[x] ="KECAP ABC";
                if(uk[x]=='b'|| uk[x]=='B'){
                    harga[x]=25000;
                }else if(uk[x]=='s'||uk[x]=='S'){
                    harga[x]=15000;
                }else{
                    harga[x]=10000;
                }
            }
            else if (kode[x]==2){
                merk[x] ="Bimoli";
                if(uk[x]=='b'|| uk[x]=='B'){
                    harga[x]=30000;
                }else if(uk[x]=='s'||uk[x]=='S'){
                    harga[x]=20000;
                }else{
                    harga[x]=15000;
                }
            }
             else if (kode[x]==3){
                merk[x] ="Susu Dancow";
                if(uk[x]=='b'|| uk[x]=='B'){
                    harga[x]=85000;
                }else if(uk[x]=='s'||uk[x]=='S'){
                    harga[x]=50000;
                }else{
                    harga[x]=20000;
                }
            }
             else if (kode[x]==4){
                merk[x] ="Vape";
                if(uk[x]=='b'|| uk[x]=='B'){
                    harga[x]=15500;
                }else if(uk[x]=='s'||uk[x]=='S'){
                    harga[x]=10500;
                }else{
                    harga[x]=5000;
                }
            }
            else{
            merk[x]="Error";
            cout<<"\n==Salah Input Kode Barang==" ;
        }

      cout<<"Nama Barang\t\t:"<<merk[x];
      cout<<"\nUkuran \t\t\t:"<<uk[x];
      cout<<"\nHarga \t\t\t:"<<harga[x];
      cout<<"\nJumlah Beli\t\t:";cin>>beli[x];

      //proses
      total[x]=harga[x]*beli[x];
      totally += total[x];
        if(totally>=500000){
            diskon = 150000;
            akhir=totally-diskon;
        }else if(totally>=350000){
            diskon = 100000;
            akhir=totally-diskon;
        }else if(totally>=200000){
            diskon=50000;
            akhir=totally-diskon;
        }else{
            diskon=0;
            akhir=totally;
            }
      cout<<"Total Belanja\t\t:"<<total[x];
      cout <<endl;

        }

    getch();
    system("cls");
    gotoxy(1,1);garis();
    gotoxy(1,2);cout<<"                 Daftar Penjualan";
    gotoxy(1,3);cout<<"                Swalayan Suka Maju    ";
    gotoxy(1,4);garis();
    gotoxy(1,5);cout<<"No   Kode  Nama          Harga   Jumlah   Total";

    gotoxy(1,6);garis();

     for(x=1;x<=n;x++){
        gotoxy(1,6+x);cout<<x;
        gotoxy(6,6+x);cout<<kode[x];
        gotoxy(12,6+x);cout<<merk[x];
        gotoxy(26,6+x);cout<<harga[x];
        gotoxy(36,6+x);cout<<beli[x];
        gotoxy(43,6+x);cout<<total[x];
    }
    gotoxy(1,6+x);garis();

     cout << "Total Keseluruhan\t:" << totally<<endl;
     cout << "Diskon\t\t\t:"<<diskon<<endl;
     cout <<"Total Bayar\t\t:"<<akhir<<endl;
     cout <<  "Bayar\t\t\t:"; cin>>bayar;

     if(bayar<akhir){
        cout<<"Mohon maaf, uang tidak mencukupi"<<endl;
     }else{
        kembalian=bayar-akhir;
       cout << "Uang Kembalian\t\t:"<<kembalian<<endl;
    }

     cout<<"\nApakah ada transaksi lain[y/n]?";cin>>jawab;
    }while(jawab=='Y'||jawab=='y');

    getch;
}
