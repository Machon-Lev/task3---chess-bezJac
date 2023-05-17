#pragma once
#include "Board.h"
#include <vector>
class Board;

/**
 * @brief Represents a chess piece with common attributes and behaviors.
 *
 * @brief The Piece class serves as a base class for specific chess piece types (e.g., Pawn, Knight, etc.).
 * It encapsulates common attributes such as color, position, and provides methods for checking the validity of moves
 * and obtaining all valid moves for a piece. Specific chess piece types derive from this class and implement their
 * own version of the `getAllvalidMoves` method.
 */
class Piece {
protected:
	int _color;				/* The color of the piece (1 for white, -1 for black). */
	Board* _game_board;		/* Pointer to the game board the piece belongs to. */
	int _row;				/* The row index of the piece's current position. */
	int _col;				/* The column index of the piece's current position. */
public:
	Piece(int color, Board* board,int row,int col);

	/**
	 * @brief Checks if a move to the specified target position is valid for the piece.
	 * @param target_row The row index of the target position.
	 * @param target_col The column index of the target position.
	 * @return True if the move is valid, False otherwise.
	 */
	virtual bool isValidMove(int target_row, int target_col) ;

	/**
	 * @brief Retrieves all valid moves for the piece.
	 * @return A vector of tuples representing the valid target positions.
	 * The `getAllvalidMoves` function returns a vector of tuples, with each tuple representing a valid target position
	 * for the piece. 
	 */
	virtual std::vector<std::tuple<int, int>> getAllvalidMoves() = 0;
	int getColor() { return _color; }
	int getRow() { return _row; }
	int getCol() { return _col; }
	void setRow(int row) { _row = row; }
	void setCol(int col) { _col = col; }
};