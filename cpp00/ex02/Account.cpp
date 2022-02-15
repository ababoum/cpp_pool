/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:27:06 by mababou           #+#    #+#             */
/*   Updated: 2022/02/15 17:38:19 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	std::cout << " ";
	
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "index:" << this->_accountIndex << ";";
	
	this->_amount = initial_deposit;
	if (initial_deposit > 0)
		this->_nbDeposits = 1;
	else
		this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "amount:" << this->_amount << ";";

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	if (initial_deposit > 0)
		Account::_totalNbDeposits += 1;

	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
		Account::_displayTimestamp();
	std::cout << " ";
	
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	
	return ;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	int i = 0;

	// display each account info
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_nbDeposits++;

	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > this->_amount)
		return false;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	Account::_totalAmount -= withdrawal;
	Account::_nbWithdrawals++;

	return true;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	// ?
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	
	std::cout << (now->tm_year + 1900);
	if (now->tm_mon + 1 <= 9)
		std::cout << "0";
	std::cout << (now->tm_mon + 1);
	if (now->tm_mday <= 9)
		std::cout << "0";
	std::cout << now->tm_mday << "_";
	
	if (now->tm_hour <= 9)
		std::cout << "0";
	std::cout << now->tm_hour;
	if (now->tm_min <= 9)
		std::cout << "0";
	std::cout << now->tm_min;
	if (now->tm_sec <= 9)
		std::cout << "0";
	std::cout << now->tm_sec;
}