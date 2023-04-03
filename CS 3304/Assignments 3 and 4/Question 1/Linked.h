#include<iostream>
#include<fstream>
using namespace std;


template <typename StackElement>
class Stack
{
public:
/***** Function Members *****/
// Prototypes same as in preceding section

  //--- Definition of Stack constructor
  Stack() {
    myTop = NULL;
  }


//--- Definition of empty()
  bool empty() const
  {
    return (myTop == NULL);
  }

//--- Definition of push()
  void push(StackElement value)
  {
    myTop = new Node(value, myTop);
  }



//--- Definition of top()
  StackElement top()
  {
    if (!empty())
      return (myTop->data);
    else
    {
      cerr << "*** Stack is empty "
           " -- returning garbage ***\n";
      return *(new StackElement);   // "Garbage" value
    }
  }

//--- Definition of pop()
  void pop()
  {
    if (!empty())
    {
      Node *ptr = myTop;
      myTop = myTop->next;
      delete ptr;
    }
    else
      cout << "*** Stack is empty -- can't remove a value ***\n";
  }

  void display()
  {
    Stack::Node* ptr;
    for (ptr = myTop; ptr != NULL; ptr = ptr->next)
      cout << ptr->data << endl;
  }

private:
  /*** Node class ***/
  class Node
  {
  public:
    StackElement data;
    Node * next;
    //--- Node constructor
    Node(StackElement value, Node * link = NULL)
    /*------------------------------------------------------
      Precondition:  value is received
      Postcondition: A Node has been constructed with value
          in its data part and itb next part set to link
          (default 0).
     ------------------------------------------------------*/
    { data = value; next = link; }

  };



  /***** Data Members *****/
  Node* myTop;      // pointer to top of stack

}; // end of class declaration