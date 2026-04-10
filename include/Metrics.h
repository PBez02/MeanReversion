#pragma once
#include <vector>

namespace Metrics {
    double totalReturn(double startingCash, double finalCash);
    double sharpeRatio(const std::vector<double>& returns);
    double maxDrawdown(const std::vector<double>& returns);
}