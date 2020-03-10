#include "TextureManager.h"
#include "App.h"

TextureManager::TextureManager(App* app) : app_(app)
{
	loadTextures();
}

Texture* TextureManager::getTexture(size_t id)
{
	return textures_[id];
}

void TextureManager::loadTextures()
{
	size_t numTextures = 1; // Must match the amount of loaded textures, efficiency
	
	textures_.reserve(numTextures);
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/personaje.png", 1, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/buttons.png", 3, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/logo.png", 1, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/controller.png", 1, 1));
	textures_.emplace_back(new Texture(app_->getRenderer(), "../../../../assets/Assets/images/opciones_.png", 1, 1));

	// textures_.emplace_back(new Texture(app_->getRenderer(), "Filepath", cols, fils));
}

TextureManager::~TextureManager()
{
	for (Texture* tex : textures_) {
		delete tex;
	}
}