#include <iostream>
#include"game.h"
#include<cstdlib>
#include "MinMax.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"

void game::run() {
    while (window->isOpen()) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
                if (exit->getArea()->getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    window->close();
                }

                if (restart->getArea()->getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    this->restartStain();
                }
                if (!this->end && !sbWin) {
                    for (auto &item: field) {
                        for (const auto &item1: item) {
                            if (item1->getArea()->getGlobalBounds().contains(mousePosition.x, mousePosition.y) &&
                                item1->isActive()) {
                                this->makePlayerMove(item1);
                            }
                        }
                    }
                }

            }
        }
        window->clear(sf::Color::Black);
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        this->update(mousePosition);
        for (const auto &item: field) {
            for (const auto &item1: item) {
                window->draw(*item1->getArea());
            }
        }
        if (sbWin) {
            window->draw(*this->winBoxBg);
            window->draw(*this->winBox);
        }
        window->draw(*restart->getArea());
        window->draw(*exit->getArea());
        if(this->end){
            auto *texture = new sf::Texture;
            texture->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\draw.png)");
            this->winBox->setTexture(texture);
            window->draw(*this->winBox);
        }
        window->display();
    }
}

void game::initVariables() {
    this->sbWin = false;
    this->end = false;
    for (auto &move: moves) {
        for (auto &item: move) {
            item = 0;
        }
    }
}

game::game() {
    this->initStain();
    this->initVariables();
    this->window = new sf::RenderWindow(sf::VideoMode(680, 880), "Duży kwadratowy przycisk");
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);
}


void game::initStain() {
    auto *shape = new sf::RectangleShape(sf::Vector2f(680, 400));
    shape->setPosition(0, 320);
    sf::Color rectColor(255, 255, 255, 168);
    shape->setFillColor(rectColor);
    this->winBox = shape;

    shape = new sf::RectangleShape(sf::Vector2f(680, 880));
    shape->setPosition(0, 0);
    rectColor = sf::Color(0, 0, 0, 168);
    shape->setFillColor(rectColor);
    this->winBoxBg = shape;

    auto *texture1 = new sf::Texture;
    texture1->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\ei.png)");
    auto *texture2 = new sf::Texture;
    texture2->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\eh.png)");
    shape = new sf::RectangleShape(sf::Vector2f(200, 100));
    shape->setPosition(80, 50);
    this->exit = new button(shape, texture1, texture2);

    texture1 = new sf::Texture;
    texture1->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\ri.png)");
    texture2 = new sf::Texture;
    texture2->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\rh.png)");
    shape = new sf::RectangleShape(sf::Vector2f(200, 100));
    shape->setPosition(380, 50);
    this->restart = new button(shape, texture1, texture2);

    texture1 = new sf::Texture;
    texture1->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\p1.png)");
    texture2 = new sf::Texture;
    texture2->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\p2.png)");
    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(20, 220);
    this->field[0][0] = new class field(shape, true, texture1, texture2, new Move(0, 0));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(240, 220);
    this->field[0][1] = new class field(shape, true, texture1, texture2, new Move(0, 1));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(460, 220);
    this->field[0][2] = new class field(shape, true, texture1, texture2, new Move(0, 2));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(20, 440);
    this->field[1][0] = new class field(shape, true, texture1, texture2, new Move(1, 0));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(240, 440);
    this->field[1][1] = new class field(shape, true, texture1, texture2, new Move(1, 1));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(460, 440);
    this->field[1][2] = new class field(shape, true, texture1, texture2, new Move(1, 2));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(20, 660);
    this->field[2][0] = new class field(shape, true, texture1, texture2, new Move(2, 0));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(240, 660);
    this->field[2][1] = new class field(shape, true, texture1, texture2, new Move(2, 1));

    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setPosition(460, 660);
    this->field[2][2] = new class field(shape, true, texture1, texture2, new Move(2, 2));
}


void game::update(sf::Vector2i mousePosition) {
    if (!this->sbWin)
        this->updateStain(mousePosition);
    this->updateFunctionalButton(mousePosition);
}

void game::updateStain(sf::Vector2i mousePosition) {

    for (const auto &item: field) {
        for (const auto &item1: item) {

            item1->update(mousePosition);
        }
    }
}

void game::updateFunctionalButton(sf::Vector2i mousePosition) {
    this->exit->update(mousePosition);
    this->restart->update(mousePosition);

}

void game::makeBotMove() {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<moves[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    MinMax minMax;
    Move move = minMax.findBestMove(this->moves);
    this->moves[move.getY()][move.getX()]=2;
    //std::cout<<move.getY()<<" "<<move.getX()<<std::endl;
    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\kk.png)");
    this->field[move.getY()][move.getX()]->setTexture(texture);
    this->field[move.getY()][move.getX()]->setMove();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<moves[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    /*srand(time(0));
    std::vector<std::pair<int,int>> vector;
    int i=0;
    int j=0;
    for (const auto &move: this->moves) {
        for (const auto &item: move) {
            if(item!=1&&item!=2){
                vector.push_back(std::pair(j,i));
            }
            i++;
        }
        j++;
        i=0;
    }
    int choice=rand()%vector.size();
    this->moves[vector[choice].first][vector[choice].second]=2;
    sf::Texture *texture=new sf::Texture;
    texture->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\kk.png)");
    this->field[vector[choice].first][vector[choice].second]->setTexture(texture);
    this->field[vector[choice].first][vector[choice].second]->setMove();
*/

}

bool game::cheekIfNoMoves() {
    for (const auto &move1: moves) {
        for (const auto &move: move1) {
            if (move != 1 && move != 2)
                return true;
        }
    }
    this->end = true;
    return false;
}

void game::restartStain() {
    this->sbWin = false;
    this->end=false;
    for (const auto &item: field) {
        for (const auto &item1: item) {

            item1->restartButton();
        }
    }
    for (auto &move: moves) {
        for (auto &item: move) {
            item = 0;
        }
    }
}

void game::cheekForWin() {
    if (this->moves[0][0] != 0 && this->moves[0][0] == this->moves[0][1] && this->moves[0][1] == this->moves[0][2])
        this->win(this->moves[0][0]);
    if (this->moves[1][0] != 0 && this->moves[1][0] == this->moves[1][1] && this->moves[1][1] == this->moves[1][2])
        this->win(this->moves[1][0]);
    if (this->moves[2][0] != 0 && this->moves[2][0] == this->moves[2][1] && this->moves[2][1] == this->moves[2][2])
        this->win(this->moves[2][0]);

    if (this->moves[0][0] != 0 && this->moves[0][0] == this->moves[1][0] && this->moves[1][0] == this->moves[2][0])
        this->win(this->moves[0][0]);
    if (this->moves[0][1] != 0 && this->moves[0][1] == this->moves[1][1] && this->moves[1][1] == this->moves[2][1])
        this->win(this->moves[1][1]);
    if (this->moves[0][2] != 0 && this->moves[0][2] == this->moves[1][2] && this->moves[1][2] == this->moves[2][2])
        this->win(this->moves[2][2]);

    if (this->moves[0][0] != 0 && this->moves[0][0] == this->moves[1][1] && this->moves[1][1] == this->moves[2][2])
        this->win(this->moves[0][0]);
    if (this->moves[0][2] != 0 && this->moves[0][2] == this->moves[1][1] && this->moves[1][1] == this->moves[2][0])
        this->win(this->moves[0][2]);

}

void game::win(int winner) {
    this->sbWin = true;
    auto *texture = new sf::Texture;
    if (winner == 1)
        texture->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\wink.png)");
    else
        texture->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\winkk.png)");

    this->winBox->setTexture(texture);

}

void game::makePlayerMove(class field *button) {
    this->moves[button->getIndex()->getX()][button->getIndex()->getY()] = 1;
    auto *texture = new sf::Texture;
    texture->loadFromFile(R"(C:\Users\jakub\CLionProjects\untitled4\images\k.png)");
    button->setTexture(texture);
    button->setMove();
    this->cheekForWin();
    if (this->cheekIfNoMoves() && !this->sbWin)
        this->makeBotMove();
    this->cheekForWin();
}


#pragma clang diagnostic pop