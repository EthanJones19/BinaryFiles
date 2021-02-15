#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);

	float health;
	float damage;
	float test;
	void attack(Character* other);
	float takeDamage(float damage);
	bool getIsAlive();
	float getDamage() { return damage; }
	float getHealth() { return health; }
};