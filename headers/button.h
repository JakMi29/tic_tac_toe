#ifndef UNTITLED4_BUTTON_H
#define UNTITLED4_BUTTON_H
#include"SFML/Graphics.hpp"

#include "Move.h"

class button {
private:
    sf::Texture *click{};
    sf::RectangleShape *area;
    sf::Texture *idle;
    sf::Texture *hover;
public:
    void setTexture(sf::Texture *newTexture) {
        this->click = newTexture;
    }

    button(sf::RectangleShape *area, sf::Texture *idle, sf::Texture *hover);

    void update(sf::Vector2i mousePosition);

    sf::RectangleShape *getArea();
};

#endif //UNTITLED4_BUTTON_H
