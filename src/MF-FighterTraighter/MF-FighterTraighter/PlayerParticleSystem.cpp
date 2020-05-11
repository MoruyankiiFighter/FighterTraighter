#include "PlayerParticleSystem.h"
#include "Entity.h"

void PlayerParticleSystem::init()
{
	phys_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	textureNames_ = std::vector<AssetsManager::TextureNames>(maxParticles_);
	texturePos_ = std::vector<Vector2D>(maxParticles_);
	textureSize_ = std::vector<Vector2D>(maxParticles_);
	textureTime_ = std::vector<int>(maxParticles_);
	textureCancelOnHit_ = std::vector<bool>(maxParticles_);
}
