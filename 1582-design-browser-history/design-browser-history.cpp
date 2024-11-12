class BrowserHistory {
public:
    class Node {
    public:
        string str;
        Node* prev;
        Node* next;

        Node(string s) : str(s), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* curr;

    BrowserHistory(string homepage) {
        Node* temp = new Node(homepage);
        head = temp;
        curr = temp;
    }
    
    void visit(string url) {
         Node* forwardNode = curr->next;

        Node* temp = new Node(url);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;

        // Clear forward history by deleting nodes after `curr`
       
        while (forwardNode != nullptr) {
            Node* nextNode = forwardNode->next;
            delete forwardNode;
            forwardNode = nextNode;
        }
        curr->next = nullptr; // Ensure the current node is now the end
    }
    
    string back(int steps) {
        while (steps > 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }
        return curr->str;
    }
    
    string forward(int steps) {
        while (steps > 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }
        return curr->str;
    }
};
