class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    Node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {

        // Invalid index
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    void addAtTail(int val) {

        Node* newNode = new Node(val);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;

        size++;
    }

    void addAtIndex(int index, int val) {

        // If index > size, do nothing
        if (index > size) {
            return;
        }

        // Insert at beginning
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;

        // Reach node before insertion position
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);

        newNode->next = curr->next;
        curr->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {

        // Invalid index
        if (index < 0 || index >= size) {
            return;
        }

        // Delete head
        if (index == 0) {

            Node* temp = head;

            head = head->next;

            delete temp;

            size--;

            return;
        }

        Node* curr = head;

        // Reach node before the node to delete
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* temp = curr->next;

        curr->next = temp->next;

        delete temp;

        size--;
    }
};