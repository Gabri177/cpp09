#ifndef HEAD_RPN_HPP
# define HEAD_RPN_HPP
# include <iostream>
# include <algorithm>
# include <stack>

class RPN {

	private:
		std::stack<int>			_temp;

	public:
		int						resultRPN(const std::string & evaluation);
};

#endif