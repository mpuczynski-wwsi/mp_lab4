#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;

/**
Napisz funkcję o nagłówku vector<double> suma(vector<double> t1, vector<double> t2) , która zwróci tablicę wypełnioną w taki sposób, 
aby każdy element tej tablicy był sumą odpowiednich elementów z tablic t1 i t2 (zadbawszy uprzednio o odpowiedni rozmiar wektora wynikowego). 
Co proponujesz zrobić, gdy rozmiary tablic danych są różne?

Napisz funkcję o nagłówku vector<int> uporzadkuj(const vector<int> & dane), która zwróci nowy wektor z tą samą zawartością, 
co dany,ale uporządkowany w ten sposób, by wszystkie liczby parzyste poprzedzały liczby nieparzyste.Nie używaj żadnych standardowych algorytmów 
ani struktur danych oprócz vectora.

Napisz program, który spyta użytkownika o nazwę pliku i przeprowadzi statystykę znaków niebiałyc występujących w tym pliku wyświetlając 
jednokrotnie kod każdego z występujących znaków wraz z jego liczebnością. Użyj vectora.
*/

void menu();
vector<double> suma(vector<double> t1, vector<double> t2);
vector<int> uporzadkuj(const vector<int> & dane);

vector<double> t1 = {2.0, 5.0, 8.0, 16.0, 25.0};
vector<double> t2 = {6.0, 7.0, 14.0, 22.0};
vector<double> wynik;

void wyswietl(vector<double> t);


int main(int argc, char const *argv[])
{
  menu();
  return 0;
}


void menu(){
  int wybor = 0;
  do {
    cout << "MENU: " << endl;
    cout << "(1) funkcja SUMA" << endl;
    cout << "(2) funkcja UPORZADKUJ" << endl;
    cout << "(3) Sprawdz biale znaki" << endl;
    cout << "(0) Wyjdz" << endl;
    cin >> wybor;
    int rok;
    switch (wybor)
    {
    case 1:
        wynik = suma(t1,t2);
        wyswietl(wynik);
      break;
    case 2:

      break;
    case 3:

      break;
    }
  } while (wybor != 0);
}

vector<double> suma(vector<double> t1, vector<double> t2){
  vector<double> out;
  int minSize = t1.size();
  if (t2.size() < minSize){
    minSize = t2.size();
  }
  for(int i = 0; i < minSize; i++){
    out.push_back(t1[i] + t2[i]);
  }
}

void wyswietl(vector<double> t){
    cout << "[";
    for(int i = 0; i < t.size(); i++){
      if (i > 0){
        cout << ", ";
      }
      cout << t[i];
    }
    cout << "]";
}

