#include <iostream>
#include <exception>
#include "../include/shop.h"


int main()
{
    Shop shop;

    std::cout << "Enter database shop: " << std::endl;
    std::string article;
    std::size_t count;
    do
    {
        std::cout<<"Insert [Article] and [count]:" << std::endl;
        std::cin >> article;
        if(article != "end")
        {
            std::cin >> count;
            try
            {
                shop.insert(article, count);
            }
            catch(const exception_shop& e)
            {
                std::cerr << e.what() << '\n';
            }

            std::cout<<"Enter [end] to complete:" << std::endl;
        }

    }while(article != "end");

    if(shop.count_product() == 0)
    {
        std::cout << "The database has been empty, exit to programm..." << std::endl;
        return 0;
    }

    std::cout << "The database has been created, use [add], [remove], [exit] to work" << std::endl;
    shop.show();

    do
    {
        std::cout << ">> ";
        std::cin >> article;
        if(article == "add")
        {
            std::cout<< "Enter name article for add count: ";
            std::cin >> article;
            std::cout<< "Enter count: ";
            std::cin >> count;
            try
            {
                shop.add(article, count);
                shop.show();
            }
            catch(const exception_shop& e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what();
                return 1;
            }

        }
        else if(article == "remove")
        {
            std::cout<< "Enter name article for remove count: ";
            std::cin >> article;
            std::cout<< "Enter count: ";
            std::cin >> count;
            try
            {
                shop.remove(article, count);
                shop.show();
            }
            catch(const exception_shop& e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what();
                return 1;
            }
        }

    } while (article != "exit");
    std::cout << "The database close" << std::endl;
}
