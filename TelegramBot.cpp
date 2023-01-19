#include "TelegramBot.h"
#include "HttpClient.h"

TelegramBot::TelegramBot(const std::string& botToken, const std::string& chatId)
    : botToken_(botToken), chatId_(chatId) {}

void TelegramBot::sendMessage(const std::string& message) {
    HttpClient httpClient;
    std::string url = "https://api.telegram.org/bot" + botToken_ + "/sendMessage";
    std::string data = R"({"chat_id": ")" + chatId_ + R"(", "text": ")" + message + R"("})";

    httpClient.postRequest(url, data);
}
