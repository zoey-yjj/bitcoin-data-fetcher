#include "HttpClient.h"
#include <iostream>

HttpClient::HttpClient() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    headers = nullptr;
}

HttpClient::~HttpClient() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    if (headers) {
        curl_slist_free_all(headers);
    }
    curl_global_cleanup();
}

std::string HttpClient::getRequest(const std::string& url) {
    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        std::cerr << "Failed to perform request: " << curl_easy_strerror(result) << std::endl;
    }

    return response;
}

std::string HttpClient::postRequest(const std::string& url, const std::string& data) {
    std::string response;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");  // Adjust the Content-Type as needed
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.length());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode result = curl_easy_perform(curl);
        if (result != CURLE_OK) {
            std::cerr << "Failed to perform request: " << curl_easy_strerror(result) << std::endl;
        }
        curl_slist_free_all(headers);
    }
    return response;
}

void HttpClient::addHeader(const std::string& headerName, const std::string& headerValue) {
    std::string header = headerName + ": " + headerValue;
    headers = curl_slist_append(headers, header.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
}

size_t HttpClient::writeCallback(void* buffer, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* response = static_cast<std::string*>(userp);
    response->append(static_cast<char*>(buffer), totalSize);
    return totalSize;
}
