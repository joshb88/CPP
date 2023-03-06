#include <iostream> 
#include "MyList.h" 
using namespace std; 
 
int main() 
{ 
    MyList<int> a(3); 
    MyList<double> b(-10); 
    cout << "Size of a: " << a.getSize() << endl; 
    cout << "Capacity of a: " << a.getCapacity() << endl; 
    cout << "Size of b: " << b.getSize() << endl; 
    cout << "Capacity of b: " << b.getCapacity() << endl; 
    a.add(9); a.display(); 
    a.add(2); a.display(); 
    a.add(4); a.display(); 
    a.add(3); a.display(); 
    a.add(5); a.display(); 
    a.add(1); a.display(); 
    a.add(4); a.display(); 
    cout << "a.getMin(): " << a.getMin() << endl; 
    // Instructions are showing the specified index - 1, but alas.
    cout << "a.at(3): " << a.at(3) << endl;                 
    // Also, in the instructions it says it takes no parameters and doesn't 
    cout << "a.removeMin(): " << a.removeMin() << endl; 
    a.display(); 
    a.removeMin(); a.display();
     for (int i = 1; i <= 5; i++) { 
      cout << i << ": " << a.lastIndexOf(i) << endl; 
     }
     a.clear(); 
     a.display(); 
     cout << "Size of a: " << a.getSize() << endl; 
     cout << "Capacity of a: " << a.getCapacity() << endl; 
} 