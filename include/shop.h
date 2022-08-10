#pragma once

#include <string>
#include <map>
#include <exception>

class exception_shop : std::exception
{
    std::string _message;

public:
    exception_shop(const std::string& message) : _message(message){}
    const char* what() const noexcept override
    {

        return _message.c_str();
    }
};

class Shop{

    std::map<std::string, std::size_t> _shop;
    std::size_t _setw = 0;

public:
    Shop() = default;
    ~Shop() = default;
    Shop(const Shop& other) = default;
    Shop& operator=(Shop& other) = default;

    void insert(const std::string& article, std::size_t count);

    void add(const std::string& article, std::size_t count);

    void remove(const std::string& article, std::size_t count);

    std::size_t count_article(const std::string& article) const;

    std::size_t count_product() const;

    void show() const;
};
