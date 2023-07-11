/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:47:18 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/11 01:51:43 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
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
		std::vector<int>	_input;
		std::deque<int>		_inputDeq;
		std::vector<int>	_vec;
		std::deque<int>		_deque;
		std::vector<std::pair<int, int> >	_pairVec;
		std::deque<std::pair<int, int> >	_pairDeq;
		
		void	_sortVec();
		void	_sortDeq();
		void	_print(int argc);
		void	_recursiveSort(std::vector<int>& S, int start, int end);
		void	_binarySearch(std::vector<int>& sequence, int num);
		void	_recursiveSort(std::deque<int>& S, int start, int end);
		void	_binarySearch(std::deque<int>& sequence, int num);
};

#endif