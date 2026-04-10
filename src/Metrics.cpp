#include "../include/Metrics.h"
#include <cmath>
#include <numeric>
#include <stdexcept>

double Metrics::totalReturn(double startingCash, double finalCash)
{
    return (finalCash - startingCash) / startingCash * 100;
}

double Metrics::sharpeRatio(const std::vector<double> &returns)
{
    if (returns.empty())
        return 0.0;

    double mean = std::accumulate(returns.begin(), returns.end(), 0.0) / returns.size();

    double sumSq = 0.0;
    for (double r : returns)
    {
        sumSq += (r - mean) * (r - mean);
    }

    double stddev = std::sqrt(sumSq / (returns.size() - 1));

    if (stddev == 0.0)
        return 0.0;
    return mean / stddev;
}

double Metrics::maxDrawdown(const std::vector<double> &returns)
{
    if (returns.empty())
        return 0.0;

    double peak = 0.0;
    double maxDD = 0.0;
    double cumulative = 0.0;

    for (double r : returns)
    {
        cumulative += r;
        if (cumulative > peak)
            peak = cumulative;
        double drawdown = peak - cumulative;
        if (drawdown > maxDD)
            maxDD = drawdown;
    }
    return maxDD;
}
