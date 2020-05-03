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
	textures_.emplace(CharacterSelection, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/characters_selection.png", 4, 1));
	textures_.emplace(Banner, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/warbanner.png", 1, 1)); 

	//backgrounds
	textures_.emplace(BackgroundFight, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/FONDO.png", 2, 1));
	
	//UI elements
		//healthbar
	textures_.emplace(Healthbar, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbar.png", 1, 1));
	textures_.emplace(HealthbarSaco, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbarSaco.png", 1, 1));
	textures_.emplace(HealthbarBack, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbarBack.png", 1, 1));
		//roundcounter
	textures_.emplace(RoundCounter, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/RoundCounter.png", 2, 1));

	//aisha resources
	textures_.emplace(Aisha_icon, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/aisha-icon.png", 2, 1)); 
	textures_.emplace(AishaArtwork, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/aisha.png", 1, 1)); 
	
	//flor resources
	textures_.emplace(Flor_icon, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/flor-icon.png", 2, 1));
	textures_.emplace(FlorArtwork, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/flor.png", 1, 1));

	//ganon resources
	textures_.emplace(Ganonbot_icon, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/ganonbot-icon.png", 2, 1)); 
	textures_.emplace(GanonArtwork, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/ganonbot.png", 1, 1)); 
	textures_.emplace(GanonSheet, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/characters/Ganonbot_spritesheet.png", 15, 23));
	
	//mockingbird resources
	textures_.emplace(Mock_icon, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/moc-icon.png", 2, 1));  
	textures_.emplace(MockArtwork, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/selection characters/mock.png", 1, 1));  
	
	textures_.emplace(Panel, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/panel.png", 1, 1)); 
	
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
