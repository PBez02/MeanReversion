#include <iostream>
#include "include/DataLoader.h"
#include "include/Portfolio.h"
#include "include/MeanRevStrategy.h"

int main()
{
    std::vector<Candle> candles = DataLoader::load("data/prices.csv");

    Portfolio portfolio(10000.0);
    MeanRevStrategy strategy(portfolio, 20, 2.0);

    for (int i = 1; i <= (int)candles.size(); i++)
    {
        std::vector<Candle> window(candles.begin(), candles.begin() + i);
        strategy.onBar(window);
    }

    portfolio.printStatus(candles.back().close);
    return 0;
}