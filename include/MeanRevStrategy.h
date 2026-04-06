#pragma once
#include "Strategy.h"
#include "Portfolio.h"

class MeanRevStrategy : public Strategy { 
    public:
        MeanRevStrategy(Portfolio& portfolio, int window, double threshold);

        void onBar(const std::vector<Candle>& candles) override;
    
    private:
        Portfolio& portfolio;
        int window;
        double threshold;
        bool inPosition;
};