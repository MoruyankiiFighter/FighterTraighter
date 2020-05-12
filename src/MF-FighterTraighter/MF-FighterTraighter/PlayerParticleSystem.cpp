#include "PlayerParticleSystem.h"
#include "Entity.h"

void PlayerParticleSystem::init()
{
	currParticles_ = 0;

	phys_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	textureNames_ = std::vector<AssetsManager::TextureNames>(maxParticles_);
	texturePos_ = std::vector<Vector2D>(maxParticles_);
	textureSize_ = std::vector<Vector2D>(maxParticles_);
	textureTime_ = std::vector<int>(maxParticles_);
	textureDeletion_ = std::vector<DeletionMethod>(maxParticles_);

	for (int i = 0; i < textureTime_.size(); ++i) {
		textureTime_[i] = -1;
	}
}
