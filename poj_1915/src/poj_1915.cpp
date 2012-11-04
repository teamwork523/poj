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

int main() {
	int totalCase, curCase = 1;
	cin >> totalCase;

	// iterate through all the cases
	while (curCase <= totalCase) {
		cin >> totalLen;
		cin >> start[0] >> start[1];
		cin >> end[0] >> end[1];

		// TODO: core part

		curCase++;
	}
}
