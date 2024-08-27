#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100; // Maximum number of reservations

string data[MAX_SIZE];
int front = 0;
int rear = -1;

void enqueue(string customerName){
    if (rear == MAX_SIZE-1) {
        cout << "Queue is full. Cannot add more reservations." << endl;
        return;
    }
    rear++;
    data[rear] = customerName;
    cout << "Reservation for " << customerName <<" added to the queue"<< endl;
}

void dequeue(){
    if (front > rear){
        cout << "Queue is empty. No reservation to dequeue." << endl;
        return;
    }
    cout << "Reservation for " << data[front] << " removed from the queue." << endl;
}

void display(){
    if (front > rear) {
        cout << "Queue is empty. No reservations to display." << endl;
        return;
    }
    cout << "Current reservations:" << endl;
    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". " << data[i] << endl;
    }
}

void cancelReservation(string customerName){
    for (int i = front; i <= rear; i++) {
        if (data[i] == customerName) {
            cout << "Reservation for " << customerName << " canceled." << endl;
            for (int j = i; j < rear; j++){
                data[j] = data[j + 1];
            }
            rear--;
            return;
        }
    }
    cout << "Reservation for " << customerName << " not found." << endl;
}

bool checkAvailability(string customerName){
    for (int i = front; i <= rear; i++) {
        if (data[i] == customerName) {
            cout << "Reservation for " << customerName << " exists." << endl;
            return true;
        }
    }
    cout << "Reservation for " << customerName << " does not exist." << endl;
    return false;
}

void clearQueue(){
    front = 0;
    rear = -1;
    cout << "All reservations cleared." << endl;
}

int getQueueSize(){
    return rear - front + 1;
}

void peekFront(){
    if (front > rear) {
        cout << "Queue is empty. No reservations at the front." << endl;
        return;
    }
    cout << "Reservation at the front: " << data[front] << endl;
}

void peekRear() {
    if (front > rear) {
        cout << "Queue is empty. No reservations at the rear." << endl;
        return;
    }
    cout << "Reservation at the rear: " << data[rear - 1] << endl;
}

int main() {
    cout << "Welcome to the Movie Theater Ticket Booking System!" << endl;
    int choice;
    string customerName;

    do {
        cout << "\n1. Book a ticket\n2. Cancel a reservation\n3. Display reservations\n4. Check availability\n5. Clear all reservations\n6. Get queue size\n7. Peek at front\n8. Peek at rear\n9. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> customerName;
                enqueue(customerName);
                break;
            case 2:
                cout << "Enter customer name to cancel: ";
                cin >> customerName;
                cancelReservation(customerName);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Enter customer name to check availability: ";
                cin >> customerName;
                checkAvailability(customerName);
                break;
            case 5:
                clearQueue();
                break;
            case 6:
                cout << "Queue size: " << getQueueSize() << " reservations." << endl;
                break;
            case 7:
                peekFront();
                break;
            case 8:
                peekRear();
                break;
            case 9:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}


