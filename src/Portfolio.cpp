#include "../include/Portfolio.h"
#include <iostream>

Portfolio::Portfolio(double startingCash)
{
    cash = startingCash;
    entryPrice = 0.0;
    quantity = 0;
}

void Portfolio::buy(double price, int qty)
{
    cash -= price * qty;
    entryPrice = price;
    quantity += qty;
}

void Portfolio::sell(double price, int qty)
{
    tradeReturns.push_back((price - entryPrice) / entryPrice * 100);
    cash += price * qty;
    quantity -= qty;
    entryPrice = 0.0;
}

double Portfolio::getUnrealisedPnL(double currentPrice) const
{
    return (currentPrice - entryPrice) * quantity;
}

void Portfolio::printStatus(double currentPrice) const
{
    std::cout << "Cash: $" << cash
              << " | Shares: " << quantity
              << " | Unrealised PnL $:" << getUnrealisedPnL(currentPrice)
              << "\n";
}

const std::vector<double> &Portfolio::getTradeReturns() const
{
    return tradeReturns;
}

double Portfolio::getCash() const
{
    return cash;
}