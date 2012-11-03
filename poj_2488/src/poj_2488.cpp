//============================================================================
// Name        : poj_2488.cpp
// Author      : Haokun Luo
// Version     : 1.0
// Description : POJ 2488 A Knight's Journey
//============================================================================

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int rowNum, colNum;
int* Map;

bool isOutBound (int row, int col) {
	if (row >= 0 && row < rowNum && col >= 0 && col < colNum)
		return false;
	return true;
}

bool dsfMap (int curRow, int curCol, int depth, string& path) {
	// make that point count
	if (Map[curRow*colNum+curCol] == 0) {
		path.push_back('A'+curRow);
		path.push_back('0'+curCol);
		Map[curRow*colNum+curCol] = 1;
		return true;
	}
	// check if the last step
	if (depth >= curRow*curCol) {
		return true;
	}
}

int main() {
	int totalCase, curCase = 1;
	cin >> totalCase;

	// iterate through all the cases
	while (curCase <= totalCase) {
		cin >> rowNum >> colNum;
		cout << "Scenario #" << curCase << ":" << endl;
		// allocate a map
		Map = new int[rowNum*colNum];

		// iterate through a quarter of the map
		int halfRow = ceil(rowNum/2.0);
		int halfCol = ceil(colNum/2.0);
		for (int j = 0; j < halfRow; j++) {
			for (int i = 0; i < halfCol; i++) {
				string path = "";
				// mark the first visited
				Map[j*colNum+i] = 1;
				dsfMap(j, i, 0, path);
			}
		}

		// deallocate map
		delete[] Map;
		curCase++;
		cout << endl;
	}
}
