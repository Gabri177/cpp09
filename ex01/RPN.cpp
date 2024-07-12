#include "RPN.hpp"

bool					isSymbolCaculate(char c){

	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

bool					formatCheck(const std::string & evaluation){

	size_t start_p = evaluation.find_first_not_of(' ');
	//size_t end_p = evaluation.find_last_not_of(' ');
	if (start_p == std::string::npos || !(evaluation[start_p] >= '0' && evaluation[start_p] <= '9'))
		return false;
	for (size_t i = start_p; i < evaluation.size(); i ++){

		if (evaluation[i] == ' ')
			continue ;
		if (!isSymbolCaculate(evaluation[i]) && !(evaluation[i] >= '0' && evaluation[i] <= '9'))
			return false;
		if (i + 1 < evaluation.size() && evaluation[i + 1] != ' ' && evaluation[i + 1] != '\0')
			return false;
	}
	return true;
}

int						RPN::resultRPN(const std::string & evaluation){

	if (!formatCheck(evaluation))
		throw std::invalid_argument("Error");
	size_t start = evaluation.find_first_not_of(' ');
	for (size_t i = start; i < evaluation.size(); i += 2){
		if (!isSymbolCaculate(evaluation[i]))
			_temp.push(evaluation[i] - '0');
		else{

			int a = _temp.top();
			_temp.pop();
			int b = _temp.top();
			_temp.pop();
			switch (evaluation[i]){

				case '+':
					_temp.push(b + a);
					break;
				case '-':
					_temp.push(b - a);
					break;
				case '*':
					_temp.push(b * a);
					break;
				case '/':
					if (a == 0)
						throw std::runtime_error("Error");
					_temp.push(b / a);
					break;
				default:
					throw std::runtime_error("Error");
			}
		}
	}
	if (_temp.size() != 1)
		throw std::runtime_error("Error");
	return _temp.top();
}


RPN::RPN(){}

RPN::RPN(const RPN & obj){*this = obj;}

RPN::~RPN(){}

RPN &					RPN::operator=(const RPN & obj){

	(void)obj;
	return *this;
}