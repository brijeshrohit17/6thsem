struct input
{
    int num;
};

struct output
{
    char str[100];
};

program EXEC_PROG{
    version EXEC_VERS{
        output exec(input)=1;
    }=1;
}=0x2f2f2f2f;
