#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include <string.h>

#define ANSI_RESET_ALL          "\x1b[0m"           //Definições para interface em linguagem C

#define ANSI_COLOR_BLACK        "\x1b[30m"
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_WHITE        "\x1b[37m"

#define ANSI_BACKGROUND_BLACK   "\x1b[40m"
#define ANSI_BACKGROUND_RED     "\x1b[41m"
#define ANSI_BACKGROUND_GREEN   "\x1b[42m"
#define ANSI_BACKGROUND_YELLOW  "\x1b[43m"
#define ANSI_BACKGROUND_BLUE    "\x1b[44m"
#define ANSI_BACKGROUND_MAGENTA "\x1b[45m"
#define ANSI_BACKGROUND_CYAN    "\x1b[46m"
#define ANSI_BACKGROUND_WHITE   "\x1b[47m"

#define ANSI_STYLE_BOLD         "\x1b[1m"
#define ANSI_STYLE_ITALIC       "\x1b[3m"
#define ANSI_STYLE_UNDERLINE    "\x1b[4m"

typedef struct word {           //palavras
    char* text;
    struct word* proximo;
} Word;

typedef struct line {            //lista encadeada de palavras "LINHAS"
    Word* primeiraPalavra;
    Word* ultimaPalavra;
    struct line* proximo;
} Line;

typedef struct {                //lista encadeada de linhas "TEXTO"
    Line* primeiraLinha;
    Line* ultimaLinha;
} LineList;

int i, j, ch;
char fn[20], e, c;
FILE *fp1, *fp2, *fp;

LineList lineList;

void Criar();
void Acrescentar();
void Editar();
void Copiar();
void Delete();
void Mostrar();

void main()
{
    lineList.primeiraLinha = NULL;
    lineList.ultimaLinha = NULL;

    do
    {
        system("cls");
        system("MODE con cols=80 lines=35 ");
        printf(ANSI_BACKGROUND_YELLOW ANSI_COLOR_YELLOW"--------------------------------------------------------------------------------\n");
        printf(ANSI_BACKGROUND_YELLOW ANSI_COLOR_YELLOW"--------------------------------------------------------------------------------\n");
        printf(ANSI_BACKGROUND_YELLOW ANSI_COLOR_YELLOW"--------------------------------------------------------------------------------\n");
        printf(ANSI_RESET_ALL ANSI_COLOR_YELLOW"\n================================"ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE" EDITOR DE TEXTO "ANSI_RESET_ALL ANSI_COLOR_YELLOW"===============================\n\n");
        printf(ANSI_STYLE_UNDERLINE ANSI_STYLE_BOLD"\n\n\tMENU:\n\t\n"ANSI_RESET_ALL );
        printf(ANSI_COLOR_YELLOW "\n\t1.CRIAR\n\t2.ABRIR\n\t3.DELETAR\n\t4.SAIR\n\n\n\n");
        printf("================================================================================\n");
        printf(ANSI_BACKGROUND_YELLOW ANSI_COLOR_YELLOW"--------------------------------------------------------------------------------\n");
        printf(ANSI_BACKGROUND_YELLOW ANSI_COLOR_YELLOW"--------------------------------------------------------------------------------\n");
        printf(ANSI_BACKGROUND_YELLOW ANSI_COLOR_YELLOW"--------------------------------------------------------------------------------\n");
        printf(ANSI_RESET_ALL ANSI_COLOR_RED ANSI_BACKGROUND_WHITE"\n\n\tDigite sua Escolha: "ANSI_RESET_ALL ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK);
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Criar();
            break;
        case 2:
            Mostrar();
            break;
        case 3:
            Delete();
            break;
        case 4:
            exit(0);
        }
    } while (1);
}

void adicionarLinhaLista(char* lineText) {                  //Funcao adicionar linha na lista
    Line* novaLinha = (Line*)malloc(sizeof(Line));
    novaLinha->primeiraPalavra = NULL;
    novaLinha->ultimaPalavra = NULL;
    novaLinha->proximo = NULL;                              //Inicializa e aloca a memoria

    char* token = strtok(lineText, " ");
    while (token != NULL) {                                      //Inseri as palavras na linha e depois as linhas na lista
        Word* novaPalavra = (Word*)malloc(sizeof(Word));
        novaPalavra->text = token;
        novaPalavra->proximo = NULL;

        if (novaLinha->primeiraPalavra == NULL) {
            novaLinha->primeiraPalavra = novaPalavra;
            novaLinha->ultimaPalavra = novaPalavra;
        } else {
            novaLinha->ultimaPalavra->proximo = novaPalavra;
            novaLinha->ultimaPalavra = novaPalavra;
        }

        token = strtok(NULL, " ");
    }

    if (lineList.primeiraLinha == NULL) {
        lineList.primeiraLinha = novaLinha;
        lineList.ultimaLinha = novaLinha;
    } else {
        lineList.ultimaLinha->proximo = novaLinha;
        lineList.ultimaLinha = novaLinha;
    }
}

void Criar()
{
    char arquivo[500];
    char lineBuffer[1000];
    int lineBufferIndex = 0;
    int isNewLine = 0;

    system("cls");
    printf("\n\n\n\t\t\tDigite o nome do Arquivo: \n\t\t\t\t");
    scanf("%s", &arquivo);

    printf("\n\n\n\t\t\tDeseja continuar?\n\n\t\t\t\t1-SIM\t2-NAO");

    system("cls");

    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"--------------------------------------------------------------------------------");
    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_WHITE"\n  %s:"ANSI_RESET_ALL ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"                    ");
    printf(ANSI_RESET_ALL ANSI_STYLE_UNDERLINE ANSI_BACKGROUND_BLUE ANSI_COLOR_WHITE"|Digite o texto e pressione '.' salvar|"ANSI_RESET_ALL ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"       "ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE);
    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"________________________________________________________________________________"ANSI_RESET_ALL, arquivo);
    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"________________________________________________________________________________\n"ANSI_RESET_ALL ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK, arquivo);
    fp1 = fopen(arquivo, "w");
    while (1)
    {
        c = getchar();

        if (c == '.') {
            lineBuffer[lineBufferIndex] = '\0';
            adicionarLinhaLista(lineBuffer);
            lineBufferIndex = 0;

            system("cls");
            fclose(fp1);
            printf(ANSI_COLOR_GREEN"\n\n\n\t\t\tArquivo Salvo com sucesso!"ANSI_RESET_ALL);
            sleep(1);
            break;
        } else if (c == ' ') {
            lineBuffer[lineBufferIndex] = '\0';
            adicionarLinhaLista(lineBuffer);
            lineBufferIndex = 0;
            fputc(c, fp1);
        } else if (c == '\n') {
            isNewLine = 1;
        } else {
            lineBuffer[lineBufferIndex] = c;
            lineBufferIndex++;
            fputc(c, fp1);
        }

        if (isNewLine) {
            lineBuffer[lineBufferIndex] = '\0';
            adicionarLinhaLista(lineBuffer);
            lineBufferIndex = 0;
            fputc('\n', fp1);
            isNewLine = 0;
        }
    }
}

void Mostrar()
{
    int escolha;

    system("cls");
    printf("\n\n\n\t\t\tDigite o nome do Arquivo: \n\t\t\t\t");
    scanf("%s", fn);
    system("cls");
    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"--------------------------------------------------------------------------------");
    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_WHITE"\n  %s:"ANSI_RESET_ALL ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"                    ");
    printf(ANSI_RESET_ALL ANSI_BACKGROUND_BLUE ANSI_COLOR_WHITE"                                       "ANSI_RESET_ALL ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"       "ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE);
    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"________________________________________________________________________________"ANSI_RESET_ALL);
    printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_BLUE"________________________________________________________________________________\n"ANSI_RESET_ALL ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK);

    fp1 = fopen(fn, "r");
    if (fp1 == NULL)
    {
        system("cls");
        printf(ANSI_RESET_ALL ANSI_BACKGROUND_BLACK ANSI_COLOR_RED"\n\n\n\t\t\tArquivo nao encontrado!"ANSI_RESET_ALL ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK);
        sleep(1);
        Mostrar();
        goto end1;

    }else{
        while (!feof(fp1))
        {
            c = getc(fp1);
            printf("%c", c);
        }
    end1:
        fclose(fp1);
        printf(ANSI_BACKGROUND_BLUE ANSI_COLOR_WHITE"\n\n\n\n\t\t\tDIGITE A OPCAO DESEJADA:\n\n\t\t1-EDITAR\t2-DELETAR\t3-SAIR\n\n"ANSI_RESET_ALL ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK);
        scanf("%d",&escolha);

    switch(escolha){
        case 1: Acrescentar();break;
        case 2: Delete();break;
        case 3: printf("\n\n\n\t\t  pressione qualquer tecla para continuar\n"ANSI_RESET_ALL);getch();break;
    }

}}

void Delete()
{
    char arquivo[500];

    system("cls");
    printf("\n\n\n\t\t\tDigite o nome do Arquivo: \n\t\t\t\t");
    scanf("%s", &arquivo);

    fp1 = fopen(arquivo, "r");
    if (fp1 == NULL)
    {
        system("cls");
        printf(ANSI_RESET_ALL ANSI_BACKGROUND_BLACK ANSI_COLOR_RED"\n\n\n\t\t\tArquivo nao encontrado!"ANSI_RESET_ALL ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK);
        sleep(1);
        Delete();
        goto end2;
    }
    fclose(fp1);
    if (remove(arquivo) >= 0)
    {
        system("cls");
        printf(ANSI_COLOR_GREEN"\n\n\tO arquivo foi exclu�do com sucesso"ANSI_RESET_ALL);
        goto end2;
    }
    else
        printf(ANSI_COLOR_RED"\n\tERRO!\n"ANSI_RESET_ALL);
end2:
    printf("\n\n\tpressione qualquer tecla para continuar\n");
    getch();
}

void Acrescentar()
{
    system("cls");
    printf("\n\n\n\t\t\tDigite o nome do Arquivo: \n\t\t\t\t");
    scanf("%s", fn);
    system("cls");

    fp1 = fopen(fn, "r");
    if (fp1 == NULL)
    {
        system("cls");
        printf(ANSI_RESET_ALL ANSI_BACKGROUND_BLACK ANSI_COLOR_RED"\n\n\n\t\t\tArquivo nao encontrado!"ANSI_RESET_ALL ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK);
        sleep(1);
        Acrescentar();
        fclose(fp1);
        system("cls");
        goto end3;
    }
    while (!feof(fp1))
    {
        c = getc(fp1);
        printf("%c", c);
    }
    fclose(fp1);
    printf(ANSI_COLOR_BLUE"\n\n\tDigite o texto e pressione Ctrl+S para acrescentar.\n");
    printf("\n____________________________________________________________________________\n="ANSI_RESET_ALL);
    fp1 = fopen(fn, "a");
    while (1)
    {
        c = getch();
        if (c == 19)
            goto end3;
        if (c == 13)
        {
            c = '\n';
            printf("\n\t");
            fputc(c, fp1);
        }
        else
        {
            printf("%c", c);
            fputc(c, fp1);
        }
    }
end3:
    fclose(fp1);

    getch();
}

void Editar()
{
    char arquivo[500];
    int lineIndex, lineCount;
    Line* currentLine;

    system("cls");
    printf("\n\tDigite o nome do arquivo:");
    scanf("%s", &arquivo);
    fp1 = fopen(arquivo, "r");
    if (fp1 == NULL)
    {
        system("cls");
        printf("\n\tArquivo n�o encontrado!");
        goto end;
    }

    lineCount = 0;
    currentLine = lineList.primeiraLinha;
    while (currentLine != NULL)
    {
        lineCount++;
        currentLine = currentLine->proximo;
    }

    fclose(fp1);

    printf("\n\tDigite o n�mero da linha a ser editada (1-%d): ", lineCount);
    scanf("%d", &lineIndex);

    if (lineIndex < 1 || lineIndex > lineCount)
    {
        printf("\n\tLinha inv�lida!\n");
        goto end;
    }

    currentLine = lineList.primeiraLinha;
    for (i = 1; i < lineIndex; i++)
    {
        currentLine = currentLine->proximo;
    }

    printf("\n\tDigite o novo texto da linha %d: ", lineIndex);
    fflush(stdin);
    gets(currentLine->primeiraPalavra->text);

    fp1 = fopen(arquivo, "w");
    currentLine = lineList.primeiraLinha;
    while (currentLine != NULL)
    {
        Word* currentWord = currentLine->primeiraPalavra;
        while (currentWord != NULL) {
            fprintf(fp1, "%s ", currentWord->text);
            currentWord = currentWord->proximo;
        }
        fprintf(fp1, "\n");
        currentLine = currentLine->proximo;
    }
    fclose(fp1);

    printf("\n\tLinha editada com sucesso!\n");

end:
    printf("\n\n\tpressione qualquer tecla para continuar\n");
    getch();
}
