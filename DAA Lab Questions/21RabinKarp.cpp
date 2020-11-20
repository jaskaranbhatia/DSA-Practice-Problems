#include <bits/stdc++.h>
using namespace std;

#define d 10

void search(string pat, string txt, int q)
{
    int M = pat.length(); // M is pattern length
    int N = txt.length(); // N is text length
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // h has  a value of (10^M-1) % q;
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // calculate hash value of pattern and text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide pattern over the text one character at a time
    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Below code calculates hash for next window of text
        // Remove the leading digit and add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
}

int main()
{
    string txt = "abcxxxabc";
    string pat = "x";

    int q = 13;

    search(pat, txt, q);
    return 0;
}