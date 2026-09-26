class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
class MyCircularDeque {
public:
    int curr ,cap;
    Node* front=nullptr , * rear=nullptr;
    MyCircularDeque(int k) {
        this->cap = k;
        this->curr = 0;
    }
    
    bool insertFront(int value) {
        if(curr==cap)return false;
        Node * temp = new Node(value);
        if(curr == 0){
            front = temp;
            rear = temp;
        }
        else{
            front->prev = temp;
            temp->next = front;
            front = temp;
        }
        curr++;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(curr==cap)return false;
        Node * temp = new Node(value);
        if(curr == 0){
            front = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        curr++;
        return true;
    }
    
    bool deleteFront() {
        if(curr == 0)return 0;
        front = front->next;
        curr--;
        return true;
    }
    
    bool deleteLast() {
        if(curr == 0)return 0;
        rear = rear->prev;
        curr--;
        return true;
    }
    
    int getFront() {
        if(curr==0)return -1;
        return front->data;
    }
    
    int getRear() {
        if(curr==0)return -1;
        return rear->data;
    }
    
    bool isEmpty() {
        return curr==0;
    }
    
    bool isFull() {
        return curr==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */