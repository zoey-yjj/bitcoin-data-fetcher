#include "CoinMarketCap.h"
#include "HttpClient.h"
#include <iostream>

int main() {
    std::string apiKey = "free-api-get-from-coin-market"; // Replace with your actual API key
    std::string symbol = "BTC";
    std::string base = "USD";

    CoinMarketCap coinMarketCap(apiKey);
    Json::Value coinData = coinMarketCap.getMarketData(symbol, base);

    if (coinData.size() == 0) {
        std::cout << "Symbol/Base: " << symbol << "/" << base << " is not available..." << std::endl;
    } else {
        std::cout << "Symbol/Base: " << symbol << "/" << base << std::endl;
        std::cout << "Price: " << coinData["price"].asFloat() << std::endl;
        std::cout << "Market Cap: " << coinData["market_cap"].asFloat() << std::endl;
    }

    return 0;
}