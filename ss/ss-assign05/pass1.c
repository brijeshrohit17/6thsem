#include <stdio.h>
#include <stdlib.h>
#include "mnetype.h"
#include<string.h>

char label[50],mnem[50], opr1[50],sym[50],lit[50];
struct symbol_tab symtab[1000];
struct literal_tab littab[1000];
int sym_ct=0,lit_ct=0;

int islit(char * str)
{
    if(str[0]=='=')return 1;
    return 0;
}


void parse(char *inst)
{
    strcpy(label,"");
    strcpy(mnem,"");
    strcpy(opr1,"");
    strcpy(sym,"");
    strcpy(lit,"");
    int i=0,j=0;
    char word[5][20];
    char temp[20]="";
    for(j=0;j<strlen(inst);j++)
    {
        //printf("%d %c\n",j,inst[j]);
        if(inst[j]==':'||inst[j]==' '||inst[j]==',')
        {
            if((inst[j]==','&&inst[j+1]==' ')||(inst[j]==':'&&inst[j+1]==' '))continue;

            strcpy(word[i],temp);
            strcpy(temp,""); 
            i++;
            continue;
        }
        else 
        {
            char c[2];
            c[0]=inst[j];
            c[1]='\0';
            strcat(temp,c);
        }
    }
    strcpy(word[i],temp);
    i++;
    printf("%d\n",i);
    if(i==0)
    {
        return;
    }
    if(i==1)
    {
        strcpy(mnem,word[0]);
    }
    else if(i==2)
    {
        strcpy(mnem,word[0]);
        if(islit(word[1]))
        {
            strcpy(lit,word[1]);
        }
        else
        {
            strcpy(sym,word[1]);
        }
        
    }
    else if(i==3)
    {
        strcpy(mnem,word[0]);
        strcpy(opr1,word[1]);
        //strcpy(opr2,word[2]);
        if(islit(word[2]))
        {
            strcpy(lit,word[2]);
        }
        else
        {
            strcpy(sym,word[2]);
        }
    }
    else
    {
        strcpy(label,word[0]);
        strcpy(mnem,word[1]);
        strcpy(opr1,word[2]);
        
        if(islit(word[3]))
        {
            strcpy(lit,word[3]);
        }
        else
        {
            strcpy(sym,word[3]);
        }   
    }
}

int insym(char *sym1)
{
    int i=0;
    while(i<sym_ct)
    {
        if(strcpy(symtab[i].symbol,sym1)==0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int inlit(char *lit1)
{
    int i=0;
    while(i<lit_ct)
    {
        if(strcpy(littab[i].literal,lit1)==0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}



int main()
{
    set();
    FILE *src,*inter;
    src=fopen("input.txt","r");
    inter=fopen("inter.txt","w");

    char inst[20];

    fgets(inst,20,src);
    
    printf("hell\n");
    int lc=100;
    parse("MOVER AREG, ='5'");
    char * intline="";
    int i=0;

    return 0;
}