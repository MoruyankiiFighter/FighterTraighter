#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "PhysicsTransform.h"

class Entity;

class PlayerParticleSystem : public Component {
public:
	enum DeletionMethod {
		None,
		OnHit,
		OnAttack,
		OnDamaged
	};

	PlayerParticleSystem(int max) : Component(ecs::PlayerParticleSystem), maxParticles_(max) {};
	void addNewParticle(AssetsManager::TextureNames name, Vector2D pos, Vector2D size, int time, DeletionMethod deletion) {
		if (currParticles_ < maxParticles_) {
			int index = findAvailableIndex(); //Find empty spot (timer = -1)
			textureNames_[index] = name;
			texturePos_[index] = pos;
			textureSize_[index] = size;
			textureTime_[index] = time;
			textureDeletion_[index] = deletion;
			currParticles_++;
		}
	}
	virtual void init() override;

	virtual void update() override {
		for (int i = 0; i < textureNames_.size(); ++i) {
			//Lower the timer
			if (textureTime_[i] > 0) {
				textureTime_[i]--;
			}
			if (textureTime_[i] == 0) {
				textureTime_[i] = -1;
				currParticles_--;		//Timer reached -1 -> Free spot
			}
		}
	}

	virtual void render() {
		for (int i = 0; i < textureNames_.size(); ++i) {
			if (textureTime_[i] != -1) {	//This allows particles with time = -2 to not have a time limit, and to be instead released by another method (like onHit)
				Texture* tex = app_->getAssetsManager()->getTexture(textureNames_[i]);
				SDL_Rect dest = SDL_Rect();
				dest.x = phys_->getPosition().getX() + texturePos_[i].getX();
				dest.y = phys_->getPosition().getY() + texturePos_[i].getY();
				dest.w = textureSize_[i].getX();
				dest.h = textureSize_[i].getY();
				SDL_RendererFlip flip;
				if (phys_->getOrientation() == 1) flip = SDL_FLIP_NONE;
				else flip = SDL_FLIP_HORIZONTAL;
				tex->render(dest, flip);
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
			++i;
		}

		return found;
	}

	void removeDeletionMethodParticles(DeletionMethod meth) {
		for (int i = 0; i < textureNames_.size(); ++i) {
			if (textureDeletion_[i] == meth) {
				textureTime_[i] = -1;
				currParticles_--;
			}
		}
	}

	~PlayerParticleSystem() {};
private:
	int maxParticles_;
	int currParticles_;

	std::vector<AssetsManager::TextureNames> textureNames_;
	std::vector<Vector2D> texturePos_;
	std::vector<Vector2D> textureSize_;
	std::vector<int> textureTime_;
	std::vector<DeletionMethod> textureDeletion_;

	PhysicsTransform* phys_;
};