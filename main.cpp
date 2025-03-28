#include "Holod.h"
#include <iostream>

using namespace std;

int main() {
    Product* products = nullptr;
    int count = 0;

    loadFile(products, count); 

    int choice;
    do {
        cout << "\nВыберите действие:\n"
            << "1. Добавить продукт\n"
            << "2. Удалить продукт\n"
            << "3. Редактировать продукт\n"
            << "4. Показать продукты\n"
            << "5. Сохранить продукты в файл\n"
            << "0. Выход\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addProduct(products, count);
            break;
        case 2:
            deleteProduct(products, count);
            break;
        case 3:
            editProduct(products, count);
            break;
        case 4:
            printProducts(products, count);
            break;
        case 5:
            saveFile(products, count);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
            break;
        }
    } while (choice != 0);

    delete[] products; 
    return 0;
}
