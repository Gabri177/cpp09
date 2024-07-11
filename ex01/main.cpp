#include "RPN.hpp"


int main(int argc, char** argv){

	if (argc != 2){
		std::cerr << "No evaluation!" << std::endl;
		return 1;
	}
	try{
		RPN test;
		std::cout << test.resultRPN(argv[1]) << std::endl;
	}catch(std::exception & e){

		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}