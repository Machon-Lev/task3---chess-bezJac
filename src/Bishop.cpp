#include "Bishop.h"

Bishop::Bishop(int color, Board* board, int row, int col) :Piece(color, board, row, col) {}

bool Bishop::isValidMove(int target_row, int target_col) {
	if (_row == target_row || _col == target_col)
		return false;
	return Piece::isValidMove(target_row, target_col);
}


std::vector<std::tuple<int, int>> Bishop::getAllvalidMoves() {
	std::vector<std::tuple<int, int>> moves;
	traverseleftToRightDiagonal(moves);
	traverseRightToLeftDiagonal(moves);
	return moves;
}

std::vector<std::tuple<int, int>> Bishop::traverseleftToRightDiagonal(std::vector<std::tuple<int, int>>& moves) {
	for (int i = _row + 1, j = _col + 1; i < ROW_LENGTH && j < COL_LENGTH; i++, j++)
	{
		Piece* current = _game_board->getPiece(i, j);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(i, j));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(i, j));
			break;
		}
	}

	for (int i = _row - 1, j = _col - 1; i >= 0 && j >= 0; i--, j--)
	{
		Piece* current = _game_board->getPiece(i, j);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(i, j));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(i, j));
			break;
		}
	}
	return moves;
}
std::vector<std::tuple<int, int>> Bishop::traverseRightToLeftDiagonal(std::vector<std::tuple<int, int>>& moves) {
	for (int i = _row + 1, j = _col - 1; i < ROW_LENGTH && j >=0; i++, j--)
	{
		Piece* current = _game_board->getPiece(i, j);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(i, j));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(i, j));
			break;
		}
	}

	for (int i = _row - 1, j = _col + 1; i >= 0 && j < COL_LENGTH; i--, j++)
	{
		Piece* current = _game_board->getPiece(i, j);
		if (current == nullptr)
			moves.push_back(std::tuple<int, int>(i, j));
		else if (current->getColor() == _color)
			break;
		else {
			moves.push_back(std::tuple<int, int>(i, j));
			break;
		}
	}
	return moves;
}


