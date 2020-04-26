#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

long Perevert(long x);
void function(const char* type, ...);

int main() {
    function("llill", 157757, 423444, 95739, 4567, 2345); 
}

void function(const char* type, ...) {
    va_list p;
    va_start(p, type);
    while (*type) {
        switch (*type) {
            case 'l': 
                printf("%d\t", Perevert(va_arg(p, long)));
                break;
            case 'i':
                printf("%d\t", Perevert(va_arg(p, int)));
                break;
        }
        type++;
    }
    va_end(p);
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
