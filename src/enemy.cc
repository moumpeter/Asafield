#include "enemy.h"

Enemy::Enemy(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed)
	:Dynamic{file_path, width, height, pos, speed}
{ }
