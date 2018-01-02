# Here are the instructions given to the class for the Tractor Project:

This assignment models the techniques used for the length-based attack. The length-based attack is one way to test the reliability of encryption algorithms. Later such algorithms are used for online shopping, banking, logging in, protecting files and emails. Also, very similar problems can be found in text analysis and genetics.



The assignment should be submitted ONLY through the Blackboard. No late submissions! Your program should compile and run on our Linux Lab computers. The assignment should be completed individually. You are responsible for every statement in your project (check our syllabus for more details).

When grading, I will first check if the classes work as specified. Then I will evaluate your programming style. Think about the following breakdown:

Program that doesn’t compile or doesn’t do what it needs to do is always 0 points. If your program works then:
Program working correctly: 80%
Program using a safe programming style: 15%
Readability: 5%


I advise you to not wait until the very last moment. You are welcome to ask questions during and after the class. Feel free to show me your programs after the class for a quick initial check.


## ASSIGNMENT
Your program should ask for a string of symbols which we refer as “target string”.

Your program should ask for the size of “elements” set. “elements” is the set of strings. After receiving the set size, the program asks for each string of the set.

Then the program outputs the sequence of “elements” that make up target string when concatenated. The sequence of elements should be outputted in the form of indexes from the elements set.



The implementation must be recursive and use backtracking.



Example : Target string is “abbccca”. Elements set has 3 strings in it: “a”, “bb” and “ccc” (in this order). So the output shows 0 1 2 0 because “abbccca” is “a”+”bb”+”ccc”+”a”.
