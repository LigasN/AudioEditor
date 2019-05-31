
#ifndef TXT_BODY_ITALIAN_CPP
#define TXT_BODY_ITALIAN_CPP

#include "TXT_Body_Italian.h"
#include <assert.h>

namespace NL
{
	void TXT_Body_Italian::Load_Texts_Matrix(std::vector <std::wstring> &newText)
	{
		newText.clear();
		assert(newText.empty());

		std::wifstream file;
		file.open("Texts_Italian.txt", std::ios::in);

		std::wstring partLine{};
		std::wstring wholeLine{};
		int i{};
		while (std::getline(file, partLine))
		{

			if (partLine.empty()) {
				wholeLine += L"\n";
				newText.push_back(wholeLine);
				wholeLine.clear();
				assert(wholeLine.empty());
			}
			else
			{
				wholeLine += partLine + L"\n";
			}

		}
		newText.push_back(wholeLine);
		file.close();
	}
}
#endif // !TXT_BODY_ITALIAN_CPP