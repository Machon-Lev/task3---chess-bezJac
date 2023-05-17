#include "Piece.h"


Piece::Piece(int color, Board* board, int row, int col):_color(color),_game_board(board),_row(row),_col(col){}

bool Piece::isValidMove(int target_row, int target_col) {
	
	auto legalMoves = getAllvalidMoves();
	std::tuple<int, int> move = std::make_tuple(target_row, target_col);

	// check that move is in legal moves of piece
	if (std::find(legalMoves.begin(), legalMoves.end(), move) == legalMoves.end())
		return false;
	return true;
}