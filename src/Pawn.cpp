#include "Pawn.h"


Pawn::Pawn(int color, Board* board, int row, int col) :Piece(color, board, row, col) {}

bool Pawn::isValidMove(int target_row, int target_col) {
	if ((_color ==WHITE &&target_row < _row) || target_col >_col + 1 || target_col < _col - 1)
		return false;
	if (hasPawnMoved() && target_row > _row + 1)
		return false;
	return Piece::isValidMove(target_row, target_col);
}
std::vector<std::tuple<int, int>> Pawn::getAllvalidMoves() {
	std::vector<std::tuple<int, int>> moves;
	int increment = (_color == WHITE) ? 1 : -1;
	if (checkCellStatus(_row + increment, _col))		//forward move
		moves.push_back(std::tuple<int, int>(_row + increment, _col));

	if (checkCellStatus(_row + increment, _col + 1))		//diagonal side 1
		moves.push_back(std::tuple<int, int>(_row + increment, _col+1));

	if (checkCellStatus(_row + increment, _col - 1))		// diagonal side 2
		moves.push_back(std::tuple<int, int>(_row + increment, _col-1));

	if (!hasPawnMoved())				//inital double forward move
		moves.push_back(std::tuple<int, int>(_row + 2 * increment, _col));

	return moves;
}

bool Pawn::hasPawnMoved() {
	if (_color == WHITE)
		return (_row == 1) ? false : true;
	else
		return (_row == 6) ? false : true;
}
bool Pawn::checkCellStatus(int row, int col) {
	
	// logic to check if cell is a legal move
	// called by getAllValidMoves().
	if (row >= ROW_LENGTH || col < 0 || col >= COL_LENGTH)
		return false;

	Piece* p = _game_board->getPiece(row, col);
	if (col == _col && (p == nullptr || p->getColor() != _color))
	{
			p = nullptr;
			return true;
	}
	else if(p != nullptr && p->getColor() != _color)
	{
		p = nullptr;
		return true;
	}
	p = nullptr;
	return false;
	
}
