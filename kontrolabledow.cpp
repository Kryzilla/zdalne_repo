#include <iostream>

using namespace std;

  int main()
{
    int a,b,c;
    bool aCzyBlad,bCzyBlad,cCzyBlad;
    
    do
	{	
	   	cout << "Podaj liczbe a: ";
	    cin >> a;
	    aCzyBlad = cin.fail();
	    cin.clear();
		cin.ignore( 1000, '\n' );	   
	}while(aCzyBlad==1);
	
	do
	{	
	    cout << "\nPodaj liczbe b: ";
	    cin >> b;
	    bCzyBlad = cin.fail();
	    cin.clear();
	    cin.ignore( 1000, '\n' );
	}while(bCzyBlad==1);
	
    do
	{
	    cout << "\nPodaj liczbe c: ";
	    cin >> c;
	    cCzyBlad = cin.fail();
	    cin.clear();
	    cin.ignore( 1000, '\n' );
    }while(cCzyBlad==1);
    
    
    cout << "Liczba pierwsza to: " << a;
    cout << " Blad? " << aCzyBlad;
    cout << "\nLiczba druga to: " << b;
    cout << " Blad? " << bCzyBlad;
    cout << "\nLiczba trzecia to: " << c;
    cout << " Blad? " << cCzyBlad;
    return 0;
}
