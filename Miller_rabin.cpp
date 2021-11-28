#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

#define type long long int


type mulmod( type a, type b, type mod) {
   	type x = 0;
	type y = a%mod;

	while(b > 0){
        if(b%2 == 1) x = (x+y)%mod;
       	y = (y*2)%mod;
		b /= 2;
    }
    return x%mod;
}

type mod_exp (type a, type n, type q)
{
	type var = 1;
	type mult = a;
	while ( n != 0 ) {
		if (n%2 == 1) var  = mulmod(var, mult, q);
		mult = mulmod(mult, mult, q);
		n = n>>1;
	}
	return var;
}

int power2 ( type n , type * u)
{
	type var;
	for (var = 0; n%2 == 0; (n = n>>1)&& var++);
	*u = n;
	return var;
}

int witness(int a,int n)
{
	type i, t, u, x, y;

	t = power2(n-1, &u);
	y = mod_exp(a, u, n);
	
	for (i = 0; i < t; i++) {
		x = mulmod(y,y,n) ;

		if (x == 1 && y != 1 && y != n-1)  return 1;
		y = x;
	}

	if ( y != 1 )  return 1;
	return 0;
}

int miller_rabin(int n, int s)
{
	if(n<2) return 0;
	if(n == 2) return 1;
	if(n != 2 && n%2 == 0) return 0;

	for (int j = 0; j < s; j++) 
	{
		int a = 1 + rand()%((n-1)-1) ;
		if ( witness(a, n) ) return 1;
	}
	return 0;
}


int main()
{ 
	std::list<int> numeros; int ayuda;
	for(int i=100; i<999; i++)
	{
		if(!miller_rabin(i,128)) numeros.push_back(i);
		ayuda++;
	}

	/*
	int k=0;
	for(const int& x : numeros){
		cout<<x<<" -> "; k++;
		if(k==15) {cout<<x<<endl; k=0;}
	}
	*/

    return 0;
}