#include "../include/DataLoader.h"
#include <fstream> // Reading files
#include <sstream> // Storing strings as streams
#include <stdexcept>

std::vector<Candle> DataLoader::load(const std::string &filepath)
{
    // intialising our vector to store our candles
    std::vector<Candle> candles;

    // opening the file with price data
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filepath);
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::istringstream ss(line);
        std::string token;
        Candle c;

        std::getline(ss, c.date, ',');
        std::getline(ss, token, ',');
        c.open = std::stod(token);
        std::getline(ss, token, ',');
        c.high = std::stod(token);
        std::getline(ss, token, ',');
        c.low = std::stod(token);
        std::getline(ss, token, ',');
        c.close = std::stod(token);
        std::getline(ss, token, ',');
        c.volume = std::stol(token);

        candles.push_back(c);
    }

    return candles;
}
