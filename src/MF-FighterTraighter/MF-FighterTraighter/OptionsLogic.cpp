#include "OptionsLogic.h"

void OptionsLogic::init()
{
	//graphicsNav

	//WindowManager* mngr = app_->getWindowManager();
	//AudioManager* audioMng =app_->getAudioMngr();
	//resolutionsSlider_->setValue(mngr->getCurResolutionIndex());
	//resolutionsSlider_->setMinValue(0);
	//resolutionsSlider_->setMaxValue(mngr->getAvailableResolutions() - 2);
	//resolutionsSlider_->setSteps(mngr->getAvailableResolutions() - 2);
	//brightnessSlider_->setValue(mngr->getCurBrightness());
	//musicSlider_->setValue(audioMng ->getMusicVolume());
	////Solucion 1 Poner volumen a 0
	////audioMng->setSFXVolume(0);
	//SFXSlider_->setValue(audioMng->getSFXVolume());
	////Solucion 2 poner un valor inicial del slider sin que llame al callback
	////SFXSlider_->setinValue(audioMng->getSFXVolume());
	//SetElements();
}

void OptionsLogic::SetElements()
{
	WindowManager* mngr = app_->getWindowManager();

	resolutionsText_->setText(std::to_string(mngr->getSupportedResolutions()[resolutionsSlider_->getValue()].w)
		+ "x" + std::to_string(mngr->getSupportedResolutions()[resolutionsSlider_->getValue()].h) 
		+ "@" + std::to_string(mngr->getSupportedResolutions()[resolutionsSlider_->getValue()].refresh_rate) + "Hz");

	brightnessText_->setText(std::to_string(mngr->getCurBrightness()));
	musicText_->setText(std::to_string(app_->getAudioMngr()->getMusicVolume()));
	
	if (app_->getAudioMngr()->pausedMusic()) {//just change the value
		SFXText_->setText(std::to_string((int)SFXSlider_->getValue()));
	}
	else//do a sound if not silenced and change the value
		SFXText_->setText(std::to_string(app_->getAudioMngr()->getSFXVolume()));

}

void OptionsLogic::update()
{
	//SetElements();
}
