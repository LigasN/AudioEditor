#include "AudioEditorManager.h"
#include <iostream>

AudioEditorManager::AudioEditorManager(const std::shared_ptr <Display> & display, const std::shared_ptr <Buttons> & buttons) : display(display), buttons(buttons),
firstButtonEffect(std::make_shared <FirstButtonEffect>(display)), secondButtonEffect(std::make_shared <SecondButtonEffect>(display)),
thirdButtonEffect(std::make_shared <ThirdButtonEffect>(display)), fourthButtonEffect(std::make_shared <FourthButtonEffect>(display)),
audioPlayer(std::make_shared <AudioPlayer>(display)), currentState(std::make_shared <AudioPlayer>(display))
{
}

AudioEditorManager::~AudioEditorManager()
{
}

void AudioEditorManager::updateState()
{
	std::cout << "Update STate()" << std::endl;
	std::cout << (int)currentState->getStateName() << std::endl;
	Buttons::MousePositions clickedButton = buttons->ButtonUpdate();

	switch (clickedButton)
	{
	case Buttons::MousePositions::playButton:

		switch (currentState->getStateName())
		{
			std::cout << "getStateName()" << std::endl;
		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:
		case AudioEditorState::States::NoneEffectState:

			currentState = audioPlayer;

			std::cout << "currentState = audioPlayer;" << std::endl;
			std::cout << (int)currentState->getStateName() << std::endl;
		case AudioEditorState::States::Player:

			std::cout << "audioPlayer->UpdateEditedSound();\tAudioEditorManager::updateState() " << std::endl;
			audioPlayer->UpdateEditedSound(firstButtonEffect->getEffectManager(), secondButtonEffect->getEffectManager(), thirdButtonEffect->getEffectManager(), fourthButtonEffect->getEffectManager());
			std::cout << "sound updated" << std::endl;
			audioPlayer->Play();
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::cleanButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:
		case AudioEditorState::States::NoneEffectState:

			currentState = audioPlayer;

		case AudioEditorState::States::Player:

			audioPlayer->Clean();
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::stopButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:
		case AudioEditorState::States::NoneEffectState:

			currentState = audioPlayer;

		case AudioEditorState::States::Player:

			if (audioPlayer->GetStatus())
			{
				audioPlayer->Stop();
			}

			else if (!audioPlayer->GetStatus() && !audioPlayer->GetSavingState())
			{
				audioPlayer->SetSavingState();
			}

			else if (!audioPlayer->GetStatus() && audioPlayer->GetSavingState())
			{
				audioPlayer->Save();
				audioPlayer->ResetSavingState();
			}

			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::rightArrowButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:

			break;

		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:

			currentState->NextParameterSettings();

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::leftArrowButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:

			break;

		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:

			currentState->PreviousParameterSettings();

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::upArrowButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:

			break;

		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:

			currentState->IncreaseParameter();

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::downArrowButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:

			break;

		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:

			currentState->DecreaseParameter();

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::firstEffectButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:

			currentState = firstButtonEffect;
			currentState->UpdateDisplay();
			break;

		case AudioEditorState::States::FirstButtonEffect:

			currentState->ChangeEffectStatus();
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::secondEffectButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:
		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:

			currentState = secondButtonEffect;
			currentState->UpdateDisplay();
			break;

		case AudioEditorState::States::SecondButtonEffect:

			currentState->ChangeEffectStatus();
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::thirdEffectButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:
		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::FourthButtonEffect:

			currentState = thirdButtonEffect;
			currentState->UpdateDisplay();
			break;

		case AudioEditorState::States::ThirdButtonEffect:

			currentState->ChangeEffectStatus();
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::fourthEffectButton:

		switch (currentState->getStateName())
		{
		case AudioEditorState::States::Player:
		case AudioEditorState::States::NoneEffectState:
		case AudioEditorState::States::FirstButtonEffect:
		case AudioEditorState::States::SecondButtonEffect:
		case AudioEditorState::States::ThirdButtonEffect:

			currentState = fourthButtonEffect;
			currentState->UpdateDisplay();
			break;

		case AudioEditorState::States::FourthButtonEffect:

			currentState->ChangeEffectStatus();
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::noneButton:

		break;

	default:
		assert("Developer's mistake");
		break;
	}
}