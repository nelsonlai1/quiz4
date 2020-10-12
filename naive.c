#include <stdio.h>
int main() {
    char buf[20];
    for (unsigned int i = 1; i <= 100000000; i++) {
        if (i % 3 == 0) sprintf(buf, "Fizz");
        if (i % 5 == 0) sprintf(buf, "Buzz");
        //if (i % 15 == 0) sprintf(buf, "FizzBuzz");
        if ((i % 3) && (i % 5)) sprintf(buf, "%u", i);
    }
    return 0;
}
