#include "Headers/backtrack_functions.h"

int main() {
    /*
     * 1. n elembol allo novekvo reszsorozat
     * 2. gen ki az 5 betus maganhangzokbol allo szavakat
     * 3. gen ki az osszes olyan szamot amely szamjegyeinek osszege <= beolvasott osszeg
     * 4. gen ki az osszes 3 szinu zaszlot mely a szin (Fekete, feher, piros, zold, kek, sarga) es a kozepso szin feher vagy fekete*/
    int n;
    printf("n=");
    scanf("%d", &n);
    char *d = "123456789";
    char s[n+1];
    s[n] = '\0';
    //feladat1(n, 0, d, s);
    //feladat2("aeiou", s, 0);
    int ossz;
    //printf("Osszeg:");
    //scanf("%d", &ossz);
    //feladat3(n, ossz, 0,0);
    //feladat4();
    return 0;
}
