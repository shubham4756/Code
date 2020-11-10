/*
Link: https://leetcode.com/problems/nth-digit/
*/

class Solution {
public:
    int findNthDigit(int n) {
        long base=9,digit=1;
        while(n-base*digit>0) {
            n-=base*digit;
            base*=10;
            digit++;
        }
        long index=n%digit;
        if(index==0)
            index=digit;
        long num=1;
        for(long i=1;i<digit;i++)
            num*=10;
        num += (index==digit) ? n/digit-1 : n/digit;
        for(long i=index; i<digit ; i++) 
            num/=10;
        return (int)num%10;
    }
};
