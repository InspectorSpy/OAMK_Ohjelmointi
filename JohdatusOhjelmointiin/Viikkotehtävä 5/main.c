#include <stdio.h>
#include <locale.h>
#include <string.h>

// Vaihdoin testimielessä scanf() toiminnon fgets() toimintoon näissä tehtävissä.

// Tehtävä 1 alku
/*
Kirjoita ohjelma, -jossa on tietue nimeltään Car, jossa seuraavat kentät:
• brand CHAR(20)
• model CHAR(50)
• yearModel INT
-luo Car-tyyppinen muuttuja nimeltään car_1
-lisää koodi, jossa käyttäjältä kysytään car_1:n tiedot
-lisää koodi, jolla tulostetaan car_1:n tiedo
*/
typedef struct{
    char brand[20];
    char model[50];
    int yearModel;
} Car;

void autoTietue() {
    Car car_1;

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte
    
    printf("Anna auton merkki: ");
    fgets(car_1.brand, sizeof(car_1.brand), stdin);
    car_1.brand[strcspn(car_1.brand, "\n")] = 0;

    printf("Anna auton malli: ");
    fgets(car_1.model, sizeof(car_1.model), stdin);
    car_1.model[strcspn(car_1.model, "\n")] = 0;

    printf("Anna auton vuosimalli: ");
    scanf("%d", &car_1.yearModel);

    printf("\nAuton tiedot:\n");
    printf("Merkki: %s\n", car_1.brand);
    printf("Malli: %s\n", car_1.model);
    printf("Vuosimalli: %d\n", car_1.yearModel);
}
// Tehtävä 1 loppu

// Tehtävä 2 alku
/*
Kirjoita ohjelma, jossa on samanlainen tietue Car kuin edellä.
Luo Car-tyyppinen taulukko, johon voidaan tallentaa 3 alkiota.
Lisää koodi, jolla käyttäjältä kysellään kolmen auton tiedot ja ne tallennetaan em. taulukkoon.
Lisää koodi, jolla em. autojen tiedot tulostetaan ruudulle.
*/
void autoTietue2() {
    Car cars[3];

    for (int i = 0; i < 3; i++) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

        printf("Anna auton %d merkki: ", i + 1);
        fgets(cars[i].brand, sizeof(cars[i].brand), stdin);
        cars[i].brand[strcspn(cars[i].brand, "\n")] = 0;

        printf("Anna auton %d malli: ", i + 1);
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        cars[i].model[strcspn(cars[i].model, "\n")] = 0;

        printf("Anna auton %d vuosimalli: ", i + 1);
        scanf("%d", &cars[i].yearModel);
    }

    printf("\nAutotiedot:\n");
    for (int i = 0; i < 3; i++) {
        printf("Auto %d:\n", i + 1);
        printf("Merkki: %s\n", cars[i].brand);
        printf("Malli: %s\n", cars[i].model);
        printf("Vuosimalli: %d\n\n", cars[i].yearModel);
    }
}
// Tehtävä 2 loppu

// Tehtävä 3 alku
/*
Kirjoita ohjelma, joka toimii kuten edellinen sovellus, mutta
nyt kysytään viiden auton tiedot
autojen tietoja ei tulosteta ruudulle
kun autojen tiedot on annettu käyttäjältä kysytään auton merkki(brand) ja tulostetaan kaikki
kyseisen merkin autojen tiedot. Käyttäjältä kysellään merkkiä, kunnes hän antaa merkiksi
”LOPETA”.
*/
void autoTietue3() {
    Car cars[5];
    char brandSearch[20];

    for (int i = 0; i < 5; i++) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

        printf("Anna auton %d merkki: ", i + 1);
        fgets(cars[i].brand, sizeof(cars[i].brand), stdin);
        cars[i].brand[strcspn(cars[i].brand, "\n")] = 0;

        printf("Anna auton %d malli: ", i + 1);
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        cars[i].model[strcspn(cars[i].model, "\n")] = 0;

        printf("Anna auton %d vuosimalli: ", i + 1);
        scanf("%d", &cars[i].yearModel);
    }

    while (1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

        printf("Anna haettavan auton merkki (tai 'LOPETA' lopettaaksesi): ");
        fgets(brandSearch, sizeof(brandSearch), stdin);
        brandSearch[strcspn(brandSearch, "\n")] = 0;

        if (strcmp(brandSearch, "LOPETA") == 0) {
            printf("Lopetetaan...\n");
            break;
        }

        int found = 0;
        for (int i = 0; i < 5; i++) {
            if (strcmp(cars[i].brand, brandSearch) == 0) {
                printf("Auto %d:\n", i + 1);
                printf("Merkki: %s\n", cars[i].brand);
                printf("Malli: %s\n", cars[i].model);
                printf("Vuosimalli: %d\n\n", cars[i].yearModel);
                found = 1;
            }
        }

        if (!found) {
            printf("Ei löytynyt autoja merkille: %s\n", brandSearch);
        }
    }
}
// Tehtävä 3 loppu

// Tehtävä 4 alku
/*
Tee aliohjelma tulostaPaikallinenOsoite.
Aliohjelma luo paikallisen merkkijonotaulukon nimeltään "lisatiedot" ja täyttää sen käyttäjän
syötteellä.
Sen jälkeen aliohjelma tulostaa merkkijonon 1. merkin ja lopetusmerkin (arvo 0 tai merkki ’\0’)
osoitteen muistissa.
"Lisatiedot-merkkijonon 1. merkin osoite on: ... ja lopetusmerkin osoite on: ..."
*/
void paikallinenOsoite() {
    char lisatiedot[100];

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

    printf("Anna lisatiedot: ");
    fgets(lisatiedot, sizeof(lisatiedot), stdin);
    lisatiedot[strcspn(lisatiedot, "\n")] = 0;

    printf("Lisatiedot-merkkijonon 1. merkin osoite on: %p\n", (void*)&lisatiedot[0]);

    int pituus = strlen(lisatiedot);
    printf("Lopetusmerkin osoite on: %p\n", (void*)&lisatiedot[pituus]);
}
// Tehtävä 4 loppu

// Tehtävä 5 alku
/*
Tee edellinen ohjelma siten, että merkkijonotaulukko luodaan ja täytetään pääohjelmassa.
Siirrä sitten merkkijonotaulukon alkuosoite aliohjelmalle ”tulostaPointteri”. Ota osoite vastaan
osoittimena char-tyyppiin (char* merkkiPointteri). Pointterin osoittama osoite on merkkiPointteri
ja sen osoittama arvo on *merkkiPointteri.
Pointteria voi liikuttaa muistissa "++" -operaattorilla.
Tulosta samat asiat kuin edellisessä tehtävässä.
*/
void paikallinenOsoite2() {
    char* merkkiPointteri;
    printf("Lisatiedot-merkkijonon 1. merkin osoite on: %p\n", (void*)merkkiPointteri);

    while (*merkkiPointteri != '\0') {
        merkkiPointteri++;
    }

    printf("Lopetusmerkin osoite on: %p\n", (void*)merkkiPointteri);
}
// Tehtävä 5 loppu

// Pääohjelma
int main() {
    setlocale(LC_ALL, "");
    int valintaMain;

    while (1) {
        printf("\n--- Ohjelma Menu ---\n");
        printf("1. Autot\n");
        printf("2. Autot 2\n");
        printf("3. Autot 3\n");
        printf("4. Paikallinen osoite\n");
        printf("5. Paikallinen osoite 2\n");
        printf("0. Sulje\n");
        printf("Valitse ohjelma: ");

        if (scanf("%d", &valintaMain) != 1) {
            printf("Virheellinen syöte. Yritä uudelleen.\n");
            while (getchar() != '\n'); // Tyhjennä syöte
            continue;
        }

        switch (valintaMain) {
            case 1: autoTietue(); break;
            case 2: autoTietue2(); break;
            case 3: autoTietue3(); break;
            case 4: paikallinenOsoite(); break;
            case 5: paikallinenOsoite2(); break;
            case 0: printf("Suljetaan...\n"); return 0;
            default: printf("Väärä valinta. Kokkeile uudelleen.\n"); break;
        }
    }

    return 0;
}