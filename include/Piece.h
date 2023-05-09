#pragma once
#include "Board.h"
#include <vector>
class Board;

class Piece {
protected:
	int _color;
	Board* _game_board;
	int _row;
	int _col;
public:
	Piece(int color, Board* board,int row,int col);
	virtual bool isValidMove(int target_row, int target_col) = 0 ;
	virtual std::vector<std::tuple<int, int>> getAllvalidMoves() = 0;
	int getColor() { return _color; }
	int getRow() { return _row; }
	int getCol() { return _col; }
	void setRow(int row) { _row = row; }
	void setCol(int col) { _col = col; }
};