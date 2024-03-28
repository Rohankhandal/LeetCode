class Node{
    public:
    string  str;
    Node *prev;
    Node*next;
    
    Node(string s)
    {
        str=s;
        prev=NULL;
        next=NULL;
    }
};
class BrowserHistory {
public:
    Node *head=NULL;
    Node *ptr=NULL;
    BrowserHistory(string homepage) {
        Node*temp=new Node(homepage);
        head=temp;
        ptr=head;
    }
    
    void visit(string url) {
        Node *temp=new Node(url);
        ptr->next=temp;
        temp->prev=ptr;
        //update the location
        ptr=temp;
    }
    
    string back(int steps) {
        int count=0;
        while(ptr->prev!=NULL)
        {
            ptr=ptr->prev;
            count++;
            if(count==steps)
            {
                break;
            }
        }
        return ptr->str;
    }
    
    string forward(int steps) {
        int count=0;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            count++;
            if(count==steps) break;
        }
        return ptr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */