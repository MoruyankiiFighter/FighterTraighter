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

Mix_Music* AssetsManager::getMusic(size_t id)
{
	return music_[id];
}

void AssetsManager::loadMusic()
{
	size_t id = 1;
	music_.reserve(id);
	music_.emplace_back(app_->getAudioManager()->loadMusic("../../../../assets/Assets/Sounds/Songs/New Hope menu.ogg"));
	music_.emplace_back(app_->getAudioManager()->loadMusic("../../../../assets/Assets/Sounds/Songs/Boss Fight.ogg"));
	
	//music_.emplace_back(app_->getAudioManager()->loadMusic("../../../../assets/Assets/Sounds/Songs/nombre de la cancion. formato"));

}

Mix_Chunk* AssetsManager::getSFX(size_t id)
{
	return sfx_[id];
}

void AssetsManager::loadSFX()
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

	for (Mix_Music* m : music_) {
		delete m;
	}

	for (Mix_Chunk* sfx : sfx_) {
		delete sfx;
	}
}
