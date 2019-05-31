#pragma once

#ifndef TXT_HANDLE_H
#define TXT_HANDLE_H

#include <memory>
#include "TXT_Body.h"
#include "TXT_Body_Polish.h"
#include "TXT_Body_English.h"
#include "TXT_Body_Italian.h"
#include "TXT_Body_French.h"

namespace NL
{
	////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Class of Handle Body design pattern 
	///
	/// Way to use:
	///		Make a constructor and give him pointer to solution You want
	///		Next you have function which this solution will make the way you choose
	///
	///
	////////////////////////////////////////////////////////////////////////////////////////////
	class TXT_Handle
	{
	private:

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Pointer named BodyPtr to TXT_Body to handle with files
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		using BodyPtr = std::unique_ptr<TXT_Body>;

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Object of BodyPtr which is pointer to TXT_Body
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		BodyPtr BodyObject;

	public:
		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Class enum with languages of texts to take into Your program
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		enum class LANGUAGES
		{
			Polish,
			English,
			Italian,
			French
		};

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Default constructor which set the txt format of text file
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		TXT_Handle();

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Parametric constructor which take the txt format of text file by class enum
		/// EHandledFormats
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		TXT_Handle(LANGUAGES language);

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Virtual destructor
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		virtual ~TXT_Handle() = default;

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Main function which read file with texts from file determinated by Handle
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		virtual void Load_Texts_Matrix(std::vector <std::wstring> &newText);
	};

}

#endif // !TXT_HANDLE_H