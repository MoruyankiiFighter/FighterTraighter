#include "PlayerData.h"

PlayerData::PlayerData(std::vector<SDL_Scancode> keys, double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, Vector2D speed, double ini_health, double attack, double defense) :
    Component(ecs::PlayerData), width_(width), height_(height), rotation_(rotation), jump_impulse_(jump_impulse), initial_position_(ini_pos), speed_(speed), initial_health_(ini_health), attack_(attack), defense_(defense){
    leftKey_ = keys[0]; righKey_ = keys[1]; jumpKey_ = keys[2]; crouchKey_ = keys[3]; guardKey_ = keys[8];
    normalPunchKey_ = keys[4]; hardPunchKey_ = keys[5]; normalKickKey_ = keys[6]; hardKickKey_ = keys[7];
    //--!-- faltan keys de guarbreaker y abilities
}