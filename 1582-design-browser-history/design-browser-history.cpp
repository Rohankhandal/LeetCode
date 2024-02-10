class Node{
    public:
    string data;
    Node *next;
    Node *prev;
    Node():data(0),next(nullptr),prev(nullptr){};
     Node(string x):data(x),next(nullptr),prev(nullptr){};
      Node(string x, Node *next,Node *random):data(x),next(next),prev(random){};
};
class BrowserHistory {
    Node *currentPage;
public:

    BrowserHistory(string homepage) {
        currentPage=new Node(homepage);
    }
    
    void visit(string url) {
        Node *newNode=new Node(url);
        currentPage->next=newNode;
        newNode->prev=currentPage;
        currentPage=newNode;
    }
    
    string back(int steps) {
        while(steps)
        {
            if(currentPage->prev) //check wheather previous node is present or not
            {
                currentPage=currentPage->prev;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        while(steps)
        {
            if(currentPage->next)  //check wheather next node is present or not
            {
                currentPage=currentPage->next;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHist ory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */