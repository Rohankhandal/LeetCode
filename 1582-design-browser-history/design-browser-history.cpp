class BrowserHistory {
public:
    class Node{
        public :
        string str;
        Node*prev;
        Node*next;

        
        Node()
        {
            str="";prev=nullptr,next=nullptr;
        }
        Node(string s)
        {
            str=s;prev=nullptr,next=nullptr;
        }
    };

    Node *head=NULL;
    Node *tail=NULL;
    Node *curr=NULL;


    
    BrowserHistory(string homepage) {
        Node *temp=new Node(homepage);
        head=temp;
        tail=temp;
        curr=temp;
    }
    
    void visit(string url) {
        Node*temp=new Node(url);
        curr->next=temp;
        temp->prev=curr;
        curr=temp;
    }
    
    string back(int steps) {
        while(steps>0 && curr->prev!=NULL)
        {
            curr=curr->prev;
            steps--;
        }
        return curr->str;
    }
    
    string forward(int steps) {
        while(steps>0 && curr->next!=NULL)
        {
            curr=curr->next;
            steps--;
        }
        return curr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */