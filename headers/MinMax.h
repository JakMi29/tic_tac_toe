#ifndef UNTITLED4_MINMAX_H
#define UNTITLED4_MINMAX_H
#include "Move.h"
#include<bits/stdc++.h>

using namespace std;
class MinMax{
    bool isMovesLeft(int tab[3][3])
    {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if (tab[i][j]==0)
                    return true;
        }
        return false;
    }


    int evaluate(int b[3][3])
    {
        for (int row = 0; row<3; row++)
        {
            if (b[row][0]==b[row][1] &&
                b[row][1]==b[row][2])
            {
                if (b[row][0]==2)
                    return +10;
                else if (b[row][0]==1)
                    return -10;
            }
        }

        for (int col = 0; col<3; col++)
        {
            if (b[0][col]==b[1][col] &&
                b[1][col]==b[2][col])
            {
                if (b[0][col]==2)
                    return +10;

                else if (b[0][col]==1)
                    return -10;
            }
        }

        if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
        {
            if (b[0][0]==2)
                return +10;
            else if (b[0][0]==1)
                return -10;
        }

        if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
        {
            if (b[0][2]==2)
                return +10;
            else if (b[0][2]==1)
                return -10;
        }


        return 0;
    }


public: int minimax(int board[3][3], int depth, bool isMax)
    {
        int score = evaluate(board);


        if (score == 10)
            return score;

        if (score == -10)
            return score;

        if (!isMovesLeft(board))
            return 0;


        if (isMax)
        {
            int best = -1000;


            for (int i = 0; i<3; i++)
            {
                for (int j = 0; j<3; j++)
                {

                    if (board[i][j]==0)
                    {

                        board[i][j] = 2;


                        best = max( best,
                                    minimax(board, depth+1, !isMax) );


                        board[i][j] = 0;
                    }
                }
            }
            return best;
        }
        else
        {
            int best = 1000;

            for (int i = 0; i<3; i++)
            {
                for (int j = 0; j<3; j++)
                {
                    if (board[i][j]==0)
                    {
                        board[i][j] = 1;

                        best = min(best,
                                   minimax(board, depth+1, !isMax));

                        board[i][j] = 0;
                    }
                }
            }
            return best;
        }
    }

    Move findBestMove(int board[3][3])
    {
        int bestVal = -1000;
        Move bestMove(-1,-1);


        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {

                if (board[i][j]==0)
                {
                    board[i][j] = 2;


                    int moveVal = minimax(board, 0, false);


                    board[i][j] = 0;


                    if (moveVal > bestVal)
                    {
                        bestMove.setY(i);
                        bestMove.setX(j);
                        bestVal = moveVal;
                    }
                }
            }
        }

        return bestMove;
    }
};
#endif UNTITLED4_MINMAX_H
