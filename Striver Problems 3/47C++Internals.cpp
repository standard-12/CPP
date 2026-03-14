#include<bits/stdc++.h>
using namespace std;
// THIS IS NOT ANY QUESTION JUST RECAP OF SYNTAX DETAILS 
class Example {
    public:
        /*unordered_set needs two things to work:
                unordered_set< KeyType, HashFunction, EqualityFunction >
                                        A hash function → decides the bucket
                                        An equality function → checks if two elements in the bucket are the same object*/
        class demo {
            public:
                int a;
                int b;

                bool operator== (const demo& other){  // The Equaltity Function can be written here or sent separately while defininge unordered_set
                    return (other.a==a && other.b==b);
                }
        };

        struct demoHash{  // This is the hash Funciton which returns a size_t 
            size_t operator()(const demo& x)const noexcept{
                return (size_t(x.a)<<32 ^ size_t(x.b));
            }
        };
        void timepass(){
            unordered_set<demo,demoHash> st;  // we should alwayse send a hash Struct if we are hashing a object or if there is no built in
            // std::hash defined 
            // inside it is called as 
            // demoHash hash;
            // bucket_no = hash(x) % no_of_buckets
        }
};

class OperatorOverLoadingExample{
    public:
        struct Vec2 {
            float x, y;

            // vector addition
            Vec2 operator+(const Vec2& other) const {
                return Vec2{x + other.x, y + other.y};
            }
        };

        void temp(){
            Vec2 a{2.0f, 3.0f};
            Vec2 b{4.0f, 1.0f};

            Vec2 c = a + b;  // uses operator+

            std::cout << c.x << ", " << c.y << std::endl;  // 6, 4
        }

};