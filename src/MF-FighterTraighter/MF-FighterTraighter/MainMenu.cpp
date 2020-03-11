#include "MainMenu.h"

#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"

#include "Font.h"

#include "App.h"
#include "consts.h"

MainMenu::MainMenu(App* app): GameState(app)
{
	
	cout << "Menu principal" << endl;
	init();
}

MainMenu::~MainMenu()
{

}

//void MainMenu::OnButtClick(string text) { std::cout << "Botón activado: "<< text << endl; };

void MainMenu::init()
{

	cout << "init" << endl;
	string filePath = "../../../../assets/Assets/images/UI/buttons.png";
	string filename_logo = "../../../../assets/Assets/images/UI/logo.png";
	texture_ = new Texture(app_->getRenderer(),filePath.c_str(), 3, 1);
	logo_ = new Texture(app_->getRenderer(), filename_logo.c_str(), 1, 1);

	Entity* logo = new Entity();
	
	Transform* transform=logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(WINDOW_WIDTH_/2, POS_Y_LOGO);
	
	RenderImage* img = logo->addComponent<RenderImage>(logo_);
	scene.push_back(logo);

	arcade = new Entity();
	arcade->setApp(app_);
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(POS_X_ARCADE, POS_Y_ARCADE);
	t->setWidth(WIDTH_BUTTON); 
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	arcade->addComponent<RenderImage>(texture_); //añadir textura
	Font* font = new Font("../../../../assets/Assets/Fonts/Roboto-Black.ttf", 20);	// Until TextureManager (or AssetManager) has Fonts
	arcade->addComponent<TextComponent>("ARCADE", font, 20);
	arcade->addComponent<Button>(ArcadeCallback);
	scene.push_back(arcade);
}
