#include "AssetsManager.h"
#include "App.h"

AssetsManager::AssetsManager(App* app) : app_(app)
{
	loadTextures();
	loadFonts();
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
	// textures_.emplace_back(new Texture(app_->getRenderer(), "Filepath", cols, fils));
}

void AssetsManager::loadFonts()
{
	size_t numFonts = 1; // Must match the amount of loaded fonts, efficiency
	fonts_.reserve(numFonts);


	fonts_.emplace_back(new Font("../../../../assets/Assets/Fonts/Roboto-Black.ttf", 20));
	// fonts_.emplace_back(new Font("Filepath", size));
}

Font* AssetsManager::getFont(size_t id)
{
	return fonts_[id];
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
