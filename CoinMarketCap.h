#ifndef COINMARKETCAP_H
#define COINMARKETCAP_H

#include <string>

class CoinMarketCap {
public:
    CoinMarketCap(const std::string& apiKey);

private:
    std::string apiKey;
};

#endif
