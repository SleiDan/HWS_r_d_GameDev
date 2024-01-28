// PlayerClass.h
#pragma once

class PlayerClass
{
public:
	virtual float getDamageMultiplier() const = 0;
	virtual float getArmorMultiplier() const = 0;
	virtual float getMissChance() const = 0;

	virtual ~PlayerClass() {} // virtual destructor for proper destruction of the objects in hierarchy
};

class DefaultClass : public PlayerClass
{
public:
	virtual float getDamageMultiplier() const override { return 1.0f; }
	virtual float getArmorMultiplier() const override { return 1.0f; }
	virtual float getMissChance() const override { return 0.0f; }
};

class DefenderClass : public DefaultClass
{
public:
	virtual float getDamageMultiplier() const override { return 0.9f; }
	virtual float getArmorMultiplier() const override { return 1.2f; }
	virtual float getMissChance() const override { return 0.1f; }
};

class AttackerClass : public DefaultClass
{
public:
	virtual float getDamageMultiplier() const override { return 1.1f; }
	// Leave modifyArmor and getMissChance as is
};

class LuckyManClass : public DefaultClass
{
public:
	virtual float getMissChance() const override { return 0.3f; } // High miss chance rate
};

class BerserkClass : public AttackerClass, public LuckyManClass
{
public:
	virtual float getArmorMultiplier() const override { return 0.5f; } // Very low armor rate
};

// You can add more player classes as needed

// PlayerClass.cpp
#include "PlayerClass.h"
