#include <iostream> 
#include <iomanip> 
#include <Windows.h> 
using namespace std;

// Task
//Product > id,name, price, discount
//
//Store > Address, Product** products, count
//
//
//Show All Products 1
//Add New Products  2
//Delete products   3
//Buy Products      4

struct Product {
    int id;
    char* name;
    double price;
    double discount;
};

struct Store {
    int address;
    Product* products;
    int product_count;
};

void ShowProduct(const Product& product) {
    cout << "Id : " << product.id << endl;
    cout << "Name : " << product.name << endl;
    cout << "Price : " << product.price << endl;
    cout << "Discount : " << product.discount << endl;
    cout << endl;
}

void ShowStore(const Store& store) {
    cout << "Address: " << store.address << endl;
    cout << "Product count: " << store.product_count << endl;
    cout << "Products:" << endl;
    for (int i = 0; i < store.product_count; i++) {
        ShowProduct(store.products[i]);
    }
}

void ShowAllProduct(const Product products[], int count) {
    for (int i = 0; i < count; i++) {
        ShowProduct(products[i]);
    }
}

void AddNewProduct(Product products[], int& count) {
    cout << "Enter the ID new product : ";
    int id;
    cin >> id;

    cin.ignore();
    cout << "Enter the NAME new product : ";
    char* name = new char[50];
    cin.getline(name, 50);

    cout << "Enter the PRICE new product : ";
    double price;
    cin >> price;

    cout << "Enter the DISCOUNT new product : ";
    double discount;
    cin >> discount;

    Product new_product{ id,name, price, discount };
    products[count++] = new_product;

    delete[] name;
}

void DeleteProduct(Product products[], int& count) {
    cout << "Enter the ID product to delete : ";
    int id;
    cin >> id;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            products[i] = products[i + 1];
        }
        count--;
        cout << "Product has been deleted." << endl;
    }
    else {
        cout << "Product has not found." << endl;
    }
}

void BuyProduct(Product products[], int count) {
    for (size_t i = 0; i < count; i++)
    {
        cout << "Id-" << products[i].id << endl;
        cout << "Name-" << products[i].name << endl;
    }

    cout << "Enter the Id of the product you want to Buy :";
    int id_product;
    cin >> id_product;
    int index = -1;
    for (size_t i = 0; i < count; i++)
    {
        if (products[i].id == id_product) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        if (products[index].discount > 0) {
            cout << "Succeful purchase " << products[index].name << " is "
                << products[index].price - (products[index].price * products[index].discount) << "AZN" << " after discount " << endl;
        }
        else {
            cout << "Price " << products[index].name << " is " << products[index].price << endl;
        }
    }
    else {
        cout << "Product is not find" << endl;
    }
}


void ShowMenu() {
    cout << "\t\t\t*****Show All Menu*****" << endl << endl;
    cout << "1.Show All Products\t\t\t\t   2.Add New Product" << endl << endl;
    cout << "3.Deleted Product\t\t\t\t   4.Buy Product" << endl << endl;
    cout << "\t\t\t\t5.Exit" << endl << endl;
}

void main() {
    Product cola;
    cola.id = 7777;
    cola.name = new char[50] { "Cola" };
    cola.price = 3;
    cola.discount = 0.20;

    Product fanta;
    fanta.id = 9999;
    fanta.name = new char[50] { "Fanta" };
    fanta.price = 2;
    fanta.discount = 0.25;

    Product products[10] = { cola, fanta };
    int count = 2;

    int choice;
    while (true)
    {
        ShowMenu();
        cout << "Enter your choice : ";
        cin >> choice;
        Sleep(1000);
        system("cls");
        switch (choice) {
        case 1: {
            ShowAllProduct(products, count);

            break;
        }
        case 2: {
            AddNewProduct(products, count);
            ShowAllProduct(products, count);
            break;
        }
        case 3: {
            DeleteProduct(products, count);
            ShowAllProduct(products, count);
            break;
        }
        case 4: {
            BuyProduct(products, count);
            break;
        }
        case 5: {
            system("cls");
            cout << "Exiting proqram" << endl;
            break;
        }
        default: {
            system("cls");
            cout << "Invalid selection" << endl;
            break;
        }
        }
    }
}
