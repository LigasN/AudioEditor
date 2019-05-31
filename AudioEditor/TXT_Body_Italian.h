#pragma once

#ifndef TXT_BODY_ITALIAN_H
#define TXT_BODY_ITALIAN_H

#include "TXT_Body.h"
#include <fstream>
#include <string>
#include <vector>

namespace NL
{
	class TXT_Body_Italian : public TXT_Body
	{
	public:
		virtual void Load_Texts_Matrix(std::vector <std::wstring> &newText) override;
	};
}
#endif // !TXT_BODY_ITALIAN_H
