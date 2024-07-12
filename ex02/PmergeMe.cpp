#include "PmergeMe.hpp"


void								PmergeMe::fordJohnsonSort(std::vector<int> & vec){

	size_t n = vec.size();
	if (n < 2)
		return ;

	std::vector<int> min_temp, max_temp;
	for (size_t i = 0; i < n; i += 2){

		if (i + 1 < n){

			if (vec[i] < vec[i + 1]){

				min_temp.push_back(vec[i]);
				max_temp.push_back(vec[i + 1]);
			}else{

				min_temp.push_back(vec[i + 1]);
				max_temp.push_back(vec[i]);
			}
		}else{

			min_temp.push_back(vec[i]);
		}
	}
	fordJohnsonSort(min_temp);
	insertMerge(min_temp, max_temp);
	std::copy(min_temp.begin(), min_temp.end(), vec.begin());
}

void								PmergeMe::fordJohnsonSort(std::deque<int> & deq){

	size_t n = deq.size();
	if (n < 2)
		return ;

	std::deque<int> min_temp, max_temp;
	for (size_t i = 0; i < n; i += 2){

		if (i + 1 < n){

			if (deq[i] < deq[i + 1]){

				min_temp.push_back(deq[i]);
				max_temp.push_back(deq[i + 1]);
			}else{

				min_temp.push_back(deq[i + 1]);
				max_temp.push_back(deq[i]);
			}
		}else{

			min_temp.push_back(deq[i]);
		}
	}
	fordJohnsonSort(min_temp);
	insertMerge(min_temp, max_temp);
	std::copy(min_temp.begin(), min_temp.end(), deq.begin());
}

void								PmergeMe::insertMerge(std::vector<int> & minVecSorted, std::vector<int> & maxVec){

	for (size_t i = 0; i < maxVec.size(); i ++){

		std::vector<int>::iterator it = std::lower_bound(minVecSorted.begin(), minVecSorted.end(), maxVec[i]);
		minVecSorted.insert(it, maxVec[i]);
	}
}

void								PmergeMe::insertMerge(std::deque<int> & minQueSorted, std::deque<int> & maxQue){

	for(size_t i = 0; i < maxQue.size(); i ++){

		std::deque<int>::iterator it = std::lower_bound(minQueSorted.begin(), minQueSorted.end(), maxQue[i]);
		minQueSorted.insert(it, maxQue[i]);
	}
}

void								PmergeMe::addNum(int num){

	if(num <= 0)
		throw std::invalid_argument("Error.");
		c_vec.push_back(num);
		c_deq.push_back(num);
}

void								PmergeMe::print(){

	std::cout << "Before: ";
	for (std::vector<int>::iterator it = c_vec.begin(); it != c_vec.end(); it ++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	clock_t	start1 = clock();
	fordJohnsonSort(c_vec);
	clock_t end1 = clock();
	double	diff1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;


	clock_t	start2 = clock();
	fordJohnsonSort(c_deq);
	clock_t end2 = clock();
	double	diff2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (std::vector<int>::iterator it = c_vec.begin(); it != c_vec.end(); it ++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << c_vec.size() << " elements with std::[Vector] : " << diff1 << "µs" << std::endl;
	std::cout << "Time to process a range of " << c_vec.size() << " elements with std::[Deque] : " << diff2 << "µs" << std::endl;
}

PmergeMe::PmergeMe(){

}

PmergeMe::PmergeMe(const PmergeMe & obj){

	*this = obj;
}

PmergeMe::~PmergeMe(){

}

PmergeMe &							PmergeMe::operator=(const PmergeMe & obj){

	if (this != &obj){

		c_vec = obj.c_vec;
		c_deq = obj.c_deq;
	}
	return *this;
}