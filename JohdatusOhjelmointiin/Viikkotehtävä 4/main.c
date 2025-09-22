#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

// Tehtävä 1 alku
/*
Tee ohjelma, jossa on pääohjelma (main-funktio) ja aliohjelma (funktio) nimeltä tulosta().
Pääohjelmasta kutsutaan em. aliohjelmaa, joka tulostaa näytölle ”Hei maailma!”.
*/
void helloWorld()
{
    int valinta1 = -1;
    while (valinta1 != 0)
    {
        printf("Hello world!\n");
        printf("Paina 0 lopettaaksesi: ");
        if (scanf("%d", &valinta1) != 1)
        {
            printf("Virheellinen syöte. Yritä uudelleen.\n");
            while (getchar() != '\n')
                ; // Tyhjennä syöte
            valinta1 = -1;
        }
    }
}
// Tehtävä 1 loppu

// Tehtävä 2 alku
/*
Tee ohjelma, jossa on pääohjelma (main-funktio) ja aliohjelma (funktio) nimeltä lue().
Pääohjelmasta kutsutaan em. aliohjelmaa, joka tulostaa näytölle ”Anna kokonaisluku”.
Tässä aliohjelmassa luetaan myös kokonaisluku ja palautetaan se pääohjelmaan, joka
tulostaa luvun näytölle
*/
int lue2() {
    int luku2;
    printf("Anna kokonaisluku: ");
    if (scanf("%d", &luku2) != 1) {
        printf("Virheellinen syöte. Yritä uudelleen.\n");
        while (getchar() != '\n'); // Tyhjennä syöte
    }
    return luku2;
}

void kokonaislukuCase() {
    int valinta = -1;
    while (valinta != 0)
    {
        printf("Valikko:\n");
        printf("1. Anna kokonaisluku\n");
        printf("0. Lopeta\n");
        printf("Valitse ohjelma: ");
        if (scanf("%d", &valinta) != 1) {
            printf("Virheellinen syöte. Yritä uudelleen.\n");
            while (getchar() != '\n'); // Tyhjennä syöte
            continue;
        }

        switch (valinta) {
            case 1:
                printf("Kokonaisluvun valinta:\n");
                int luku1 = lue2();
                printf("Annoit luvun: %d\n", luku1);
                break;
            case 0: printf("Suljetaan...\n"); break;
            default: printf("Väärä valinta. Yritä uudelleen.\n"); break;
        }
    }
}
// Tehtävä 2 loppu

// Tehtävä 3 alku
/*
Muuta edellistä ohjelmaa siten, että lisäät siihen luvunTulostus() nimisen aliohjelman. Tätä
aliohjelmaa kutsutaan pääohjelmasta (sitten, kun luku on luettu) ja siihen välitetään luettu
kokonaisluku. luvunTulostus() aliohjelma tulostaa siihen välitetyn luvun näytölle.
*/
int lue3() {
    int luku3;
    printf("Anna kokonaisluku: ");
    while (scanf("%d", &luku3) != 1) {
        printf("Virheellinen syöte. Yritä uudelleen.\n");
        while (getchar() != '\n'); // Tyhjennä syöte
    }
    return luku3;
}

void luvunTulostus(int luku3) {
    printf("Annoit luvun: %d\n", luku3);
}

void case2Tulostuksella() {
    int valinta3 = -1;
    
    while (valinta3 != 0) {
        printf("Valikko:\n");
        printf("1. Anna kokonaisluku\n");
        printf("0. Lopeta\n");
        printf("Valitse ohjelma: ");
            if (scanf("%d", &valinta3) != 1) {
                printf("Virheellinen syöte. Kokeile uudelleen.\n");
                while (getchar() != '\n'); // Tyhjennä syöte
                continue;
        } 
        switch (valinta3) {
            case 1: {
                printf("Kokonaisluvun valinta:\n");
                int luku3 = lue3();
                luvunTulostus(luku3);
                break;
            }
            case 0: 
                printf("Suljetaan...\n"); 
                break;
            default: 
                break;
        }
    }
}
// Tehtävä 3 loppu

// Tehtävä 4 alku
/*
Tee ohjelma jossa on pääohjelma (main-funktio) sekä yksi funktio eli aliohjelma, joka kysyy
float-luvun käyttäjältä, kertoo luvun kolmella ja palauttaa tuloksen main()-funktiolle, jossa
tulos tulostetaan näytölle.
*/
void kertoFloat() {
float luku4;

printf("Anna luku: ");
scanf("%f", &luku4);

float tulos4 = luku4 * 3;
printf("Luku kerrottuna kolmella: %.2f\n", tulos4);
}

void case4() {
    int valinta4 = -1;
    while (valinta4 != 0)
    {
        printf("Valikko:\n");
        printf("1. Kerro luku kolmella\n");
        printf("0. Lopeta\n");
        printf("Valitse ohjelma: ");
        if (scanf("%d", &valinta4) != 1) {
            printf("\nVirheellinen syöte. Yritä uudelleen.\n");
            while (getchar() != '\n'); // Tyhjennä syöte
            continue;
        }
    
    switch (valinta4) {
        case 1: kertoFloat(); break;
        case 0: printf("Suljetaan...\n"); break;
        default: printf("Väärä valinta. Yritä uudelleen.\n"); break;
        }
    }
}
// Tehtävä 4 loppu

// Tehtävä 5 alku
/*
Tee ohjelma, jossa on funktio vertaile() johon viedään kaksi kokonaislukua. Tämä funktio
vertailee niiden suuruutta ja tulostaa ne suuruusjärjestyksessä näytölle (suurin ensin).
*/
void vertaile(int luku5a, int luku5b)
{
    if (luku5a > luku5b) {
        printf("Suuruusjärjestyksessä (suurin ensin): %d, %d\n", luku5a, luku5b);
    } else if (luku5a < luku5b) {
        printf("Suuruusjärjestyksessä (suurin ensin): %d, %d\n", luku5b, luku5a);
    } else{
        printf("Luvut ovat yhtäsuuria: %d, %d\n", luku5a, luku5b);
    }
}

void vertaileCase() {
    int a, b;

    printf("Anna ensimmäinen kokonaisluku: ");
    while (scanf("%d", &a) != 1) {
        printf("Virheellinen syöte. Yritä uudelleen.\n");
        while (getchar() != '\n'); // Tyhjennä syöte
    }
    printf("Anna toinen kokonaisluku: ");
    while (scanf("%d", &b) != 1) {  
        printf("Virheellinen syöte. Yritä uudelleen.\n");
        while (getchar() != '\n'); // Tyhjennä syöte
    }
    vertaile(a, b);
}
// Tehtävä 5 loppu

// Tehtävä 6 alku
/*
Tee ohjelma joka tulostaa käyttäjälle seuraavan valikon, jossa on kolme vaihtoehtoa:
1. Neliön kehän pituus
2. Ympyrän kehän pituus
9. Lopetus.
Käyttäjä voi valita halutun toiminnan syöttämällä 1,2 tai 9.
Valinta 1 saa aikaan nelioLasku()- funktion kutsun, valinta 2 saa aikaan ympyraLasku()-
funktion kutsun. Em. funktioissa lasketaan ja tulostetaan neliön ja ympyrän kehän pituudet.
Ympyrän kehä lasketaan kaavalla 2*3.14*ympyränSäde. Neliön kehä lasketaan kaavalla
kehänPituus=4*sivunPituus. Muista kysyä funktioissa käyttäjältä tarvittaessa ympyrän säde
ja neliön sivun pituus. Aina kehänpituuden laskennan ja tulostuksen jälkeen valikko
tulostetaan näytölle uudelleen. Valinta 9 lopettaa ohjelman. (Käytä while-toistorakennetta)
*/
void neliöLasku() {
    float sivu;
    printf("Anna neliön sivun pituus: ");
    while (scanf("%f", &sivu) != 1 || sivu <= 0) {
        printf("Virheellinen syöte. Anna positiivinen luku.\n");
        while (getchar() != '\n'); // Tyhjennä syöte
    }
    float keha = 4 * sivu;
    printf("Neliön kehä on: %.2f\n", keha);
}

void ympyräLasku() {
    float sade;
    const float pii = 3.14159;
    printf("Anna ympyrän säde: ");
    while (scanf("%f", &sade) != 1 || sade <= 0) {
        printf("Virheellinen syöte. Anna positiivinen luku.\n");
        while (getchar() != '\n'); // Tyhjennä syöte
    }
    float keha = 2 * pii * sade;
    printf("Ympyrän kehä on: %.2f\n", keha);
}

void valikkoCase() {
  int valinta6 = -1;
  while (valinta6 != 0)
  {
      printf("Valikko:\n");
      printf("1. Neliön kehän pituus\n");
      printf("2. Ympyrän kehän pituus\n");
      printf("0. Lopeta\n");
      printf("Valitse ohjelma: ");
      if (scanf("%d", &valinta6) != 1) {
          printf("Virheellinen syöte. Yritä uudelleen.\n");
          while (getchar() != '\n'); // Tyhjennä syöte
          continue;
      }

  switch (valinta6) {
      case 1: neliöLasku(); break;
      case 2: ympyräLasku(); break;
      case 0: printf("Suljetaan...\n"); break;
      default: printf("Väärä valinta. Yritä uudelleen.\n"); break;
    }
  }
}
// Tehtävä 6 loppu

// Tehtävä 7 alku
/*
Tee ohjelma, jossa välität funktioon merkkijonon (merkkitaulukon), joka on määritelty
paikalliseksi (ei globaali) muuttujaksi. Funktiossa tämä merkkijono tulostetaan näytölle.
*/
void tulostaMerkkijono(const char merkkijono[]) {
    printf("Annoit merkkijonon: %s\n", merkkijono);
}

void jonoCase() {
    char paikallinenMerkkijono[] = "Ohjelmointi on kivaa! (sarkasmia..)";
    tulostaMerkkijono(paikallinenMerkkijono);

    return 0;
}
// Tehtävä 7 loppu

// Tehtävä 8 alku
/*
Tee ohjelma, joka lukee käyttäjän syöttämän kokonaisluvun (int) ja desimaaliluvun (double)
char-taulukkoon. Sitten ohjelma summaa luvut ja tulostaa näyttöön. (Käytä <stdlib.h>
kirjaston atoi()- ja atof()-funktioita, jotka muuttavat merkkijonon luvuksi
int luku=atoi(merkkijono); //muuntaa merkkijonon kokonaisluvuksi
double luku2=atof(merkkijono); //muuntaa merkkijonon double luvuksi)
*/
void intDouble() {
    char merkkijono[2][30];

    printf("Anna kokonaisluku: ");
    scanf("%s", merkkijono[0]);

    printf("Anna desimaaliluku: ");
    scanf("%s", merkkijono[1]);

    int kokonaisluku = atoi(merkkijono[0]);
    double desimaaliluku = atof(merkkijono[1]);

    printf("%d + %.2f = %.2f\n", kokonaisluku, desimaaliluku, kokonaisluku + desimaaliluku);
}
// Tehtävä 8 loppu

int main() {
    setlocale(LC_ALL, "");
    int valintaMain;

    while (1) {
        printf("\n--- Ohjelma Menu ---\n");
        printf("1. Hello world!\n");
        printf("2. Kokonaisluku case (ei käytössä)\n");
        printf("3. Case2 tulostuksella\n");
        printf("4. Kerto float\n");
        printf("5. Vertailu\n");
        printf("6. Neliö | Ympyrä\n");
        printf("7. Merkkijono\n");
        printf("8. Int + Double\n");
        printf("0. Sulje\n");
        printf("Valitse ohjelma: ");

        if (scanf("%d", &valintaMain) != 1) {
            printf("Virheellinen syöte. Yritä uudelleen.\n");
            while (getchar() != '\n'); // Tyhjennä syöte
            continue;
        }

        switch (valintaMain) {
            case 1: helloWorld(); break;
            // case 2: kokonaislukuCase(); break;
            case 3: case2Tulostuksella(); break;
            case 4: case4(); break;
            case 5: vertaileCase(); break;
            case 6: valikkoCase(); break;
            case 7: jonoCase(); break;
            case 8: intDouble(); break;
            case 0: printf("Suljetaan...\n"); return 0;
            default: printf("Väärä valinta. Kokkeile uudelleen.\n"); break;
        }
    }

    return 0;
}