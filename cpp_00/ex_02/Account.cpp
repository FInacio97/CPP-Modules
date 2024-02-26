#include "Account.hpp"
# include <iostream>
# include <ctime>

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int	prev_amout = this->_amount;

	if (deposit < 0)
		return ;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev_amout
		<< ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:"
		<< this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int	prev_amout = this->_amount;

	if (withdrawal > this->_amount)
	{
	Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:"
			<< prev_amout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev_amout
		 << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
		 << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return (true);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
	<< this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{	
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{	
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{	
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{	
	int nb_acc = Account::getNbAccounts();
	int total_amout = Account::getTotalAmount();
	int total_deposits = Account::getNbDeposits();
	int total_withdrawals = Account::getNbWithdrawals();

	Account::_displayTimestamp();
	std::cout << "accounts:" << nb_acc << ";total:" << total_amout
		 << ";deposits:" << total_deposits << ";withdrawals:"
		<< total_withdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t epoch;
	std::tm *time;

	epoch = std::time(NULL);
	time = std::localtime(&epoch);
	time->tm_year += 1900;
	time->tm_mon += 1;
	std::cout << "[" << time->tm_year << time->tm_mon << time->tm_mday
		<< "_" << time->tm_hour  << time->tm_min  << time->tm_sec << "] ";
	

}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;