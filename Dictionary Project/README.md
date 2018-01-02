# Here are the instructions given to the class for the Dictionary Project:

You should submit me Dictionary.h and Dictionary.cpp files. There should be declaration and implementation of Dictionary class template in these files. Dictionary class emulates the already existing C++ map container. Name “Dictionary” is actually taken from Python analog of C++ map. You are NOT allowed to use any implemented C++ containers.



The assignment should be submitted ONLY through the Blackboard. No late submissions! Your program should compile and run on our Linux Lab computers. The assignment should be completed individually. You are responsible for every statement in your project (check our syllabus for more details).

Grading:

Program that doesn’t compile or doesn’t do what it needs to do is always 0 points. If your program works then:
Program working correctly: 80%
Program using a safe programming style: 15%
Readability: 5%


I advise you to not wait until the very last moment. You are welcome to ask questions during and after the class. Feel free to show me your programs after the class for a quick initial check.







## ASSIGMNENT



Container Dictionary works like this:



All items have keys. Keys act like tags to identify items. Every item in Dictionary has its own unique key. Keys can be integers, string or more complex objects. Keys must be comparable (operations ==, !=, >, <, >=, <= should be defined for keys).
When Dictionary is instantiated, it takes two data types – KeyType and ItemType . First data type is the type of the keys. Second data type is the type of the stored items.
Items are stored in form of a binary search tree.


### The following methods and operators should be implemented:



Constructor that sets up an empty container.
Destructor.
bool IsEmpty() – returns true if the container is empty.
void Clear() – empties the container (removes all items and leaves the container empty).
int Size() – returns the number of items stored in the container.
int Height() – returns the height of the binary search tree.
int Count(KeyType key) – returns 1 if an item with a given key exists in the container and 0 otherwise. Slightly weird name is taken from map container in C++.
operator[] – returns the reference to the item with the given key. Again, we are not referencing items by their position in the container, but by the key. Such referencing is called associative.
If the container does not have the item with a given key, it creates a new item and assigns it the given key. Here is the example



Dictionary<std::string, int> container; // creates new empty container that

// stores integers with the string keys.



container [“Crazy”] =1;                      // the container is empty so a new entry with a key “Crazy” and a value 1 is created.



container [“Crazy”] += 1;                   // the existing value with the key “Crazy” was accessed and increased by 1.



std::cout<<container["Crazy"];          // the value 2 appears on the screen



void Remove(KeyType key) – function that removes the item with the specified key from the container.
void Balance() – function that rearranges the tree to make it balanced.


Hints:

In case you need some additional information you can check standard C++ container map.
In function Balance() you will need a temporary storage. Since you are not allowed to use C++ containers you will have to use dynamically allocated array. Make sure to avoid memory leak!


Good luck!
