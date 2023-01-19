#include <string>

class TelegramBot {
public:
    TelegramBot(const std::string& botToken, const std::string& chatId);
    void sendMessage(const std::string& message);

private:
    std::string botToken_;
    std::string chatId_;
};
