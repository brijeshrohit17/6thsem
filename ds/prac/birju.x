struct input
{
    int choice;
    char str1[50];
    char str2[50];			
    int num1;
    int num2;
    int year;
    int arr[100];	
};

struct output
{
    int flag;		
    int gcd;		
    float sqrt;
    int num1;
    int num2;
    int max;
    int min;
    float avg;
    char str[100];
    int arr[100];
};

program EXEC_PROG{
    version EXEC_VERS{
        output exec(input)=1;
    }=1;
}=0x2f2f2f2f;
