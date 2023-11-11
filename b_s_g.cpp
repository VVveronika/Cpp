#include <iostream>
#include <string>

using namespace std;

class Queue {
 private:
    struct Node {
        int value;
        Node* next_element_ptr = nullptr;
    };

    Node* last_element_ptr = nullptr;
    Node* first_element_ptr = nullptr;

    int length = 0;

    void delete_first_element() {
        length--;
        Node* deleted_element = first_element_ptr;
        first_element_ptr = first_element_ptr->next_element_ptr;
        delete deleted_element;

        if (length == 0) {
            last_element_ptr = nullptr;
            first_element_ptr = nullptr;
        }
    }

    void clear_all() {
        while (length > 0) {
            delete_first_element();
        }
    }

 public:
    void push(int value) {
        length++;
        Node* n = new Node;
        n->value = value;

        if (first_element_ptr == nullptr) {
            first_element_ptr = n;
        }

        if (last_element_ptr != nullptr) {
            last_element_ptr->next_element_ptr = n;
        }

        last_element_ptr = n;
    }

    int front() {
        return first_element_ptr->value;
    }

    int pop() {
        int tmp_value = front();
        delete_first_element();
        return tmp_value;
    }

    int size() {
        return length;
    }

    void clear() {
        clear_all();
    }

    void exit() {
        clear_all();
    }
};

int main() {
    Queue q;
    string command = "";

    while (command != "exit") {
        cin >> command;
        if (command == "pop") {
            cout << q.pop() << endl;
        } else if (command == "front") {
            cout << q.front() << endl;
        } else if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "clear") {
            q.clear();
            cout << "ok" << endl;
        } else if (command == "exit") {
            q.exit();
            cout << "bye" << endl;
        } else if (command == "push") {
            int value;
            cin >> value;
            q.push(value);
            cout << "ok" << endl;
        }
    }

    return 0;
}
