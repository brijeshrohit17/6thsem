struct maxarray{
    int size;
    int arr[100];
};

program MAXARRAY_PROG{
    version MAXARRAY_VERS{
        int max(maxarray)=1;
    }=1;
}=0x2f2f2f2f;