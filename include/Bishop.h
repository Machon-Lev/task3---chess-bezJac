#pragma once
#include "Piece.h"

/**
 * @brief Represents a bishop chess piece.
 */
class Bishop : public Piece {
public:
	Bishop(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:

	/**
	 * @brief helper function -  finds all valid moves for bishop on diagonal runing from top left to bottom right of board 
	 * @param moves vector of already found legal moves
	**/
	void traverseleftToRightDiagonal(std::vector<std::tuple<int, int>>& moves);

	/**
	 * @brief helper function -  finds all valid moves for bishop on diagonal runing from top right to bottom left of board
	 * @param moves vector of already found legal moves
	**/
	void traverseRightToLeftDiagonal(std::vector<std::tuple<int, int>>& moves);
};