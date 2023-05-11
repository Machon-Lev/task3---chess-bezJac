#include "King.h"

King::King(int color, Board* board, int row, int col) :Piece(color, board, row, col) {}

bool King::isValidMove(int target_row, int target_col) {
	if (abs(target_row - _row) > 1 || abs(target_col - _col) > 1)
		return false;
	return Piece::isValidMove(target_row, target_col);
}

std::vector<std::tuple<int, int>> King::getAllvalidMoves() {

	std::vector<std::tuple<int, int>> moves;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (checkValidCell(_row + i,_col+ j))
			{
				Piece* current = _game_board->getPiece(_row + i, _col + j);
				if (current == nullptr)
					moves.push_back(std::tuple<int, int>(_row + i, _col + j));
				else if(current->getColor() !=_color)	
				{
					moves.push_back(std::tuple<int, int>(_row + i, _col + j));
				}
			}
		}
	}
	return moves;

}

bool King::checkValidCell(int row, int col) { return (row < 0 || row > 7 || col < 0 || col > 7) ? false : true; }

