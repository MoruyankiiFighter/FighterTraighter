#include "ControlsOptionsLogic.h"

void ControlsOptionsLogic::init()
{
	setElements();
}

void ControlsOptionsLogic::update()
{
	if (enabled) setElements();
}

void ControlsOptionsLogic::setEnabled(bool e)
{
	enabled = e;

	if (e) {
		player1Nav_->setEnabled(true);
		player1Nav_->ChangeSelectedItem(0, 0);
		player2Nav_->setEnabled(true);
		player2Nav_->ChangeSelectedItem(0, 0);
		for (int i = 0; i < player1Buttons_.size(); ++i) {
			std::get<0>(player1Buttons_[i])->getComponent<RenderImage>(ecs::RenderImage)->setRendered(true);
			std::get<0>(player1Buttons_[i])->getComponent<ButtonControl>(ecs::UIElement)->setEnabled(true);
		}
		for (int i = 0; i < player2Buttons_.size(); ++i) {
			std::get<0>(player2Buttons_[i])->getComponent<RenderImage>(ecs::RenderImage)->setRendered(true);
			std::get<0>(player2Buttons_[i])->getComponent<ButtonControl>(ecs::UIElement)->setEnabled(true);
		}
		for (int i = 0; i < keyIdentifierTexts_.size(); ++i) {
			keyIdentifierTexts_[i]->getComponent<TextComponent>(ecs::TextComponent)->setText(keyTexts[i]);
		}
		player1Text_->getComponent<TextComponent>(ecs::TextComponent)->setText("Player One");
		player2Text_->getComponent<TextComponent>(ecs::TextComponent)->setText("Player Two");
	}
	else {
		player1Nav_->setEnabled(false);
		player2Nav_->setEnabled(false);
		for (int i = 0; i < player1Buttons_.size(); ++i) {
			std::get<0>(player1Buttons_[i])->getComponent<RenderImage>(ecs::RenderImage)->setRendered(false);
			std::get<0>(player1Buttons_[i])->getComponent<ButtonControl>(ecs::UIElement)->setEnabled(false);
		}
		for (int i = 0; i < player2Buttons_.size(); ++i) {
			std::get<0>(player2Buttons_[i])->getComponent<RenderImage>(ecs::RenderImage)->setRendered(false);
			std::get<0>(player2Buttons_[i])->getComponent<ButtonControl>(ecs::UIElement)->setEnabled(false);
		}
		for (int i = 0; i < keyIdentifierTexts_.size(); ++i) {
			keyIdentifierTexts_[i]->getComponent<TextComponent>(ecs::TextComponent)->setText("");
		}
		player1Text_->getComponent<TextComponent>(ecs::TextComponent)->setText("");
		player2Text_->getComponent<TextComponent>(ecs::TextComponent)->setText("");
	}
}

void ControlsOptionsLogic::setElements()
{
}
