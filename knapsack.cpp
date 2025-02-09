#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;

    Item() : weight(0), value(0), ratio(0.0) {}

    Item(int w, int v) {
        weight = w;
        value = v;
        ratio = (double)v / w;  
    }
};

double fractionalKnapsack(int capacity, Item items[], int n) {
    sort(items, items + n, [](Item& a, Item& b) {
        return a.ratio > b.ratio;  
    });

    double totalValue = 0.0;  
    for (int i = 0; i < n; ++i) {
        if (capacity == 0) {
            break;  
        }

    
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0;  
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;


    Item items[100];  

    cout << "Enter the weight and value for each item:\n";
    for (int i = 0; i < n; ++i) {
        int weight, value;
        cout << "Item " << i + 1 << ": ";
        cin >> weight >> value;
        items[i] = Item(weight, value);
    }


    double result = fractionalKnapsack(capacity, items, n);

    cout << "The maximum value that can be obtained is: " << result << endl;

    return 0;
}

//O(nlogn) time complexity
//O(n) space complexity