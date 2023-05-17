#pragma once
#include "Piece.h"

/**
 * @brief Represents a rook chess piece.
 */
class Rook : public Piece {
public:
	Rook(int color, Board* board, int row, int col);
	bool isValidMove(int target_row,int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:
	/**
	* @brief helper function -  finds all valid moves for rook on row of current position
	* @param moves vector of already found legal moves
	**/
	void traverseRows(std::vector<std::tuple<int, int>>& moves);
	/**
	 * @brief helper function -  finds all valid moves for rook on row of current position
	 * @param moves vector of already found legal moves
	**/
	void traverseCols(std::vector<std::tuple<int, int>>& moves);
};