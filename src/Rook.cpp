#include "Rook.h"
#include "Piece.h"

Rook::Rook(int color, Board* board, int row, int col) :Piece(color,board,row,col){

}
bool Rook::isValidMove(int target_row, int target_col) {
	
	if (_row != target_row && _col != target_col)
		return false;

	return Piece::isValidMove(target_row, target_col);

}

std::vector<std::tuple<int, int>> Rook::getAllvalidMoves() {
	
	std::vector<std::tuple<int, int>> moves;
	traverseRows(moves);
	traverseCols(moves);
	return moves;		
}


void Rook::traverseRows(std::vector<std::tuple<int, int>>& moves) {
	
	for (int i = _row + 1; i < ROW_LENGTH; i++)
	{
		Piece* current = _game_board->getPiece(i, _col);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(i, _col));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(i, _col));
			break;
		}
	}

	for (int i = _row - 1; i >= 0; i--)
	{
		Piece* current = _game_board->getPiece(i, _col);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(i, _col));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(i, _col));
			break;
		}
	}
}
void Rook::traverseCols(std::vector<std::tuple<int, int>>& moves) {

	for (int i = _col + 1; i < COL_LENGTH; i++)
	{
		Piece* current = _game_board->getPiece(_row, i);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(_row, i));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(_row, i));
			break;
		}
	}

	for (int i = _col - 1; i >= 0; i--)
	{
		Piece* current = _game_board->getPiece(_row,i);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(_row, i));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(_row, i));
			break;
		}
	}
}