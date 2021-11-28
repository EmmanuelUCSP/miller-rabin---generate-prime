#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>

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

int witness(type a,type n)
{
	type i; type t; type u; type x; type y;

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

int miller_rabin(type n, int s)
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

int generate_prime_candidate(int b)
{
	if(!b) {cout<<"el numero 0 no es valido :( "<<endl; return 0;}
	b=b-1;
	int limite_0 = 1*(pow(10,b));  //generalisacion de 1-10-100-1000....etc
	int limite_1 = 9*(pow(11,b));  //generalisacion de 9-99-999-9999....etc

	int n = rand() % (limite_1-limite_0) + limite_0;  //genera numero aleatorio entre numeros de b bits

	return n;
}

int generate_prime(int b)
{
	int s = 228;
	int n= generate_prime_candidate(b);

	while(miller_rabin(n,s))	n=n+2;
	return n;
}





int main()
{
    //cout<<miller_rabin(41,2);
	int n, t;
	while(t<100){
		n=generate_prime(5);
		cout<<n<<endl;
		t++;
	}


    return 0;
}