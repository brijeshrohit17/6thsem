%{
    #include<stdio.h>
    int vowels=0, consonants=0, chars=0;
%}

%%
[aeiouAEIOU] {vowels++;chars++;}
[a-zA-Z] {consonants++;chars++;}
. {chars++;}
%%

int yywrap() {}

int main() {
    printf("Enter string : ");
    yylex();
    printf("\nNumber of vowel : %d\n", vowels);
    printf("Number of consonants : %d\n", consonants);
    printf("Number of chars : %d\n", chars);
    return 0;
}