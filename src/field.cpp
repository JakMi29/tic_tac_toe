#include "field.h"

field::field(sf::RectangleShape *area, bool active, sf::Texture* idle, sf::Texture* hover, Move* index) : area(area), active(active), idle(idle), hover(hover), index(index) {}


sf::RectangleShape *field::getArea() {
    return area;
}



void field::update(const sf::Vector2i mousePosition) {
    if(this->active) {
        if (this->area->getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            this->area->setTexture(hover);
        } else {
            this->area->setTexture(idle);
        }
    }
}

bool field::isActive() const {
    return active;
}

Move* field::getIndex()  {
    return index;
}

void field::restartButton() {
    this->area->setTexture(nullptr);
    this->active=true;
    this->area->setTexture(this->idle);
}
