#ifndef GAMA_H_INCLUDED
#define GAMA_H_INCLUDED
#endif // GAMA_H_INCLUDED

void GamaAerial(){

}

void Principal__Gama(){

    system("cls");
    int a;

    while(a != 0){
        system("cls");
        printf("Digite o numero para a resolucao da imagem: \n0- SAIR\n1- Replicacao\n2- Media\n");
        scanf("%d",&a);

        switch(a){
            case 0: a=0;
            case 1: GamaAerial(); break;
            //case 2: Media(); break;
        }
    }
    return 0;
}
