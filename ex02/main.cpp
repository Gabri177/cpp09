#include "PmergeMe.hpp"

int main (int argc, char** argv){

	if (argc == 1){
		
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try{
		PmergeMe	test;
		for (int i = 1; i < argc; i ++)
			test.addNum(std::atoi(argv[i]));
		test.print();
	}catch(...){
		std::cerr << "Error." << std::endl;
		return 1;
	}
	return 0;
}