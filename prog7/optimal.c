#include <stdio.h>

int main()
{
    int pages[20], frame[10];
    int n, f, i, j, k;
    int fault = 0, found;

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
            int pos = -1, farthest = i;

            for(j = 0; j < f; j++)
            {
                int nextUse = 999;

                for(k = i + 1; k < n; k++)
                {
                    if(frame[j] == pages[k])
                    {
                        nextUse = k;
                        break;
                    }
                }

                if(nextUse > farthest)
                {
                    farthest = nextUse;
                    pos = j;
                }
            }

            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);

    return 0;
}