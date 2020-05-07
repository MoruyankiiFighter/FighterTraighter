#include "OptionsLogic.h"

void OptionsLogic::init()
{
	WindowManager* mngr = app_->getWindowManager();
	AudioManager* audioMng =app_->getAudioMngr();
	resolutionsSlider_->setValue(mngr->getCurResolutionIndex());
	resolutionsSlider_->setMinValue(0);
	resolutionsSlider_->setMaxValue(mngr->getAvailableResolutions() - 2);
	resolutionsSlider_->setSteps(mngr->getAvailableResolutions() - 2);
	brightnessSlider_->setValue(mngr->getCurBrightness());
	musicSlider_->setValue(audioMng ->getMusicVolume());
	SFXSlider_->setValue(audioMng->getSFXVolume());

	SetElements();
}

void OptionsLogic::SetElements()
{
	WindowManager* mngr = app_->getWindowManager();

	resolutionsText_->setText(std::to_string(mngr->getSupportedResolutions()[resolutionsSlider_->getValue()].w)
		+ "x" + std::to_string(mngr->getSupportedResolutions()[resolutionsSlider_->getValue()].h) 
		+ "@" + std::to_string(mngr->getSupportedResolutions()[resolutionsSlider_->getValue()].refresh_rate) + "Hz");

	brightnessText_->setText(std::to_string(mngr->getCurBrightness()));
	musicText_->setText(std::to_string(app_->getAudioMngr()->getMusicVolume()));
	SFXText_->setText(std::to_string(app_->getAudioMngr()->getSFXVolume()));

}

void OptionsLogic::update()
{
	SetElements();
}
