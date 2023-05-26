# **CoinMarketCap Data to Telegram Bot**

This project retrieves cryptocurrency data from the CoinMarketCap API and sends it to a Telegram bot. It provides a simple way to stay updated with the latest cryptocurrency prices on your Telegram account.

## **Prerequisites**

Before running the project, make sure you have the following prerequisites installed:

- C++ compiler
- libcurl library
- jsoncpp library
- Telegram bot token (obtained from the BotFather)

## **Installation**

1. Clone the repository:

    ```
    git clone https://github.com/zoey-yjj/coinmarketcap-telegram.git
    ```

2. Compile the source code:

    ```
    make
    ```

3. Set up the Telegram bot:
    - Create a new bot on Telegram using the BotFather.
    - Obtain the bot token.

4. Configure the project:
    - Open main.cpp in a text editor.
    - Replace <your-bot-token> with your Telegram bot token.
    - Replace <your-chat-id> with your Telegram chat ID.

## **Usage**

1. Run the compiled executable:

    ```
    ./fetcher
    ```

2. The program will fetch cryptocurrency data from CoinMarketCap API and send it to your Telegram bot.

3. Open your Telegram account and start a conversation with your bot. You will receive messages with the latest cryptocurrency prices.

## **Customization**

You can customize the project according to your requirements. Here are a few possible customizations:

- Modify the code in `CoinMarketCap.cpp` to retrieve additional data from the CoinMarketCap API.
- Implement your own strategy for sending messages to the Telegram bot, such as sending alerts based on specific price thresholds.
- Schedule the program to run periodically using a task scheduler or cron job.
