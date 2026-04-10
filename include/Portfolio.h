#pragma once
#include <vector>

class Portfolio
{
public:
    Portfolio(double startingCash);
    void buy(double price, int qty);
    void sell(double price, int qty);
    double getUnrealisedPnL(double currentPrice) const;
    void printStatus(double currentPrice) const;
    const std::vector<double> &getTradeReturns() const;
    double getCash() const;

private:
    double cash;
    double entryPrice;
    int quantity;
    std::vector<double> tradeReturns;
};