#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<math.h>

using namespace std;

class NAZWA_KLASY {
private:

	int n, m;									//PRYWATNE ZMIENNE

public:											//PUBLICZNA ZMIENNA
	long double **tablica2D;					
												//KONSTRUKTOR 1
	NAZWA_KLASY() { n = m = 0; }
												//KONSTRUKTOR 2
	NAZWA_KLASY(int valn, int valm) {			
		m = valm;
		n = valn;
	}
												//destruktor
	~NAZWA_KLASY() {
		/*for (int i = 0; i < n; i++) {
			delete[] tablica2D[i];
		}
		delete[] tablica2D;*/
	}
												//PRZYKLAD FUNCKJI WEWNETRZNEJ
	void read() const {

	}

	/*
	long double Wyznacznik_Macierzy() {
		long double w = FUNKCJA Z ZEWNATRZ( ZMIENNE);
		return w;
	}*/

};