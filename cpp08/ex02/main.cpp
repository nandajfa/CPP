/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:36:30 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/27 20:20:46 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << CYN << "===== Subject Main =====" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
	
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << CYN << "==== test with list ====" << RESET << std::endl;
		std::list<int> ls;
		ls.push_back(5);
		ls.push_back(17);
		std::cout << ls.back() << std::endl;
		ls.pop_back();
		std::cout << ls.size() << std::endl;
		ls.push_back(3);
		ls.push_back(5);
		ls.push_back(737);
		ls.push_back(0);
	
		std::list<int>::iterator it = ls.begin();
		std::list<int>::iterator ite = ls.end();
	
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
