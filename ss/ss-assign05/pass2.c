// U19CS003 AMAN KUMAR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to extract the numeric val depending on the type of mnemonic used.
char *extract(char *str)
{
    //- MEANING NOT REQUIRED THUS 00.
    if (strcmp(str, "-") == 0)
    {
        char* a = "00";
        return a;
    }

    // IF THE STR IS NUMERIC THEN RETURN THE STRING ITSELF.
    if (str[0] >= '0' && str[0] <= '9')
    {
        return str;
    }

    char *final = malloc(sizeof(char) * 4);
    strcpy(final, "");
    int i = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ',')
            break;
    }
    i++;
    int j = 0;
    while (i < strlen(str))
    {
        char ch[2] = {str[i], '\0'};
        strcat(final, ch);
        i++;
    }

    // IF STR[0]=='S' THEN SEARCHING 'final' FROM THE SYMBOL TABLE TO RETURN ADDRESS.
    if (str[0] == 'S')
    {
        FILE *f = fopen("symbol.txt", "r");
        int n = atoi(final);
        int x;
        char t1[8], t2[8];
        while (fscanf(f, "%d%s%s", &x, t1, t2) != EOF)
        {
            if (n == x)
            {
                strcpy(final, t2);
                break;
            }
        }
        fclose(f);
    }

    // IF STR[0]=='L' THEN SEARCHING 'final' FROM THE LITERAL TABLE TO RETURN ADDESSS.
    if (str[0] == 'L')
    {
        FILE *f = fopen("literal.txt", "r");
        int n = atoi(final);
        int x;
        char t1[8], t2[8];
        while (fscanf(f, "%d %s %s", &x, t1, t2) != EOF)
        {
            if (n == x)
            {
                strcpy(final, t2);
                break;
            }
        }
        fclose(f);
    }

    return final;
}

int main()
{
    char lc[8], mnem[8], reg[8], symlit[8];
    FILE *fin, *fsym, *flit, *fout;

    // OPENING FILES.
    fin = fopen("inter.txt", "r");
    fout = fopen("obcode.txt", "w");

    fscanf(fin, "%s%s%s", mnem, reg, symlit);

    char *s = extract(mnem);
    char *s1 = extract(reg);
    char *s2 = extract(symlit);
    // printf("%s %s %s\n",s,s1,s2);
    fprintf(fout, "%s %s %s\n", s, s1, s2);

    // AD,02 STANDS FOR 'END'.
    while (strcmp(mnem, "AD,02") != 0)
    {

        fscanf(fin, "%s %s %s %s", lc, mnem, reg, symlit);

        char op[8], op1[8], op2[8];

        // FOR ASSEMBLER DIRECTIVES
        if (mnem[0] == 'A' && mnem[1] == 'D')
        {
            s2 = extract(symlit);
            fprintf(fout, "%s) 00 00 %s\n", lc, s2);
        }

        // FOR IMPERATIVE STATEMENTS
        else if (mnem[0] == 'I' && mnem[1] == 'S')
        {
            s = extract(mnem);
            s1 = extract(reg);
            s2 = extract(symlit);
            fprintf(fout, "%s) %s %s %s\n", lc, s, s1, s2);
        }

        // FOR DECLARATIVE STATEMENTS
        else if (mnem[0] == 'D' && mnem[1] == 'L')
        {
            //DECLARATIVE STORAGE STATEMENT 
            if(mnem[3]=='0'&&mnem[4]=='1')
            {
                fprintf(fout, "%s) 00 00 000\n", lc);
            }
            else{
                s2 = extract(symlit);
            fprintf(fout, "%s) 00 00 %s\n", lc, s2);
            }
            
        }
    }
    // CLOSING THE FILES
    fclose(fout);
    fclose(fin);

    return 0;
}