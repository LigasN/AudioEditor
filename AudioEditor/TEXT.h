#pragma once

#include<iostream>

using namespace std;

typedef enum {
	Error = 0,
	Menu_glowne = 1,
	Menu_koncowe = 2,
	Menu_ustawien = 3,
} TEXT_ID;

static const char* TEXTS[]{
	"Nie oczekiwany b³¹d\n\n",						//0
	"Wybierz od czego zaczniemy. Wpisz numer odpowiadaj¹cy\n"		//1
	"wybranej przez Ciebie opcji i zatwierdŸ enterem.\n"
	"1- ...\n"
	"2- ...\n",
	"Wybierz jedn¹ z poni¿szych opcji:\n"							//2
	"1- Je¿eli chcesz kontynuowaæ\n"
	"2- Je¿eli chcesz powróciæ do menu\n"
	"3- Je¿eli chcesz zakoñczyæ pracê\n\n",
	"Wybierz ustawienia:\n"											//3
	"1 - ...\n"
	"2 - ...\n"
	"3 - ...\n"
	"4 - Wyjscie\n\n"
};