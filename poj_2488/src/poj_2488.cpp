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
int depth;

bool isOutBound (int row, int col) {
	if (row >= 0 && row < rowNum && col >= 0 && col < colNum)
		return false;
	return true;
}

bool dfsMap (int curRow, int curCol, int*Map, string &path) {
	if (isOutBound(curRow, curCol) || Map[curRow*colNum+curCol] == 1) {
		return false;
	}
	// make the current point
	Map[curRow*colNum+curCol] = 1;
	depth++;

	path.push_back('A'+curRow);
	path.push_back('1'+curCol);

	if (depth >= rowNum*colNum) {
		return true;
	}

	// loop through all eight possible neighbours
	// in lexicographically first path (A2 > A3)
	int newRow, newCol;
	// case 1
	newRow = curRow-2;
	newCol = curCol-1;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	// case 2
	newRow = curRow-2;
	newCol = curCol+1;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	// case 3
	newRow = curRow-1;
	newCol = curCol-2;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	// case 4
	newRow = curRow-1;
	newCol = curCol+2;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	// case 5
	newRow = curRow+1;
	newCol = curCol-2;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	// case 6
	newRow = curRow+1;
	newCol = curCol+2;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	// case 7
	newRow = curRow+2;
	newCol = curCol-1;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	// case 8
	newRow = curRow+2;
	newCol = curCol+1;
	//if (!isOutBound(newRow, newCol) && Map[newRow*colNum+newCol] == 0) {
		if (dfsMap(newRow, newCol, Map, path)) {
			depth--;
			return true;
		}
	//}
	//cout << "Path is " << path << endl;
	//cout << "Depth is " << depth << endl;
	// Unmark the point
	Map[curRow*colNum+curCol] = 0;
	path.erase(path.end()-2, path.end());
	depth--;
	return false;
}

int main() {
	int totalCase, curCase = 1;
	cin >> totalCase;

	// iterate through all the cases
	while (curCase <= totalCase) {
		cin >> colNum >> rowNum;
		cout << "Scenario #" << curCase << ":" << endl;

		// iterate through a quarter of the map
		int halfRow = ceil(rowNum/2.0);
		int halfCol = ceil(colNum/2.0);
		bool isPath = false;
		string path = "";
		for (int j = 0; j < halfRow; j++) {
			for (int i = 0; i < halfCol; i++) {
				// allocate a map
				depth = 0;
				int *map = new int[rowNum*colNum];
				if (dfsMap(j, i, map, path)) {
					isPath = true;
					break;
				}
				// deallocate map
				delete[] map;
			}
			if (isPath)
				break;
		}
		// output Path
		if (isPath)
			cout << path << endl;
		else
			cout << "impossible" << endl;
		curCase++;
		cout << endl;
	}
}
