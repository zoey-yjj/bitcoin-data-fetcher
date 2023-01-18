#include "CoinMarketCap.h"
#include "HttpClient.h"
#include <iostream>

int main() {
    // Crypto data to be collected
    std::string apiKey = "free-api-get-from-coin-market"; // Replace with your actual API key
    std::string symbol = "BTC";
    std::string base = "USD";

    // initialise CoinMarketCap with apiKey
    CoinMarketCap coinMarketCap(apiKey);

    // get data in jason format using getMarketData function
    Json::Value coinData = coinMarketCap.getMarketData(symbol, base);

    // if data size is zero, there is no related information for required pair Symbol/Base
    if (coinData.size() == 0) {
        std::cout << "Symbol/Base: " << symbol << "/" << base << " is not available..." << std::endl;
    
    // data is received, print out for checking
    } else {
        std::cout << "Symbol/Base: " << symbol << "/" << base << std::endl;
        std::cout << "Price: " << coinData["price"].asFloat() << std::endl;
        std::cout << "Market Cap: " << coinData["market_cap"].asFloat() << std::endl;
    }

    return 0;
}