#include <iostream>
#include <string>

class http {
   private:
    std::string cookie;

   public:
    void init();
    std::string httpGet(std::string queryString);
    std::string httpPost(std::string postData);
    std::string getCookie(std::string name);
    std::string setCookie(std::string name);
    http(){};
    ~http(){};
};
