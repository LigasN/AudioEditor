#include "TXT_Handle.h"
#include <assert.h>
#include <vector>
#include <string>

TXT_Handle::TXT_Handle()
{
	BodyObject = std::make_unique<TXT_Body_Polish>();
}

TXT_Handle::TXT_Handle(LANGUAGES language)
{
	switch (language)
	{
	case LANGUAGES::Polish:
		BodyObject = std::make_unique<TXT_Body_Polish>();
		break;

	case LANGUAGES::English:
		BodyObject = std::make_unique<TXT_Body_English>();
		break;

	case LANGUAGES::Italian:
		BodyObject = std::make_unique<TXT_Body_Italian>();
		break;

	case LANGUAGES::French:
		BodyObject = std::make_unique<TXT_Body_French>();
		break;

	default:
		assert(false);
		break;
	}
}

void TXT_Handle::Load_Texts_Matrix(std::vector <std::wstring> &newText)
{
	assert(BodyObject);
	BodyObject->Load_Texts_Matrix(newText);
}

