#pragma once
#include <vector>
#include "Candle.h"

class Strategy {
    public:
        virtual void onBar(const std::vector<Candle>& candles) = 0;
        virtual ~Strategy() = default;
};