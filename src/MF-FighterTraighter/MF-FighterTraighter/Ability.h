#pragma once
class Ability 
{
public:
	virtual ~Ability() {}
	virtual void effect_o_update() = 0;
	//cambiar estadisticas cuando las tenga el personaje
	//generar hitboxes con el hitbox manager o un animationChain y que contenga los callbacks
	//generar otras entidades / proyectiles 
}