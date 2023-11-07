#include <iostream>
#include <string>

using namespace std;

class Queue {
 private:
    string protocol = "";
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
        protocol = protocol + "ok" + '\n';
    }

    void front() {
        protocol = protocol + to_string(first_element_ptr->value) + '\n';
    }

    void pop() {
        front();
        delete_first_element();
    }

    void size() {
        protocol = protocol + to_string(length) + '\n';
    }

    void clear() {
        clear_all();
        protocol = protocol + "ok" + '\n';
    }

    void exit() {
        protocol = protocol + "bye" + '\n';
        clear_all();
        cout << protocol;
    }
};

int main() {
    Queue q;
    string command = "";

    while (command != "exit") {
        cin >> command;
        if (command == "pop") {
            q.pop();
        } else if (command == "front") {
            q.front();
        } else if (command == "size") {
            q.size();
        } else if (command == "clear") {
            q.clear();
        } else if (command == "exit") {
            q.exit();
        } else if (command == "push") {
            int value;
            cin >> value;
            q.push(value);
        }
    }

    return 0;
}
