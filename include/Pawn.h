#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:
	bool checkCellStatus(int i, int j);
	bool hasPawnMoved();
};