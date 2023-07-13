/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:47:18 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/13 14:06:40 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
#include <set>

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const& copy);
		~PmergeMe(void);

		PmergeMe& operator=(PmergeMe const & src);
		void	pMerge(int argc, char *argv[]);

		template<typename T>
		void	printSequence(const T& sequence);

	private:
		float	_time;
		int		_stragglerVec;
		int		_straggler;
		
		std::vector<int>	_input;
		std::vector<int>	_mainVec;
		std::vector<int>	_pendVec;
		std::vector<int>	_jacobSeqVec;
		std::vector<int>	_posVec;
		std::vector<std::pair<int, int> >	_pairVec;
		
		std::deque<int>		_inputDeq;
		std::deque<int>		_mainDeque;
		std::deque<int>		_pendDeque;
		std::deque<int>		_jacobSeqDeq;
		std::deque<int>		_posDeq;
		std::deque<std::pair<int, int> >	_pairDeq;
		
		void	_print(int argc);
		int		_jacobsthal(int n);

		void	_sortVec();
		void	_mergeSort(std::vector<int>& S, int start, int end);
		int 	_binarySearch(std::vector<int> vec, int n, int begin, int end);
		void 	_insertNumbersVec();
		void	_positionsVec();
		void	_jacobInsertSeqVec();
		
		void	_sortDeq();
		void	_mergeSort(std::deque<int>& S, int start, int end);
		int		_binarySearch(std::deque<int> deq, int n, int begin, int end);
		void	_insertNumbersDeque();
		void	_positionsDeque();
		void	_jacobInsertSeqDeq();

};

#endif
