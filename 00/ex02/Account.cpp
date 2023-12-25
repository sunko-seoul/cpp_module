#include "Account.hpp"
#include <ctime>
#include <iostream>

// static member function
// 어떤 인스턴스에서도 함수를 호출할 수 있음
// this를 사용한다는 건 특정한 인스턴스의 주소를 받아서 쓴다는 것임
// 따라서 this를 static function은 쓸 수 없음, 또한 this로 접근할 수 있는 것은 접근 못함
// 따라서 특정 instance에 private 변수는 접근 못함
// this가 없어도 this를 쓰고 있다는 말이 this를 쓰지 않아도 특정한 instace 주소를 통해 함수를 쓴다는 것임

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) { return (_nbAccounts); }
int	Account::getTotalAmount(void) { return (_totalAmount); }
int	Account::getNbDeposits(void) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

// 현재 시점으로 해야 하나?
void	Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	struct tm	*timeinfo = localtime(&now);
	char	buff[80];
	strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", timeinfo);
	std::string	str_time(buff);
	std::cout << str_time;
}

Account::Account(int initial_deposit)
	:	_accountIndex(getNbAccounts()),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_displayTimestamp();
	_nbAccounts++;
	_totalAmount += _amount;
	_totalNbDeposits += _nbDeposits;
	_totalNbWithdrawals += _totalNbWithdrawals;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int		p_amount;

	p_amount = _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	_amount -= withdrawal;
	if (checkAmount() < 0)
	{
		_amount = p_amount;
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
