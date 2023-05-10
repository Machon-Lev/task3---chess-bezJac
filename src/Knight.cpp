#include "Knight.h"

Knight::Knight(int color, Board* board, int row, int col) :Piece(color, board, row, col) {}
bool Knight::isValidMove(int target_row, int target_col) {
	if (abs(target_row - _row) > 2 || abs(target_col - _col) > 2)
		return false;
	return Piece::isValidMove(target_row, target_col);
}
std::vector<std::tuple<int, int>> Knight::getAllvalidMoves() {
	Piece* p;
	std::vector<std::tuple<int, int>> moves;
	for (int i = -2; i <=2; i++)
	{
		if (i != 0) {
			for (int j = -2; j <=2; j++)
			{
				if (j != 0 && abs(i) != abs(j))
				{
					if (checkValidCell(_row + i, _col + j))
					{
						p = _game_board->getPiece(_row + i, _col + j);
						if (p == nullptr || p->getColor() != _color)
							moves.push_back(std::tuple<int, int>(_row + i, _col + j));

					}
				}
			}
		}
	}
	return moves;
}

bool Knight::checkValidCell(int row, int col) {		return (row<0 || row>=ROW_LENGTH || col < 0 || col >= COL_LENGTH) ? false : true;	}