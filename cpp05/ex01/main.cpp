/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:13:30 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/20 16:18:48 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testBr(void){
	try{
		std::cout << MAG << "Valid grades." << RESET << std::endl;
		Bureaucrat b;
		Bureaucrat b1("Leo", 55);
		Bureaucrat b2 = Bureaucrat("Katy", 20);
		Bureaucrat b3 = Bureaucrat("Tommy", 120);
		std::cout << std::endl;
		std::cout << b << std::endl;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;	
	}
	catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try {
		std::cout << std::endl;
		std::cout << MAG << "Less than minimum grade." << RESET << std::endl;
		Bureaucrat b4 = Bureaucrat("Ted", 160);
		std::cout << b4 << std::endl;
	}
	catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try {
		std::cout << std::endl;
		std::cout << MAG << "Higher than maximun grade" << RESET << std::endl;
		Bureaucrat b5 = Bureaucrat("Amy", -50);
		std::cout << b5 << std::endl;
	}
	catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << MAG << "Decrement and Increment" << RESET << std::endl;
		Bureaucrat b5 = Bureaucrat("Toby", 3);
		std::cout << b5 << std::endl;
		b5.increment();
		std::cout << "Increment 3: " << b5 << std::endl;
		b5.decrement();
		std::cout << "Decrement 3: " << b5 << std::endl;
	}
	catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << MAG << "Copy" << RESET << std::endl;
		Bureaucrat b6("Lily", 67);
		Bureaucrat copy = b6;
		std::cout << b6 << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		
		b6.increment();
		b6.increment();
		copy.decrement();
		copy.decrement();
		std::cout << b6 << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try {
		std::cout << std::endl;
		std::cout << MAG << "Decrement low grade" << RESET << std::endl;
		Bureaucrat b = Bureaucrat("b1", 150);
		b.decrement();
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << MAG << "Increment high grade" << RESET << std::endl;
		Bureaucrat b = Bureaucrat("b2", 1);
		b.increment();
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	testForm(void){
	try {
		Bureaucrat	b1("Leo", 80);
		Form	f1("1F", 80, 50);
		std::cout << std::endl;
		b1.signForm(f1);
		f1.beSigned(b1);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
	} catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat	b2("Vick",  10);
		Form	f2("2F", 15, 30);
		std::cout << std::endl;
		b2.signForm(f2);
		f2.beSigned(b2);
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
	} catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat	b3("Tomy",  150);
		Form	f3("3F", 140, 89);
		std::cout << std::endl;
		b3.signForm(f3);
		f3.beSigned(b3);
		std::cout << b3 << std::endl;
		std::cout << f3 << std::endl;
	} catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	Bureaucrat b;
	std::cout << std::endl;
	Form f4 = Form("4F", 10, 40);
	Form f5;
	f5 = f4;
	std::cout << std::endl;
	b.signForm(f5);
	std::cout << f4;
	std::cout << f5;
	std::cout << std::endl;
}

int	main(void)
{
	testBr();
	testForm();

	return (0);
}
