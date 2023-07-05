#include "button.h"

button::button(sf::RectangleShape *area, sf::Texture* idle, sf::Texture* hover) : area(area), idle(idle), hover(hover) {}

sf::RectangleShape *button::getArea() {
    return area;
}
void button::update(const sf::Vector2i mousePosition) {
        if (this->area->getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            this->area->setTexture(hover);
        } else {
            this->area->setTexture(idle);
        }
}


