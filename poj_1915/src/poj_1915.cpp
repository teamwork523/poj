//============================================================================
// Name        : poj_1915.cpp
// Author      : Haokun Luo
// Description : POJ 1915 Knight Moves
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int totalLen;
int start[2] = {0,0};
int end[2] = {0,0};
int neighbour[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int depth;

int minArray(int* array, int size) {
	// ignore all negative number
	int min = totalLen*totalLen;
	for (int i = 0; i < size; i++ ) {
		if (array[i] >= 0 && array[i] < min) {
			min = array[i];
		}
	}
	return min;
}

int bfsMap(int curRow, int curCol, int* Map, int &depth) {
	if (curRow < 0 || curRow >= totalLen || curCol < 0 || curCol >= totalLen || Map[curRow*totalLen+curCol] == 1)
		return totalLen*totalLen+1;
	if (curRow == end[0] && curCol == end[1])
		return 0;
	// Mark the current location
	Map[curRow*totalLen+curCol] = 1;
	depth++;
	int tmpResult[8];
	for (int i = 0; i < 8; i++) {
		int newRow = curRow + neighbour[i][0];
		int newCol = curCol + neighbour[i][1];
		//cout << "Reach neightbour (" << newRow << ", " << newCol << ").\n";
		tmpResult[i] = bfsMap(newRow, newCol, Map);
	}
	int result = minArray(tmpResult, 8);
	//cout << "Current result is " << result << " at (" << curRow << ", " << curCol << ")."<< endl;
	if (result >= totalLen*totalLen)
		return -1;
	else
		return result + 1;
}

int main() {
	int totalCase, curCase = 1;
	cin >> totalCase;

	// iterate through all the cases
	while (curCase <= totalCase) {
		cin >> totalLen;
		cin >> start[0] >> start[1];
		cin >> end[0] >> end[1];
		/*cout << "Current start is " << start[0] << ',' << start[1] << endl;
		cout << "Current end is " << end[0] << ',' << end[1] << endl;
		cout << "Current total length is " << totalLen << endl;*/
		cout << "Scenario #" << curCase << ":" << endl;
		int* map = new int[totalLen*totalLen];
		for (int j = 0; j < totalLen; j++)
			for (int i = 0; i < totalLen; i++)
				map[j*totalLen+i] = 0;
		// bfs
		int finalResult = bfsMap(start[0], start[1], map);
		int depth = 0;
		if (finalResult < 0)
			cout << "impossible" << endl;
		else
			cout << finalResult << endl;
		delete[] map;
		curCase++;
		cout << endl;
	}
}
