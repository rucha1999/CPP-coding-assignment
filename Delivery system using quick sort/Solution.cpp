#include <iostream>
#include <string>

using namespace std;

struct DeliveryOrder {
    string recipientName;
    string destination;
    string deliveryAddress;
    int estimatedTime;
    int orderID;
};

int partition(DeliveryOrder orders[], int left, int right) {
    int pivot = orders[right].estimatedTime;
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(orders[j].estimatedTime < pivot) {
            i++;
            swap(orders[i], orders[j]);
        }
    }
    swap(orders[i + 1], orders[right]);
    return i + 1;
}


void quicksortDeliveryOrders(DeliveryOrder orders[], int left, int right) {
    if(left<right){
        int pi = partition(orders, left, right);
        quicksortDeliveryOrders(orders, left, pi - 1);
        quicksortDeliveryOrders(orders, pi + 1, right);
    }
}


void inputDeliveryOrders(DeliveryOrder orders[], int numOrders) {
    for (int i = 0; i < numOrders; i++) {
        cin.ignore();
        cout <<endl;
        cout <<"Delivery " << i + 1 << ":" <<endl;
        cout <<"Recipient's Name: ";
        getline(cin, orders[i].recipientName);
        cout <<"Destination: ";
        getline(cin, orders[i].destination);
        cout <<"Delivery Address: ";
        getline(cin, orders[i].deliveryAddress);
        cout <<"Estimated Time (minutes): ";
        cin >> orders[i].estimatedTime;
        cout <<"Order ID: ";
        cin >> orders[i].orderID;
        
    }

}

void displaySortedOrders(DeliveryOrder orders[], int numOrders) {
    cout << endl;
    cout << "Sorted Delivery Orders:" <<endl;
    for (int i = 0; i < numOrders; i++) {
        cout << "Order ID: " << orders[i].orderID <<endl;
        cout << "Recipient's Name: " << orders[i].recipientName <<endl;
        cout << "Destination: " << orders[i].destination << endl;
        cout << "Delivery Address: " << orders[i].deliveryAddress <<endl;
        cout << "Estimated Time: " << orders[i].estimatedTime << " minutes" << endl;
        cout << "--------------------------" <<endl;
    }
}

void searchByRecipientName(DeliveryOrder orders[], int numOrders, const string& recipientName) {
    cout << endl;
    cout << "Delivery Orders for Recipient: " << recipientName << endl;
    for (int i = 0; i < numOrders; i++) {
        if (orders[i].recipientName == recipientName) {
            cout << "Order ID: " << orders[i].orderID << endl;
            cout << "Destination: " << orders[i].destination << endl;
            cout << "Estimated Time: " << orders[i].estimatedTime << " minutes" <<endl;
            cout << "-------------------------" <<endl;
        }
    }
}

void calculateTotalEstimatedTime(DeliveryOrder orders[], int numOrders) {
    int totalEstimatedTime = 0;
    for (int i = 0; i < numOrders; i++) {
        totalEstimatedTime += orders[i].estimatedTime;
    }
    cout << endl;
    cout << "Total Estimated Time for All Delivery Orders: " << totalEstimatedTime << " minutes" <<endl;
}

void findFastestAndSlowest(DeliveryOrder orders[], int numOrders) {
    cout << endl;
    cout << "Fastest Delivery Order:" << endl;
    cout << "Recipient's Name: " << orders[0].recipientName << endl;
    cout << "Destination: " << orders[0].destination << endl;
    cout << "Estimated Time: " << orders[0].estimatedTime << " minutes" << endl;
    cout << endl;
    cout << "Slowest Delivery Order:" << endl;
    cout << "Recipient's Name: " << orders[numOrders - 1].recipientName << endl;
    cout << "Destination: " << orders[numOrders - 1].destination << endl;
    cout << "Estimated Time: " << orders[numOrders - 1].estimatedTime << " minutes" << endl;
}

void displayOrdersWithinTimeRange(DeliveryOrder orders[], int numOrders, int minTime, int maxTime) {
    cout << endl;
    cout << "Delivery Orders within Time Range (" << minTime << " - " << maxTime << " minutes):" << endl;
    for (int i = 0; i < numOrders; i++) {
        if (orders[i].estimatedTime >= minTime && orders[i].estimatedTime <= maxTime) {
            cout << "Order ID: " << orders[i].orderID << endl;
            cout << "Recipient's Name: " << orders[i].recipientName << endl;
            cout << "Destination: " << orders[i].destination << endl;
            cout << "Estimated Time: " << orders[i].estimatedTime << " minutes" << endl;
            cout << "-----------------------" << endl;
        }
    }
    cout << endl;
}

int main() {
    int numOrders;
    cout << "Welcome to the Delivery Order Management System!\n";
    cout << "Enter the number of delivery orders: ";
    cin >> numOrders;

    DeliveryOrder orders[numOrders];

    // Input delivery orders
    inputDeliveryOrders(orders, numOrders);

    // Perform Quick Sort to sort delivery orders by estimated time
    quicksortDeliveryOrders(orders, 0, numOrders - 1);

    // Display sorted delivery orders
    displaySortedOrders(orders, numOrders);
    cout << endl;
    
    // Additional Tasks:
    
    // Task 3: Search for delivery orders by recipient's name
    string searchRecipient;
    cout << "Enter recipient's name to search for delivery orders: ";
    cin.ignore();
    getline(cin, searchRecipient);
    searchByRecipientName(orders, numOrders, searchRecipient);

    // Task 4: Calculate and display total estimated time
    calculateTotalEstimatedTime(orders, numOrders);

    // Task 5: Find and display the fastest and slowest delivery orders
    findFastestAndSlowest(orders, numOrders);

    // Task 6: Display delivery orders within a specific time range
    int minTime, maxTime;
    cout << endl;
    cout << "Enter minimum and maximum estimated time range (in minutes): ";
    cin >> minTime >> maxTime;
    displayOrdersWithinTimeRange(orders, numOrders, minTime, maxTime);

    return 0;
}

