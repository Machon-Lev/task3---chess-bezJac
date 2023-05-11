#pragma once
#include <vector>
#include <map>
#include <string>

/**
 * @brief Namespace containing utility functions for parsing chess commands for given chess gui implementation 
 *
 * The ParsUtil namespace provides a set of utility functions for parsing chess commands
 * and converting them into the corresponding indices on a chess board.
 */
namespace ParsUtil {

	 /**
	  * @brief Mapping of chess column characters to their corresponding row indices.
	  */
	static const std::map<char, int>row_indexes = {
			{'A', 0},
			{'B', 1},
			{'C', 2},
			{'D', 3},
			{'E', 4},
			{'F', 5},
			{'G', 6},
			{'H', 7},
			{'a', 0},
			{'b', 1},
			{'c', 2},
			{'d', 3},
			{'e', 4},
			{'f', 5},
			{'g', 6},
			{'h', 7}
	};


	/**
	 * @brief Parses a chess command of format type "letter digit letter digit" and returns the corresponding indices on a chess board.
	 * @param command The chess command to parse, e.g., "A1B5".
	 * @return An array of integers representing the indices on a chess board [source_row, source_col, target_row, target_col].
	 */
	static int* pars_chess_command(std::string command) {

		int indexes[4];
		indexes[0]= row_indexes.at(command[0]);
		indexes[1] = (command[1] - '0') - 1;
		indexes[2] = row_indexes.at(command[2]);
		indexes[3] = (command[3] - '0') - 1;
		

		return indexes;
	}
}