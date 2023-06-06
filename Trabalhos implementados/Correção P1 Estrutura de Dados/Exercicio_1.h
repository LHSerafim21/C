#ifndef EXERCICIO_1_H_INCLUDED
#define EXERCICIO_1_H_INCLUDED
#endif // EXERCICIO_1_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* str;
    int length;
} StringDinamica;

StringDinamica* criarStringDinamica(const char* str) {
    StringDinamica* stringDinamica = (StringDinamica*)malloc(sizeof(StringDinamica));
    stringDinamica->length = strlen(str);
    stringDinamica->str = (char*)malloc((stringDinamica->length + 1) * sizeof(char));
    strcpy(stringDinamica->str, str);
    return stringDinamica;
}

bool Eigual(StringDinamica* str1, StringDinamica* str2) {
    if (str1->length != str2->length) {
        return false;
    }

    return strcmp(str1->str, str2->str) == 0;
}

int funcao_Exercicio1() {
    // Exemplo de uso da função

    char a[100],b[100];

    fflush (stdin);
    printf("Digite uma String:\n");
    gets(a);
    fflush (stdin);
    printf("Digite uma String:\n");
    gets(b);

    StringDinamica* string1 = criarStringDinamica(a);
    StringDinamica* string2 = criarStringDinamica(b);

    bool result = Eigual(string1, string2);

    if (result) {
        printf("As strings sao iguais.\n");
        sleep(3);
    } else {
        printf("As strings sao diferentes.\n");
        sleep(3);
    }

    // Libera a memória alocada
    free(string1->str);
    free(string1);
    free(string2->str);
    free(string2);

    return 0;
}
