#include "dynamic.h"


Dynamic::Dynamic(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed)
    :GameObject{file_path, width, height, pos}, speed{speed}
    {}