/*
link: https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/scientists-calender/
Scientist calender on hackerearth..............
*/



#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
if(n%4==0&&n%100!=0)
cout<<n+40;
else
{ if(n%4==3||n%4==2)
cout<<n+11;
else
cout<<n+6;
}
}
