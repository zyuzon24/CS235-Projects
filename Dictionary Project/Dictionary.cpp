//
//  Dictionary.cpp
//
//
//  Created by Zach Yuzon on 11/25/17.
//
//
#ifndef Dictionary_cpp
#define Dictionary_cpp

#include "Dictionary.h"
#include <iostream>
using namespace std;

//////////////////////////////////
//          NODE CLASS          //
//////////////////////////////////

//////////////////////////////////
//           Constructors       //
//////////////////////////////////

template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(){
    left = nullptr;
    right = nullptr;
}

template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(const KeyType &newKey, const ItemType &newItem){
    key = newKey;
    item = newItem;
    left = nullptr;
    right = nullptr;
}

template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(const KeyType &newKey){
    key = newKey;
    left = nullptr;
    right = nullptr;
}

template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(const ItemType &newItem){
    item = newItem;
    left = nullptr;
    right = nullptr;
}

//////////////////////////////////
//         Accessor Methods     //
//////////////////////////////////
template<class KeyType, class ItemType>
ItemType& Node<KeyType,ItemType>::getItem(){
    return item;
}

template<class KeyType, class ItemType>
KeyType& Node<KeyType,ItemType>::getKey(){
    return key;
}

template<class KeyType, class ItemType>
Node<KeyType,ItemType>* Node<KeyType,ItemType>::getRight() const{
    return right;
}

template<class KeyType, class ItemType>
Node<KeyType,ItemType>* Node<KeyType,ItemType>::getLeft() const{
    return left;
}

//////////////////////////////////
//          Mutator Methods     //
//////////////////////////////////
template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::setItem(const ItemType &newItem){
    item = newItem;
}

template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::setKey(const KeyType &newKey){
    key = newKey;
}

template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::setRight(Node<KeyType,ItemType> *newRight){
    right = newRight;
}

template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::setLeft(Node<KeyType,ItemType> *newLeft){
    left = newLeft;
}
//////////////////////////////////
//       END OF NODE CLASS      //
//////////////////////////////////



//////////////////////////////////
//       DICTIONARY CLASS       //
//////////////////////////////////

//////////////////////////////////
//       Private Methods        //
//////////////////////////////////

template<class KeyType,class ItemType>
void Dictionary<KeyType,ItemType>::ClearPrivate(Node<KeyType,ItemType> *ptr){
    if(ptr != nullptr){
        if(ptr->getLeft() != nullptr){
            ClearPrivate(ptr->getLeft());
        }
        if(ptr->getRight() != nullptr){
            ClearPrivate(ptr->getRight());
        }
        delete ptr;
    }
    return;
}

template<class KeyType,class ItemType>
int Dictionary<KeyType,ItemType>::SizePrivate(Node<KeyType,ItemType> *ptr) const{
    if(ptr == nullptr){
        return 0;
    }
    return (SizePrivate(ptr->getLeft()) + 1 + SizePrivate(ptr->getRight()));
    
}

template<class KeyType,class ItemType>
int Dictionary<KeyType,ItemType>::HeightPrivate(Node<KeyType,ItemType> *ptr) const{
    if(ptr == nullptr){
        return 0;
    }
    
    int leftHeight= HeightPrivate(ptr->getLeft());
    int rightHeight = HeightPrivate(ptr->getRight());
    
    int maxHeight;
    
    if(leftHeight >= rightHeight){
        maxHeight = leftHeight + 1;
    } else {
        maxHeight = rightHeight + 1;
    }
    
    return maxHeight;
    
}

template<class KeyType,class ItemType>
void Dictionary<KeyType,ItemType>::RemovePrivate(const KeyType &key,Node<KeyType,ItemType>* parent){
    //if list is empty, you can't remove anything
    if (root == nullptr){
        return;
    }
    
    
    if(root->getKey() == key){
        RemoveRoot();
        return;
    }
    
    if(key < parent->getKey() && parent->getLeft() != nullptr){    //checks if key is less then the parent key and that the node to the left of the parent isn't NULL
        
        if(parent->getLeft()->getKey() == key){                   //checks if the key of the Node to the left of the parent key matches the key that is trying to be deleted
            RemoveNode(parent,parent->getLeft(),true);
            return;
        }
        
        RemovePrivate(key,parent->getLeft());
        
    } else if(key > parent->getKey() && parent->getRight() != nullptr){    //checks if key is greater then the parent key and that the node to the right of the parent isn't NULL
        
        if(parent->getRight()->getKey() == key){                   //checks if the key of the Node to the right of the parent key matches the key that is trying to be deleted
            RemoveNode(parent,parent->getRight(),false);
            return;
        }
        
        RemovePrivate(key,parent->getRight());
        
    } else {                                            //key wasn't found in the tree
        
        return;
    }
    
    
    
    
    
}


template<class KeyType,class ItemType>
void Dictionary<KeyType,ItemType>::RemoveRoot(){
    
    //empty tree
    if(root == nullptr){
        return;
    }
    
    Node<KeyType,ItemType> *del = root;
    KeyType rootKey = root->getKey();
    ItemType rootItem = root->getItem();
    
    //Case 0 - 0 children
    if(root->getLeft() == nullptr && root->getRight() != nullptr){
        root = nullptr;
        delete del;
        return;
    }
    
    //Case 1 - 1 child
    if(root->getLeft() == nullptr && root->getRight() != nullptr){
        root = root->getRight();
        del->setRight(nullptr);
        delete del;
        
        return;
    }
    
    if(root->getLeft() !=nullptr && root->getRight() == nullptr){
        root = root->getLeft();
        del->setLeft(nullptr);
        delete del;
        return;
    }
    
    //Case 2  - 2 children
    Node<KeyType,ItemType> *smallestInRightSubtree = FindSmallestInRightSubtree(root->getRight());
    KeyType newKey = smallestInRightSubtree->getKey();
    root->setItem(smallestInRightSubtree->getItem());
    RemovePrivate(smallestInRightSubtree->getKey(),root);
    root->setKey(smallestInRightSubtree->getKey());
    
    
    return;
    
    
}

template<class KeyType,class ItemType>
Node<KeyType,ItemType>* Dictionary<KeyType,ItemType>::FindSmallestInRightSubtree(Node<KeyType,ItemType> *parent) const{
    
    if(root == nullptr){
        return nullptr;
    }
    
    if(parent->getLeft() != nullptr){
        return FindSmallestInRightSubtree(parent->getLeft());
    } else {
        return parent;
    }
    
}

template<class KeyType,class ItemType>
void Dictionary<KeyType,ItemType>::RemoveNode(Node<KeyType,ItemType> *parent,Node<KeyType,ItemType> *keyBeingDeleted, bool left) {   //boolean variable lets me know if the keyBeingDeleted
    if(root == nullptr){                                                                              //is the left or right child of the parent Node
        return;                                                                                                                             //if left = true, right = false
    }
    
    KeyType matchKey = keyBeingDeleted->getKey();
    
    //Case 0 - keyBeingDeleted has 0 children
    if(keyBeingDeleted->getLeft() == nullptr && keyBeingDeleted->getRight() == nullptr){
        if(left == true){
            parent->setLeft(nullptr);
        } else {
            parent->setRight(nullptr);
        }
        delete keyBeingDeleted;
        return;
    }
    
    //Case 1 - keyBeingDeleted has 1 child
    if(keyBeingDeleted->getLeft() == nullptr && keyBeingDeleted->getRight() != nullptr){
        
        if(left == true){
            parent->setLeft(keyBeingDeleted->getRight());
        } else {
            parent->setRight(keyBeingDeleted->getRight());
        }
        
        keyBeingDeleted->setRight(nullptr);
        delete keyBeingDeleted;
        return;
    }
    
    if(keyBeingDeleted->getLeft() != nullptr && keyBeingDeleted->getRight() == nullptr){
        
        if(left == true){
            parent->setLeft(keyBeingDeleted->getLeft());
        } else {
            parent->setRight(keyBeingDeleted->getLeft());
        }
        
        keyBeingDeleted->setLeft(nullptr);
        delete keyBeingDeleted;
        return;
    }
    
    //Case 2 - keyBeingDeleted has 2 children
    Node<KeyType,ItemType> *smallestInRightSubtree = FindSmallestInRightSubtree(keyBeingDeleted->getRight());  //new ptr that points to Node with smallest Key Value in right subtree
    KeyType newKey = smallestInRightSubtree->getKey();                                                          //stores the key value of the smallest key value in the right subtree
    keyBeingDeleted->setItem(smallestInRightSubtree->getItem());                            //overwrites the item of the Node being deleted to the item of the smallest key value in the right subtree
    RemovePrivate(smallestInRightSubtree->getKey(),keyBeingDeleted);                        //removes smallest key value in the right subtree
    keyBeingDeleted->setKey(newKey);                                                        //stores the key value of the smallest key value in the right subtree in the Node that was supposed to be
                                                                                            //deleted.This doesn't delete the Node that you want to delete but rather stores new information in it.
                                                                                            //did this so the BST wouldn't be changing too much.
}

template <class KeyType, class ItemType>
void Dictionary<KeyType, ItemType> :: Trav_InOrder(Node <KeyType, ItemType> **nodes, Node <KeyType, ItemType> *cur, int &index){
    if (cur == nullptr)
        return;
    Trav_InOrder(nodes, cur->getLeft(),index);
    nodes[index]=cur;
    index++;
    Trav_InOrder(nodes,cur->getRight(),index);
}

template <class KeyType, class ItemType>
Node <KeyType, ItemType> * Dictionary<KeyType, ItemType>:: BalancePrivate(Node <KeyType, ItemType> **nodes, int small, int large){
    if (small > large){
        return nullptr;
    }
    
    if (small == large){
        nodes[small] -> setRight(nullptr);
        nodes[small] -> setLeft(nullptr);
        return nodes[small];
    }
    
    int avg = (small + large)/2;
    nodes[avg]-> setLeft(BalancePrivate(nodes, small, avg - 1));
    nodes[avg]-> setRight(BalancePrivate(nodes, avg + 1, large));
    return nodes[avg];
    
}


template<class KeyType,class ItemType>
Node<KeyType,ItemType>* Dictionary<KeyType,ItemType>::AddNodePrivate(Node<KeyType,ItemType> *nNode,Node<KeyType,ItemType> *ptr){
    
    
    if(root == nullptr){
        root = nNode;
        return nNode;
    }
    while(ptr != nullptr){
        //key doesnt exist
        if(nNode->getKey() < ptr->getKey()){
            
            if(ptr->getLeft() != nullptr){
                ptr = ptr->getLeft();
            } else {
                ptr->setLeft(nNode);
                return ptr->getLeft();
            }
        }
        
        if(nNode->getKey() > ptr->getKey()){
            
            if(ptr->getRight() != nullptr){
                ptr = ptr->getRight();
            } else {
                ptr->setRight(nNode);
                return ptr->getRight();
            }
        }
        //key does exist
        if(ptr->getKey() == nNode->getKey()){
            return ptr;
        }
    }
    
    return nullptr;
    
}

//////////////////////////////////
//         Public Methods       //
//////////////////////////////////

//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////
template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::Dictionary(){
    root = nullptr;
}

template<class KeyType,class ItemType>
Dictionary<KeyType,ItemType>::~Dictionary(){
    Clear();
    root = nullptr;
}

//////////////////////////////////
//   Other Public Methods       //
//////////////////////////////////
template<class KeyType,class ItemType>
bool Dictionary<KeyType,ItemType>::IsEmpty() const{
    if(root==nullptr){
        return true;
    }
    return false;
}

template<class KeyType,class ItemType>
void Dictionary<KeyType,ItemType>::Clear(){
    ClearPrivate(root);
    root = nullptr;
}

template<class KeyType,class ItemType>
int Dictionary<KeyType,ItemType>::Size() const{
    return SizePrivate(root);
}

template<class KeyType,class ItemType>
int Dictionary<KeyType,ItemType>::Height() const{
    if(HeightPrivate(root) == 0){
        return 0;
    }
    return HeightPrivate(root)-1;
}

template<class KeyType,class ItemType>
int Dictionary<KeyType,ItemType>::Count(const KeyType &checkKey) const{
    Node<KeyType,ItemType> *cur = root;
    
    while(cur != nullptr && cur->getKey() != checkKey){
        if(checkKey > cur->getKey()){
            cur = cur->getRight();
        } else {
            cur = cur->getLeft();
        }
    }
    
    if(cur == nullptr){
        return 0;
    } else {
        return 1;
    }
}

template<class KeyType,class ItemType>
ItemType& Dictionary<KeyType,ItemType>::operator[](const KeyType &key){
    
    //If The key exists
    if(Count(key)==1){
        Node<KeyType,ItemType> *cur = root;
        while(cur->getKey() != key){
            if(key > cur->getKey()){
                cur = cur->getRight();
            } else {
                cur = cur->getLeft();
            }
        }
        return (cur->getItem());
    }
    
    //If The key doesn't exist
    Node<KeyType,ItemType> *nNode = new Node<KeyType,ItemType>(key);
    nNode = AddNodePrivate(nNode,root);
    return (nNode->getItem());
}

template <class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Balance(){
    
    Node <KeyType, ItemType>** n;
    n = new Node <KeyType, ItemType>*[Size()];
    int index=0;
    Trav_InOrder(n, root, index);
    int smallIndex= 0;
    int largeIndex= Size()-1;
    root = BalancePrivate(n, smallIndex, largeIndex);
    
    delete []n;
    for(int i = 0; i < Size(); i++){
        n[i] = nullptr;
    }
    return;
}

template<class KeyType,class ItemType>
void Dictionary<KeyType,ItemType>::Remove(const KeyType &key){
    RemovePrivate(key,root);
}






//////////////////////////////////
//    END OF DICTIONARY CLASS   //
//////////////////////////////////

#endif




