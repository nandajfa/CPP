/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:47:28 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/13 15:00:09 by jefernan         ###   ########.fr       */
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

void	PmergeMe::pMerge(int argc, char *argv[]){
	clock_t start = clock();
	std::set<int>	numbers;
	
	this->_straggler = -1;
	this->_stragglerVec = -1;
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
	clock_t end = clock();
	this->_time = (end - start) / CLOCKS_PER_SEC;
	_sortVec();
	_sortDeq();
}

/*  Print  */
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

int PmergeMe::_jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (_jacobsthal(n - 1) + 2 * _jacobsthal(n - 2));
}

/*   Vector  */
void PmergeMe::_jacobInsertSeqVec()
{
    size_t size;
    size_t jacobIndex;
    int index;

    size = _pendVec.size();
    index = 3;

    while ((jacobIndex = this->_jacobsthal(index)) < size - 1)
    {
        this->_jacobSeqVec.push_back(jacobIndex);
        index++;
    }
}

void PmergeMe::_positionsVec()
{
    if (this->_pendVec.empty())
        return;

    this->_jacobInsertSeqVec();
    size_t lastPos = 1;
    size_t val = 1;
    for (size_t i = 0; i < this->_jacobSeqVec.size(); i++)
    {
        val = this->_jacobSeqVec.at(i);
        this->_posVec.push_back(val);

        size_t pos = val - 1;
        while (pos > lastPos)
        {
            this->_posVec.push_back(pos);
            pos--;
        }
        lastPos = val;
    }

    while (val++ < this->_pendVec.size())
        this->_posVec.push_back(val);
}

int PmergeMe::_binarySearch(std::vector<int> vec, int n, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (n == vec.at(mid))
			return (mid);

		if (n > vec.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (n > vec.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::_insertNumbersVec()
{
	std::vector<int>::iterator	it;
    size_t addCount = 0;

    this->_positionsVec();
	for (it = this->_posVec.begin(); it < this->_posVec.end(); it++)
    {
        int n = this->_pendVec.at(*it - 1);
        size_t endPos = *it + addCount;
        size_t pos = _binarySearch(this->_mainVec, n, 0, endPos);
        this->_mainVec.insert(this->_mainVec.begin() + pos, n);
		addCount++;
    }
    if (_stragglerVec != -1)
    {
        size_t n = _stragglerVec;
        size_t pos = _binarySearch(this->_mainVec, n, 0, this->_mainVec.size() - 1);
        this->_mainVec.insert(this->_mainVec.begin() + pos, n);
    }
}

void PmergeMe::_mergeSort(std::vector<int>& S, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    _mergeSort(S, start, mid);
    _mergeSort(S, mid + 1, end);

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

void	PmergeMe::_sortVec(){
	clock_t start = clock();
	size_t	size = _input.size();
	
	if (size % 2 == 1){
		_stragglerVec = _input.back();
		_input.pop_back();
	}

	for (size_t i = 0; i < size - 1; i += 2){
		_pairVec.push_back(std::make_pair(_input[i], _input[i + 1]));
	}
	for (size_t i = 0; i < _pairVec.size(); i++){
		if (_pairVec[i].first < _pairVec[i].second){
			std::swap(_pairVec[i].first, _pairVec[i].second);
		}
		_mainVec.push_back(_pairVec[i].first);
		_pendVec.push_back(_pairVec[i].second);
	}

	_mergeSort(_mainVec, 0, _mainVec.size() - 1);
	_mainVec.insert(_mainVec.begin(), _pendVec[0]);
	_insertNumbersVec();

	clock_t end = clock();
	double elapsed_ms = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After:  ";
	printSequence(_mainVec);
	std::cout << "Time to process a range of " << size << " elements with std::vector : " << elapsed_ms + _time << " ms" << std::endl;
}

/*  Deque   */
int PmergeMe::_binarySearch(std::deque<int> deq, int n, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (n == deq.at(mid))
			return (mid);

		if (n > deq.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (n > deq.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::_jacobInsertSeqDeq()
{
	size_t size;
	size_t jacobIndex;
	int index;

	size = this->_pendDeque.size();
	index = 3;

	while ((jacobIndex = this->_jacobsthal(index)) < size - 1)
	{
		this->_jacobSeqDeq.push_back(jacobIndex);
		index++;
	}
}

void PmergeMe::_positionsDeque()
{
	if (this->_pendDeque.empty())
		return;

	this->_jacobInsertSeqDeq();
	size_t lastPos = 1;
	size_t val = 1;
	while (!this->_jacobSeqDeq.empty())
	{
		val = this->_jacobSeqDeq.front();

		this->_jacobSeqDeq.pop_front();
		this->_posDeq.push_back(val);

		size_t pos = val - 1;
		while (pos > lastPos)
		{
			this->_posDeq.push_back(pos);
			pos--;
		}
		lastPos = val;
	}
	while (val++ < this->_pendDeque.size())
		this->_posDeq.push_back(val);
}

void PmergeMe::_insertNumbersDeque()
{
	std::deque<int>::iterator it;
	size_t addCount = 0;

	this->_positionsDeque();
	for (it = this->_posDeq.begin(); it < this->_posDeq.end(); it++)
	{
		int n = this->_pendDeque.at(*it - 1);

		size_t endPos = *it + addCount;
		size_t pos = this->_binarySearch(this->_mainDeque, n, 0, endPos);
		this->_mainDeque.insert(this->_mainDeque.begin() + pos, n);
		addCount++;
	}
	if (_straggler != -1)
	{
		size_t n = _straggler;
		size_t pos = this->_binarySearch(this->_mainDeque, n, 0, this->_mainDeque.size() - 1);
		this->_mainDeque.insert(this->_mainDeque.begin() + pos, n);
	}
}

void PmergeMe::_mergeSort(std::deque<int>& S, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    _mergeSort(S, start, mid);
    _mergeSort(S, mid + 1, end);

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

void	PmergeMe::_sortDeq(){
	clock_t start = clock();
	size_t	size = _inputDeq.size();
	
	if (size % 2 == 1){
		_straggler = _inputDeq.back();
		_inputDeq.pop_back();
	}
	for (size_t i = 0; i < size - 1; i += 2){
		_pairDeq.push_back(std::make_pair(_inputDeq[i], _inputDeq[i + 1]));
	}
	for (size_t i = 0; i < _pairDeq.size(); i++){
		if (_pairDeq[i].first < _pairDeq[i].second)
			std::swap(_pairDeq[i].first, _pairDeq[i].second);
		_mainDeque.push_back(_pairDeq[i].first);
		_pendDeque.push_back(_pairDeq[i].second);
	}
	
	_mergeSort(_mainDeque, 0, _mainDeque.size() - 1);
	_mainDeque.push_front(_pendDeque[0]);

	_insertNumbersDeque();
	printSequence(_mainDeque);
	clock_t end = clock();
	double elapsed_ms = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << size << " elements with std::deque  : " << elapsed_ms + _time << " ms" << std::endl;
}
