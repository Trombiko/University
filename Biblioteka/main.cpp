#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
void zapisz_baze();
void odczytaj_baze();

  int liczbaKsiazek=0;

struct ksiazka
{
    int ilosc_stron;
    string tytul,imie,nazwisko;

};

ksiazka dodaj_ksiazke()
        {
           ksiazka pierwszy;
            cout<<"Tytul(bez spacji):\n";
            cin>>pierwszy.tytul;
            cout<<"Imie autora:\n";
            cin>>pierwszy.imie;
            cout<<"Nazwisko autora:\n";
            cin>>pierwszy.nazwisko;
            cout<<"Liczba stron:\n";
            cin>>pierwszy.ilosc_stron;
            return pierwszy;

        };


void zapisz_baze(ksiazka*tablica)
{

    ofstream zapisz;
	zapisz.open("zapis.txt");
    for(int i=0;i<liczbaKsiazek;i++)
    {
        zapisz<<tablica[i].tytul<<endl;
    	zapisz<<tablica[i].imie<<endl;
        zapisz<<tablica[i].nazwisko<<endl;
		zapisz<<tablica[i].ilosc_stron<<endl;
    }
    zapisz.close();
}


void odczytaj_baze(ksiazka*tablica_ksiazek)
{
    ifstream odczyt;
	odczyt.open("zapis.txt");
    int data_wydania,ilosc_stron;
    string tytul,imie,nazwisko;
    int i=-1;
    while(!odczyt.eof())
    {
        ++i;
        odczyt>>tablica_ksiazek[i].tytul;
        odczyt>>tablica_ksiazek[i].imie;
        odczyt>>tablica_ksiazek[i].nazwisko;
        odczyt>>tablica_ksiazek[i].ilosc_stron;

		
    }
    for(int j=0;j<i;j++){
    cout << "Numer "<<j+1 << "\nTytul: " << tablica_ksiazek[j].tytul << "\nImie autora: " << tablica_ksiazek[j].imie << "\nNazwisko autora: " << tablica_ksiazek[j].nazwisko << "\nLiczba stron: " << tablica_ksiazek[j].ilosc_stron << "\n " <<endl;
}
    odczyt.close();
}



int main()
{
    char odp;
    ksiazka tab_ksiazek[500];
    int data_wydania,ilosc_stron;
    string tytul,imie,nazwisko;
    int x;
  
    START:
    cout<<"-----------MENU GLOWNE---------\n";
    cout<<"1.Dodaj ksiazke do bazy danych.\n";
    cout<<"2.Zapisz baze danych.\n";
    cout<<"3.Odczytaj baze danych.\n";
    cout<<"4.Wyjdz\n";
    cout<<"-------------------------------"<<endl;
    cin>>x;




    switch (x)
        {
            case 1:
            {
            	system("cls");
                tab_ksiazek[liczbaKsiazek] = dodaj_ksiazke();
                liczbaKsiazek++;
                break;
            }

            case 2:
            {
            	system("cls");
                zapisz_baze(tab_ksiazek);
                break;
            }
            case 3:
            {
            	system("cls");
                odczytaj_baze(tab_ksiazek);
                break;
            }
            case 4:
            {
            	system("cls");
            	cout<<"Do zobaczenia! :)\n";
                exit(0);
                break;
            }
        }


cout<<"Czy chcesz powrocic na poczatek menu?\n             Wybierz T/N\n";
cin>>odp;
   if(odp=='T'||odp=='t') {
   		system("cls");
       goto START;
   }
    if(odp!='T'||odp!='t') return 0;

}

