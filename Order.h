/*
Jay , Chole, 
CS 355
10/19/2026
Restaurant Order Management- code to run stacks and queues to order a Restaurant.
*/

#ifndef ORDER_H
#define ORDER_H

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

#endif
 



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
