#include <stdio.h>
#include <vector>
#include <iostream>
#include <tuple>
#include <fstream>

using namespace std;

/**
Napisz funkcję o nagłówku vector<double> suma(vector<double> t1, vector<double> t2) , która zwróci tablicę wypełnioną w taki sposób, 
aby każdy element tej tablicy był sumą odpowiednich elementów z tablic t1 i t2 (zadbawszy uprzednio o odpowiedni rozmiar wektora wynikowego). 
Co proponujesz zrobić, gdy rozmiary tablic danych są różne?

Napisz funkcję o nagłówku vector<int> uporzadkuj(const vector<int> & dane), która zwróci nowy wektor z tą samą zawartością, 
co dany,ale uporządkowany w ten sposób, by wszystkie liczby parzyste poprzedzały liczby nieparzyste.Nie używaj żadnych standardowych algorytmów 
ani struktur danych oprócz vectora.

Napisz program, który spyta użytkownika o nazwę pliku i przeprowadzi 
statystykę znaków niebiałyc występujących w tym pliku wyświetlając 
jednokrotnie kod każdego z występujących znaków wraz z jego liczebnością. Użyj vectora.
*/

void menu();
vector<double> suma(vector<double> t1, vector<double> t2);
vector<int> uporzadkuj(const vector<int> & dane);
vector<int> liczNiebialeZnaki(string plik);

vector<double> t1 = {2.0, 5.0, 8.0, 16.0, 25.0};
vector<double> t2 = {6.0, 7.0, 14.0, 22.0};
const vector<int> t3 = {2,1,8,6,7,9,5,3,4};
vector<double> wynik1;
vector<int> wynik2;

string wyswietl(vector<double> t);
string wyswietl(vector<int> t);


int main(int argc, char const *argv[])
{
  menu();
  return 0;
}


void menu(){
  int wybor = 0;
  do {
    cout <<  endl;
    cout << "MENU: " << endl;
    cout << "(1) funkcja SUMA" << endl;
    cout << "(2) funkcja UPORZADKUJ" << endl;
    cout << "(3) Sprawdz biale znaki" << endl;
    cout << "(0) Wyjdz" << endl;
    cout <<  endl;
    cin >> wybor;
    int rok;
    string nazwaPliku;
    switch (wybor)
    {
    case 1:
        wynik1 = suma(t1,t2);
        cout << wyswietl(t1) << ", " << wyswietl(t2) << " daje w wyniku: " << endl;
        cout << wyswietl(wynik1);
      break;
    case 2:
        wynik2 = uporzadkuj(t3);
        cout << "Po uporzadkowaniu wektor: " << wyswietl(t3) << " daje w wyniku: " << endl;
        cout << wyswietl(wynik2);
      break;
    case 3:
      cout << "Podaj nazwe pliku: " << endl;
      cout << "(Pusta nazwa spowoduje wyswietlenie domyslnego pliku przykladowego)" << endl;
      cin.ignore();
      getline(cin, nazwaPliku);

      liczNiebialeZnaki(nazwaPliku);
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
  return out;
}

vector<int> uporzadkuj(const vector<int> & dane){
  vector<int> out;
  vector<int> nieparzyste;
  for(int i = 0; i < dane.size(); i++){
    if (dane[i] % 2 == 0){
      out.push_back(dane[i]);
    } else {
      nieparzyste.push_back(dane[i]);
    }
  }


  for(int i = 0; i < nieparzyste.size(); i++){
    out.push_back(nieparzyste[i]);
  }
  return out;
}

vector<int> liczNiebialeZnaki(string plik){
  vector<int> out;
  string linia;
  string sciezka;

    cout  << "sss" << plik;
  if (plik == ""){
    sciezka = "input";
  } else {
    sciezka = plik;
  }
  ifstream fileHandler(sciezka);
  while(getline(fileHandler, linia)){
    for(string::iterator it = linia.begin(); it != linia.end(); ++it) {
    cout << (int) *it << endl;
  }
  }
  return out;
}

string wyswietl(vector<double> t){
  char buffer[100];
    string out =  "[";
    for(int i = 0; i < t.size(); i++){
      if (i > 0){
        out += ", ";
      }
      sprintf(buffer, "%.2f", t[i]);
      out += buffer;
    }
    out += "]";
    return out;
}

string wyswietl(vector<int> t){
  char buffer[100];

  string out =  "[";
  for(int i = 0; i < t.size(); i++){
    if (i > 0){
      out += ", ";
    }
    sprintf(buffer, "%d", t[i]);
    out += buffer;
  }
  out += "]";
  return out;
}

