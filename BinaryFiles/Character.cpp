#include "Character.h"

Character::Character()
{
	health = 100;
	damage = 20;
	test = 15;
}

Character::Character(float Health, float Damage)
{
	health = Health;
	damage = Damage;
}

bool Character::getIsAlive()
{
	return health > 0;
}

void Character::attack(Character* other)
{
	other->takeDamage(damage);
}

float Character::takeDamage(float damage)
{
	health -= damage;
	return damage;

}