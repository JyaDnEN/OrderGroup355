/*
Group Names: Delonzo Weaver, Jay Neil, Chloe Byrd
CS 355 Assignment 9
October 19, 2026
Description: This assignment is about building a class that handles queues and stacks 
            in a restaurant order management setting. We will demonstrate how each one works in our small program.
*/

#include <iostream>
#include <queue>
#include <stack>

struct Order {
    int number;
    string name;
    string foodOrder;
};
 
void addOrder(queue<Order>& pending, int& nextNumber){
    Order o;
    o.number = nextNumber++; 
    cout << "Enter customer name: ";
    cin >> o.name;

    pending.push(o);
    cout << "Added: " << o.name << " (Number: " << o.number << ")\n";
}

void showMenu() {
    cout << "        Restaurant Order Menu        " << endl
         << "1. Add a new order" << endl
         << "2. Prepare the next order" << endl
         << "3. Display pending orders" << endl
         << "4. View most recently completed order" << endl
         << "5. Reopen most recently completed order" << endl
         << "6. Exit" << endl
         << "Choose an option: ";
}

void showPending(queue<Order> pending) {
    if (pending.empty()) {
    cout << "The Queue is empty. \n";
    return;
    }
    cout <<  "    Waiting Line   " << endl;
    while (!pending.empty()) {
    cout << "#" << pending.front().number << "-" << pending.front().name << endl;
    pending.pop();
    }
}

void finishOrder(queue<Order>& pending,stack<Order>& done){
if (pending.empty()) {
    cout << "NO MORE ORDERS" << endl;
    return;
}
    
    Order o = pending.front();
    pending.pop();
    done.push(o);
    
    cout << " Finished order for " << o.name << endl;
}

int main() {
    int choice = 0; 
    int orderNumber = 100;
    queue<Order> orders;
    stack<Order> compOrders;

    while (choice != 6) {
        showMenu();
        if (choice == 1) {
            addOrder(orders, orderNumber);
        }
        else if (choice == 2) {
            finishOrder(orders, compOrders);
        }
        else if (choice == 3) {
            showPending(orders, compOrders);
        }
        else if (choice == 4) {
            showLastDone(orders);
        }
        else if (choice == 5) {
            
        }
        else if (choice == 6) {
            cout << "Thank you for using this system, have a nice day!";
        else {
            cout << "ERROR: Invalid input, try again.";
        }
    }
    return 0;
}
