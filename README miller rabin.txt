Primero tenemos las funciones (mulmod / mod_exp / power2)
que sera funciones auxiliares para la funcion "witness"

La funcion witness recibe dos parametrosa a,n
	definimos como tamien a: i,t,u,x,y
		entonces t toma el valor de power(n-1, u)
		y "y" = mod_exp(a, u, n)

	luego ejecutamos un for desde 0 hasta el valor de t
		haciendo que x=mulmod(y,y,n)

		si "x" es igual a 1, "y" es distinto de 1 o de "n-1"
			retornamos 1;

		"y" toma el valor de "x"

	por ultimo si "y" es distinto de 1 retornamos 1, de lo
	contrario retornamos 0


la funcion miler rabin recibe un numero, y el numero de bases para el que sera probado
	primero de realizan comprobacion si el numero ingresado "n"

	es menor a 2, distinto de 2, o el modulo es 0, retornamos 0
	si es igual a 2 retornamos 1

	ejecutando un for desde 0 hasta s
		generamos un numero aleatorio "a" que ira desde 1 hasta n-1
		si al ejecutar "witness(a,n)" nos devuelve 1, retornamos 1

	si no retorna 1 en nigun momento entonces retornamos 0



en la funcion main se intenta encontrar todos los numeros primos de 3 cifras
ejecutando miller rabin, cuando este retorne 1, agregaremos el numero a una lista-enlazada
que guardara esos valores.
