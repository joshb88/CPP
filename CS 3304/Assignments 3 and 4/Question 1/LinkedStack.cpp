#include <iostream>
#include <fstream>
#include <string>
#include "Linked.h"

using namespace std;

template <class StackElement>
class Stack
{
public:
    Stack();                    // constructor
    Stack(const Stack<StackElement> & original); // copy constructor
    ~Stack();                   // destructor
    Stack<StackElement> & operator=(const Stack<StackElement> & rightHandSide); // assignment operator
    bool empty() const;         // Returns true if the stack is empty, otherwise returns false.
    void push(const StackElement & value); // Adds value to the top of the stack.
    void pop();                 // Removes the top value from the stack.
    StackElement top() const;   // Returns a copy of the top value on the stack.

private:
    /*** Node class ***/
    class Node
    {
    public:
        StackElement data;
        Node * next;
        //--- Node constructor
        Node(StackElement value, Node * link = 0)
            /*------------------------------------------------------
            Precondition:  value is received
            Postcondition: A Node has been constructed with value
            in its data part and its next part set to link (default 0).
            --------------------------------------------------------*/
        {
            data = value; next = link;
        }
    };

    typedef Node * NodePointer;

    /*** Data Members ***/
    NodePointer myTop;      // pointer to top of stack
};

template <class StackElement>
Stack<StackElement>::Stack()
{
    myTop = 0;
}

template <class StackElement>
Stack<StackElement>::Stack(const Stack<StackElement> & original)
{
    myTop = 0;
    if (!original.empty())
    {
        // Copy first node
        myTop = new Node(original.top());

        // Set pointers to run through the stack's linked lists
        NodePointer lastPtr = myTop,
            origPtr = original.myTop->next;

        while (origPtr != 0)
        {
            lastPtr->next = new Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}








//--- LStack.cpp -------------------------------------------------
bool evenOrOdd(string expr)
{
  Stack<char> s;
  char x;

  // Traversing the Expression
  for (int i = 0; i < expr.length(); i++)
  {
    if (expr[i] % 2 == 0)   // even
    {
        if (expr[i] == s.top())
        {
            s.pop();
            continue
        }
        else
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

    }

    // IF current current character is not opening
    // bracket, then it must be closing. So stack
    // cannot be empty at this point.
    if (s.empty())
      return false;

    switch (expr[i]) {
    case ')':

      // Store the top element in a
      x = s.top();
      s.pop();
      if (x == '{' || x == '[')
        return false;
      break;

    case '}':

      // Store the top element in b
      x = s.top();
      s.pop();
      if (x == '(' || x == '[')
        return false;
      break;

    case ']':

      // Store the top element in c
      x = s.top();
      s.pop();
      if (x == '(' || x == '{')
        return false;
      break;
    }
  }

  // Check Empty Stack
  return (s.empty());
}