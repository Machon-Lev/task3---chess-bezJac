#pragma once
#include "Piece.h"


/**
 * @brief Represents a queen chess piece.
 */
class Queen : public Piece {
public:
	Queen(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:

	/**
	 * @brief helper function -  finds all valid moves for queen on diagonal runing from top left to bottom right of board
	 * @param moves vector of already found legal moves
	**/
	void traverseleftToRightDiagonal(std::vector<std::tuple<int, int>>& moves);

	/**
	 * @brief helper function -  finds all valid moves for queen on diagonal runing from top right to bottom left of board
	 * @param moves vector of already found legal moves
	**/
	void traverseRightToLeftDiagonal(std::vector<std::tuple<int, int>>& moves);

	/**
	 * @brief helper function -  finds all valid moves for queen on row of current position
	 * @param moves vector of already found legal moves
	**/
	void traverseRows(std::vector<std::tuple<int, int>>& moves);
	/**
	 * @brief helper function -  finds all valid moves for queen on row of current position
	 * @param moves vector of already found legal moves
	**/
	void traverseCols(std::vector<std::tuple<int, int>>& moves);
};