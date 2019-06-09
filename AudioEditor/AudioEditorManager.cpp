#include "AudioEditorManager.h"

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
	Buttons::MousePositions clickedButton = buttons->ButtonUpdate();

	buttons->setOff(Buttons::MousePositions::stopButton);
	buttons->setOff(Buttons::MousePositions::rightArrowButton);
	buttons->setOff(Buttons::MousePositions::leftArrowButton);
	buttons->setOff(Buttons::MousePositions::upArrowButton);
	buttons->setOff(Buttons::MousePositions::downArrowButton);

	switch (clickedButton)
	{
	case Buttons::MousePositions::playButton:

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

			audioPlayer->UpdateEditedSound(firstButtonEffect->getEffectManager(), secondButtonEffect->getEffectManager(), thirdButtonEffect->getEffectManager(), fourthButtonEffect->getEffectManager());
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

		buttons->setOff(Buttons::MousePositions::playButton);

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

			if (audioPlayer->GetStatus() == true)
				buttons->setOn(Buttons::MousePositions::cleanButton);
			else
				buttons->setOff(Buttons::MousePositions::cleanButton);
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::stopButton:

		buttons->setOff(Buttons::MousePositions::playButton);
		buttons->setOff(Buttons::MousePositions::cleanButton);
		buttons->setOn(Buttons::MousePositions::stopButton);


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

		buttons->setOn(Buttons::MousePositions::rightArrowButton);

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
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::leftArrowButton:

		buttons->setOn(Buttons::MousePositions::leftArrowButton);

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
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::upArrowButton:

		buttons->setOn(Buttons::MousePositions::upArrowButton);

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
			break;

		default:
			assert("Developer's mistake");
			break;
		}

		break;

	case Buttons::MousePositions::downArrowButton:

		buttons->setOn(Buttons::MousePositions::downArrowButton);

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
			break;

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

			currentState->UpdateDisplay();
			break;

		default:
			assert("Developer's mistake");
			break;
		}
		currentState->UpdateEffectStatus(buttons->getButtonsStatus(Buttons::MousePositions::firstEffectButton));

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

			currentState->UpdateDisplay();
			break;

		default:
			assert("Developer's mistake");
			break;
		}
		currentState->UpdateEffectStatus(buttons->getButtonsStatus(Buttons::MousePositions::secondEffectButton));

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

			currentState->UpdateDisplay();
			break;

		default:
			assert("Developer's mistake");
			break;
		}
		currentState->UpdateEffectStatus(buttons->getButtonsStatus(Buttons::MousePositions::thirdEffectButton));

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

			currentState->UpdateDisplay();
			break;

		default:
			assert("Developer's mistake");
			break;
		}
		currentState->UpdateEffectStatus(buttons->getButtonsStatus(Buttons::MousePositions::fourthEffectButton));

		break;

	case Buttons::MousePositions::noneButton:

		break;

	default:
		assert("Developer's mistake");
		break;
	}
}