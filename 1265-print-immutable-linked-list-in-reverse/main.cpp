#include<stack>
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */
 class ImmutableListNode {
    public:
    void printValue(); // print the value of the node.
    ImmutableListNode* getNext(); // return the next node.
 };

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(!head)
            return
        std::stack<ImmutableListNode*> st;

        ImmutableListNode* curr = head;
        while(curr){
            st.push(curr);



            curr = curr->getNext();
        }
        
        ImmutableListNode* temp;
        while(!st.empty()){
            temp = st.top();
            temp->printValue();
            st.pop();
        }
        
        
    }
};