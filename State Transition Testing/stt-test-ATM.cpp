#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
   cout << "======= ATM =======" << endl;
   cout << "1. Cek saldo" << endl;
   cout << "2. Tarik tunai" << endl;
   cout << "3. Setor tunai" << endl;
   cout << "4. Keluar" << endl;
}

// Fungsi untuk menampilkan saldo
void cekSaldo(int saldo) {
   cout << "Saldo Anda: Rp" << saldo << endl;
}

// Fungsi untuk menarik tunai
void tarikTunai(int saldo, double jumlah) {
   if (jumlah <= saldo) {
      saldo -= jumlah;
      cout << "Anda berhasil menarik tunai sebesar Rp" << jumlah << endl;
      cekSaldo(saldo);
   } else {
      cout << "Saldo tidak mencukupi" << endl;
   }
}

// Fungsi untuk menyetor tunai
void setorTunai(int saldo, double jumlah) {
   saldo += jumlah;
   cout << "Anda berhasil menyetor tunai sebesar Rp" << jumlah << endl;
   cekSaldo(saldo);
}

// Mesin ATM
/*enum ATMState {
   IDLE_STATE,
   CEK_SALDO_STATE,
   TARIK_TUNAI_STATE,
   SETOR_TUNAI_STATE,
   KELUAR_STATE,
};*/

int main() {
   //ATMState currentState = IDLE_STATE;
   int saldo = 1000000;
   int pilih;
   char pilih2;

   do {
      system("cls");
      tampilkanMenu();
      cout << "Pilih Menu : "; cin>>pilih;

      switch (pilih) {
         case 1 :
         cekSaldo(saldo);
            break;

         case 2 :
            double jumlah;
            cout << "Masukkan jumlah yang ingin ditarik: Rp";
            cin >> jumlah;
            tarikTunai(saldo, jumlah);
            //currentState = IDLE_STATE;
            break;

         case 3 :
            double jumlah2;
            cout << "Masukkan jumlah yang ingin disetor: Rp";
            cin >> jumlah2;
            setorTunai(saldo, jumlah2);
            //currentState = IDLE_STATE;
            break;

         case 4 :
            exit(0);
            break;

      }
      cout<<"Kembali ke Menu Utama? (y/n) : ";cin>>pilih2;

   } 
   while(pilih2 =='y' || pilih2 == 'Y');

   //1cout << "Terima kasih telah menggunakan mesin ATM kami" << endl;

   return 0;
}
