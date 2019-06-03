#pragma once

#ifndef C_TEXT_H
#define C_TEXT_H

/////////////////////////////////////////////////////////////////////////////
/// HEADERS
/////////////////////////////////////////////////////////////////////////////
#include <string>
#include "TXT_Handle.h"
#include <memory>
#include <vector>

namespace NL
{

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///	Class C_TEXTS
	///
	/// Aim: Controls all of texts in program. Change language and read txt files with interface texts 
	///
	/// Description: Uses Handle-Body design patterned classes TXT_...(part of Handle-Body)
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	class C_TEXTS
	{
	private:

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Variable with all texts from file.
		/// Defined in constructor.
		/// Way to use:	TEXTS(C_TEXTS::TEXT_ID::chosen_text_id)
		/// Example:		std::cout << TEXTS(C_TEXTS::TEXT_ID::chosen_text_id) << std::endl;
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		std::vector <std::wstring> TEXTS;

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Smart pointer named HandlePtr to TXT_Handle to handle with files
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		using HandlePtr = std::shared_ptr<TXT_Handle>;

		////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// TXT_Handle smart pointer to object which handle with languages of texts
		///
		////////////////////////////////////////////////////////////////////////////////////////////
		HandlePtr TEXTS_Update;

	public:

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Enum with names of texts
		/// Way to use:	C_TEXTS::TEXT_ID::chosen_text_id
		/// Example:		std::cout << TEXTS(C_TEXTS::TEXT_ID::chosen_text_id) << std::endl;
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		enum class TEXT_ID
		{
			Error,
			Settings,
			Upload_Sound,
			SavingQuestion,
			TextSaved,
			Playing,
			PlayingClean,
			Stopped,
			ProblemWithSave,
			EffectName,
			Distortion,
			Echo,
			Delay,
			Tremolo,
			Delay_level_per_echo,
			Delay_time,
			Pitch_change_effect,
			Pitch_change_per_echo,
			Number_of_echoes,
			Clipping_level,
			Drive,
			Make_up_Gain,
			Decay_factor,
			waveform_type,
			startingPhase,
			wetLevel,
			frequency,
			sin,
			triangle,
			sawtooth,
			inverse_sawtooth,
			square

		};

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Default constructor which have choosing language and reading file operations
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		C_TEXTS();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Parametrical constructor in C_TEXTS class
		///
		/// Aim: Set all parametrs as wanted. Set argument as default language 
		///
		/// Arguments:	-TXT_Handle::LANGUAGES 			-language of texts
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		C_TEXTS(TXT_Handle::LANGUAGES language);

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Function in C_TEXTS class
		///
		/// Aim: Update language of C_TEXTS class by int choice on console
		///
		/// Way: -Use Handle-Body design pattern which handle files with texts in different languages
		///	 	 -Update texts in TEXTS tab
		///
		/// Arguments:	-int			-choice from console
		///
		/// Returns: Boolean true if success, false if not
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		bool langugeUpdate(int language);

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Function in C_TEXTS class
		///
		/// Aim: Update language of C_TEXTS class by TXT_Handle LANGUAGES enum
		///
		/// Way: -Use Handle-Body design pattern which handle files with texts in different languages
		///	 	 -Update texts in TEXTS tab
		///
		/// Arguments:	-TXT_Handle::LANGUAGES language			-language to update to
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		void langugeUpdate(TXT_Handle::LANGUAGES language);

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Function in C_TEXTS class
		///
		/// Aim: Wite requested text on console
		///
		/// Way: -Use iostream and wstring text matrix saved in TEXTS variable
		///
		/// Returns: Boolean true if success, false if not
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		bool writeText(TEXT_ID text);

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Function in C_TEXTS class
		///
		/// Aim: Return requested text in wstring
		///
		/// Returns: std::wstring
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		std::wstring getText(TEXT_ID text);

	};

}
#endif // !C_TEXT_H