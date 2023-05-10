#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
	Knight(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;

};