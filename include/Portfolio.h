#pragma once

class Portfolio {
    public:
        Portfolio(double startingCash);
        void buy(double price, int qty);
        void sell(double price, int qty);
        double getUnrealisedPnL(double currentPrice) const;
        void printStatus(double currentPrice) const;
    
    private:
        double cash;
        double entryPrice;
        int quantity;
};