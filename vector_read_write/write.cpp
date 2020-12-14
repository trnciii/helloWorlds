#include <iostream>
#include <vector>
#include "vectorio.h"

int main() {
	std::string filename = "test";
	std::vector<double> testWrite;
	for (int i = 0 ; i < 100 ; i++)
		testWrite.push_back(i);

	if (writeVector(testWrite, filename) ) std::cout <<"file saved as " <<filename <<std::endl;
	else std::cout << "failed to write" << std::endl;

	return 0;
}