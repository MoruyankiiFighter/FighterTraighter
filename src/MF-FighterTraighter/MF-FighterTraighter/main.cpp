#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "App.h"

int main(int argi, char* argc[]) {
	App app = App();
	app.run();
	return 0;
}