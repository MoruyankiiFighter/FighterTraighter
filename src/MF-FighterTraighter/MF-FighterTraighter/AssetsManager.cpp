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

Mix_Music* AssetsManager::getMusic(size_t id)
{
	return music_[id];
}

void AssetsManager::loadMusic()
{
	size_t id = 2;
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
	size_t id = 1;
	sfx_.reserve(id);

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

	for (Mix_Music* m : music_) {
		delete m;
	}

	//for (Mix_Chunk* sfx : sfx_) {
		//delete sfx;
	//}
}
