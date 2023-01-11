#ifndef COINMARKETCAP_H
#define COINMARKETCAP_H

#include <string>
#include <jsoncpp/json/json.h>

class CoinMarketCap {
public:
    CoinMarketCap(const std::string& apiKey);

    Json::Value getMarketData(const std::string& symbol);

private:
    std::string apiKey;
};

#endif
