/*/Cadastro de portaria de condominio, por struct/*/

 #include <stdlib.h>
 #include <stdio.h>
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct funcionario{
    char nomef[100], cargof[100];
    int cadastrof;
    };

    struct morador{
    char nomem[100];
    int casam, cadastrom; 
    };

    struct prestador{
    char nomep[100], motivop[100];
    int casap;
    };

    struct visita{
    char nomev[100], pessoav[100];
    int casav;
    };
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    funcao_funcionario(){

        system("color 3e");
        struct funcionario f;
        system("cls");
        printf("Para a ficha de Funcionario, Digite:\n\nDigite o seu nome:\n");
        fgets(f.nomef,100,stdin);
        fflush (stdin);
        system("cls");
        printf("Para a ficha de Funcionario, Digite:\n\nDigite o seu cargo:\n");
        fgets(f.cargof,100,stdin);
        fflush (stdin);
        system("cls");
        printf("Para a ficha de Funcionario, Digite:\n\nDigite o seu cadastro:\n");
        scanf("%d",&f.cadastrof);
        system("cls");

        printf("Ficha:\n\nNome: %s\nCargo: %s\nCadastro: %d\n\n\n\n",f.nomef,f.cargof,f.cadastrof);
        return 0;
    }

    funcao_morador(){

        struct morador m;
        system("cls");
        printf("Para a ficha de morador, Digite:\n\nDigite o seu nome:\n");
        fgets(m.nomem,100,stdin);
        fflush (stdin);
        system("cls");
        printf("Para a ficha de morador, Digite:\n\nDigite o numero da sua casa:\n");
        scanf("%d",&m.casam);
        system("cls");
        printf("Para a ficha de morador, Digite:\n\nDigite o seu cadastro:\n");
        scanf("%d",&m.cadastrom);
        system("cls");

        printf("Ficha:\n\nNome: %s\nCasa: %s\nCadastro: %d\n\n\n\n",m.nomem,m.casam,m.cadastrom);
        return 0;
    }

    funcao_prestador_de_servico(){

        struct prestador p;
        system("cls");
        printf("Para a ficha de prestador de servico, Digite:\n\nDigite o seu nome:\n");
        fgets(p.nomep,100,stdin);
        fflush (stdin);
        system("cls");
        printf("Para a ficha de prestador de servico, Digite:\n\nDigite qual o servico que sera prestado:\n");
        fgets(p.motivop,100,stdin);
        fflush (stdin);
        system("cls");
        printf("Para a ficha de prestador de servico, Digite:\n\nDigite qual casa sera prestado o servico:\n");
        scanf("%d",&p.casap);
        system("cls");

        printf("Ficha:\n\nNome: %s\nCasa: %s\nCadastro: %d\n\n\n\n",p.nomep,p.motivop,p.casap);
        return 0;
    }

    funcao_visita(){

        struct visita v;
        system("cls");
        printf("Para a ficha de visitante, Digite:\n\nDigite o seu nome:\n");
        fgets(v.nomev,100,stdin);
        fflush (stdin);
        system("cls");
        printf("Para a ficha de visitante, Digite:\n\nDigite qual pessoa ira visitar:\n");
        fgets(v.pessoav,100,stdin);
        fflush (stdin);
        system("cls");
        printf("Para a ficha de visitante, Digite:\n\nDigite qual casa ira visitar:\n");
        scanf("%d",&v.casav);
        system("cls");

        printf("Ficha:\n\nNome: %s\nCasa: %s\nCadastro: %d\n\n\n\n",v.nomev,v.pessoav,v.casav);
        return 0;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////
 int main(){

    int n;

    system("cls");
    printf("Digite como deseja se cadastrar:\n1-Funcionario\n2-Morador\n3-Prestador de Servico\n4-Visita\n");
    scanf("%d",&n);

    switch(n){
        case 1: funcao_funcionario();
        case 2: funcao_morador();
        case 3: funcao_prestador_de_servico();
        case 4: funcao_visita();
    }
 }

 