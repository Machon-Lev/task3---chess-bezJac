#pragma once
#include "Piece.h"

/**
 * @brief Represents a pawn chess piece.
 */
class Pawn : public Piece {
public:
	Pawn(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:
	/**
	* @brief helper function -  Checks if a cell purposed in getAllvalidMoves() containes a legal move for pawn
	* @param row The row index of the target position.
	* @param col The column index of the target position.
	* @return True if the cell is a legal move, False otherwise.
	*/
	bool checkCellStatus(int row, int col);  

	/**
	* @brief helper function -  Checks if a pawn has moved from initial position at beginig og game.
	* @brief enables blocking double forward move if pawn has already moved in the past.
	* @return True if pawn has moved from initial position, oterwise false.
	*/
	bool hasPawnMoved();
};