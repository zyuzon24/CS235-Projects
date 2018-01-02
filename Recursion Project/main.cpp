//
//  Recursion.cpp
//
//
//  Zach Yuzon
//
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


// this method checks if the string being checked matches with the "key" string starting at a given position
 
bool check(const string &check, const int pos, const string &key){
    
    if(key.substr(pos, check.size()) == check){
        return true;
    }
    
    return false;
}

// parameters are the result string, starting position of the section of the key being checked,
// the target string aka the key, the vector of strings which contains the elements
// and the stack which stores the int positions of the correct elements backwards
 
bool solve(string res, int pos, const string &key, const vector<string> &elements, stack<int> &stk){
    
    if (res == key){
        return true;
    }
    
    for(int i = 0; i < elements.size(); i++){
        
        if(check(elements[i], pos, key)){
            
            
            if(solve(res + elements[i], pos + elements[i].size(), key, elements, stk)){
                
                stk.push(i);
                
                return true;
            }
            
            
        }
    }
    
    return false;
    
}

void printAnswer(stack<int> &stk){
    cout << "The solution is: ";
    while(stk.size() != 0){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void runProgram(){
    //Get Target String from the user
    string targetString;
    cout << "Please enter the Target String: " << endl;
    cin >> targetString;
    
    //Get the size of the elements set from the user
    int numOfElements;
    cout << "Please enter the SIZE of the \"elements\" set: " << endl;
    cin >> numOfElements;
    
    //Get each string of the set and put it inside the vecctor.
    vector<string> allElem (numOfElements);
    int i;
    string element;
    for(i = 0; i < numOfElements; i++){
        cout << "Please enter a string for the element set: " << endl;
        cin >> element;
        allElem[i] = element;
    }
    
    stack<int> answer;
    
    solve("", 0, targetString, allElem, answer);
    printAnswer(answer);
    
}
 */

void PrintArray(int *arr){
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

int main(){
    runProgram();
    return 0;
}
