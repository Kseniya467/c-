#include "Holod.h"
#include <fstream>
#include <iostream>

using namespace std;

Product::Product(const std::string& name, double price)
    : name(name), price(price) {
}

istream& operator>>(istream& in, Product& product) {
    in >> product.name >> product.price;
    return in;
}


ostream& operator<<(ostream& out, const Product& product) {
    out << product.name << " " << product.price;
    return out;
}

void printProducts(Product* products, int count) {
    cout << "Содержимое холодильника:\n";
    for (int i = 0; i < count; i++) {
        cout << "Название: " << products[i].name << ", Цена: " << products[i].price << endl;
    }
}

void addProduct(Product*& products, int& count) {
    Product* newProducts = new Product[count + 1];

    for (int i = 0; i < count; i++) {
        newProducts[i] = products[i];
    }

    cout << "Введите название продукта: ";
    cin >> newProducts[count].name;

    cout << "Введите цену: ";
    cin >> newProducts[count].price;

    delete[] products;
    products = newProducts;
    count++;
}

void deleteProduct(Product*& products, int& count) {
    printProducts(products, count);
    int index;

    cout << "Введите номер продукта для удаления: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Несуществующий номер\n";
        return;
    }

    Product* newProducts = new Product[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index - 1) {
            newProducts[j++] = products[i];
        }
    }

    delete[] products;
    products = newProducts;
    count--;
}

void editProduct(Product* products, int count) {
    int index;
    printProducts(products, count);

    cout << "Введите номер продукта для редактирования: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Несуществующий номер\n";
        return;
    }

    string newName;
    double newPrice;

    cout << "Редактирование продукта: " << products[index - 1].name << "\n";
    cout << "Введите новое название продукта (или оставьте пустым для сохранения): ";
    cin.ignore();
    getline(cin, newName);
    if (!newName.empty()) {
        products[index - 1].name = newName;
    }

    cout << "Введите новую цену (или введите 0 для сохранения): ";
    cin >> newPrice;
    if (newPrice != 0) {
        products[index - 1].price = newPrice;
    }
}

void saveFile(Product* products, int count) {
    ofstream out("Holodilnic.txt");
    if (!out.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }
    out << count << endl;
    for (int i = 0; i < count; i++) {
        out << products[i] << endl;
    }
    cout << "Данные сохранены" << endl;
    out.close();
}

void loadFile(Product*& products, int& count) {
    ifstream in("Holodilnic.txt");
    if (!in.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }
    in >> count;
    products = new Product[count];
    for (int i = 0; i < count; i++) {
        in >> products[i];
    }
    in.close();
}
