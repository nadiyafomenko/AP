#include <stdio.h>

//пототипи
long Perevert(long x);
void function(int k, ...);


int main() {
    function(5, 157757, 423444, 95739, 45678, 2345);
}


void function(int k, ...) {

    int* pik = &k;

    for (; k; k--) {
        printf("%d\n", Perevert(*++pik));
        }
}


long Perevert(long x)
{
    long y = 0;

 while (x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}
