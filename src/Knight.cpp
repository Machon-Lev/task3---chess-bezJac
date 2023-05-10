#include "Knight.h"

Knight::Knight(int color, Board* board, int row, int col):Piece(color,board,row,col){}
bool Knight::isValidMove(int target_row, int target_col) {
	if (_row == target_row || _col == target_col)
		return false;
	return Piece::isValidMove(target_row, target_col);
}


std::vector<std::tuple<int, int>> Knight::getAllvalidMoves() {
	std::vector<std::tuple<int, int>> moves;
	return moves;
}


