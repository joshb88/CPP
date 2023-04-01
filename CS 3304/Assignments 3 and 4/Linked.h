class Stack
{
 public:
 /***** Function Members *****/
 // Prototypes same as in preceding section

 private:
    /*** Node class ***/
   class Node
   {
    public:
      typedef int StackElement;
      StackElement data;
      Node * next;
      //--- Node constructor
      Node(StackElement value, Node * link = 0)
      /*------------------------------------------------------
        Precondition:  value is received
        Postcondition: A Node has been constructed with value
            in its data part and itb next part set to link
            (default 0).
       ------------------------------------------------------*/
      { data = value; next = link; }

  };

  typedef Node * NodePointer;

  /***** Data Members *****/
  NodePointer myTop;      // pointer to top of stack

}; // end of class declaration 