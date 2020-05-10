#pragma once
#include "UserData.h"
#include "Vector2D.h"

class HitboxData :  public UserData
{
public:
	HitboxData(double damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, bool mHit = false, bool proy = false) : UserData(e),
		damage_(damage), time_(time), hitstun_(hitstun), knockBack_(knockback), guardBreaker_(guardbreaker), id_(id), multiHit_(mHit), proyectile_(proy){}
	virtual ~HitboxData() {}
	virtual void onHit(b2Fixture* other) {
		if (!multiHit_ && !destroy_) {			
			entity_->getState()->killHitbox(it_, id_);
			destroy_ = true;
		}
	}
	void setIt(std::list<b2Fixture*>::iterator i) {
		it_ = i;
	}

	//returns true if the hitbox lifetime is over
	virtual void update() {
		if(--time_ <= 0 && !destroy_)	//actualizamos el tiempo de vida y si ha terminado y no ha sido "destruida" antes, se apunta a la lista de hitbox a destruir
		{
			entity_->getState()->killHitbox(it_, id_);
			destroy_ = true;
		}
	}

	//use this method to check if the hitbox can do damage
	//if a hitbox is not multiHit, it does damage everytime
	//if not,it does damage every "damage_frec" frames while the hitbox is alive
	virtual bool doesDamage() {
		if (multiHit_) {	//just in case
			aux_frec = max(0, aux_frec - 1);
			bool doDamage = aux_frec == 0;
			if (doDamage) {
				aux_frec = damage_frec;
			}
			return doDamage;
		}
		return !multiHit_;
	}
	//Establish the hitbox as a multiHit that hits every frame_time
	virtual void enableMultiHit(int frame_time) {
		multiHit_ = true;
		damage_frec = frame_time;
	}
	//Attributes
	std::list<b2Fixture*>::iterator it_; 
	unsigned int id_ = 1;
	double damage_ = -1,
		time_ = -1,
		hitstun_ = -1;
	Vector2D knockBack_; //Assuming looking to the right
	bool guardBreaker_ = false;
	bool destroy_ = false;//if its true it means that it has to be destroyed
	bool multiHit_ = false;	//si la hitbox es multiHit, solo se destruye cuando pasa su tiempo
	bool proyectile_ = false; //si la hitbox es un proyectil, para no eliminarla cuando aterrizas o te interrumpen un ataque
	int damage_frec = 0;	//frames that the hitbox is not doing damage 
	int aux_frec = 0;		//if aux_fec == 0, a multiHit hitbox can do damage
};

