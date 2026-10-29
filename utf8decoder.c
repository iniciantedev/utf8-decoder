#include <stdio.h>
#include <stdlib.h>

int char_decode(const unsigned char* c, unsigned int* cp) {
    unsigned int c0 = c[0];
    if ((c0 >> 7) == 0){
        cp[0] = c0;
        return 1;
    }
    if ((c0 >> 5) == 0b110) {
        unsigned int c1 = c[1];
        cp[0] = ((c0 & 0b00011111) << 6 |
              (c1 & 0b00111111));
        return 2;
    }
    if ((c0 >> 4) == 0b1110) {
        unsigned int c1 = c[1];
        unsigned int c2 = c[2];
        cp[0] = ((c0 & 0b00001111) << 12 |
              (c1 & 0b00111111) << 6 |
              (c2 & 0b00111111));
        return 3;
    }
    if ((c0 >> 3) == 0b11110) {
        unsigned int c1 = c[1];
        unsigned int c2 = c[2];
        unsigned int c3 = c[3];
        cp[0] = ((c0 & 0b00000111) << 18 |
              (c1 & 0b00111111) << 12 |
              (c2 & 0b00111111) << 6 |
              (c3 & 0b00111111));
        return 4;
    }

return 0;
}

int main()
{
    //const unsigned char c[] = {0xC3, 0xA7, 0};
    const unsigned char* c = (const unsigned char*) "ç";

    unsigned int cp = 0;
    int retorno = char_decode(c, &cp);
    printf("value U+%x\n size %d bytes\n", cp, retorno);
    return 0;
}
