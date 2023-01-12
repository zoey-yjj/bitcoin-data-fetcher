#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <string>
#include <curl/curl.h>

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    std::string getRequest(const std::string& url);

    void addHeader(const std::string& headerName, const std::string& headerValue);

private:
    CURL* curl;
    struct curl_slist* headers;

};

#endif