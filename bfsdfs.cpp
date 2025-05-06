#include <iostream>
using namespace std;

class graph {
public:
    int vcnt, rcnt;
    int a[20][20];
    int v[20];

    graph() {
        vcnt = 0;
        rcnt = 0;
    }
    void admat();
    void dis_admat();
    void bfs();
    void dfs();
    int search(int key);
    void reset_visited() { rcnt = 0; } // Reset visited nodes
};

void graph::admat() {
    cout << "Enter total no. of vertices: ";
    cin >> vcnt;
    for (int i = 1; i <= vcnt; i++) {
        for (int j = 1; j <= vcnt; j++) {
            cout << "Edge from " << i << " to " << j << " (1/0): ";
            cin >> a[i][j];
        }
    }
}

void graph::dis_admat() {
    for (int i = 1; i <= vcnt; i++) {
        for (int j = 1; j <= vcnt; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

class queue {
public:
    int q[20];
    int front, rear;
    queue() {
        front = 0;
        rear = 0;
    }
    void insert(int key);
    int del();
    bool is_empty() { return front == rear; }
};

void queue::insert(int key) {
    if (rear < 20) {
        q[rear++] = key;
    } else {
        cout << "Queue is full." << endl;
    }
}

int queue::del() {
    if (!is_empty()) {
        return q[front++];
    } else {
        cout << "Queue is empty." << endl;
        return -1; // Indicate error
    }
}

class stack {
public:
    int s[20];
    int top;
    stack() {
        top = -1;
    }
    void push(int key);
    int pop();
    bool is_empty() { return top == -1; }
};

void stack::push(int key) {
    if (top < 19) {
        s[++top] = key;
    } else {
        cout << "Stack is full." << endl;
    }
}

int stack::pop() {
    if (!is_empty()) {
        return s[top--];
    } else {
        cout << "Stack is empty." << endl;
        return -1; // Indicate error
    }
}

int graph::search(int key) {
    for (int i = 0; i < rcnt; i++) {
        if (v[i] == key) {
            return 1;
        }
    }
    return 0;
}

void graph::bfs() {
    int sv, curr;
    cout << "Enter start vertex: ";
    cin >> sv;
    reset_visited(); // Reset before traversal

    queue q;
    q.insert(sv);
    v[rcnt++] = sv;

    while (!q.is_empty()) {
        curr = q.del();
        if (curr == -1) break; // Handle error

        for (int c = 1; c <= vcnt; c++) {
            if (a[curr][c] == 1 && search(c) == 0) {
                q.insert(c);
                v[rcnt++] = c;
            }
        }
    }

    cout << "BFS: ";
    for (int i = 0; i < rcnt; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void graph::dfs() {
    int sv, curr;
    cout << "Enter start vertex: ";
    cin >> sv;
    reset_visited(); // Reset before traversal

    stack s1;
    s1.push(sv);
    v[rcnt++] = sv;

    while (!s1.is_empty()) {
        curr = s1.pop();
        if (curr == -1) break; // Handle error

        for (int c = vcnt; c >= 1; c--) { // Reverse order to match DFS
            if (a[curr][c] == 1 && search(c) == 0) {
                s1.push(c);
                v[rcnt++] = c;
            }
        }
    }

    cout << "DFS: ";
    for (int i = 0; i < rcnt; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    graph obj;
    obj.admat();
    obj.dis_admat();

    int choice;
    do {
        cout << "\nMenu\n1. BFS\n2. DFS\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                obj.bfs();
                break;
            case 2:
                obj.dfs();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}