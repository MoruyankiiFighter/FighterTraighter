#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"
#include "PhysicsTransform.h"

//constructor
PlayerController::PlayerController(SDL_Scancode left, SDL_Scancode right, SDL_Scancode block,
	float jImpulse, SDL_Scancode jumpkey,
	SDL_Scancode crouchk) : Component(ecs::PlayerController),
transform_(nullptr), left_(left), right_(right), block_(block), jumpKey_(jumpkey), jumpImpulse(jImpulse), crouchKey_(crouchk)
{
}

//destructor
PlayerController::~PlayerController()
{
}

//init
void PlayerController::init()
{
	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	
}

//update
void PlayerController::update()
{
	//transform_->setPosition(transform_->getPosition() + transform_->getSpeed());
	if(abs(transform_->getBody()->GetLinearVelocity().x < maxSpeed))
		transform_->getBody()->ApplyForceToCenter(acc_ * dir_, true);
	cout << transform_->getBody()->GetMass() << endl;
	//transform_->getBody()->
}

//handle input
void PlayerController::handleInput()
{
	//Vector2D speed(transform_->getSpeed());
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	InputManager* input = app_->getInputManager();
	if (input->isKeyDown(block_) && currState->canGuard())
	{
		if (currState->isCrouch()) uncrouch();
		else if (currState->isMoving())stop();
		if (!currState->isGuarding()) currState->goGuardingTransition(6);
	}
	else if ((input->isKeyDown(jumpKey_) || input->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.9)
		&& currState->canJump()) 
	{
		//pTR_->setSpeed(0, 5);
		//force and where you use the fore
		transform_->getBody()->ApplyLinearImpulse(b2Vec2(0, -1000), transform_->getBody()->GetWorldCenter(), true);
		if (currState->isCrouch()) uncrouch();
		currState->goJumpingTrans(7);
		std::cout << "salto" << std::endl;
	}
	else if ((input->isKeyDown(crouchKey_) || input->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.1)
		&& currState->canCrouch())
	{
		cout << "crouch" << endl;
		if (currState->isMoving()) stop();//transform_->setSpeed(0, speed.getY());
		crouch();
	}
	else if (currState->isAbletoMove() && (input->isKeyDown(left_) || input->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) < 0))//mueves a la izq
	{
		if(!wallLeft_) dir_ = { -1, 0 };
		
		else {
			stop();//speed = { 0, speed.getY() };
		}
		//transform_->setSpeed(speed);
		if (currState->isGrounded()) currState->goMoving();
		else { currState->goJumping(); };
	}
	else if (currState->isAbletoMove() && (input->isKeyDown(right_) || input->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) > 0.09))
	{
		if (!wallRight_) dir_ = { 1, 0 };//speed = { 45, speed.getY() };
		else {
			stop();
		}		//transform_->setSpeed(speed);
		if (currState->isGrounded()) currState->goMoving();
		else { currState->goJumping(); };
	}

	//Si eésa tecla no está activa
	if(input->isKeyUp(left_) && input->isKeyUp(right_) && input->isKeyUp(jumpKey_)){	
		if (currState->isMoving() || currState->isJumping()) 
		{
			//transform_->setSpeed(0, speed.getY());
			//stop
			stop();
			if (currState->isGrounded()) currState->goIdle();
			else { currState->goJumping(); };
		}	
	}
	if (input->isKeyUp(block_)) {
		if (currState->isGuarding())
		{
			currState->goGuardingLeaving(14);
		}
	}
	if (input->isKeyUp(crouchKey_)) {
		if (currState->isCrouch())
		{
			uncrouch();
		}
	}
}

//crouch
void PlayerController::crouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goCrouch();

	transform_->setHeight(transform_->getHeight() / 2);
	transform_->setColliderHeight(transform_->getHeight());
	transform_->setColliderWidth(transform_->getWidth() / 2);
	double height = transform_->getHeight();
	double width = transform_->getWidth();

	transform_->setPosition(transform_->getPosition().getX() + width / 2, transform_->getPosition().getY() + height);

	//animaciones de agachar
}

//uncrouch
void PlayerController::uncrouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goIdle();

	double width = transform_->getWidth();

	transform_->setPosition(transform_->getPosition().getX() + width / 2, transform_->getPosition().getY());
	transform_->setHeight(transform_->getHeight() * 2);
	transform_->setColliderHeight(transform_->getHeight());
	transform_->setColliderWidth(transform_->getWidth() / 2);

	//animaciones por defecto
}

void PlayerController::stop() {
	dir_ = { 0,0 };
	b2Body* b = transform_->getBody();
	transform_->getBody()->SetLinearVelocity(b2Vec2(0, b->GetLinearVelocity().y));
	transform_->getBody()->SetAngularVelocity(0);
}