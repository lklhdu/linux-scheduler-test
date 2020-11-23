#include <stdio.h>
const int DIGITS = 2400; // must: DIGITS % LEN == 0
const int BASE = 10000;  // BASE == 10 ** LEN
const int LEN = 4;
const int TIMES = 14;
int get_item(int pi[], int n)
{
    int item = 0;
    for (int k = n - 1; k >= 0; k--)
    {
        item += pi[k] * BASE;
        pi[k] = item % (k * 2 + 1);
        item /= (k * 2 + 1);
        if (k > 0)
            item *= k;
    }
    return item;
}

int main()
{
    int pi[DIGITS / LEN * TIMES], n = sizeof(pi) / sizeof(pi[0]);
    for (int i = 0; i < n; i++)
        pi[i] = BASE / 5; // BASE / 5 == 2.000
    for (int i = 0; i < 20000; i++)
    {
        for (int remainder = 0; n > 0; n -= TIMES)
        {
            int item = get_item(pi, n);
            // printf("%.*d", LEN, remainder + item / BASE);
            remainder = item % BASE;
        }
        // printf("\n");
    }
}