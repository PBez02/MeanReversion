#pragma once
#include <string>

struct Candle
{
    std::string date;
    double open;
    double close;
    double high;
    double low;
    long volume;
};