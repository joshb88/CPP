#ifndef MYLIST
#define MYLIST
#include <iostream>

//MyCon class
template<class T>
class MyList
{
private:
    T *my_array;
    int my_size;
    int my_capacity;
public:
    MyList(int capacity);
    int getSize() const;
    int getCapacity() const;
    void add(T element);
    T getMin();
    T removeMin();
    void display();
    T at(int index);
    int lastIndexOf(T element);
    bool search(T element);
    void clear();
};

template<class T>MyList<T>::MyList(int capacity)
{
    if (capacity < 0) 
    { 
        my_capacity = 5;
    }

    else
    {
        my_capacity = capacity;
    }
    my_array = new T[my_capacity]{0};
    my_size = 0;
}

template<class T> int MyList<T>::getSize() const
{ 
    return my_size;
}

template<class T> int MyList<T>::getCapacity() const
{
     return my_capacity;
}

template<class T>void MyList<T>::add(T element)
{
    if (my_size == my_capacity)
    {
        my_capacity = my_capacity * 2;
        T *temp = new T[my_capacity]{0};
        for (int i = 0; i < my_size; i++)
        {
            temp[i] = my_array[i];
        }
        delete[] my_array;
        my_array = temp;
    }
   if (element > my_array[0])
        {
            my_array[my_size] = element;
            my_size++;
        }
    if (element < my_array[0])
    {
        T placeholder;
        placeholder = my_array[0];
        my_array[0] = element;
        my_size++;
        my_array[my_size-1] = placeholder;
        
    }
}

template<class T> T MyList<T>::getMin()
{
    try
    {
        if (my_size == 0) 
            throw("");
        else
        {
            return my_array[0];
        }
    }
    catch(...)
    {
        std::cout << "Error: No values in the list. Returning -1." << std::endl;
        return -1;
    } 
}

template<class T> T MyList<T>::removeMin()
{
    T current_min = my_array[0];
    T new_min = my_array[1];
    int new_min_index;

    for (int i = 1; i < my_size; i++)
    {
        if (new_min >= my_array[i])
        {
            new_min = my_array[i];
            new_min_index = i;
        }
    }
    my_array[0] = new_min;
    for (int i = new_min_index; i < my_size; i++)
    {
        my_array[i] = my_array[i + 1];
    }
    my_size--;
    return current_min;
}


template<class T> void MyList<T>::display()
{
    std::cout << "[";
    for(int i=0; i < my_size; i++)
    {
        std::cout << my_array[i];
        if (i != my_size-1) {std::cout << ", "; }
    }
    std::cout << "]" << std::endl;
}

template<class T> T MyList<T>::at(int index)
{
    try
    {
        if (index > my_size)
            throw("");
        else
        {
            return my_array[index];
        }
    }
    catch(...)
    {
        std::cout << "Error: Specified index does not exist in the list. Returning -1." << std::endl;
        return -1;
    }
    
}

template<class T> int MyList<T>::lastIndexOf(T element)
{
    for (int i = 0; i < my_size; i++)
    {
        
    }
}

#endif // MYLIST