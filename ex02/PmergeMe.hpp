#ifndef HEAD_PMERGE_HPP
# define HEAD_PMERGE_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe {

	private:
		std::vector<int>					c_vec;
		std::deque<int>						c_deq;
		void								fordJohnsonSort(std::vector<int> & vec);
		void								fordJohnsonSort(std::deque<int> & deq);
		void								insertMerge(std::vector<int> & minVecSorted, std::vector<int> & maxVec);
		void								insertMerge(std::deque<int> & minQueSorted, std::deque<int> & maxQue);
	
	public:
		void								addNum(int num);
		void								print();
											PmergeMe();
											PmergeMe(const PmergeMe & obj);
											~PmergeMe();
		PmergeMe &							operator=(const PmergeMe & obj);
		
};

#endif