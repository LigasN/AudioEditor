#pragma once

#ifndef TXT_BODY_ENGLISH_H
#define TXT_BODY_ENGLISH_H

#include "TXT_Body.h"
#include <fstream>
#include <string>
#include <assert.h>
#include <vector>

namespace NL
{
	class TXT_Body_English : public TXT_Body
	{
	public:
		virtual void Load_Texts_Matrix(std::vector <std::wstring> &newText) override;
	};

}
#endif // !TXT_BODY_ENGLISH_H