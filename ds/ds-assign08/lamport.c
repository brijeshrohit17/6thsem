#include <stdio.h>
#include <stdlib.h>
// FUNCTION TO GET MAXIMUM OF TWO NUMBERS
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// LAMPORT'S CLOCK
void lamport(int p1, int p2, int message[p1][p2])
{
    int i, j, k, P1[p1], P2[p2];

    // INITIALISING PROCESS 1
    for (i = 0; i < p1; i++)
    {
        P1[i] = i + 1; // 1,2,3,4,5,6,7
    }
    // INITIALISING PROCESS 2
    for (i = 0; i < p2; i++)
    {
        P2[i] = i + 1; // 1,2,3,4,5,6
    }
    printf("\nBefore Implementing Lamport's logical clock => ");
    printf("\nTimeStamps of Process P1 is : ");
    for (i = 0; i < p1; i++)
    {
        printf("%d,", P1[i]);
    }
    printf("\nTimeStamps of Process P2 is : ");
    for (i = 0; i < p2; i++)
    {
        printf("%d,", P2[i]);
    }

    for (i = 0; i < p1; i++)
    {
        for (j = 0; j < p2; j++)
        {
            // 1 REPRESENTS MESSAGE BEING SENT
            // FROM P1 TO P2
            // THUS WE NEED TO ADJUST TIMESTAMP OF P2.
            // IMPLEMENTING (e1 -> e2) {HAPPENS BEFORE} RULE
            // THUS P2[j]=max(P2[j],P[i]+1)
            // OTHER FUTHER EVENTS WOULD BE ADJUSTED ACCORDINGLY
            if (message[i][j] == 1)
            {
                P2[j] = max(P2[j], P1[i] + 1);
                for (k = j+1; k < p2; k++)
                    P2[k] = P2[k - 1] + 1;
            }

            //-1 RESPRESENTS MESSAGE BEING RECEIVED
            // THUS SAME THING BUT REPLACING P1 PROCESS WITH P2.
            if (message[i][j] == -1)
            {
                P1[i] = max(P1[i], P2[j] + 1);

                for (k = i + 1; k < p2; k++)
                    P1[k] = P1[k - 1] + 1;
            }
        }
    }
    printf("\n\nAfter Implementing Lamport's logical clock => ");
    printf("\nTimeStamps of Process P1 is : ");
    for (i = 0; i < p1; i++)
    {
        printf("%d,", P1[i]);
    }
    printf("\nTimeStamps of Process P2 is : ");
    for (i = 0; i < p2; i++)
    {
        printf("%d,", P2[i]);
    }
}

int main()
{
    int n1 = 5, n2 = 4;
    int message[n1][n2];
    int i, j;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            message[i][j] = 0;
        }
    }
    // MESSAGES SENT AND RECEIVED.
    message[1][1] = 1;
    message[2][3] = 1;
    message[4][5] = -1;

    // message[1][1]=1;
    // message[1][0]=-1;
    // CALLING THE FUNCTION
    lamport(n1, n2, message);
    printf("\n");
    return 0;
}