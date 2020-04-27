#include "CharacterSelectionLogic.h"


CharacterSelectionLogic::~CharacterSelectionLogic()
{
}

void CharacterSelectionLogic::init()
{
	j2_text_->setText("");
}

void CharacterSelectionLogic::update()
{
	SetElements();
}

void CharacterSelectionLogic::SetElements()
{

	j2_text_->setText("....");
}
