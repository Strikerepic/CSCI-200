/* Functions
 * Parts of a function
 * Parameters and arguments
 * Pass By Value
*/
#include <iostream>
using namespace std;

const double SALES_TAX = 0.07;

/**
 * @brief calculate total including sales tax
 * 
 * @param i items quant.
 * @param p pricer per item
 * @return double - total with tax
 */
double calc_total(int i, double p) {
    double total = i * p;
    total += SALES_TAX * total;
    return total;
}

int main() {
    int items = 0;
    double price = 0.0, total = 0.0;

    // Read the quantity and price from the user
    cout << "Enter item quantity: ";
    cin >> items;
    cout << "Enter price per item: ";
    cin >> price;

    // calculate and print the order total
    total = calc_total(items,price);
    cout << "Total is " << total << endl;
    
    cout << "With 10 percent price reduction" << endl;
    price = price * .9;

    // calculate and print order total with 10 percent membership
    total = calc_total(items,price);
    cout << "Total is " << total << endl;
    
    return 0;
}