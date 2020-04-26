#include <stdio.h>

long Perevert(long x);
void function(const char* type, long numb ...);

int main() {
    function("lllii", 157757, 423444, 95739, 4567, 2345); 
}

void function(const char* type, long n ...) {
    long* number = &n;
    while (*type) {
        switch (*type) {
            case 'l': 
                printf("%d\t", Perevert(*number));
                break;
            case 'i':
                printf("%d\t", Perevert(*number));
                break;
        }
        type++;
        number++;
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
