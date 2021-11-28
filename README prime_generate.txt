La funcion generate_prime_candidate recibe el parametro de cantidad de bits
que tendra el numero

si el numero de bits es 0, retornamos un mensaje de error y 0;

se crean los limites 0-1 para la creacion de un numero aleatorio de n bits
tomando en cuenta que al ingresar n el limite debe estar entre:

	n:	 limite inferior     limite superior
      1 bit		1		     9
      2 bits		10		     99
      3 bits		100		     999
      4bits		1000                 9999

donde se puede expresar como:

limite inferior               limite superior
      1*10^0			9*11^0
      1*10^1			9*11^1
      1*10^2			9*11^2
      1*10^3			9*11^3

creamos un numero aleatorio n, en el rango de los limites superior-inferior
el cual resultara ser un numero de b bits


La funcion generate_prime recibe la cantida de bits b
	genera el numero de pruebas s
	crea a "n = generate_prime_candidate(b)"

	luego haciendo uso de un while, ejecutamos mille_rabin con los parametros 
	"n" y "s", mientras nos retorne 1, n=n+2;

	finalmente retornamos n
