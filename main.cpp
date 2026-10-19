/*
Group Names: Delonzo Weaver, Jay Neil, Chloe Byrd
CS 355 Assignment 9
October 19, 2026
Description: This assignment is about being a class that handles queues and stacks 
            in a restaurant order managment setting. It will demonstrate how each one works in a small program.
*/

#include <iostream>
#include <string>
#include <queue>
#include <stack>

struct Order {
    int id;
    std::string name;
};

void addOrder(queue<Order>& pending, int nextId);
void finishOrder(queue<Order>& pending,stack<Order>& done);
void showPending(queue<Order> pending);
void showLastDone(stack<Order> done);
void showMenu();


 
void addOrder(queue<Order>& pending, int& nextNumber){
    Order o;
    o.number = nextNumber++; 
    cout << "Enter customer name: ";
    cin >> o.name;

    pending.push(o);
    cout << "Added: " << o.name << " (Number: " << o.number << ")\n";
}

void showMenu() {
    cout << "        Restaurant Order Menu        " << endl;
         << "1. Add a new order" << endl;
         << "2. Prepare the next order" << endl;
         << "3. Display pending orders" << endl;
         << "4. View most recently completed order" << endl;
         << "5. Reopen most recently completed order" << endl;
         << "6. Exit" << endl;
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
    done.push(o);
    
    cout << " Finished order for " << o.name << endl;
}

void showLastDone(stack<Order> done){

}
