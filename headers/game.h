#ifndef UNTITLED4_GAME_H
#define UNTITLED4_GAME_H
#include"SFML/Graphics.hpp"
#include"field.h"
#include"button.h"


class game{
private:
    bool end{};
    bool sbWin{};
    sf::RenderWindow *window;
    field *field[3][3]{};
    int moves[3][3]{};
    button *exit;
    button *restart;
    sf::RectangleShape *winBox;
    sf::RectangleShape *winBoxBg;
public:
    void run();
    void initStain();
    explicit game();
    void makeBotMove();
    bool cheekIfNoMoves();
    void restartStain();
    void cheekForWin();
    void win(int winner);
    void update(sf::Vector2i mousePosition);
    void updateFunctionalButton(sf::Vector2i mousePosition);
    void updateStain(sf::Vector2i mousePosition);
    void initVariables();
    void makePlayerMove(class field* button);
};
#endif
