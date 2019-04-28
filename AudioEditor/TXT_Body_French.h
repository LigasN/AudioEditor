#pragma once
#include "TXT_Body.h"
#include <fstream>
#include <string>
#include <vector>

class TXT_Body_French : public TXT_Body
{
public:
	virtual void Load_Texts_Matrix(std::vector <std::wstring> &newText) override;
};
