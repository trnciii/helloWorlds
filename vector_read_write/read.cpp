#include <iostream>
#include <vector>
#include "vectorio.h"

int main() {
	std::string filename = "test";

	std::vector<double> testRead;
	if (readVector(testRead, filename)) std::cout <<"read file " <<filename <<std::endl;
	else std::cout << "failed to read" << std::endl;


	for ( int i = 0; i < testRead.size(); ++i )
		std::cout << testRead[i] << std::endl;
}