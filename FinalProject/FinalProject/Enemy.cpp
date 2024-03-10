#include "Enemy.h"

Enemy::Enemy() : hitCount(0), expForKilling(20), damage(10) {}

int Enemy::getHitCount() const { return hitCount; }
void Enemy::incrementHitCount() { hitCount++; }
bool Enemy::operator==(const Enemy& other) const { return this == &other; }
int Enemy::getExpForKilling() const { return expForKilling; }
int Enemy::getDamage() const { return damage; }