#pragma once
#include "Piece.h"
#include <string>
#include <memory>

const int ROW_LENGTH = 8;
const int COL_LENGTH = 8;
const int  WHITE = 1;
const int BLACK = -1;


class Piece;

/**
 * @brief Represents a chess board and provides functionality for managing and manipulating the game state.
 *
 * @brief The Board class maintains an 8x8 grid of Piece objects, representing a chess board. It tracks the positions of
 * the pieces, the current player, and provides methods for executing moves, checking for checkmate, and other
 * chess-specific operations.
 */
class Board {
	
	Piece* _board[ROW_LENGTH][COL_LENGTH];		/* The 8x8 grid representing the chess board. */
	Piece* _white_king;							/* Pointer to the white king piece. */
	Piece* _black_king;							/* Pointer to the black king piece. */
	int _current_player;						/* The current player (1 for white, -1 for black). */

public:
	Board();
	~Board();

	/**
	 * @brief Executes a chess move from the source position to the target position.
	 * @param s_row The row index of the source position.
	 * @param s_col The column index of the source position.
	 * @param t_row The row index of the target position.
	 * @param t_col The column index of the target position.
	 * @return An integer representing the result of the move execution.
	 */
	int execute_command(int s_row, int s_col, int t_row, int t_col);

	/**
	 * @brief Retrieves the piece at the specified position on the board.
	 * @param row The row index of the position.
	 * @param col The column index of the position.
	 * @return A pointer to the Piece object at the specified position, or nullptr if no piece is present.
	 */
	Piece* getPiece(int row, int col) { return _board[row][col]; }

	/**
	 * @brief Retrieves the current player.
	 * @return An integer representing the current player (1 for white, -1 for black).
	 */
	int getPlayer() { return _current_player; }

private:

	/**
	 * @brief Moves a piece from the source position to the target position on the board.
	 * @param s_row The row index of the source position.
	 * @param s_col The column index of the source position.
	 * @param t_row The row index of the target position.
	 * @param t_col The column index of the target position.
	 */
	void movePiece(int s_row, int s_col, int t_row, int t_col);

	/**
	 * @brief Undoes a move by moving a piece from the target position back to the source position. 
		(used to revert a move if it isn't legal)
	 * @param s_row The row index of the source position of original move.
	 * @param s_col The column index of the source position position of original move.
	 * @param t_row The row index of the target position position of original move.
	 * @param t_col The column index of the target position position of original move.
	 * @param target A pointer to the Piece object representing the original piece at the target position.
	 **/
	void undoMove(int s_row, int s_col, int t_row, int t_col, Piece* target);

	/**
	* @brief Checks if the specified player is currently in a check position.
	* @param player The player to check for check position (1 for white, -1 for black).
	* @return True if the player is in check, False otherwise.
	 **/
	bool isInCheck(int player);

	/**
	* @brief Checks if the specified player is in checkmate.
	* @param player The player to check for checkmate (1 for white, -1 for black).
	* @return True if the player is in checkmate, False otherwise.
	*/
	bool isCheckMate(int player);

	/**
	 * @brief Initializes the chess board with the starting arrangement of pieces.
	 */
	void initializeBoard();

	/**
	 * @brief Retrieves the location of the king for the specified player.
	 * @param player The player for which to retrieve the king's location (1 for white, -1 for black).
	 * @return A tuple containing the row and column indices of the king's location.
	 */
	std::tuple<int, int> getKingLocation(int player);
};