#include "../include/MeanRevStrategy.h"
#include <cmath>
#include <iostream>

MeanRevStrategy::MeanRevStrategy(Portfolio& portfolio, int window, double threshold) : portfolio(portfolio), window(window), threshold(threshold), inPosition(false) {}

void MeanRevStrategy::onBar(const std::vector<Candle>& candles) {
    if ((int)candles.size() < window) return;

    int start = candles.size() - window;
    double sum = 0.0;
    for (int i = start; i < (int)candles.size(); i++) {
        sum += candles[i].close;
    }
    double mean = sum / window;

    double sumSq = 0.0;
    for (int i = start; i < (int)candles.size(); i++) {
        double diff = candles[i].close - mean;
        sumSq += diff * diff;
    }
    double stddev = std::sqrt(sumSq / (window - 1));

    double currentPrice = candles.back().close;
    double zscore = (currentPrice - mean) / stddev;

    if ( zscore < - threshold && inPosition) {
        portfolio.buy(currentPrice, 10);
        inPosition = true;
        std::cout << "BUY at " << currentPrice << " | z-score: " << zscore << "\n";
    }
    else if (zscore > threshold && inPosition) {
        portfolio.sell(currentPrice, 10);
        inPosition = false;
        std::cout << "SELL at " << currentPrice << " | z-score: " << zscore << "\n";
    }

}