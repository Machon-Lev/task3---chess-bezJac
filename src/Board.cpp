#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#include <memory>

Board::Board()
{
	initialize();
}

Board::~Board() {
	for (int i = 0; i < ROW_LENGTH; i++)
	{
		for (int j = 0; j < COL_LENGTH; j++)
		{
			if (_board[i][j] != nullptr)
				delete _board[i][j];
		}
	}
}
void Board::initialize() {

	for (int i = 0; i < ROW_LENGTH; i++)
	{
		for (int j = 0; j < COL_LENGTH; j++)
		{
			_board[i][j] = nullptr;
		}
	}
	_current_player = WHITE;
	_board[0][0] = new Rook(1, this, 0, 0);
	_board[0][7] = new Rook(1, this, 0, 7);
	_board[7][0] = new Rook(-1, this, 7, 0);
	_board[7][7] = new Rook(-1, this, 7, 7);
	_board[0][4] = new King(1, this, 0, 4);
	_board[7][4] = new King(-1, this, 7, 4);
}

int Board::execute_command(int row_source, int col_source, int row_target, int col_target) {


	Piece* source = _board[row_source][col_source];
	Piece* target = _board[row_target][col_target];

	if (source == nullptr)
		return 11;
	if (source->getColor() != _current_player)
		return 12;
	if (target != nullptr && target->getColor() == _current_player)
		return 13;
	if (!source->isValidMove(row_target, col_target))
		return 21;

	movePiece(row_source, col_source, row_target, col_target);

	int result;
	if (isInCheck(_current_player))
	{
		if (isCheckMate(_current_player))
			result = 31;
		else
			result = 21;
		undoMove(row_source, col_source, row_target, col_target, target);
		return result;
	}

	if (isInCheck(-(_current_player)))
		result = 41;
	else
		result = 42;

	delete target;
	_current_player = -_current_player;
	return result;
}

void Board::movePiece(int s_row, int s_col, int t_row, int t_col) {

	_board[t_row][t_col] = _board[s_row][s_col];
	_board[t_row][t_col]->setRow(t_row);
	_board[t_row][t_col]->setCol(t_col);

	_board[s_row][s_col] = nullptr;
}
void Board::undoMove(int s_row, int s_col, int t_row, int t_col, Piece* target)
{
	_board[s_row][s_col] = _board[t_row][t_col];
	_board[s_row][s_col]->setRow(s_row);
	_board[s_row][s_col]->setCol(s_col);
	_board[t_row][t_col] = target;
}