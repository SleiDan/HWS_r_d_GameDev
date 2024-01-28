#include "Weapon.h"

float SniperRifle::getPrecision(int distance) const
{
	//This const values can be moved later into a config file
	//so they can be modified more granuarily on the go(by other programmers or designers) without need to modify code
	if (distance > 2000)
	{
		return 0.2f;
	}
	if (distance > 1000)
	{
		return 1.5f;
	}
	if (distance > 300)
	{
		return 5.0f;
	}
	return 1.0f;
}

float Pistol::getPrecision(int distance) const
{
	if (distance > 2000)
	{
		return 0.f;
	}
	if (distance > 1000)
	{
		return 0.5f;
	}
	if (distance > 300)
	{
		return 2.0f;
	}
	return 1.0f;
}

float AssaultRifle::getPrecision(int distance) const
{
	if (distance > 2000)
	{
		return 0.1f;
	}
	if (distance > 1000)
	{
		return 1.5f;
	}
	if (distance > 300)
	{
		return 3.0f;
	}
	return 1.0f;
}

float BareHand::getPrecision(int distance) const
{
	if(distance > 100)
	{
		return 1.0f;
	}
	else
	{
		return 0.f;
	}
}

float Axe::getPrecision(int distance) const
{
	if(distance > 150)
	{
		return 10.0f;
	}
	else
	{
		return 0.f;
	}
}
