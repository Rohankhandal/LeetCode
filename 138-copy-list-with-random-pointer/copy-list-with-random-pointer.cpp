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
     Node* temp = head;
	//step 1  Create deep nodes of all nodes. Instead of storing these nodes in a 
    // hashmap, we will point it to the next of the original nodes.
    while(temp != NULL) {
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
	//step 2Take a pointer, say itr, point it to the head of the list. This will 
    // help us to point random pointers as per the original list. This can be 
    // achieved by itr->next->random = itr->random->next

    Node* itr = head;
    while(itr != NULL) {
        if(itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
	//step 3  Use three pointers. One dummy node whose next node points to the 
    // first deep node. itr pointer at the head of the original list and fast 
    // which is two steps ahead of the itr. This will be used to separate the 
    // original linked list with the deep nodes list.
    Node* dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node* fast;
    while(itr != NULL) {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;
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