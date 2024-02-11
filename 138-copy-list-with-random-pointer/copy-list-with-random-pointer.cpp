/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
     Node* temp=head;
     while(temp!=NULL)
     {
         Node* newNode=new Node(temp->val);
         newNode->next=temp->next;
         temp->next=newNode;
        
        //go to next node in original LL
         temp=temp->next->next;
     }

     temp=head;
     while(temp!=NULL)
     {
         if(temp->random)
          temp->next->random= temp->random->next;
         else{
             temp->next->random=NULL;
         }

        temp=temp->next->next;
     }


     //now split original and copied LL
     temp=head;
     Node* dummyNode=new Node(-1);
     Node *itr=dummyNode;
     Node *fast;
     while(temp!=NULL)
     {
         fast=temp->next->next;
         itr->next=temp->next;
         temp->next=fast;

         temp=temp->next;
         itr=itr->next;
     }

     return dummyNode->next;
    }
};



// Time Complexity: O(N)+O(N)
// Space Complexity: O(N)

// Reason: Use of hashmap for storing entire data.
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*,Node*> hashMap;
//     Node* temp = head;
// //first iteration for inserting deep nodes of every node in the hashmap.
//     while(temp != NULL) {
//         Node* newNode = new Node(temp->val);
//         hashMap[temp] = newNode;
//         temp = temp->next;
//     }
//     Node* t = head;
// //second iteration for linking next and random pointer as given question.
//     while(t != NULL) {
//         Node* node = hashMap[t];
//         node->next = (t->next != NULL) ? hashMap[t->next]:NULL;
//         node->random = (t->random != NULL) ? hashMap[t->random]:NULL;
//         t = t->next;
//     }
//     return hashMap[head];
//     }
// };