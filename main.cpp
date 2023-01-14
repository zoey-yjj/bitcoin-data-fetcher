#include "CoinMarketCap.h"
#include "HttpClient.h"
#include <iostream>

int main() {
    std::string apiKey = "free-api-get-from-coin-market"; // Replace with your actual API key
    std::string symbol = "BTC";
    std::string base = "USD";

    CoinMarketCap coinMarketCap(apiKey);
    Json::Value coinData = coinMarketCap.getMarketData(symbol, base);

    std::cout << "coinData is " << coinData << std::endl;

    return 0;
}