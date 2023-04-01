template <typename T>
class LinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* top;
public:
    LinkedStack() : top(nullptr) {}
    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    bool isEmpty() const {
        return top == nullptr;
    }
    void push(const T& data) {
        top = new Node(data, top);
    }
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        Node* oldTop = top;
        T data = oldTop->data;
        top = oldTop->next;
        delete oldTop;
        return data;
    }
    T& peek() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return top->data;
    }
};