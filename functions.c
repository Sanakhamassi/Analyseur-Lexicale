#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define IDFSIZE 50    // taille maximal d'un identificateur
#define NUMBERSIZE 32 // taille maximal d'un nombre
boolean isNumber = FALSE;
// savoir si un caractère est une alphabet

boolean isAlphabetic(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
    {
        return TRUE;
    }
    return FALSE;
}
// savoir si un caractère est un chiffre
boolean isNumeric(char c)
{
    if (c >= '0' && c <= '9')
    {
        return TRUE;
    }
    return FALSE;
}
// savoir si un caractère est un symbole simple
// retourner son numéro dans nameToken si caractère est un symbole simple, -1 sinon
int caractereSpecial(char c)
{
    int i = 0;
    int symbole = (int)STAR_TOKEN; // STAR_TOKEN est le premier symbole simple dans nameToken
    while (i < symbole_token_size)
    {
        if (c == symbole_token[i])
        {
            symbole = symbole + i;
            return symbole;
        }
        i++;
    }
    return -1;

}

token getToken()
{
    // Lire le caractère suivant
    char character = fgetc(fileSrc);
    token A;
    int i = 0;
    // Eliminer les blancs
    if (character == ' ' || character == '\t' || character == '\n')
    {
        return getToken();
    }
    // Reconnaissance des mots-clé et des identificateurs
    else if (isAlphabetic(character) == TRUE)
    {
        // code ici
    }
    // Reconnaissance des nombres
    else if (isNumeric(character) == TRUE)
    {
        // code ici
    }
    // Reconnaissance des variables textes
    else if (character == '"' || character == '\'')
    {
        // code ici
    }
    // Elimination des commentaires
    else if (character == '/')
    {
        // code ici
    }
    // Reconaissance des symboles simples
    else if ((i = caractereSpecial(character)) > -1)
    {
        // code ici
    }
    /*
    Reconnaissance des symboles complexes
    */
    // La fin de la lecture
    else if (character == EOF)
    {
        A.name = EOF_TOKEN;
        return A;
    }
    // Si on rencontre d'autre caractères non analysés
    else
    {
        A.name = ERROR_TOKEN;
        return A;
    }
}