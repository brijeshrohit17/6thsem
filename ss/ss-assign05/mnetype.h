#include<string.h>

struct command {
    char mnemonic[10];
    char type[2];
    int opcode;
    int length;
};

struct registers
{
    int code;
    char* name;
};

struct symbol_tab
{
    int sym_no;
    char symbol[20];
    int address;
};

struct literal_tab
{
    int lit_no;
    char literal[20];
    int address;
};

struct command mot[11];
struct command pot[6];
struct command dl[3];
struct registers reg[4];
void set()
{
    int i = 0;

    //SETTING MOTS
    for (i = 1; i < 11; i++)
    {
        strcpy(mot[i].type, "IS");
        mot[i].opcode = i;
        mot[i].length = 1;
    }

    strcpy(mot[1].mnemonic, "MOVER");
    strcpy(mot[2].mnemonic, "MOVEM");
    strcpy(mot[3].mnemonic, "ADD");
    strcpy(mot[4].mnemonic, "SUB");
    strcpy(mot[5].mnemonic, "MULT");
    strcpy(mot[6].mnemonic, "DIV");
    strcpy(mot[7].mnemonic, "BC");
    strcpy(mot[8].mnemonic, "COMP");
    strcpy(mot[9].mnemonic, "PRINT");
    strcpy(mot[10].mnemonic, "READ");

    //SETTING POTS
    for (i = 1; i < 6; i++)
    {
        strcpy(pot[i].type, "AD");
        pot[i].opcode = i;
    }
    strcpy(pot[1].mnemonic, "START");
    strcpy(pot[2].mnemonic, "END");
    strcpy(pot[3].mnemonic, "EQU");
    strcpy(pot[4].mnemonic, "ORIGIN");
    strcpy(pot[5].mnemonic, "LTORG");

    //SETTING DLS

    for (i = 1; i < 3; i++)
    {
        strcpy(dl[i].type, "DL");
        dl[i].opcode = i + 5;
    }
    strcpy(dl[1].mnemonic, "DS");
    strcpy(dl[2].mnemonic, "DC");

    //REGISTERS
    for (i = 1; i < 4; i++)
    {
        reg[i].code = i;
    }
    strcpy(reg[1].name, "AREG");
    strcpy(reg[2].name, "BREG");
    strcpy(reg[3].name, "CREG");

}