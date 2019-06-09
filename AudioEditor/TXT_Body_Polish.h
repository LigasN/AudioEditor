#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include "TXT_Body.h"
#include <fstream>
#include <string>
#include < vector>

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// TXT_Body_Polish class
///
/// Aim: Handle Body element with other TXT classes. Loads matrix of texts in Polish.
///
///////////////////////////////////////////////////////////////////////////////////////////////
class TXT_Body_Polish : public TXT_Body
{
public:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual override function in TXT_Body_Polish class
	///
	/// Aim: Load matrix with text from file in proper language (Polish)
	///
	/// Arguments: std::vector <std::wstring> &
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Load_Texts_Matrix(std::vector <std::wstring> &newText) override;
};
