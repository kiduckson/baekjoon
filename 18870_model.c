#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getChar(void);
int getInt(void);
void putChar(int c);
void putInt(int c);
void flush(void);
int cmp(const void *p1, const void *p2)
{ return *(int *)p1 - *(int *)p2; }

int main ()
{
    int i, j, n = getInt();
    int v[n][2]; // Get coordinates
    for (i = 0; i < n; i++) {
        v[i][0] = getInt();
        v[i][1] = i;
    }

    qsort(v, n, sizeof(int) * 2, cmp);

    int res = 0;
    int *cnt = (int *) calloc(n, sizeof(int));
    for (i = 0, j = 1; j < n; i++, j++) {
        res += (v[j][0] > v[i][0]);
        cnt[v[j][1]] = res;
    }

    // Print
    for (i = 0; i < n; i++) {
        putInt(cnt[i]);
        putChar(' ');
    }
    flush();
}

#define BSIZE 1 << 20

char rbuf[BSIZE];
int rp = BSIZE;
char wbuf[BSIZE];
int wp = 0;

int getChar(void)
{
    if (rp == BSIZE) {
        fread(rbuf, 1, BSIZE, stdin);
        rp = 0;
    }
    return rbuf[rp++];
}

int getInt(void)
{
    int c, sgn, num;
    sgn = num = 0;

    while (isspace(c = getChar()));
    if (c == '-') {
        sgn = 1;
        c = getChar();
    }
    while (isdigit(c)) {
        num = 10 * num + (c - '0');
        c = getChar();
    }
    return sgn ? -num : num;
}

void putChar(int c)
{
    if (wp == BSIZE) {
        fwrite(wbuf, 1, BSIZE, stdout);
        wp = 0;
    }
    wbuf[wp++] = c;
}

void putInt(int c)
{
    if (c < 0) {
        putChar('-');
        c = -c;
    }
    if (c / 10)
        putInt(c / 10);
    putChar(c % 10 + '0');
}

void flush(void)
{
    fwrite(wbuf, 1, wp, stdout);
    wp = 0;
}
