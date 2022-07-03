/*/Concatenar duas frases infinitamente/*/

#include <stdio.h>
#include <string.h>

void main ()
{
	char nome[100], sobrenome[100], nomecmpl[300];
	unsigned short casos, i, j, k;
	unsigned contador, aux;
	scanf("%hu", &casos);
	while (casos--)
	{
		scanf(" %[^\n] %[^\n]", nome, sobrenome);
		contador = 0;
		i = 0;
		k = 0;
		j = 0;

		aux = strlen(sobrenome);
		while (aux--)
		{

			while (nome[i])
			{	
				nomecmpl[k++] = nome[i++];
				contador++;

				if (contador == 2)
					break;
			}
			contador = 0;
			while (sobrenome[j])
			{
				nomecmpl[k++] = sobrenome[j++];
				contador++;
				if (contador == 2)
					break;
			}
			contador = 0;
		}
		nomecmpl[k] = '\0';
		printf("%s\n", nomecmpl);
	}
}
