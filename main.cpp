#include <iostream>
#include "include/DataLoader.h"

int main()
{
    std::vector<Candle> candles = DataLoader::load("data/prices.csv");

    std::cout << "Loaded " << candles.size() << " candles\n";
    std::cout << "First candle: " << candles[0].date << " close: " << candles[0].close << "\n";

    return 0;
}