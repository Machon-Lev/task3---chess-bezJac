#pragma once
#include <vector>
#include <map>
#include <string>

namespace ParsUtil {
	const std::map<char, int>row_indexes = {
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

	int* pars_chess_command(std::string command) {

		int indexes[4];
		indexes[0]= row_indexes.at(command[0]);
		indexes[1] = (command[1] - '0') - 1;
		indexes[2] = row_indexes.at(command[2]);
		indexes[3] = (command[3] - '0') - 1;
		

		return indexes;
	}
}