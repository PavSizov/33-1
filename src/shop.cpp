#include "../include/shop.h"
#include <iostream>
#include <iomanip>


void Shop::insert(const std::string& article, std::size_t count)
{
    if(count == SIZE_MAX)
        throw exception_shop("Error count");

    auto it_find = _shop.find(article);

    if(it_find != _shop.end())
    {
        throw exception_shop("Such an article [" + article + "] already exists, use \"ADD\" to add the product");
    }
    else
    {
        _shop.insert(std::make_pair(article, count));
        _setw = std::max(_setw, article.size());
    }
}

void Shop::add(const std::string& article, std::size_t count)
{
    if(count == SIZE_MAX)
        throw exception_shop("Error count");

    auto it_find = _shop.find(article);

    if(it_find != _shop.end())
    {
        it_find->second += count;
    }
    else
    {
        throw exception_shop("Article " + article + " not found");
    }
}

void Shop::remove(const std::string& article, std::size_t count)
{
    if(count == SIZE_MAX)
        throw exception_shop("Error count");

    auto it_find = _shop.find(article);

    if(it_find != _shop.end())
    {
        if(count > it_find->second)
        {
            throw exception_shop("Error: The quantity being deleted is larger than the existing one");
        }
        else
        {
            it_find->second -= count;
        }

    }
    else
    {
        throw exception_shop("Article " + article + " not found");
    }
}

std::size_t Shop::count_article(const std::string& article) const
{
    auto it_find = _shop.find(article);

    if(it_find != _shop.end())
    {
        return it_find->second;
    }
    else
    {
        throw exception_shop("Article [" + article + "] not faund");
    }
}

std::size_t Shop::count_product() const
{
    return _shop.size();
}

void Shop::show() const
{

    for(auto it = _shop.begin(); it != _shop.end(); ++it)
    {
        std::cout << std::setw(static_cast<int>(_setw)) << std::left
                  << it->first << " : " << it->second << std::endl;
    }
}
