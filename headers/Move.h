//
// Created by jakub on 08.06.2023.
//

#ifndef UNTITLED4_MOVE_H
#define UNTITLED4_MOVE_H


class Move {
int x, y;
public:
    Move(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    void setX(int x) {
        Move::x = x;
    }

    void setY(int y) {
        Move::y = y;
    }

    int getY() const {
        return y;
    }
};


#endif //UNTITLED4_MOVE_H
