#include<iostream>
#include<cstdio>
using namespace std;

int zakoduj(int id_wirnika, int** kody, int wejscie)
{
	int wynik = kody[id_wirnika][wejscie];
	cout << wejscie << " -> " << wynik << endl;
	return wynik;
}

void obrot()
{
	
}

int main()
{
	int alfabet, wirniki, pom_p;
	cin >> alfabet >> wirniki;
	alfabet++;
	
	int** kody_1 = new int* [wirniki];
	int** kody_2 = new int* [wirniki];
	int** obrot = new int* [wirniki];
	int* p = new int[wirniki];

	for (int k = 0; k < wirniki; k++)           
	{
		kody_1[k] = new int[alfabet];
		kody_2[k] = new int[alfabet];
		for (int h = 1; h < alfabet; h++)        
		{
			cin >> kody_1[k][h];
			int pom = kody_1[k][h];
			kody_2[k][pom] = h;
		}

		cin >> pom_p;
		p[k]=pom_p;
		obrot[k] = new int[pom_p];
		for (int h = 0; h < pom_p; h++)
		{
			cin >> obrot[k][h];
		}
	}

	int l;
	cin >> l;
	int** reflektory = new int* [l];

	for (int k = 0; k < l; k++)
	{
		reflektory[k] = new int[alfabet];
		for (int h = 1; h < alfabet; h++)
		{
			cin >> reflektory[k][h];
		}
	}
	
	int liczba_zadan, liczba_wirnikow, id_reflektora, litera;
	cin >> liczba_zadan;
	

	for (int k = 0; k < liczba_zadan; k++)              
	{
		cin >> liczba_wirnikow;
		int* uzywane_wirniki = new int[liczba_wirnikow];
		int* pozycje = new int [liczba_wirnikow];

		for (int h = 0; h < liczba_wirnikow; h++)          
		{
			int id_wirnika;
			cin >> id_wirnika;
			uzywane_wirniki[h] = id_wirnika; 
			
			cin >> pozycje[id_wirnika];
			    
		}
		cin >> id_reflektora;
		
		cin >> litera;
		while (litera != 0)
		{
			for (int h = 0; h < liczba_wirnikow; h++)
			{
				int id_wirnika = uzywane_wirniki[h];
				litera = zakoduj(id_wirnika, kody_1, litera);
			}
			litera = zakoduj(id_reflektora, reflektory, litera);
			for (int h = liczba_wirnikow-1; h >= 0; h--)
			{
				int id_wirnika = uzywane_wirniki[h];
				litera = zakoduj(id_wirnika, kody_2, litera);
			}


			cin >> litera;
		}

		delete[] uzywane_wirniki;
		uzywane_wirniki = NULL;
		delete[] pozycje;
		pozycje = NULL;
	}

	








	for (int i = 0; i < wirniki; i++)
	{
		delete[] kody_1[i];
		delete[] kody_2[i];
		delete[] obrot[i];
	}
	delete[] kody_1;
	delete[] kody_2;
	delete[] obrot;
	kody_1 = NULL;
	kody_2 = NULL;
	obrot = NULL;
	delete[] p;
	p = NULL;

	for (int i = 0; i < l; i++)
	{
		delete[] reflektory[i];
	}
	delete[] reflektory;
	reflektory = NULL;
}