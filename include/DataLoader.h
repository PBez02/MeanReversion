#pragma once
#include <vector>
#include <string>
#include "Candle.h"

class DataLoader
{
public:
    static std::vector<Candle> load(const std::string &filepath);
};