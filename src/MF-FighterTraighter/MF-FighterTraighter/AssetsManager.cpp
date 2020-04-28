#include "AssetsManager.h"
#include "App.h"

AssetsManager::AssetsManager(App* app) : app_(app)
{

	loadTextures();
	loadFonts();
	loadMusic();
}

Texture* AssetsManager::getTexture(AssetsManager::TextureNames id)
{
	return textures_[id];
}

void AssetsManager::loadTextures()
{
	textures_.emplace(Player, new Texture(app_->getRenderer(), "../../../../assets/Assets/personaje.png", 1, 1));
	textures_.emplace(Button, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/buttons.png", 3, 1));
	textures_.emplace(Logo, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/logo.png", 1, 1));
	textures_.emplace(Controller, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/controller.png", 1, 1));
	
	textures_.emplace(Slidebar, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/slidebar.png", 1, 1));
	textures_.emplace(SliderRegulator, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/regulador.png", 1, 1));
	textures_.emplace(PlayerActing, new Texture(app_->getRenderer(), "../../../../assets/Assets/personajeActing.png", 1, 1));
	
	textures_.emplace(Background, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/backgroundtemp.png", 1, 1));
	textures_.emplace(Healthbar, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbar.png", 1, 1));
	textures_.emplace(HealthbarBack, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbarBack.png", 1, 1));
	textures_.emplace(RoundCounter, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/RoundCounter.png", 2, 1));
	textures_.emplace(CharacterSelection, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/characters_selection.png", 4, 1));
	
	textures_.emplace(SubMenuFondo,new Texture(app_->getRenderer(), "../../../../assets/Assets/images/submenuFondo.jpg", 1, 1));
	textures_.emplace(SubMenuWin,new Texture(app_->getRenderer(), "../../../../assets/Assets/images/submenuwin.jpg", 1, 1));
	textures_.emplace(FSGente,new Texture(app_->getRenderer(), "../../../../assets/Assets/images/FondoSGente.jpg", 1, 1));
	
	////// Imagenes de habilidades
	textures_.emplace(Pollo, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/habilidades/pollo.png", 1, 1));
	textures_.emplace(Mina, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/habilidades/mina.png", 2, 1));
	textures_.emplace(Hielo, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/habilidades/hielo.png", 2, 1));
	textures_.emplace(Toxic, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/habilidades/poison syrup.png", 2, 1));
	textures_.emplace(Buff, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/habilidades/doping.png", 2, 1));

	// textures_.emplace("key", new Texture(app_->getRenderer(), "Filepath", cols, fils));
}

Font* AssetsManager::getFont(AssetsManager::FontNames id)
{
	return fonts_[id];
}

void AssetsManager::loadFonts()
{
	fonts_.emplace(Roboto_Black, new Font("../../../../assets/Assets/Fonts/Roboto-Black.ttf", 20, 0.5));
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
	for (auto tex = textures_.begin(); tex != textures_.end(); ++tex) {
		delete tex->second;
	}
	for (auto font = fonts_.begin(); font != fonts_.end(); ++font) {
		delete font->second;
	}
}
