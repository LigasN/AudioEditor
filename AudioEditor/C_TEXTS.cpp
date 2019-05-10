#ifndef TEXTS_MATRIX_CPP
#define TEXTS_MATRIX_CPP

#include "C_TEXTS.h"
#include <iostream>
#include <assert.h>


C_TEXTS::C_TEXTS()
{
	int choice{};
	std::cout << "\nChoose language:\n\t1 - Polish\n\t2 - English\n\t3 - Italian\n\t4 - French\n";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::Polish);
		break;

	case 2:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::English);
		break;

	case 3:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::Italian);
		break;

	case 4:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::French);
		break;

	default:
		assert("Bad choice");
		break;
	}
	
	TEXTS_Update->Load_Texts_Matrix( TEXTS );

}

C_TEXTS::C_TEXTS(TXT_Handle::LANGUAGES language)
{

	TEXTS_Update = std::make_unique<TXT_Handle>(language);

	TEXTS_Update->Load_Texts_Matrix(TEXTS);
}

bool C_TEXTS::langugeUpdate(int language)
{
	switch(language)
	{
	case 0:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::Polish);
		TEXTS_Update->Load_Texts_Matrix( TEXTS );
		return true;
	case 1:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::English);
		TEXTS_Update->Load_Texts_Matrix(TEXTS);
		return true;
	case 2:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::Italian);
		TEXTS_Update->Load_Texts_Matrix(TEXTS);
		return true;
	case 3:
		TEXTS_Update = std::make_unique<TXT_Handle>(TXT_Handle::LANGUAGES::French);
		TEXTS_Update->Load_Texts_Matrix(TEXTS);
		return true;
	}

	return false;
}

void C_TEXTS::langugeUpdate(TXT_Handle::LANGUAGES language)
{
	TEXTS_Update = std::make_unique<TXT_Handle>(language);
	TEXTS_Update->Load_Texts_Matrix(TEXTS);
}

bool C_TEXTS::writeText(TEXT_ID text)
{
	std::wcout << TEXTS[(int)text] << std::endl;
	return true;

}

std::wstring C_TEXTS::getText(TEXT_ID text)
{
	return  TEXTS[(int)text];
}



#endif	//TEXTS_MATRIX_CPP