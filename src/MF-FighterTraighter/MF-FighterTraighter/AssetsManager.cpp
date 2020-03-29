#include "AssetsManager.h"
#include "App.h"

AssetsManager::AssetsManager(App* app) : app_(app)
{

	loadTextures();
	loadFonts();
	loadMusic();
}

Texture* AssetsManager::getTexture(size_t id)
{
	return textures_[id];
}

void AssetsManager::loadTextures()
{
	size_t numTextures = 3; // Must match the amount of loaded textures, efficiency
	textures_.reserve(numTextures);


	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/personaje.png", 1, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/buttons.png", 3, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/logo.png", 1, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/controller.png", 1, 1));
	
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/slidebar.png", 1, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/regulador.png", 1, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/personajeActing.png", 1, 1));
	
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/backgroundtemp.png", 1, 1));
	
	
	// textures_.emplace_back(new Texture(app_->getRenderer(), "Filepath", cols, fils));
}

Font* AssetsManager::getFont(size_t id)
{
	return fonts_[id];
}

void AssetsManager::loadFonts()
{
	size_t numFonts = 1; // Must match the amount of loaded fonts, efficiency
	fonts_.reserve(numFonts);


	fonts_.emplace_back(new Font("../../../../assets/Assets/Fonts/Roboto-Black.ttf", 20, 45));
	// fonts_.emplace_back(new Font("Filepath", size));
}

void AssetsManager::loadMusic()
{

}

void AssetsManager::playMusic(const string& name, int channel)
{
}

void AssetsManager::resumeAll()
{
}

void AssetsManager::resumeMusic()
{
}

void AssetsManager::pauseMusic()
{
}

void AssetsManager::stopMusic()
{
}

int AssetsManager::getGeneralVolume() const
{
	return 0;
}

int AssetsManager::getMusicVolume() const
{
	return 0;
}

int AssetsManager::getChannelVolume(int channel) const
{
	return 0;
}

void AssetsManager::setGeneralVolume(float volume_ratio)
{
}

void AssetsManager::setChannelvolume(int channel, float volume_ratio)
{
}

void AssetsManager::setMusicVolume(float volume_ratio)
{
}

void AssetsManager::setSFXVolume(const string& name, float volume_ratio)
{
}

AssetsManager::~AssetsManager()
{
	UnloadAssets();
}

void AssetsManager::UnloadAssets()
{
	for (Texture* tex : textures_) {
		delete tex;
	}
	for (Font* font : fonts_) {
		delete font;
	}
}
