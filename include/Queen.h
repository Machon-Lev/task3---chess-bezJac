#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	Queen(int color, Board* board, int row, int col);
	bool isValidMove(int target_row, int target_col) override;
	std::vector<std::tuple<int, int>> getAllvalidMoves() override;
private:
	std::vector<std::tuple<int, int>> traverseleftToRightDiagonal(std::vector<std::tuple<int, int>>& moves);
	std::vector<std::tuple<int, int>> traverseRightToLeftDiagonal(std::vector<std::tuple<int, int>>& moves);
	std::vector<std::tuple<int, int>> traverseRows(std::vector<std::tuple<int, int>>& moves);
	std::vector<std::tuple<int, int>> traverseCols(std::vector<std::tuple<int, int>>& moves);
};