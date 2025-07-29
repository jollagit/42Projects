/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:38:29 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 10:49:43 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

int		Account::getNbAccounts(void) {
	return _nbAccounts;
}

int		Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int		Account::getTotalAmount(void) {
	return _totalAmount;
}

int		Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void	Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm *lt = std::localtime(&now);
	std::cout << "[" << std::setfill('0')
			  << std::setw(4) << lt->tm_year + 1900
			  << std::setw(2) << lt->tm_mon + 1
			  << std::setw(2) << lt->tm_mday << "_"
			  << std::setw(2) << lt->tm_hour
			  << std::setw(2) << lt->tm_min
			  << std::setw(2) << lt->tm_sec << "] ";
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits++;

	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;
	if (_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return true;
}

int		Account::checkAmount() const {
	return _amount;
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}
