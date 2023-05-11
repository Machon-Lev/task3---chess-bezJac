#include "Queen.h"

Queen::Queen(int color, Board* board, int row, int col) :Piece(color, board, row, col) {}

bool Queen::isValidMove(int target_row, int target_col){
	return Piece::isValidMove(target_row,target_col);
}
std::vector<std::tuple<int, int>> Queen::getAllvalidMoves() {
	std::vector<std::tuple<int, int>> moves;
	traverseleftToRightDiagonal(moves);
	traverseRightToLeftDiagonal(moves);
	traverseRows(moves);
	traverseCols(moves);
	return moves;
}

void Queen::traverseleftToRightDiagonal(std::vector<std::tuple<int, int>>& moves) {
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
}
void Queen::traverseRightToLeftDiagonal(std::vector<std::tuple<int, int>>& moves) {
	for (int i = _row + 1, j = _col - 1; i < ROW_LENGTH && j >= 0; i++, j--)
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
}

void Queen::traverseRows(std::vector<std::tuple<int, int>>& moves) {

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
void Queen::traverseCols(std::vector<std::tuple<int, int>>& moves) {

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
}