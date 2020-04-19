#include "Component.h"
#include "RenderImage.h"
#include "UIElement.h"

using CallBackOnClick = void(int index);

class ButtonControl : public UIElement {

public:
	//constructor
	ButtonControl(int index,CallBackOnClick* startClickCallback = nullptr, CallBackOnClick* stopClickCallback = nullptr) : UIElement(), clickCallback_(startClickCallback), stopClickCallback_(stopClickCallback) {};

	virtual void Press()
	{
		state_ = Pressed;
		entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(2, 0);
		//if (clickCallback_) clickCallback_(app_);
	};
	virtual void Select()
	{
		if (state_ != Selected) {
			state_ = Selected;
			entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
		}
	};
	virtual void Disable()
	{
		state_ = Disabled;
	};
	virtual void Deselect()
	{
		state_ = Normal;
		entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(0, 0);
	};

	//destructor
	virtual ~ButtonControl() {};

	//callbacks
	inline void setClickCallback(CallBackOnClick* callback) { clickCallback_ = callback; }
	inline void setStopClickCallback(CallBackOnClick* callback) { stopClickCallback_ = callback; }

	//methods overrided of Component
	void init() override;
	//handle the input of the mouse by the moment
	void handleInput() override;
	void render() override;

private:
	CallBackOnClick* clickCallback_ = nullptr;
	CallBackOnClick* stopClickCallback_ = nullptr;
};
