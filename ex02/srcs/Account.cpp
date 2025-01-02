/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:37:44 by rkassel           #+#    #+#             */
/*   Updated: 2025/01/02 09:25:13 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

Account::Account( int initial_deposit ) :
_accountIndex(getNbAccounts()),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += checkAmount();
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "created" << std::endl;
    return ;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "closed" << std::endl;
    return ;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << checkAmount() << ";";
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
    return ;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "withdrawal:";
    if ((checkAmount() - withdrawal) < 0)
    {
        std::cout << "refused";
        std::cout << std::endl;
        return (false);
    }
    else
    {
        _amount -= withdrawal;
        std::cout << withdrawal << ";";
        std::cout << "amount:" << checkAmount() << ";";
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "nb_withdrawals:" << _nbWithdrawals;
        std::cout << std::endl;
        return (true);
    }
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
    return ;
}

void	Account::_displayTimestamp( void )
{
    time_t  currentTime;
    tm      *tmStruct;
    int     hour;

    currentTime = time(NULL);
    tmStruct = localtime(&currentTime);
    
    std::cout << "[";
    
    std::cout << 1900 + tmStruct->tm_year;
    
    if (tmStruct->tm_mon < 10)
        std::cout << "0";
    std::cout << 1 + tmStruct->tm_mon;
    
    if (tmStruct->tm_mday < 10)
        std::cout << "0";
    std::cout << tmStruct->tm_mday;
    
    std::cout << "_";
    
    hour = 9 + tmStruct->tm_hour;
    if (hour >= 24)
        hour -= 24;
    if (hour < 10)
        std::cout << "0";
    std::cout << hour;
    
    if (tmStruct->tm_min < 10)
        std::cout << "0";
    std::cout << tmStruct->tm_min;
    
    if (tmStruct->tm_sec < 10)
        std::cout << "0";
    std::cout << tmStruct->tm_sec;
    
    std::cout << "] ";
    
    return ;
}

Account::Account( void )
{
    return ;
}
