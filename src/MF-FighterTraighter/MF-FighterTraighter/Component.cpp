#include "Component.h"

Component::Component():entity_(nullptr), app_(nullptr),id_()	
{}

Component::Component(ecs::CmpId id):entity_(nullptr),app_(nullptr),id_(id)
{}

Component::~Component()
{}
