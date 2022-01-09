class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b)
        {
            carry =(uint32_t) (a&b) << 1;//casting carry into an unsigned integer
            a = a^b;//diff
            b = carry;
        }
        return a;
    }
};