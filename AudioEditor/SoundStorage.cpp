#include "SoundStorage.h"



SoundStorage::SoundStorage()
{
}


SoundStorage::~SoundStorage()
{
}

SoundStorage::SoundStorage(std::string soundAdress)
{
	sound.loadFromFile(soundAdress);
	std::cout << "zaladowalem utwor" << std::endl;
}

SoundStorage::SoundStorage(sf::SoundBuffer sound)
{
}

SoundStorage::SoundStorage(const SoundStorage & sound)
{
}

void SoundStorage::Play(const std::shared_ptr <Buttons> buttons)
{
	std::cout << "odpalam utwor" << std::endl;
	sf::Sound soundplayer(sound);
	soundplayer.play();
	while (soundplayer.getStatus() == sf::Sound::Status::Playing || buttons->ButtonUpdate() != Buttons::MousePositions::noneButton)
		std::cout << "plahying all the time" << std::endl;
}
