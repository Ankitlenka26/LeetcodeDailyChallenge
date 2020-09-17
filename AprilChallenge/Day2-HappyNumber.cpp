/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
#include<iostream>
#include<unordered_map>
using namespace std ; 
class Solution {
public:
    /*
    In this solution if we look closely there is only 2 ways in which 
    1. if the number can eventually come to 1 (return True)
    2. if the number cannot come down to 1 it will form an endless loop(we need to find a way to end that loop , maps can be helpful in this case). (return false)
    */
    int sumOfSquares(int n){
        int ans =0 ;
        while(n!=0){
            int temp = n%10 ; 
            ans += temp*temp; 
            n = n/10; 
        }
        
        return ans ;
    }
    bool helper(int n , unordered_map<int,bool>& m){
        if(n==1){
            return true; 
        }
        
        if(m.find(n)!=m.end()){
            return false;
        }else{
            m[n] = true;     // to store the element for future references (Kind of like Visited Array)
        }
        
        return helper(sumOfSquares(n) , m);
    }
    bool isHappy(int n){
        if(n==0){
            return false;
        }
        unordered_map<int,bool> m ;
        return helper(n,m); 
    }
};