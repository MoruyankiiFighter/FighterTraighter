#include "AssetsManager.h"
#include "App.h"

AssetsManager::AssetsManager(App* app) : app_(app)
{

	loadTextures();
	loadFonts();
	loadMusic();
	loadSFX();
}

Texture* AssetsManager::getTexture(AssetsManager::TextureNames id)
{
	return textures_[id];
}

void AssetsManager::loadTextures()
{
	textures_.emplace(Player, new Texture(app_->getRenderer(), "../../../../assets/Assets/personaje.png", 1, 1));
	textures_.emplace(Button, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/buttons.png", 3, 1));
	textures_.emplace(Logo, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/logo.png", 1, 1));
	textures_.emplace(Controller, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/controller.png", 1, 1));
	
	textures_.emplace(Slidebar, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/slidebar.png", 1, 1));
	textures_.emplace(SliderRegulator, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/regulador.png", 1, 1));
	textures_.emplace(PlayerActing, new Texture(app_->getRenderer(), "../../../../assets/Assets/personajeActing.png", 1, 1));
	
	textures_.emplace(Background, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/backgroundtemp.png", 1, 1));
	textures_.emplace(Healthbar, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbar.png", 1, 1));
	textures_.emplace(HealthbarSaco, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbarSaco.png", 1, 1));
	textures_.emplace(HealthbarBack, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/healthbarBack.png", 1, 1));
	textures_.emplace(RoundCounter, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/RoundCounter.png", 2, 1));
	textures_.emplace(CharacterSelection, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/characters_selection.png", 4, 1));
	textures_.emplace(Mark1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/marco1.png", 1, 1));
	textures_.emplace(Mark2, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/UI/marco2.png", 1, 1));
	textures_.emplace(SeismicShock, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/Seismicshock.png", 1, 1));
	textures_.emplace(ExplosiveWillpower, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/ExplosiveWillpower.png", 1, 1));
	textures_.emplace(RandomRage, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/RandomRage.png", 1, 1));
	textures_.emplace(KnifeDance, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/KnifeDance.png", 1, 1));

	textures_.emplace(GanonSheet, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/characters/Ganonbot_spritesheet.png", 15, 23));
	textures_.emplace(F10rSheet, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/characters/flor_spritesheet.png", 6, 25));

	textures_.emplace(MkHk, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/attacks/MkWH00PHk.png", 1, 1));
	textures_.emplace(F10RHp, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/attacks/F10RHp.png", 1, 1));
	textures_.emplace(F10RHk, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/attacks/F10RHk.png", 1, 1));

	textures_.emplace(BackgroundFight, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/FONDO.png", 2, 1));

	textures_.emplace(Mg1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/mg1.png", 1, 1));
	textures_.emplace(Mg21, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/mg2-1.png", 1, 1));
	textures_.emplace(Mg22, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/mg2-2.png", 1, 1));
	textures_.emplace(Ss1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/ss1.png", 1, 1));
	textures_.emplace(Ss2, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/ss2.png", 1, 1));
	textures_.emplace(Ew1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/ew1.png", 1, 1));
	textures_.emplace(So1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/so1.png", 1, 1));
	textures_.emplace(Mp1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/mp1.png", 1, 1));
	textures_.emplace(Hs1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/hs1.png", 1, 1));
	textures_.emplace(As2, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/as2.png", 1, 1));
	textures_.emplace(Vs1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/vs1.png", 1, 1));
	textures_.emplace(Ll1, new Texture(app_->getRenderer(), "../../../../assets/Assets/images/skills/laserlineal-2.png", 1, 1));	
	// textures_.emplace("key", new Texture(app_->getRenderer(), "Filepath", cols, fils));
}

Font* AssetsManager::getFont(AssetsManager::FontNames id)
{
	return fonts_[id];
}

void AssetsManager::loadFonts()
{
	fonts_.emplace(Roboto_Black, new Font("../../../../assets/Assets/Fonts/Roboto-Black.ttf", 20, 0.5));
	// fonts_.emplace_back(new Font("Filepath", size));
}

Mix_Music* AssetsManager::getMusic(AssetsManager::MusicNames id)
{
	return music_[id];
}

void AssetsManager::loadMusic()
{
	//size_t id = 1;

	music_.emplace(MENU_PRINCIPAL, app_->getAudioMngr()->loadMusic("../../../../assets/Assets/Sounds/Songs/New Hope menu.ogg"));
	music_.emplace(MENU_OPCIONES, app_->getAudioMngr()->loadMusic("../../../../assets/Assets/Sounds/Songs/Never Surrender.ogg"));
	music_.emplace(FIGHT_1, app_->getAudioMngr()->loadMusic("../../../../assets/Assets/Sounds/Songs/Boss Fight.ogg"));
	//music_.emplace(Nombre,app_->getAudioManager()->loadMusic("../../../../assets/Assets/Sounds/Songs/nombre de la cancion. formato"));

}

Mix_Chunk* AssetsManager::getSFX(AssetsManager::SFXNames id)
{	
	return sfx_[id];
}
void AssetsManager::loadSFX()
{
	
	sfx_.emplace(MKWOP_1, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/Taunts/MKW00P/buzz.wav"));
	sfx_.emplace(MKWOP_2, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/Taunts/MKW00P/clonk.wav"));
	sfx_.emplace(MKWOP_3, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/Taunts/MKW00P/piribi.wav"));
	sfx_.emplace(MKWOP_4, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/Taunts/MKW00P/robotau.wav"));
	sfx_.emplace(MKWOP_5, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/Taunts/MKW00P/robotay.wav"));
	/*sfx_.emplace(AISHA_1, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/SFX/punch.wav"));
	sfx_.emplace(AISHA_1, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/SFX/punch.wav"));
	sfx_.emplace(AISHA_1, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/SFX/punch.wav"));
	sfx_.emplace(AISHA_1, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/SFX/punch.wav"));
	sfx_.emplace(AISHA_1, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/SFX/punch.wav"));*/
	sfx_.emplace(PUNCH, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/SFX/punch.wav"));
	sfx_.emplace(KICK, app_->getAudioMngr()->loadSFX("../../../../assets/Assets/Sounds/SFX/patada.wav"));

}
//void AssetsManager::playMusic(const string& name, int channel)
//{
//}
//
//void AssetsManager::resumeAll()
//{
//}
//
//void AssetsManager::resumeMusic()
//{
//}
//
//void AssetsManager::pauseMusic()
//{
//}
//
//void AssetsManager::stopMusic()
//{
//}
//
//int AssetsManager::getGeneralVolume() const
//{
//	return 0;
//}
//
//int AssetsManager::getMusicVolume() const
//{
//	return 0;
//}
//
//int AssetsManager::getChannelVolume(int channel) const
//{
//	return 0;
//}
//
//void AssetsManager::setGeneralVolume(float volume_ratio)
//{
//}
//
//void AssetsManager::setChannelvolume(int channel, float volume_ratio)
//{
//}
//
//void AssetsManager::setMusicVolume(float volume_ratio)
//{
//}
//
//void AssetsManager::setSFXVolume(const string& name, float volume_ratio)
//{
//}

AssetsManager::~AssetsManager()
{
	UnloadAssets();
}

void AssetsManager::UnloadAssets()
{
	for (auto tex = textures_.begin(); tex != textures_.end(); ++tex) {
		delete tex->second;
	}
	for (auto font = fonts_.begin(); font != fonts_.end(); ++font) {
		delete font->second;
	}
}
