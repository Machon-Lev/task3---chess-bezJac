#pragma once
#include "Piece.h"


/**
 * @brief Represents a King chess piece.
 */
class King : public Piece {
public:
	King(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:
	/**
	 * @brief helper function -  Checks if a move purposed in getAllvalidMoves is in the board
	 * @param row The row index of the target position.
	 * @param col The column index of the target position.
	 * @return True if the move is in the board, False otherwise.
	 */
	bool checkValidCell(int row, int col);
};