#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk menghitung nilai rata-rata dari tiga bilangan bulat
double hitungRataRata(int a, int b, int c) {
   if (a < 0 || a > 100 || b < 0 || b > 100 || c < 0 || c > 100) {
      throw "Nilai tidak valid";
   }
   
   double rataRata = (a + b + c) / 3.0;
   return round(rataRata * 100) / 100.0;
}

int main() {
   // Pengujian boundary value analysis
   int testcase[12][3] = {
      {-1, 50, 50}, // Test case 1, a < 0
      {0, -1, 50}, // Test case 2, b < 0
      {0, 50, -1}, // Test case 3, c < 0
      {101, 50, 50}, // Test case 4, a > 100
      {100, 101, 50}, // Test case 5, b > 100
      {100, 50, 101}, // Test case 6, c > 100
      {0, 0, 0}, // Test case 7, nilai minimal
      {100, 100, 100}, // Test case 8, nilai maksimal
      {1, 1, 1}, // Test case 9, nilai tepi bawah
      {99, 99, 99}, // Test case 10, nilai tepi atas
      {50, 50, 50}, // Test case 11, nilai tengah
      {30, 80, 90} // Test case 12, nilai acak
   };
   
   for (int i = 0; i < 12; i++) {
      int a = testcase[i][0];
      int b = testcase[i][1];
      int c = testcase[i][2];
      
      try {
         double rataRata = hitungRataRata(a, b, c);
         cout << "Test case " << i + 1 << ": a = " << a << ", b = " << b << ", c = " << c << ", rata-rata = " << rataRata << endl;
      } catch (const char* msg) {
         cout << "Test case " << i + 1 << ": a = " << a << ", b = " << b << ", c = " << c << ", " << msg << endl;
      }
   }

   return 0;
}
