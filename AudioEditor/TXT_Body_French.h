#pragma once

#ifndef TXT_BODY_FRENCH_H
#define TXT_BODY_FRENCH_H

#include "TXT_Body.h"
#include <fstream>
#include <string>
#include <vector>

namespace NL
{
	class TXT_Body_French : public TXT_Body
	{
	public:
		virtual void Load_Texts_Matrix(std::vector <std::wstring> &newText) override;
	};
}

#endif // !TXT_BODY_FRENCH_H