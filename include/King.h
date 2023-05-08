#pragma once
#include "Piece.h"

class King : public Piece {
public:
	King(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:
	bool checkValidCell(int i, int j);
};