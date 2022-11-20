#pragma once

#include "http.hpp"

void http::init() {
    std::string str =
        "<body>\n"
            "<p>Форма для GET</p>"
            "<form action=\"main.cgi\" method=\"GET\"> "
                    "<p><input name=\"get\"></p>"
                    "<p><input type=\"submit\" value=\"Отправить GET\"></p> "
             "</form>"
            "<p>Форма для POST</p>"
            "<form action=\"main.cgi\" method=\"POST\"> "
                "<p><input name=\"post\"></p>"
                "<p><input type=\"submit\" value=\"Отправить POST\"></p> "
            "</form>"
            "<p>Форма для COOKIE</p>"
            "<form action=\"main.cgi\" method=\"POST\"> "
                "<p><input name=\"cookie\"></p>"
                "<p><input type=\"submit\" value=\"Set-Cookie\"></p> "
            "</form>"
        "</body>";
    std::string postInput;
    std::cin >> postInput;
    if (postInput.find("cookie") != std::string::npos) {
        std::cout << setCookie(postInput);
    } else {
        std::cout << "Content-Type: text/html;charset=utf-8\r\n\r\n";
        std::string env(getenv("QUERY_STRING"));
        if (env.size()) {
            std::cout << httpGet(getenv("QUERY_STRING"));
        } else if (postInput.find("post") != std::string::npos) {
            std::cout << httpPost(postInput);
        } else {
            std::cout << str;
        }
    }
}
std::string http::httpGet(std::string queryString) {
    std::string str =
        "<body>\n"
            "<p>GET</p>"
            "<p>Вы ввели: ";
    str += queryString.substr(queryString.find("=") + 1, queryString.size());
    str +=
            "</p>"
        "</body>";
    return str;
}

std::string http::httpPost(std::string postData) {
    std::string str =
        "<body>\n"
            "<p>POST</p>"
            "<p>Вы ввели: ";
    str += postData.substr(postData.find("=") + 1, postData.size());
    str +=
            "</p>"
        "</body>";
    return str; 
}

std::string http::getCookie(std::string cookie) {
 return "1";
}

std::string http::setCookie(std::string cookie) { 
    std::cout << "Set-Cookie: yourCookie=" << cookie << ";\r\n";
    std::cout << "Content-Type: text/html;charset=utf-8\r\n\r\n";
    std::string str= 
        "<body>\n"
            "<p>POST</p>"
            "<p>Теперь ваши Cookie будут: ";
    str += cookie.substr(cookie.find("=") + 1, cookie.size());
    str +=
            "</p>"
        "</body>";
    return str;
 }