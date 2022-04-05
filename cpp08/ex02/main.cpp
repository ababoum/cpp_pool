/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:48:37 by mababou           #+#    #+#             */
/*   Updated: 2022/04/05 19:38:33 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main(void)
{
	std::cout << "\e[7m======================TEST 1======================\e[0m" << std::endl;
	{
		MutantStack<int>	mstack;
		
		mstack.push(5);
		mstack.push(17);
		std::cout << "top is: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size is: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		std::cout << "beginning is: " << *it << std::endl;
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		std::cout << "second is: " << *it << std::endl;
		--it;
		std::cout << "beginning is: " << *it << std::endl;
		
		std::cout << "Entire stack: "<< std::endl;
		while (it != ite) {
			std::cout << "> " << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);
		std::cout << "Copied stack: "<< std::endl;
		std::cout << "top is: " << s.top() << std::endl;
		std::cout << "size is: " << s.size() << std::endl;
	}
	std::cout << "\e[7m======================TEST 2======================\e[0m" << std::endl;
	{
		std::list<int>	mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top is: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "size is: " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::cout << "beginning is: " << *it << std::endl;
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		std::cout << "second is: " << *it << std::endl;
		--it;
		std::cout << "beginning is: " << *it << std::endl;
		
		std::cout << "Entire list: "<< std::endl;
		while (it != ite) {
			std::cout << "> " << *it << std::endl;
			++it;
		}
		
		std::list<int> s(mstack);
		std::cout << "Copied list: "<< std::endl;
		std::cout << "top is: " << s.back() << std::endl;
		std::cout << "size is: " << s.size() << std::endl;
	}
	std::cout << "\e[7m======================TEST 3======================\e[0m" << std::endl;
	{
		MutantStack<std::string>	str_stack;

		std::cout << "Is stack empty? " << str_stack.empty() << std::endl;
		
		for (char c = 'a'; c <= 'z'; c++) {
			std::string	ch;
			ch += c;
			str_stack.push(ch);
		}

		std::cout << "Is stack empty? " << str_stack.empty() << std::endl;
		
		std::cout << "top is: " << str_stack.top() << std::endl;
		std::cout << "size is: " << str_stack.size() << std::endl;

		str_stack.pop();

		std::cout << "top is: " << str_stack.top() << std::endl;
		std::cout << "size is: " << str_stack.size() << std::endl;
		
		for (MutantStack<std::string>::iterator	it = str_stack.begin(); \
			it != str_stack.end(); it++) {
			std::cout << "> " << *it << std::endl;
		}
		std::cout << "Copying the stack..." << std::endl;
		MutantStack<std::string>	str_stack2 = str_stack;

		for (MutantStack<std::string>::iterator	it = str_stack2.begin(); \
			it != str_stack2.end(); it++) {
			std::cout << "> " << *it << std::endl;
		}
		
	}
	return (0);
}