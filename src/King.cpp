#include "King.h"

King::King(int color, Board* board, int row, int col) :Piece(color, board, row, col) {}

bool King::isValidMove(int target_row, int target_col) {
	if (abs(target_row - _row) > 1 || abs(target_col - _col) > 1)
		return false;
	auto legalMoves = getAllvalidMoves();
	std::tuple<int, int> move = std::make_tuple(target_row, target_col);
	if (std::find(legalMoves.begin(), legalMoves.end(), move) == legalMoves.end())
		return false;
	return true;
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

bool King::checkValidCell(int i, int j) { return (i < 0 || i > 7 || j < 0 || j > 7) ? false : true; }

