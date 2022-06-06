#ifndef HEADER_FILE
#define HEADER_FILE
// Type booléen
typedef enum
{
    FALSE,
    TRUE
} boolean;
// Les mots clés de notre langage
const char *mots_cles[] = {"if", "else", "for", "while", "int", "float", "string", "void", "typedef"};
// Les symboles de notre langage
const char symboles[] = {"+", "-", "/", "*", ",", ";", "{", "}", "(", ")", "=", ">", "==", ">=", "<="};
// Le monde des tokens
typedef enum
{
    // mots clés tokens
    IF_TOKEN,
    ELSE_TOKEN,
    FOR_TOKEN,
    WHILE_TOKEN,
    INT_TOKEN,
    FLOAT_TOKEN,
    STRING_TOKEN,
    VOID_TOKEN,
    TYPEDEF_TOKEN
        // Symbole tokens
        PLUS_TOKEN,
    MINUS_TOKEN,
    DIV_TOKEN,
    STAR_TOKEN,
    COMMA_TOKEN,
    SEMICOLON_TOKEN,
    OPEN_BRACE_TOKEN,
    CLOSE_BRACE_TOKEN,
    OPEN_PARENS_TOKEN,
    CLOSE_PARENS_TOKEN,
    ASSIGNMENT_TOKEN,
    GT_TOKEN,
    LT_TOKEN,
    OP_EQ_TOKEN,
    OP_GE_TOKEN,
    OP_LE_TOKEN,
    // autres tokens
    IDF_TOKEN,
    VARCHAR_TOKEN,
    NUMBER_TOKEN,
    EOF_TOKEN,
    ERROR_TOKEN
} nameToken;

// structure d'un identificateur en c
typedef struct
{
    char *name;
} idfToken;

// structure d'un nombre
typedef struct
{
    boolean isInt; // entier ou flot
    union
    {
        int n;
        float x;
    } value;
} numberToken;

// La structure d'un token
typedef struct
{
    nameToken name; // Le nom du token
    union
    {
        idfToken idf;       // les informations de l'identificateur (si le token est IDF_TOKEN)
        numberToken number; // les informations du nombre (si le token est NUMBER_TOKEN)
    } properties;
} token;
#endif