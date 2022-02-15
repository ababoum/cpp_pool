/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:27:06 by mababou           #+#    #+#             */
/*   Updated: 2022/02/15 19:10:56 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	std::cout << " ";
	
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "index:" << this->_accountIndex << ";";
	
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "amount:" << this->_amount << ";";

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << " ";
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
	Account::_displayTimestamp();
	std::cout << " ";
	
	std::cout << "accounts:" << t::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << ";";
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " ";

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > this->_amount)
	{
		Account::_displayTimestamp();
		std::cout << " ";
	
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		
		return false;
	}

	Account::_displayTimestamp();
	std::cout << " ";

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	return true;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " ";
	
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
	
	return ;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	
	std::cout << "[";
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
	std::cout << "]";
}