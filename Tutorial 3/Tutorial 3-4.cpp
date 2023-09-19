#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    void push(int element) {
        queue1.push(element);
    }

    void pop() {
        if (queue1.empty()) {
            std::cout << "Stack is empty. Cannot pop.\n";
            return;
        }

        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        std::cout << "Popped element: " << queue1.front() << std::endl;
        queue1.pop();

        std::swap(queue1, queue2);
    }

    int top() {
        if (queue1.empty()) {
            std::cout << "Stack is empty.\n";
            return -1;
        }

        while (queue1.size() > 1) {
            queue2.push(queue1.front());
                  queue1.pop();
        }

        int topElement = queue1.front();
        queue2.push(topElement);

        std::swap(queue1, queue2);

        return topElement;
    }

    bool isEmpty() {
        return queue1.empty();
    }
};

int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "Top element: " << myStack.top() << std::endl;

    return 0;
}