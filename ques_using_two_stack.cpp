#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x) {
        s1.push(x);
    }

    int deQueue() {
        
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Operations Menu:";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enQueue(value);
                break;
            case 2:
                value = q.deQueue();
                if (value != -1) {
                    cout << "Dequeued value: " << value << endl;
                }
                break;
            case 3:
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
