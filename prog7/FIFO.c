#include <stdio.h>

int main()
{
    int pages[20], frame[10];
    int n, f, i, j;
    int fault = 0, pos = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            frame[pos] = pages[i];
            pos = (pos + 1) % f;
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);

    return 0;
}