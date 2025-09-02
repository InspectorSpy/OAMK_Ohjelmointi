#include <stdio.h>
#include <locale.h>
#include <string.h>

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

// Valitse viikonpäivä
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

// Laske kuukauden ostojen alennukset
void kuukaudenOstot() {
  float ostot, alennus_prosentti, alennukset, lopullinen;
  printf("Kuukauden ostosten määrä: ");
  scanf("%f", &ostot);
  if (ostot < 100) {
      alennus_prosentti = 10;
  } else if (ostot < 300) {
      alennus_prosentti = 15;
  } else if (ostot < 100) {
      alennus_prosentti = 10;
  } else {
      alennus_prosentti = 25;
}
  alennukset = ostot * (alennus_prosentti / 100);
  lopullinen = ostot - alennukset;
  printf("Olet ostanut %.2f€:lla ja saanut alennusta %.0f%%. ",
        ostot, alennus_prosentti);
  printf("Ostosten lopullinen summa on %.2f€\n", lopullinen);
}

// Tulosta opiskelijan suoritusten keskiarvo yms
void opiskelijaID() {
// __ Versio 1 taulukoilla __ //
/* char nimi[30], id[10];
  int suorite[3];
  float keskiarvo;

  printf("ID: ");
  scanf("%s", &id);

  printf("Nimi: ");
  scanf("%s", &nimi);

  printf("Kurssi 1 arvosana: \n");
  scanf("%d", &suorite[0]);

  printf("Kurssi 2 arvosana: \n");
  scanf("%d", &suorite[1]);

  printf("Kurssi 3 arvosana: \n");
  scanf("%d", &suorite[2]);

  keskiarvo = ((float)suorite[1] + (float)suorite[1] + (float)suorite[2]) / 3;

  printf("ID: %s\ņNimi: %s\nSuorite1: %d\nSuorite2: %d\nSuorite3 %d\nPisteet yhteensä: %d\nKeskiarvo = %.2f", id, nimi, suorite[0], suorite[1], suorite[2], (suorite[0] + suorite[1] + suorite[2]), keskiarvo);

  if (keskiarvo >= 80) {
    printf("\nArvosana = Kiitettävä");
  } else if (keskiarvo >= 60) {
    printf("\nArvosana = Hyvä");
  } else if (keskiarvo >= 40) {
    printf("\nArvosana = Tyydyttävä");
  } else {
    printf("\nArvosana = Hylätty");
  } */

  // __ Versio 2 ilman taulukkoja strcpyllä __ //
  // (kopio tieto kohteesta A kohteeseen B) //

  /*int id, suorite1, suorite2, suorite3, pisteet;
  char nimi[100], arvosana[20];
  float keskiarvo;

  printf("Anna ID: ");
  scanf("%d", &id);
  printf("Anna nimi: ");
  scanf(" %[^\n]", nimi);
  printf("Suoritus 1 pisteet (0-100): ");
  scanf("%d", &suorite1);
  printf("Suoritus 2 pisteet (0-100): ");
  scanf("%d", &suorite2);
  printf("Suoritus 3 pisteet (0-100): ");
  scanf("%d", &suorite3);

  pisteet = suorite1 + suorite2 + suorite3;
  keskiarvo = (float)pisteet / 3.0;

  if (keskiarvo >= 80) {
    strcpy(arvosana, "Kiitettävä");
  } else if (keskiarvo >= 60) {
    strcpy(arvosana, "Hyvä");
  } else if (keskiarvo >= 40) {
    strcpy(arvosana, "Välttävä");
  } else {
    strcpy(arvosana, "Hylätty");
  }

  printf("IDnumero: %d\n", id);
  printf("Nimi: %s\n", nimi);
  printf("Suorite 1: %d\n", suorite1);
  printf("Suorite 2: %d\n", suorite2);
  printf("Suorite 3: %d\n", suorite3);
  printf("Pisteet yhteensä: %d\n", pisteet);
  printf("Keskiarvo: %.2f\n", keskiarvo);
  printf("Arvosana: %s\n", arvosana);*/

  // __ Versio 3, v1 ja v2 yhdistetty __ //

  char nimi[30], id[10];
  int suorite[3];
  int yhteispisteet = 0;
  float keskiarvo;

  char arvosanat[][15] = {"Hylätty", "Välttävä", "Hyvä", "Kiitettävä"};
  int rajat[] = {0, 40, 60, 80};

  printf("Anna ID: ");
  scanf("%s", id);
  printf("Anna nimi: ");
  scanf(" %[^\n]", nimi);

  for (int i = 0; i < 3; i++) {
    printf("Suoritus %d pisteet (0-100): ", i + 1);
    scanf("%d", &suorite[i]);
    yhteispisteet += suorite[i];
  }

  keskiarvo = (float)yhteispisteet / 3.0;

  char arvosana_teksti[15];
  if (keskiarvo >= 80) {
      strcpy(arvosana_teksti, "Kiitettävä");
  } else if (keskiarvo >= 60) {
      strcpy(arvosana_teksti, "Hyvä");
  } else if (keskiarvo >= 40) {
      strcpy(arvosana_teksti, "Välttävä");
  } else {
      strcpy(arvosana_teksti, "Hylätty");
  }

  printf("\nIDnumero : %s\n", id);
  printf("Opiskelijan nimi : %s\n", nimi);
  for (int i = 0; i < 3; i++) {
      printf("Osasuoritus%d : %d\n", i + 1, suorite[i]);
  }
  printf("Pisteet yhteensä = %d\n", yhteispisteet);
  printf("Keskiarvo = %.2f\n", keskiarvo);
  printf("Arvosana = %s\n", arvosana_teksti);
}

int main() {
    setlocale(LC_ALL, "");
    int valinta;

    while (1) {
        printf("\n--- Ohjelma Menu ---\n");
        printf("1. Vertailu <=> 10\n");
        printf("2. Vertaile numeroita\n");
        printf("3. Viikonpäivä\n");
        printf("4. Kuukausi ostokset\n");
        printf("5. OpiskelijaID\n");
        printf("0. Sulje\n");
        printf("Valitse ohjelma: ");
        scanf("%d", &valinta);

        switch (valinta) {
            case 1: vertaile10(); break;
            case 2: vertaileLukuja(); break;
            case 3: viikonpaiva(); break;
            case 4: kuukaudenOstot(); break;
            case 5: opiskelijaID(); break;
            case 0: printf("Suljetaan...\n"); return 0;
            default: printf("Väärä valinta. Kokkeile uudelleen.\n"); break;
        }
    }

    return 0;
}
