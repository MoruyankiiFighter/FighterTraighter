#include "App.h"

int main(int argi, char* argc[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // check for memory leaks
	try{
	App app;
	app.run();
	}
	catch(...){
		std::cout << "EXCEPTION" << std::endl;
	}
	return 0;
}