#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void passbyvalue(box B)
{
    printf("\nPassing by value.\n");
    cout << "Height : " << B.height << endl;
    cout << "Width  : " << B.width << endl;
    cout << "Length : " << B.length << endl;
    cout << "Volume : " << B.volume << endl;
    cout << "\n";
}

void passbyaddress(box &B)
{
    B.volume = B.height*B.width*B.length;
}

bool compareboxheight(box *A, box *B)
{
    return B->height > A->height;
}

bool compareboxvolume(box *A, box *B)
{
    B->volume = B->height*B->width*B->length;
    A->volume = A->height*A->width*A->length;
    return B->volume > A->volume;
}

int main()
{
    box B;
    // B.height = 12.3;
    // B.length = 14.62;
    // B.width = 20.5;
    // B.volume = B.height*B.length*B.width;
    // printf("Please enter name of maker of box : ");
    // scanf("%d",&B.maker);
    
    passbyvalue(B);
    
    passbyaddress(B);
    
    if(compareboxvolume)
    cout << "Box B is larger than box A.\n";
    else
    cout << "Box B is not larger than box A.\n";

    if(compareboxheight)
    cout << "Box B is required one as it's height is more.\n";
    else
    cout << "Box A is required.\n";



    return 0;
}