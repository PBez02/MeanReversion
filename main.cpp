#include <iostream>
#include "include/DataLoader.h"
#include "include/Portfolio.h"
#include "include/MeanRevStrategy.h"
#include "include/Metrics.h"

// Main
int main()
{
    std::vector<Candle> candles = DataLoader::load("data/prices.csv");

    Portfolio portfolio(10000.0);
    MeanRevStrategy strategy(portfolio, 100, 2.0);

    for (int i = 1; i <= (int)candles.size(); i++)
    {
        std::vector<Candle> window(candles.begin(), candles.begin() + i);
        strategy.onBar(window);
    }

    portfolio.printStatus(candles.back().close);

    auto &returns = portfolio.getTradeReturns();

    std::cout << "Total Return: " << Metrics::totalReturn(10000.0, portfolio.getCash()) << "%\n";
    std::cout << "Sharpe Ratio: " << Metrics::sharpeRatio(returns) << "\n";
    std::cout << "Max Drawdown: " << Metrics::maxDrawdown(returns) << "\n";
    return 0;
}