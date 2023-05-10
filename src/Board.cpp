#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include <memory>

const int white_pawn_row = 1;
const int black_pawn_row = 6;

Board::Board()
{
	initializeBoard();
	_black_king = _board[7][4];
	_white_king = _board[0][4];
	_check_mate = 0;
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
	_white_king = nullptr;
	_black_king = nullptr;
}
void Board::initializeBoard() {

	for (int i = 0; i < ROW_LENGTH; i++)
		for (int j = 0; j < COL_LENGTH; j++)
			_board[i][j] = nullptr;

	_current_player = WHITE;
	_board[0][0] = new Rook(1, this, 0, 0);
	_board[0][7] = new Rook(1, this, 0, 7);
	_board[7][0] = new Rook(-1, this, 7, 0);
	_board[7][7] = new Rook(-1, this, 7, 7);
	_board[0][4] = new King(1, this, 0, 4);
	_board[7][4] = new King(-1, this, 7, 4);
	_board[0][2] = new Bishop(1, this, 0, 2);
	_board[0][5] = new Bishop(1, this, 0, 5);
	_board[7][2] = new Bishop(-1, this, 7,2);
	_board[7][5] = new Bishop(-1, this, 7, 5);
	_board[0][3] = new Queen(1, this, 0, 3);
	_board[7][3] = new Queen(-1, this, 7, 3);
	for (int column = 0; column < COL_LENGTH; column++)
	{
		_board[white_pawn_row][column] = new Pawn(1, this, white_pawn_row, column);
		_board[black_pawn_row][column] = new Pawn(-1, this,black_pawn_row, column);
	}
	
}
std::tuple<int, int> Board::getKingLocation(int player) {
	return (player == WHITE) ? std::tuple<int, int>(_white_king->getRow(), _white_king->getCol()) : std::tuple<int, int>(_black_king->getRow(), _black_king->getCol());
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
	if (_check_mate == _current_player)
		return 31;
	if (!source->isValidMove(row_target, col_target))
		return 21;
	if (isInCheck(_current_player) && isCheckMate(_current_player))
	{
		_check_mate = _current_player;
		return 31;
	}
	movePiece(row_source, col_source, row_target, col_target);

	
	if (isInCheck(_current_player))
	{
		undoMove(row_source, col_source, row_target, col_target, target);
		return 21;
	}

	int result;
	if (isInCheck(-(_current_player)))
		result = 41;
	else
		result = 42;

	if (target != nullptr)
		delete target;
	target = nullptr;
	source = nullptr;
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
	target = nullptr;
}

bool Board::isInCheck(int player) {
	std::tuple<int, int> king_location = getKingLocation(player);
	for (int i = 0; i < ROW_LENGTH; i++)
	{
		for (int j = 0; j < COL_LENGTH; j++)
		{
			Piece* p = _board[i][j];
			if (p != nullptr && p->getColor() != player)
			{
				auto p_moves = p->getAllvalidMoves();
				if (std::find(p_moves.begin(), p_moves.end(), king_location) != p_moves.end())
					return true;

			}
		}
	}
	return false;
}
bool Board::isCheckMate(int player) {
	int target_row, target_col;
	Piece* target;
	for (int i = 0; i < ROW_LENGTH; i++)
	{
		for (int j = 0; j < COL_LENGTH; j++)
		{
			Piece* source = _board[i][j];
			if (source != nullptr && source->getColor() == player)
			{
				auto p_moves = source->getAllvalidMoves();
				for (auto move : p_moves)
				{
					target_row = std::get<0>(move);
					target_col = std::get<1>(move);
					target = _board[target_row][target_col];
					movePiece(i, j, target_row, target_col);
					if (!isInCheck(player))
					{
						undoMove(i,j, target_row, target_col, target);
						return false;
					}
					undoMove(i, j, target_row, target_col, target);
					target = nullptr;
				}
			}
			source = nullptr;
		}
	}
	return true;
}
