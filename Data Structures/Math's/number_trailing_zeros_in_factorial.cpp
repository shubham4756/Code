/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/zrzr/
Learning:https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	long int t;
	cin>>t;
	while(t--){
		long int n;
		cin>>n;
		long int ans=0;
		for(long int i=5;n/i>0;i*=5){
          ans+=n/i;
		}

		cout<<ans<<endl;
	}
	return 0;
}
