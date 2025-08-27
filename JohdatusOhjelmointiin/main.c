#include <stdio.h>
#include <locale.h>

// Funktio lämpötilan muunnokselle C2F
void C2F() {
    float cels;
    printf("Write your temperature here (Celsius): ");
    scanf("%f", &cels);
    float fahren = (cels * 1.80) + 32.0;
    printf("%.2f cels equals around %.2f fahren\n", cels, fahren);
}

// Funktio kolmion pinta-alalle
void kolmionAla() {
    int kanta, korkeus, ala;
    printf("Kolmion kanta: ");
    scanf("%d", &kanta);
    printf("Kolmion korkeus on: ");
    scanf("%d", &korkeus);
    ala = (korkeus * kanta) / 2;
    printf("Kolmion ala on: %d", ala);
}

// Funktio peruslaskuille
void perusLaskut() {
    int luku1, luku2, summa, erotus, tulo;
    float osamaara;

    printf("Syötä ensimmäinen luku: ");
    scanf("%d", &luku1);
    printf("Syötä toinen luku: ");
    scanf("%d", &luku2);

    summa = luku1 + luku2;
    erotus = luku1 - luku2;
    tulo = luku1 * luku2;
    osamaara = (float)luku1 / luku2;

    printf("Lukujen summa on: %d\n", summa);
    printf("Lukujen erotus on: %d\n", erotus);
    printf("Lukujen tulo on: %d\n", tulo);
    printf("Lukujen osamäärä on: %.2f\n", osamaara);
}

// Funktio taululle 3x3
void taulukko() {
    int taulukko[3][3];
    printf("Syötä luvut 3x3 taulukkoon:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Anna luku riville %d, sarakkeelle %d: ", i + 1, j + 1);
            scanf("%d", &taulukko[i][j]);
        }
    }
    printf("\nTaulukon 1. rivin luku on %d\n", taulukko[0][2]);
    printf("Taulukon 2. rivin luku on %d\n", taulukko[1][1]);
    printf("Taulukon 3. rivin luku on %d\n", taulukko[2][0]);
}

// Funktio <=> 10
void vertaile10() {
    int luku1;
    printf("Anna kokonaisluku: ");
    scanf("%d", &luku1);
    if (luku1 < 10)
        printf("Antamasi luku on pienempi kuin 10.\n");
    else if (luku1 > 10)
        printf("Lukusi on suurempi kuin 10.\n");
    else
        printf("Lukusi on yhtäsuuri kuin 10.\n");
}

// Funktio lukujen vertailuun
void vertaileLukuja() {
    int luku1, luku2;
    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &luku1);
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku2);

    if (luku1 > luku2)
        printf("Ensimmäinen luku on suurempi kuin toinen luku.\n");
    else if (luku1 < luku2)
        printf("Toinen luku on suurempi kuin ensimmäinen luku.\n");
    else
        printf("Luvut ovat yhtäsuuria.\n");
}

void viikonpaiva() {
    int paiva;
    printf("Anna viikonpäivän numero (1-7): ");
    scanf("%d", &paiva);

    switch(paiva) {
        case 1: printf("Maanantai\n"); break;
        case 2: printf("Tiistai\n"); break;
        case 3: printf("Keskiviikko\n"); break;
        case 4: printf("Torstai\n"); break;
        case 5: printf("Perjantai\n"); break;
        case 6: printf("Lauantai\n"); break;
        case 7: printf("Sunnuntai\n"); break;
        default: printf("Annoit numeron, jolle ei ole viikonpäivää\n"); break;
    }
}

int main() {
    setlocale(LC_ALL, "");
    int valinta;

    while (1) {
        printf("\n--- Ohjelma Menu ---\n");
        printf("1. Cels 2 Fahren\n");
        printf("2. Kolmion ala\n");
        printf("3. Peruslaskut\n");
        printf("4. 3x3 taulukko\n");
        printf("5. Vertailu <=> 10\n");
        printf("6. Vertaile numeroita\n");
        printf("7. Viikonpäivä\n");
        printf("0. Sulje\n");
        printf("Valitse ohjelma: ");
        scanf("%d", &valinta);

        switch (valinta) {
            case 1: C2F(); break;
            case 2: kolmionAla(); break;
            case 3: perusLaskut(); break;
            case 4: taulukko(); break;
            case 5: vertaile10(); break;
            case 6: vertaileLukuja(); break;
            case 7: viikonpaiva(); break;
            case 0: printf("Suljetaan...\n"); return 0;
            default: printf("Väärä valinta. Kokkeile uudelleen.\n"); break;
        }
    }

    return 0;
}
