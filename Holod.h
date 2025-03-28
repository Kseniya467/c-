#include <string>
#include <iostream>

class Product {
public:
    std::string name;
    double price;

    
    Product(const std::string& name = "", double price = 0.0);

    
    friend std::istream& operator>>(std::istream& in, Product& product);
    friend std::ostream& operator<<(std::ostream& out, const Product& product);
};

void printProducts(Product* products, int count);
void addProduct(Product*& products, int& count); 
void deleteProduct(Product*& products, int& count); 
void editProduct(Product* products, int count);
void saveFile(Product* products, int count);
void loadFile(Product*& products, int& count);


