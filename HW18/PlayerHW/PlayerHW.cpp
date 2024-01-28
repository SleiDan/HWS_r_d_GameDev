#include <string>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
	//Game cycle
	Player player1("OnePunchMan", new SniperRifle);
	Player player2("JohnCena", new Axe, new DefenderClass);
	//TODO: Other players with other weapons and classes to properly cover different test-cases
	Player player3("Muhamed Ali", new BareHand, new DefenderClass);
	Player player4("Attacker", new AssaultRifle, new AttackerClass);



	player1.attack(player2, 500);
	player1.attack(player2, 2000);
	player1.attack(player1, 300);
	player2.attack(player1, 100);
	player1.attack(player2, 500);
	player3.attack(player2, 1000);
	player3.attack(player1, 500);
	player4.attack(player3, 800);
	player2.attack(player4, 600);



	return 0;
}