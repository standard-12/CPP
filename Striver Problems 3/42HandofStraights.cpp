#include<bits/stdc++.h>
using namespace std;

// This was my solution and it has Time Complexity O(n+nlogn+n+n) where m is groupsize
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        int i=0;
        while(i<n){
            int k=groupSize;
            int first=hand[i];
            if(freq.count(first)){
                while(k>0){
                    if(!freq.count(first)) return false;
                    freq[first]--;
                    if(freq[first]==0) freq.erase(first);
                    first++;
                    k--;
                }
            }
            i++;
        }
        return true;

    }
};

// Nearly same time complexity solution using map

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handSize = hand.size();

        if (handSize % groupSize != 0) {
            return false;
        }

        // Map to store the count of each card value
        map<int, int> cardCount;
        for (int i = 0; i < handSize; i++) {
            cardCount[hand[i]]++;
        }

        // Process the cards until the map is empty
        while (!cardCount.empty()) {
            // Get the smallest card value
            int currentCard = cardCount.begin()->first;
            // Check each consecutive sequence of groupSize cards
            for (int i = 0; i < groupSize; i++) {
                // If a card is missing or has exhausted its occurrences
                if (cardCount[currentCard + i] == 0) {
                    return false;
                }
                cardCount[currentCard + i]--;
                if (cardCount[currentCard + i] < 1) {
                    // Remove the card value if its occurrences are exhausted
                    cardCount.erase(currentCard + i);
                }
            }
        }

        return true;
    }
};

// O(n) solution using reverse counting Time Complexity (O(2n)) Space Complexity O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Map to store the count of each card value
        unordered_map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (int card : hand) {
            int startCard = card;
            // Find the start of the potential straight sequence
            while (cardCount[startCard - 1]) {
                startCard--;
            }

            // Process the sequence starting from startCard
            while (startCard <= card) {
                while (cardCount[startCard]) {
                    // Check if we can form a consecutive sequence of
                    // groupSize cards
                    for (int nextCard = startCard;
                         nextCard < startCard + groupSize; nextCard++) {
                        if (!cardCount[nextCard]) {
                            return false;
                        }
                        cardCount[nextCard]--;
                    }
                }
                startCard++;
            }
        }

        return true;
    }
};