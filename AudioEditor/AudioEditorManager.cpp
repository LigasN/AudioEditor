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

		if (!buttons->getButtonsStatus(Buttons::MousePositions::playButton))
		{
			buttons->setOn(Buttons::MousePositions::playButton);
			Sleep(2);
		}
		buttons->setOff(Buttons::MousePositions::playButton);


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
			if (audioPlayer->GetStatus() == true)
				buttons->setOn(Buttons::MousePositions::playButton);
			else
				buttons->setOff(Buttons::MousePositions::playButton);

			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::cleanButton:

		if (!buttons->getButtonsStatus(Buttons::MousePositions::cleanButton))
		{
			buttons->setOn(Buttons::MousePositions::cleanButton);
			Sleep(2);
		}
		buttons->setOff(Buttons::MousePositions::cleanButton);


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

		if (!buttons->getButtonsStatus(Buttons::MousePositions::stopButton))
		{
			buttons->setOn(Buttons::MousePositions::stopButton);
			Sleep(2);
		}
		buttons->setOff(Buttons::MousePositions::stopButton);


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
				buttons->setOff(Buttons::MousePositions::playButton);
				buttons->setOff(Buttons::MousePositions::cleanButton);
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

		if (!buttons->getButtonsStatus(Buttons::MousePositions::rightArrowButton))
		{
			buttons->setOn(Buttons::MousePositions::rightArrowButton);
			Sleep(2);
		}
		buttons->setOff(Buttons::MousePositions::rightArrowButton);

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
			currentState->UpdateDisplay();

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::leftArrowButton:

		if (!buttons->getButtonsStatus(Buttons::MousePositions::leftArrowButton))
		{
			buttons->setOn(Buttons::MousePositions::leftArrowButton);
			Sleep(2);
		}
		buttons->setOff(Buttons::MousePositions::leftArrowButton);

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
			currentState->UpdateDisplay();

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::upArrowButton:

		if (!buttons->getButtonsStatus(Buttons::MousePositions::upArrowButton))
		{
			buttons->setOn(Buttons::MousePositions::upArrowButton);
			Sleep(2);
		}
		buttons->setOff(Buttons::MousePositions::upArrowButton);

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
			currentState->UpdateDisplay();

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::downArrowButton:

		if (!buttons->getButtonsStatus(Buttons::MousePositions::downArrowButton))
		{
			buttons->setOn(Buttons::MousePositions::downArrowButton);
			Sleep(2);
		}
		buttons->setOff(Buttons::MousePositions::downArrowButton);

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
			currentState->UpdateDisplay();

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
			currentState->UpdateDisplay();
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
			currentState->UpdateDisplay();
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
			currentState->UpdateDisplay();
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
			currentState->UpdateDisplay();
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