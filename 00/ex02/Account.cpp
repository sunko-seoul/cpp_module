#include "Account.hpp"
#include <iostream>

int	Account::getNbAccounts(void) { return (_nbAccounts); }
int	Account::getTotalAmount(void) { return (_totalAmount); }
int	Account::getNbDeposits(void) { return (_nbDeposits); }
int	Account::getNbWithdrawals(void) { return (_nbWithdrawals); }

void	Account::displayAccountsInfos(void)
{

}

void	displayAccountsInfos(void)
{
	_displayTimestamp();

}

void	_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}



