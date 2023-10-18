#include <iostream>

using namespace std;


//Problem 1

//Part 1


  void PrintLots( List L, List P )
  {
      Position Lposition, Pposition;

      int Counter = 1;

      Lposition = L->Next;     //Both point to first position of list
      Pposition = P->Next;   


      while ( Lposition != NULL && Pposition != NULL )
      {

           if ( Pposition->Element == Counter)
           {
                cout <<  Lposition->Element ;
                Pposition = Pposition->Next;
           }
           Lposition = Lposition->Next;
           Counter++; 
        }

}

/*

Part 2

The running time (assuming length of list L is l and list P is p) of this algorithim would be O(l+P)

*/






//Question 2


void printLinkedListInReverse(Node* head) {

    // Reverse the links between the nodes
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Set the tail of the original linked list as the new head of the reversed linked list
    Node* reversedHead = prev;

    // Traverse the reversed linked list from the head to the tail, and print the value of each node
    Node* p = reversedHead;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }

    // Reverse the links between the nodes again to restore the original linked list
    curr = reversedHead;
    prev = nullptr;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

}





//Question 3

//Part 1

Node* intersection(Node* L1, Node* L2) {
    unordered_set<int> set;

    // Traverse L1 and add its elements to the set
    Node* p = L1;
    while (p != nullptr) {
        set.insert(p->data);
        p = p->next;
    }

    // Traverse L2 and check if each of its elements is in the set
    Node* result = nullptr;
    Node* tail = nullptr;
    p = L2;

    while (p != nullptr) {
        if (set.count(p->data) > 0) {
            insertNode(result, p->data);
            if (tail == nullptr) {
                tail = result;
            } else {
                tail = tail->next;
            }
        }
        p = p->next;
    }

    return result;
}


/*
Part 2

This algorithim O(L1 + L2) as the first while loop maximum iterations is L1 and the second one is L2 as the variable p is changed
before the second loop to L2. 

*/







//Question 4

//Part 1

void Remove (Node *node) {

     Node *tmp = node-> next;
     node-> data =tmp -> data;
     node -> next = tmp -> next;
     delete tmp;
}

/*
Part 2

This algorithim O(1) running time as all it does is copy the data and update the pointers regardless of list size. 

*/




