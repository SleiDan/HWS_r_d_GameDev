#pragma once
#include <string>

class Weapon
{
public:
	//Feel free to add other properties
	//Or use another approach for damage calculation:
	//health, stamina, weight, level, speed or whatever you have in mind.
	virtual int getDamageRate(int distance) const = 0;
	virtual std::string getWeaponName() const {return name;}
	int effectiveRange;
	int damageLevel;
private:
	std::string name = "WeaponName";
};

class RangedWeapon : public Weapon
{
public:
	int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

	//protected means this method is not accessible from outside but is accessible by children classes
protected:
	//Default value
	virtual float getPrecision(int distance) const { return 1.0f; }
};

class SniperRifle : public RangedWeapon
{
public:
	int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }
	std::string getWeaponName() const {return name;}
protected:
	virtual float getPrecision(int distance) const override;
private:
	std::string name = "SniperRifle";
};

class Pistol : public RangedWeapon
{
public:
	int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }
	std::string getWeaponName() const {return name;}

protected:
	virtual float getPrecision(int distance) const override;
private:
	std::string name = "Pistol";

};

class AssaultRifle : public RangedWeapon
{
public:
	int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }
	std::string getWeaponName() const {return name;}

protected:
	virtual float getPrecision(int distance) const override;
private:
	std::string name = "AssaultRifle";

};

class MeleeWeapon : public Weapon
{
public:
	virtual int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }
protected:
	//Default value
	virtual float getPrecision(int distance) const { return 1.0f; }
};

class BareHand : public MeleeWeapon
{
protected:
	virtual float getPrecision(int distance) const override;
	std::string getWeaponName() const {return name;}
private:
	std::string name = "BareHand";


};

class Axe : public MeleeWeapon
{
protected:
	//Default value
	virtual float getPrecision(int distance) const override;
	std::string getWeaponName() const {return name;}
private:
	std::string name = "Axe";


};

