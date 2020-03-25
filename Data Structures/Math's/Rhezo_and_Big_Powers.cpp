/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/rhezo-and-big-powers-1/
see comments for understand logic
*/
#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
int main(){
	long int a;
	string s;
	cin>>a>>s;
	long int b;
	for(long int i=0;i<s.size();i++){
		b=((b*10)+(s[i]-'0'))%(Mod-1);   <----------//here is main thing
	}
	long int res=1;
	long int M=1000000007;
	while(b){
		if(b&1)
		res=(res*a)%M;
		a=(a*a)%M;
		b=b>>1;
	}
	cout<<res<<endl;
	return 0;
}
