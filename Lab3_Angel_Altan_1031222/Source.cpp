#include <iostream>
using namespace std;
#include <string>

int Multi_sumas(int multiplicador, int sumando, int suma)
{
	if (sumando == 0 ) {
		return suma;
	}
	else {
		suma = suma + multiplicador;
		sumando = sumando - 1;
		return Multi_sumas(multiplicador, sumando, suma);
	}
	
}

bool Palindromas(string palabra, int i_inicio, int i_final, int cont_t, int cont_f) {
	
	if (palabra[i_inicio] == palabra[i_final]) {
		cont_t++;
	}	
	else {
		cont_f++;
	}
	if (cont_t == palabra.length()-1) {
		return true;
	}
	else if (cont_f > 0) {
		return false;
	}
	return Palindromas(palabra, (i_final++), (i_final--), cont_t, cont_f);
	
}

int Cambiodebase(int numero, int base, int cociente, int residuo, string numero_string) {
	 
	cociente = numero / base;
	residuo = numero % base;
	numero = cociente;
	numero_string = to_string(residuo) + numero_string;
	if (cociente == 0) {
		return stoi(numero_string);
	}
	return Cambiodebase(numero, base, cociente, residuo, numero_string);
}

int Cambiobinario(int bin,char num[],int i, int v_pos,int base,int potencia, int resultado ) {

	if (i < 0) {
		return resultado;
	}
	else {
		char nuevo[] = { num[i] };
		bin = atoi(nuevo);
		v_pos = pow(base, potencia);
		resultado = resultado + (bin * v_pos);
		return Cambiobinario(bin, num, i--, v_pos, base, potencia++, resultado);
	}
}

int Cambiobase10(int base_org,string num) {
	 int nuevo_num = 0, binario, contador = 0, suma=0;
	int exponente = 0, valor_posicional;
	char nuevo[100];

	for (int i = (num.length() - 1);i >= 0;i--) {
		char nuevo[] = { num[i] };
		binario = atoi(nuevo);
		valor_posicional = pow(base_org, exponente);
		nuevo_num =  (binario * valor_posicional);
		suma = suma + nuevo_num;
		exponente++;
	}
	return suma;
}
int main()
{
	int metodo_menu, menu_iterativo, menu_recursivo;
	do {
		std::cout << "Seleccione el metodo que desea visulizar" << std::endl;
		std::cout << "1. Iterativo" << std::endl;
		std::cout << "2. Recursivo" << std::endl;
		std::cout << "3. salir" << std::endl;
		std::cin >> metodo_menu;
		system("cls");
	} while (metodo_menu != 1 && metodo_menu != 2 && metodo_menu != 3);

	switch (metodo_menu) {
	case 1: {
		std::cout << "1. Multiplicacion por sumas" << std::endl;
		std::cout << "2. Palabras Palindromas" << std::endl;
		std::cout << "3. Conversion de base" << std::endl;
		std::cout << "4. salir" << std::endl;
		std::cin >> menu_iterativo;

		switch (menu_iterativo) {
		case 1: {
			system("cls");
			int x, y, resultado = 0;
			std::cout << "Ingrese el multiplicador" << std::endl;
			std::cin >> x;

			std::cout << "Ingrese el multiplicando" << std::endl;
			std::cin >> y;

			for (int i = 0; i < y; i++) {
				resultado = resultado + x;
			}

			std::cout << "El resultado de la multiplicacion es: " << resultado << std::endl;
			break;
		}//fin case 1 iterativo
		case 2: {
			string frase = " ";
			int contador=0, indice=0;
			cout << "ingrese palabra que desea analisar" << endl;
			cin >> frase;
			for (int j = frase.length() - 1;j >= 0;j--) {
				if (frase[indice] == frase[j]) {
					contador++;
				}
				indice++;
			}
			
			if (contador == frase.length()) {
				cout << "Es una palabra palindroma"<<endl;
			}
			else
				cout << "No es una palabra palindroma"<<endl;
			break;
		}//Fin case 2 Iterativo

		case 3: { //Cambio de base Iterativo
			system("cls");
			int base_org, nueva_base, nuevo_num = 0, binario, contador = 0;
			int cociente, residuo, operando;
			char num[100], ordenamiento[100];
			string num_2, resultado = "";

			int exponente = 0, valor_posicional;
			std::cout << "Ingrese la base original" << std::endl;
			std::cin >> base_org;

			std::cout << "Ingrese la base a la que desea convertir" << std::endl;
			std::cin >> nueva_base;
			std::cout << "Ingrese el numero que desea convertir" << std::endl;
			std::cin >> num;
			if (base_org == 2) { //Comprobacion binario

				num_2 = num;

				for (int i = 0;i < (num_2.length() - 1);i++) {
					char nuevo[] = { num[i] };
					binario = atoi(nuevo);
					if (binario == 0 || binario == 1) {
						contador++;
					}
				}
				if (contador != (num_2.length() - 1)) {
					std::cout << "Ingrese un numero binario";
					system("pause");
				}
			}
			int numero_decimal = Cambiobase10(base_org, num);

			do {
				cociente = (numero_decimal / nueva_base);
				residuo = (numero_decimal % nueva_base);
				numero_decimal = cociente;
				resultado = to_string(residuo) + resultado;
			} while (cociente != 0);
			cout << resultado;
			break;
		}

		}
	case 2: {
		std::cout << "1. Multiplicacion por sumas" << std::endl;
		std::cout << "2. Palabras Palindromas" << std::endl;
		std::cout << "3. Conversion de base" << std::endl;
		std::cout << "4. salir" << std::endl;
		std::cin >> menu_recursivo;

		switch (menu_recursivo) {
		case 1: {
			system("cls");
			int x, y, resultado = 0, r;
			std::cout << "Ingrese el multiplicador" << std::endl;
			std::cin >> x;
			std::cout << "Ingrese la base a la que desea convertir" << std::endl;
			std::cin >> y;

			int cociente = 0;
			int residuo = 0;
			string string_numero = "";
			r = Multi_sumas(x, y, resultado);
			std::cout << "El resultado de la operacion es: " << r << std::endl;
		}
		case 2: {
			string frase = " ";
			int  indice,contador_v=0, contador_f=0;
			bool espalindromo=true;
			cout << "ingrese palabra que desea analizar" << endl;
			cin >> frase;

			indice = frase.length()-1;

			espalindromo = Palindromas(frase, 0, indice,contador_v,contador_f);

			if (espalindromo == true) {
				cout << "es palindroma";
			}
			else {
				cout << "No es palindroma";
			}

			break;
		}//fin case 2 recursivo

		case 3: {
			system("cls");
			int base_org, nueva_base, nuevo_num = 0, binario, contador = 0;
			int cociente = 0, residuo = 0, operando;
			char num[100], ordenamiento[100];
			string num_2, resultado = "";

			int exponente = 0, valor_posicional;
			std::cout << "Ingrese la base original" << std::endl;
			std::cin >> base_org;

			std::cout << "Ingrese la base a la que desea convertir" << std::endl;
			std::cin >> nueva_base;
			std::cout << "Ingrese el numero que desea convertir" << std::endl;
			std::cin >> num;
			if (base_org == 2) { //Comprobacion binario

				num_2 = num;

				for (int i = 0;i < (num_2.length() - 1);i++) {
					char nuevo[] = { num[i] };
					binario = atoi(nuevo);
					if (binario == 0 || binario == 1) {
						contador++;
					}
				}
				if (contador != (num_2.length() - 1)) {
					std::cout << "Ingrese un numero binario";
					system("pause");
				}
			}
			int numero_decimal = Cambiobase10(base_org, num);
			int res_final = Cambiodebase(numero_decimal, nueva_base, cociente, residuo, resultado);
			cout << res_final;
		}
		}
	}
	}
	}
}


