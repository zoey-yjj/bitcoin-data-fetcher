#include "TelegramBot.h"
#include "HttpClient.h"

TelegramBot::TelegramBot(const std::string& botToken, const std::string& chatId)
    : botToken_(botToken), chatId_(chatId) {}

void TelegramBot::sendMessage(const std::string& message) {
}
