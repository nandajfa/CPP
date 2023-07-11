/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:47:28 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/11 01:53:36 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
	return ;
}

PmergeMe::~PmergeMe(void){
	return ;
}

PmergeMe::PmergeMe(PmergeMe const& copy){
	*this = copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const & src){
	if (this != &src) {}
	return (*this);
}

template<typename T>
void	PmergeMe::printSequence(const T& sequence) {
    typename T::const_iterator it;
	int	i =  0;
	for (it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it << " ";
		if (i == 15){
			std::cout << "[...]";
			break;
		}
		i++;
    }
    std::cout << std::endl;
}

void	PmergeMe::_print(int argc){
	std::cout << "Before: ";
	for(int i = 0; i < (argc - 1) ; i++) {
		std::cout << _input[i] << " ";
		if (i == 15) {
			std::cout << "[...]";
		break;
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::pMerge(int argc, char *argv[]){
	std::set<int>	numbers;
	
	for (int i = 1; i < argc; i++){
		int length = std::strlen(argv[i]);
		for (int j = 0; j < length; j++ ){
			if (!isdigit(argv[i][j]) && argv[i][j] != '+')
				throw std::invalid_argument("Error: Invalid argument.");
		}
		
		unsigned int	num = atoi(argv[i]);
		if (num < 0)
			throw std::invalid_argument("Error: Invalid argument.");
        if (!numbers.insert(num).second)
            throw std::runtime_error("Error: Duplicate number detected.");
		_input.push_back(num);
		_inputDeq.push_back(num);
	}
	_print(argc);
	_sortVec();
	_sortDeq();
}

void PmergeMe::_recursiveSort(std::vector<int>& S, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    _recursiveSort(S, start, mid);
    _recursiveSort(S, mid + 1, end);

    std::vector<int> sorted;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        if (S[left] <= S[right]) {
            sorted.push_back(S[left]);
            left++;
        } else {
            sorted.push_back(S[right]);
            right++;
        }
    }

    while (left <= mid) {
        sorted.push_back(S[left]);
        left++;
    }

    while (right <= end) {
        sorted.push_back(S[right]);
        right++;
    }

    for (int i = start; i <= end; i++) {
        S[i] = sorted[i - start];
    }
}

void	PmergeMe::_binarySearch(std::vector<int>& sequence, int num) {
	int left = 0;
	int right = sequence.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (num < sequence[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	sequence.insert(sequence.begin() + left, num);
}

void	PmergeMe::_sortVec(){
	clock_t start = clock();
	int straggler = -1;
	size_t	size = _input.size();
	
	if (size % 2 == 1){
		straggler = _input.back();
		_input.pop_back();
	}
	//Group the elements of X into [n/2] pairs of elements, arbitrarily, 
	//leaving one element unpaired if there is an odd number of elements.
	for (size_t i = 0; i < size - 1; i += 2){
		_pairVec.push_back(std::make_pair(_input[i], _input[i + 1]));
	}
	//Perform [n/2] comparisons, one per pair, 
	//to determine the larger of the two elements in each pair. 
	for (size_t i = 0; i < _pairVec.size(); i++){
		if (_pairVec[i].first < _pairVec[i].second){
			std::swap(_pairVec[i].first, _pairVec[i].second);
		}
		_vec.push_back(_pairVec[i].first);
	}
	//Recursively sort the [n/2] larger elements from each pair, creating 
	//a sorted sequence S of [n/2] of the input elements, in ascending order.
	_recursiveSort(_vec, 0, _vec.size() - 1);

	//Insert the remaining [n/2] - 1 elements of X \ S into S, one at a time, with a specially chosen insertion ordering 
	//described below. Use binary search in subsequences of S to determine the position at which each element should be inserted.
	for (size_t i = 0; i < _pairVec.size(); i++)
		_binarySearch(_vec, _pairVec[i].second);
	if (straggler != -1)
		_binarySearch(_vec, straggler);
	
	clock_t end = clock();
	double elapsed_ms = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After:  ";
	printSequence(_vec);
	std::cout << "Time to process a range of " << size << " elements with std::vector : " << elapsed_ms << " ms" << std::endl;
}

void PmergeMe::_recursiveSort(std::deque<int>& S, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    _recursiveSort(S, start, mid);
    _recursiveSort(S, mid + 1, end);

    std::vector<int> sorted;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        if (S[left] <= S[right]) {
            sorted.push_back(S[left]);
            left++;
        } else {
            sorted.push_back(S[right]);
            right++;
        }
    }

    while (left <= mid) {
        sorted.push_back(S[left]);
        left++;
    }

    while (right <= end) {
        sorted.push_back(S[right]);
        right++;
    }

    for (int i = start; i <= end; i++) {
        S[i] = sorted[i - start];
    }
}

void	PmergeMe::_binarySearch(std::deque<int>& sequence, int num) {
	int left = 0;
	int right = sequence.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (num < sequence[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	sequence.insert(sequence.begin() + left, num);
}

void	PmergeMe::_sortDeq(){
	clock_t start = clock();
	int straggler = -1;
	size_t	size = _inputDeq.size();
	
	if (size % 2 == 1){
		straggler = _inputDeq.back();
		_inputDeq.pop_back();
	}
	for (size_t i = 0; i < size - 1; i += 2){
		_pairDeq.push_back(std::make_pair(_inputDeq[i], _inputDeq[i + 1]));
	}
	for (size_t i = 0; i < _pairDeq.size(); i++){
		if (_pairDeq[i].first < _pairDeq[i].second)
			std::swap(_pairDeq[i].first, _pairDeq[i].second);
		_deque.push_back(_pairDeq[i].first);
	}
	
	_recursiveSort(_deque, 0, _deque.size() - 1);

	for (size_t i = 0; i < _pairDeq.size(); i++)
		_binarySearch(_deque, _pairDeq[i].second);
	if (straggler != -1)
		_binarySearch(_deque, straggler);
	clock_t end = clock();
	double elapsed_ms = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << size << " elements with std::deque  : " << elapsed_ms << " ms" << std::endl;
}