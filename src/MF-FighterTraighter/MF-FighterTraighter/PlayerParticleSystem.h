#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "PhysicsTransform.h"

class Entity;

class PlayerParticleSystem : public Component {
public:
	PlayerParticleSystem(int max) : Component(ecs::PlayerParticleSystem), maxParticles_(max) {};
	void addNewParticle(AssetsManager::TextureNames name, Vector2D pos, Vector2D size, int time, bool cancel) {
		if (currParticles_ < maxParticles_) {
			int index = findAvailableIndex(); //Find empty spot (timer = -1)
			textureNames_[index] = name;
			texturePos_[index] = pos;
			textureSize_[index] = size;
			textureTime_[index] = time;
			textureCancelOnHit_[index] = cancel;
			currParticles_++;
		}
	}
	virtual void init() override;

	virtual void update() override {
		int toRemove = 0;

		for (int i = 0; i < currParticles_; ++i) {
			//Lower the timer
			if (textureTime_[i] > -1) textureTime_[i]--;

			//Render the texture;
			if (textureTime_[i] > 0) {
				Texture* tex = app_->getAssetsManager()->getTexture(textureNames_[i]);
				SDL_Rect dest;
				dest.x = phys_->getPosition().getX() + texturePos_[i].getX();
				dest.y = phys_->getPosition().getY() + texturePos_[i].getY();
				dest.w = textureSize_[i].getX();
				dest.h = textureSize_[i].getY();
				SDL_RendererFlip flip;
				if (phys_->getOrientation == 1) flip = SDL_FLIP_NONE;
				else flip = SDL_FLIP_HORIZONTAL;
				tex->render(dest, flip);
			}
			else {
				currParticles_--;	//Timer reached -1 -> Free spot
			}
		}
	}

	int findAvailableIndex() {
		int i = 0;
		int found = -1;
		while (i < textureTime_.size() && found < 0) {
			if (textureTime_[i] == -1) {
				found = i;
			}
		}

		return found;
	}

	~PlayerParticleSystem() {};
private:
	int maxParticles_;
	int currParticles_ = 0;

	std::vector<AssetsManager::TextureNames> textureNames_;
	std::vector<Vector2D> texturePos_;
	std::vector<Vector2D> textureSize_;
	std::vector<int> textureTime_;
	std::vector<bool> textureCancelOnHit_;

	PhysicsTransform* phys_;
};