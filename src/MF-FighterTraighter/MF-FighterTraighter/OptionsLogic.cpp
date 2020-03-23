#include "OptionsLogic.h"

void OptionsLogic::init()
{
	WindowManager* mngr = app_->getWindowManager();

	resolutionsText_->setText(std::to_string(mngr->getCurResolution().w) + "x" + std::to_string(mngr->getCurResolution().h) + "@" + std::to_string(mngr->getCurResolution().refresh_rate) + "Hz");
	resolutionsSlider_->setValue(mngr->getCurResolutionIndex());
	resolutionsSlider_->setMinValue(0);
	resolutionsSlider_->setMaxValue(mngr->getAvailableResolutions() - 1);
	resolutionsSlider_->setSteps(mngr->getAvailableResolutions() - 1);

	brightnessText_->setText(std::to_string(mngr->getCurBrightness()));
	brightnessSlider_->setValue(mngr->getCurBrightness());
}

void OptionsLogic::update()
{
	WindowManager* mngr = app_->getWindowManager();

	resolutionsText_->setText(std::to_string(mngr->getCurResolution().w) + "x" + std::to_string(mngr->getCurResolution().h) + "@" + std::to_string(mngr->getCurResolution().refresh_rate) + "Hz");
	resolutionsSlider_->setValue(mngr->getCurResolutionIndex());
	resolutionsSlider_->setMinValue(0);
	resolutionsSlider_->setMaxValue(mngr->getAvailableResolutions());
	resolutionsSlider_->setSteps(mngr->getAvailableResolutions());

	brightnessText_->setText(std::to_string(mngr->getCurBrightness()));
	brightnessSlider_->setValue(mngr->getCurBrightness());
}
