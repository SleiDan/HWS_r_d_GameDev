#include <iostream>
#include <vector>

class Rectangle {
private:
    float length;
    float height;

public:
    // Constructors
    Rectangle() : length(0.0f), height(0.0f) {}
    Rectangle(float l, float h) : length(l), height(h) {}

    // Methods
    float getArea() const {
        return length * height;
    }

    float getPerimeter() const {
        return 2 * (length + height);
    }
};

enum PlayerClass {
    ASSAULT,
    SUPPORT,
    SNIPER,
    MEDIC
};

class Weapon {
public:
    std::string name;
    int damage;
    int range;

    Weapon(const std::string& n, int d, int r) : name(n), damage(d), range(r) {}
};

class Player {
private:
    std::string name;
    int health;
    PlayerClass playerClass;
    Weapon* weapon;

public:
    Player(const std::string& n, int h, PlayerClass pc) : name(n), health(h), playerClass(pc), weapon(nullptr) {}

    void setWeapon(Weapon* w) {
        weapon = w;
    }

    Weapon* getWeapon() const {
        return weapon;
    }

    void printPlayerInfo() const {
        std::cout << "Name: " << name << ", Health: " << health << ", Class: ";
        switch (playerClass) {
            case ASSAULT:
                std::cout << "Assault";
                break;
            case SUPPORT:
                std::cout << "Support";
                break;
            case SNIPER:
                std::cout << "Sniper";
                break;
            case MEDIC:
                std::cout << "Medic";
                break;
        }

        if (weapon != nullptr) {
            std::cout << ", Weapon: " << weapon->name << ", Damage: " << weapon->damage << ", Range: " << weapon->range;
        }

        std::cout << std::endl;
    }
};

class Team {
private:
    std::string teamName;
    std::vector<Player*> players;
    int numParticipants; // New field

public:
    Team(const std::string& name) : teamName(name), numParticipants(0) {}

    bool addPlayer(Player* p) {
        // Check if player is not already in the team
        std::vector<Player*>::iterator it = std::find(players.begin(), players.end(), p);
        if (it == players.end()) {
            players.push_back(p);
            numParticipants++;
            return true;
        }
        return false;
    }

    bool removePlayer(Player* p) {
        // Find player and remove if found
        std::vector<Player*>::iterator it = std::find(players.begin(), players.end(), p);
        if (it != players.end()) {
            players.erase(it);
            numParticipants--;
            return true;
        }
        return false;
    }

    void printTeamInfo() const {
        std::cout << "Team: " << teamName << ", Participants: " << numParticipants << std::endl;
        for (const auto& player : players) {
            player->printPlayerInfo();
        }
    }
};

int main() {
    // Creating rectangles
    Rectangle* rect1 = new Rectangle();
    Rectangle* rect2 = new Rectangle(5.0f, 10.0f);
    Rectangle* rect3 = new Rectangle(10.0f, 20.0f);

    // Printing rectangle information
    std::cout << "Rectangle 1 - Area: " << rect1->getArea() << ", Perimeter: " << rect1->getPerimeter() << std::endl;
    std::cout << "Rectangle 2 - Area: " << rect2->getArea() << ", Perimeter: " << rect2->getPerimeter() << std::endl;
    std::cout << "Rectangle 3 - Area: " << rect3->getArea() << ", Perimeter: " << rect3->getPerimeter() << std::endl << std::endl;

    // Creating weapons
    Weapon* ak47 = new Weapon("AK-47", 30, 300);
    Weapon* sniperRifle = new Weapon("AWP", 100, 1000);
    Weapon* shotgun = new Weapon("Shotgun", 50, 200);
    Weapon* medkit = new Weapon("Medkit", 0, 50);

    // Creating players
    Player* player1 = new Player("John", 100, ASSAULT);
    Player* player2 = new Player("Alice", 90, SNIPER);
    Player* player3 = new Player("Bob", 95, SUPPORT);
    Player* player4 = new Player("Eve", 85, MEDIC);

    player1->setWeapon(ak47);
    player2->setWeapon(sniperRifle);
    player3->setWeapon(shotgun);
    player4->setWeapon(medkit);

    // Creating teams
    Team* teamA = new Team("Team A");
    Team* teamB = new Team("Team B");

    // Adding players to teams
    teamA->addPlayer(player1);
    teamB->addPlayer(player2);
    teamB->addPlayer(player3);
    teamB->addPlayer(player4);

    // Printing team information
    teamA->printTeamInfo();
    std::cout << std::endl;
    teamB->printTeamInfo();

    // Cleaning up memory
    delete ak47;
    delete sniperRifle;
    delete shotgun;
    delete medkit;
    delete player1;
    delete player2;
    delete player3;
    delete player4;
    delete teamA;
    delete teamB;
    delete rect1;
    delete rect2;
    delete rect3;

    return 0;
}
