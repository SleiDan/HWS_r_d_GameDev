#include "Player.h"
#include <iostream>

Player::~Player()
{
	delete m_class;
	delete m_weapon;
}

void Player::setWeapon(Weapon* weapon)
{
	delete m_weapon;
	m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
	delete m_class;
	m_class = playerClass;
}

void Player::attack(const Player& other, int distance)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	if (&other == this)
	{
		std::cout << "\n-------FRIENDLY FIRE!-------\n";
	}

	if (other.isEliminated())
	{
		std::cout << "Player " << other.getName() << " has been already eliminated!\n";
		return;
	}

	// TODO: Add miss-chance of the class into account
	float missChance = m_class->getMissChance();
	int chance = 1 + std::rand() % 100;
	if (chance > missChance * 100) // Check if the attack hits
	{
		// More damage-related modifiers can be added here
		int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());
		other.m_health -= damage;
		std::cout << "Player " << getName() << " attacked Player " << other.getName() << " with weapon " << m_weapon->getWeaponName() <<
			" with damage " << damage << std::endl;

		std::cout << "Health left: " << other.m_health << std::endl;

		if (m_health <= 0)
		{
			m_health = 0; // for consistency. For example, UI may not support properly negative values

			std::cout << "Player " << other.getName() << " was eliminated!\n";
		}
	}
	else
	{
		std::cout << "Player " << getName() << " attacked Player " << other.getName() << " with weapon " << m_weapon->getWeaponName() <<
			" and missed " << std::endl;
	}
}
