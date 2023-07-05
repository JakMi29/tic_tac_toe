
#include"SFML/Graphics.hpp"
#include "Move.h"
#ifndef UNTITLED4_FIELD_H
#define UNTITLED4_FIELD_H
class field{
private:
    sf::Texture *click{};
    sf::RectangleShape *area;
    bool active;
    sf::Texture* idle;
    sf::Texture* hover;
    Move *index;
public:
    [[nodiscard]] bool isActive() const;

    void setTexture(sf::Texture *newTexture){
        this->click=newTexture;
    }
    void setMove(){
        this->area->setTexture(this->click);
        this->active=false;
    }

    void restartButton();

    [[nodiscard]] Move* getIndex();

    field(sf::RectangleShape *area, bool active, sf::Texture* idle, sf::Texture* hover, Move* index);

    void update(sf::Vector2i mousePosition);

    sf::RectangleShape *getArea() ;
};
#endif //UNTITLED4_FIELD_H
