//
//  Dictionary.h
//  
//
//  Created by Zach Yuzon on 11/25/17.
//
//

#ifndef Dictionary_h
#define Dictionary_h
#include <iostream>
using namespace std;
//Node Class
template<class KeyType, class ItemType>
class Node{
private:
    KeyType key;
    ItemType item;
    Node<KeyType,ItemType> *left;
    Node<KeyType,ItemType> *right;
    
public:
    //Constructors
    Node<KeyType,ItemType>();
    Node<KeyType,ItemType>(const KeyType &newKey, const ItemType &newItem);
    Node<KeyType,ItemType>(const KeyType &newKey);
    Node<KeyType,ItemType>(const ItemType &newItem);
    
    //Accessor Methods
    ItemType& getItem();
    KeyType& getKey();
    Node<KeyType,ItemType>* getRight() const;
    Node<KeyType,ItemType>* getLeft() const;
    
    //Mutator Methods
    void setItem(const ItemType &newItem);
    void setKey(const KeyType &newKey);
    void setRight(Node<KeyType,ItemType> *newRight);
    void setLeft(Node<KeyType,ItemType> *newLeft);
};

//Dictionary Class
template<class KeyType,class ItemType>
class Dictionary{
    
private:
    Node<KeyType,ItemType> *root;
    
    //Methods
    void ClearPrivate(Node<KeyType,ItemType> *ptr);
    int SizePrivate(Node<KeyType,ItemType> *ptr) const;
    int HeightPrivate(Node<KeyType,ItemType> *ptr) const;
    void RemovePrivate(const KeyType &key,Node<KeyType,ItemType>* parent);
    void RemoveRoot();
    Node<KeyType,ItemType>* FindSmallestInRightSubtree(Node<KeyType,ItemType> *parent) const;
    void RemoveNode(Node<KeyType,ItemType> *parent,Node<KeyType,ItemType> *keyBeingDeleted,bool left);
    void Trav_InOrder(Node <KeyType, ItemType> **nodes, Node <KeyType, ItemType> *cur, int &index);
    Node<KeyType, ItemType>* BalancePrivate(Node <KeyType, ItemType> **nodes, int small, int large);
    Node<KeyType,ItemType>* AddNodePrivate(Node<KeyType,ItemType> *nNode,Node<KeyType,ItemType> *ptr);
public:
    Dictionary<KeyType,ItemType>();
    ~Dictionary<KeyType,ItemType>();
    void Clear();
    bool IsEmpty() const;
    int Size() const;
    int Height() const;
    int Count(const KeyType &key) const;
    ItemType& operator[](const KeyType &newKey);
    void Balance();
    void Remove(const KeyType &key);
};
#include "Dictionary.cpp"
#endif /* Dictionary_h */












