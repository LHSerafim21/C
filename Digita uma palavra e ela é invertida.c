/*/Digita uma palavra e ela é invertida/*/

#include <stdio.h>

int main() {
    
    int c, contador = 0;
    
    scanf("%i ",&c);
    
    while(contador < c) {
        
        char palavra[1001];
        int pos = 0;
        
        scanf("%s",palavra);
    
        while (palavra[pos] != '\0')
            pos++;

        pos--;
        
        while (pos >= 0) {
            if (palavra[pos] >= 'a' && palavra[pos] <= 'z') {
                printf("%c",palavra[pos]);
            }
            pos--;
        }
        
        printf("\n");
        
        contador++;
        
    }
    return 0;
}