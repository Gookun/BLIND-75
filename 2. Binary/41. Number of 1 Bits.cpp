//solution 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n)
        {
            res+=n%2;
            n = n>>1;
        }
        return res;
    }
};

//solution 2 But BETTER

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n)
        {
        	n = n & (n - 1);
            res++;
        }
        return res;
    }
};
//solution 3
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};