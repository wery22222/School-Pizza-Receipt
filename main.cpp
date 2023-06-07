#include <iostream>
#include <string>
#include <map>

auto createPriceRef();
const float receipt(std::string& pizzaType, std::string& pizzaSize);

int main()
{
    std::string pizzaSize;
    std::string pizzaType;
    std::cout<< "Enter Pizza size (large, medium, small) ";
    getline(std::cin, pizzaSize);
    std::cout<<"Enter Pizza type (Hawaiian, Farmhouse, Margherita, Meat Feast, Caspian Special, Super Supreme) ";
    getline(std::cin, pizzaType);
    std::cout<<pizzaSize<<", "<<pizzaType<<std::endl;
    double price = 0.0;
    try
    {
         price = receipt(pizzaType, pizzaSize);
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    std::cout<<"The price is £"<<price<<std::endl;
}
auto createPriceRef()
{
    std::map<std::string, float> priceRef;
    priceRef["Hawaiian"] = 5.50f;
    priceRef["Farmhouse"] = 5.50f;
    priceRef["Margherita"] = 5.50f;
    priceRef["Meat Feast"] = 7.50f;
    priceRef["Caspian Special"] = 7.50f;
    priceRef["Super Supreme"] = 7.50f;
    return priceRef;
}
const float receipt(std::string& pizzaType, std::string& pizzaSize)
{
    auto wasFound =false;
    double price = 0;
    auto priceRef = createPriceRef();
    for (auto it:priceRef)
    {
        if (it.first == pizzaType)
        {
            price+=it.second; 
            wasFound = true;
            break;
        }
    }
    if (!wasFound)
        throw std::invalid_argument("No such Pizza type");
    if (pizzaSize == "large")
    {
        return price*=1.5;
    }
    if (pizzaSize  =="small")
        return price/=2;
    if (pizzaSize != "medium")
        throw std::invalid_argument("No such Pizza size");
    return price;
}
