#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Lire le fichier source
#include "functions.c"
int main()
{
    FILE *fileSrc;
    fileSrc = fopen("code.txt", "r");
    int k;
    token currentToken = getToken();
    if (fileSrc == NULL)
    {
        printf("Erreur d'ouverture du fichier source..\n\n");
        exit(0);
    }
    else
    {
        do
        {
            k = (int)currentToken.name;
            printf("%s ", tokens[k]);
            currentToken = getToken();
        } while (currentToken.name != EOF_TOKEN);
        printf("\n\n");
    }
    return 0;
}