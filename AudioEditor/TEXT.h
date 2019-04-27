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
	"Nie oczekiwany b��d\n\n",						//0
	"Wybierz od czego zaczniemy. Wpisz numer odpowiadaj�cy\n"		//1
	"wybranej przez Ciebie opcji i zatwierd� enterem.\n"
	"1- ...\n"
	"2- ...\n",
	"Wybierz jedn� z poni�szych opcji:\n"							//2
	"1- Je�eli chcesz kontynuowa�\n"
	"2- Je�eli chcesz powr�ci� do menu\n"
	"3- Je�eli chcesz zako�czy� prac�\n\n",
	"Wybierz ustawienia:\n"											//3
	"1 - ...\n"
	"2 - ...\n"
	"3 - ...\n"
	"4 - Wyjscie\n\n"
};