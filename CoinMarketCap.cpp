#include "CoinMarketCap.h"
#include "HttpClient.h"

CoinMarketCap::CoinMarketCap(const std::string& apiKey) : apiKey(apiKey) {}

Json::Value CoinMarketCap::getMarketData(const std::string& symbol) {
    std::string url = "https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/latest?symbol=" + symbol;

    HttpClient httpClient;

    std::string response = httpClient.getRequest(url);

    return response;
}
