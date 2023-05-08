#pragma once
#include "Piece.h"
#include <string>
#include <memory>

const int ROW_LENGTH = 8;
const int COL_LENGTH = 8;
const int  WHITE = 1;
const int BLACK = -1;


class Piece;

class Board {
	Piece* _board[ROW_LENGTH][COL_LENGTH];
	int _current_player;

	void initialize();
public:
	Board();
	~Board();
	int execute_command(int s_row, int s_col, int t_row, int t_col);
	Piece* getPiece(int row, int col) { return _board[row][col]; }
	int getPlayer() { return _current_player; }
	void movePiece(int s_row, int s_col, int t_row, int t_col);
	void undoMove(int s_row, int s_col, int t_row, int t_col, Piece* target);
	bool isInCheck(int player) { return false; }
	bool isCheckMate(int player) { return false; }
};