#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if( b == 0)
		return a;
	return gcd(b,a%b);
}
int x,y,GCD;
int extended_euciliden(int a, int b){
	if(b == 0){
		x = 1;
		y = 0;
		GCD = a;
		return 0;
	}
	extended_euciliden(b,a%b);
	int Cx = y;
	int Cy = x - (a/b)*y;
	x = Cx;
	y = Cy;
	return x;
}
// inverse modulo 
// (a*b)%m = 1 aana chahiye
// let 
// a*b -1 = km
// a*b - km = 1
// a*b - (-km) = 1 or a*b + (k'm) = 1
// similar to ecuilid algo
// Ax + By = gcd(a,b)
// we have to find only x 
// one condition also tha when gcd of a and m is one  then inverse exist 
int inverse_modulo(int a,int m){
	extended_euciliden(a,m);
	return (x+m)%m; // for making x positive
}
int main(){
	cout << inverse_modulo(6,7) << endl;
	cout << inverse_modulo(18,7) << endl;

}
