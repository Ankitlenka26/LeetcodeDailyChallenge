/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std; 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        /*
        Time complexity : O(NKlogK)
        Space Complexity : O(N)
        it is basically taking advantage of the fact that the anagrams when sorted becomes equal so that can be           used as a key  
        */
        vector<vector<string>> Anagrams;
        unordered_map<string , vector<string>> m ; 
        
        for(int i=0 ;i<strs.size(); i++){
            string curr = strs[i]; 
            int ans =0 ;
            sort(curr.begin() , curr.end());
            m[curr].push_back(strs[i]); 
        }
        
        for(auto it : m){
            Anagrams.push_back(it.second); 
        }
        
        return Anagrams;
    }
};

/*
Approach 2: Categorize by Count
Intuition

Two strings are anagrams if and only if their character counts (respective number of occurrences of each character) are the same.

Algorithm

We can transform each string \text{s}s into a character count, \text{count}count, consisting of 26 non-negative integers representing the number of \text{a}a's, \text{b}b's, \text{c}c's, etc. We use these counts as the basis for our hash map.

In Java, the hashable representation of our count will be a string delimited with '#' characters. For example, abbccc will be #1#2#3#0#0#0...#0 where there are 26 entries total. In python, the representation will be a tuple of the counts. For example, abbccc will be (1, 2, 3, 0, 0, ..., 0), where again there are 26 entries total.


class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        int[] count = new int[26];
        for (String s : strs) {
            Arrays.fill(count, 0);
            for (char c : s.toCharArray()) count[c - 'a']++;

            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                sb.append('#');
                sb.append(count[i]);
            }
            String key = sb.toString();
            if (!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}

Complexity Analysis:

Time Complexity: O(NK)O(NK), where NN is the length of strs, and KK is the maximum length of a string in strs. Counting each string is linear in the size of the string, and we count every string.

Space Complexity: O(NK)O(NK), the total information content stored in ans.
*/