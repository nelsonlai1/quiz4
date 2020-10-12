#include <stdio.h>
#include <stdint.h>

uint16_t ecc(uint16_t n)
{
    int flip = 0;
    for (int i = 0; i < 16; i++) {
        if ((n >> i) & 1)
            flip ^= i;
    }
    //printf("%d\n", flip);
    return flip ? n ^ (1 << (15 - flip)) : n;
}
uint16_t encode(uint16_t n)
{
    int mod = 0;
    uint16_t result = n;
    for (int i = 0; i < 16; i++) {
        if ((n >> i) & 1)
            mod ^= i;
    }
    //printf("%d\n", mod);
    while (mod != 0) {
        result ^= (1 << (15 - (mod & -mod)));
        //printf("%d\n", mod & -mod);
        mod ^= (mod & -mod);
    }
    //printf("%d\n", result);
    return result;
}
int main()
{
    uint16_t ori = 7156;
    uint16_t noise, rec;
    printf("original message : ");
    for (int i = 12; i >=0; i--) {
        if (i == 11 || i == 7)
            continue;
        printf("%d", (ori >> i) & 1);
    }
    printf("\n");
    ori = encode(ori);
    noise = ori ^ (1 << 7);
    rec = ecc(noise);
    printf("received message : ");
    for (int i = 12; i >=0; i--) {
        if (i == 11 || i == 7)
            continue;
        printf("%d", (rec >> i) & 1);
    }
    printf("\n");   
}
