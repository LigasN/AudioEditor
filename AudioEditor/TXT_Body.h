#pragma once

#ifndef TXT_BODY_H
#define TXT_BODY_H

#include <string>
#include <vector>

namespace NL
{
	////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Abstract class. Body to Handle-Body design pattern of texts reading
	///
	////////////////////////////////////////////////////////////////////////////////////////////
	class TXT_Body
	{
	public:
		virtual void Load_Texts_Matrix(std::vector <std::wstring> &newText) = 0;
		virtual ~TXT_Body() = default;
	};

}
#endif // !TXT_BODY_H
