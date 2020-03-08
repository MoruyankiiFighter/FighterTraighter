#pragma once
enum phase {charing,attacking,recovering};
class Attack 
{
public:
	Attack(int startFrame, int endFrame, int chargeTime, int damageTime, int recoveryTime, int damage, double range) :
		startFrame(startFrame), endFrame( endFrame), chargeTime(chargeTime), damageTime(damageTime), 
		recoveryTime(recoveryTime), damage(damage), range(range)
	{}
	virtual ~Attack() {}
	void makeAttack();//do
	bool canAttack() { return available; }
private:
	//igual falta incluir algo de animaciones pero no estoy seguro

	int startFrame, endFrame;//the frame of the spreetSheet start the attack and end it
	int damage;
	int chargeTime,//time between its active and do damage
		damageTime,//time doing damage(prob 1 frame)
		recoveryTime;//time between doing damage and is available again this attack

	//if you can attack (e.g. if you are doing this attack, you cant do it again until the animation has end)
	bool available=true;
	double range;//Attacks's range

};

