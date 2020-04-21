#include "Component.h"
#include "RenderImage.h"
#include "UIElement.h"

using SetIndexOnClick = void(App * app, int index);

class ButtonControl : public UIElement {

public:
	//constructor
	ButtonControl(SetIndexOnClick* setIndexOnclick ,int index) : UIElement(),index(index) {};

	virtual void Press()
	{
		state_ = Pressed;
		entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(2, 0);
		if (setIndexOnclick_) setIndexOnclick_(app_,index);
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
	inline void setClickCallback(SetIndexOnClick* setonclick) { setIndexOnclick_ = setonclick; }

	//methods overrided of Component
	void init() override;
	//handle the input of the mouse by the moment
	void handleInput() override;
	void render() override;
	int getIndex()
	{
		return index;
	}

private:
	SetIndexOnClick* setIndexOnclick_ = nullptr;
	int index;
};
