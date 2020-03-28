#include "Component.h"
#include "RenderImage.h"

using CallBackOnClick = void(App* app);

////callback para el juego
//void PauseCallback(App* app);


class Button : public Component {

public:
	//constructor
	Button(CallBackOnClick* startClickCallback = nullptr, CallBackOnClick* stopClickCallback = nullptr) : Component(ecs::Button), clickCallback_(startClickCallback), stopClickCallback_(stopClickCallback) {};
	inline void setClickCallback(CallBackOnClick* callback) { clickCallback_ = callback; }
	inline void setStopClickCallback(CallBackOnClick* callback) { stopClickCallback_ = callback; }
	inline void setSelected(bool sel) 
	{
		selected_ = sel; 
		if(sel) entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
		else entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(0, 0);
	}
	//destructor
	virtual ~Button() {};

	void init() override;
	//handle the input of the mouse by the moment
	void handleInput() override;

private:
	Transform* trans_ = nullptr;
	bool pressed_ = false;
	bool selected_ = false;
	CallBackOnClick* clickCallback_ = nullptr;
	CallBackOnClick* stopClickCallback_ = nullptr;
};
