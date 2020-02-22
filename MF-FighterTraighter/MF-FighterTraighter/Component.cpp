#include "Component.h"

Component::Component():entity_(nullptr), app_(nullptr),id_(NULL)	
{}

Component::Component(int id):entity_(nullptr),app_(nullptr),id_(id)
{}

Component::~Component()
{}
