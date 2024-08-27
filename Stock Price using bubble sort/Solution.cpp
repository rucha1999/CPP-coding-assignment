
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_DAYS = 100;

struct StockRecord {
    string date;
    double price;
};

void inputStockPrices(StockRecord records[],int numDays);
void bubbleSortByDate(StockRecord records[],int numDays);
double calculateAveragePrice(StockRecord records[],int numDays);
void findHighestAndLowestPrices(StockRecord records[],int numDays);
void searchStockPricesInRange(StockRecord records[],int numDays);
int countPricesAboveThreshold(StockRecord records[],int numDays,double threshold);

int main(){
    StockRecord records[MAX_DAYS];
    int numDays;

    cout<<"Welcome to the Enhanced Stock Price Analysis Tool!\n";
    cout<<"Enter the number of days with historical stock prices (up to 100): ";
    cin>>numDays;

    inputStockPrices(records, numDays);
    bubbleSortByDate(records, numDays);

    int choice;
    do {
        cout<<"\nAdditional Features:\n";
        cout<<"1. Calculate average stock price.\n";
        cout<<"2. Find highest and lowest stock prices.\n";
        cout<<"3. Search for stock prices within a date range.\n";
        cout<<"4. Count days with stock price above a threshold.\n";
        cout<<"5. Exit.\n";
        cout<<"Select an option (1-5): ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Average stock price: $"<<fixed<<setprecision(2)<<calculateAveragePrice(records, numDays)<<endl;
                break;
            case 2:
                findHighestAndLowestPrices(records,numDays);
                break;
            case 3:
                searchStockPricesInRange(records,numDays);
                break;
            case 4: {
                double threshold;
                cout<<"Enter threshold price: $";
                cin>>threshold;
                cout<<"Number of days with stock price above the threshold: " << countPricesAboveThreshold(records, numDays, threshold)<<endl;
                break;
            }
            case 5:
                cout<<"Goodbye!\n";
                break;
            default:
                cout<<"Invalid choice. Please select again.\n";
                break;
        }
    } while(choice != 5);
    return 0;
}

void inputStockPrices(StockRecord records[],int numDays) {
    for (int i = 0; i < numDays; ++i) {
        cout<<"\nDay "<< i + 1 << ":\n";
        cout<<"Date (YYYY-MM-DD): ";
        cin>>records[i].date;
        cout<<"Stock Price: $";
        cin>>records[i].price;
    }
}

void bubbleSortByDate(StockRecord records[],int numDays) {
    for (int i = 0; i<numDays - 1; ++i) {
        for (int j = 0; j<numDays - i - 1; ++j) {
            if (records[j].date > records[j + 1].date) {
                swap(records[j],records[j + 1]);
            }
        }
    }
    cout<<"\nStock prices sorted successfully!\n";
}

double calculateAveragePrice(StockRecord records[],int numDays) {
    double total=0.0;
    for (int i = 0; i<numDays; ++i) {
        total += records[i].price;
    }
    return total/numDays;
}

void findHighestAndLowestPrices(StockRecord records[],int numDays) {
    cout<< "Highest stock price:\n";
    cout<< "Date: "<< records[numDays - 1].date << ", Price: $" <<records[numDays - 1].price <<endl;
    cout<< "Lowest stock price:\n";
    cout<< "Date: " << records[0].date << ", Price: $" << records[0].price <<endl;
}

void searchStockPricesInRange(StockRecord records[], int numDays) {
    string startDate,endDate;
    cout<< "Enter start date (YYYY-MM-DD): ";
    cin>>startDate;
    cout<< "Enter end date (YYYY-MM-DD): ";
    cin>>endDate;

    cout<<"Stock prices within the date range:\n";
    for (int i = 0; i < numDays; ++i) {
        if (records[i].date >= startDate && records[i].date <= endDate) {
            cout << "Date: " << records[i].date << ", Price: $" << records[i].price << endl;
        }
    }
}

int countPricesAboveThreshold(StockRecord records[],int numDays,double threshold) {
    int count = 0;
    for (int i = 0; i<numDays; ++i) {
        if (records[i].price >threshold) {
            count++;
        }
    }
    return count;
}
