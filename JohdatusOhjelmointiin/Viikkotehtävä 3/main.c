#include <stdio.h>
#include <locale.h>
#include <string.h>

// Funktio lämpötilan muunnokselle C2F
void viisiKertaa() {
  int i = 0;
  while (i < 5) {
    printf("100\n");
    i++;
  }
}

void kayttajanNimi() {
  char nimi[30];
  int tulostus, i;

  printf("Anna nimi: \n");
  scanf("%29s", nimi);
  printf("Montako kertaa nimi tulostetaan? . \n");
  scanf("%d", &tulostus);

  printf("\nTulostus while rakenteella\n");
  i = 0;
  while (i < tulostus) {
    printf("%s\n", nimi);
    i++;
  }
}

void salanumero() {
  int numero;
  printf("Anna salanumero: \n");
  scanf("%d", &numero);

  switch(numero) {
  case 17: printf("Oikea vastaus\n"); break;
  default: printf("Väärä vastaus\n"); break;
  }
}

void kymmenKerto() {
  int numero;
  printf("Anna numero: ");
  scanf("%d", &numero);

  int i;
  for (i = 1; i <= 10; i++) {
    printf("%d*%d=%d\n", numero, i, numero * i);
  }
}

void kokonaisLuku() {
  int luku, summa = 0;
  printf("Anna kokonaisluku: ");
  scanf("%d", &luku);

  for (int i = 0; i <= luku; i++) {
      if(i % 2 == 0) {
          summa += i;
      }
  }
  printf("Lukujen summa on: %d\n", summa);
}

void valikkoCase() {
  int valinta;
  while (valinta != 0)
  {
      printf("Valikko:\n");
      printf("1. Neliön kehän pituus\n");
      printf("2. Ympyrän kehän pituus\n");
      printf("0. Lopeta\n");
      printf("Valitse ohjelma: ");
      scanf("%d", &valinta);

  switch (valinta) {
      case 1: printf("Neliön kehän pituus valittu\n"); break;
      case 2: printf("Ympyrän kehän pituus valittu\n"); break;
      case 0: printf("Suljetaan...\n"); break;
      default: printf("Väärä valinta. Yritä uudelleen.\n"); break;
    }
  }
}

int main() {
    setlocale(LC_ALL, "");
    int valinta;

    while (1) {
        printf("\n--- Ohjelma Menu ---\n");
        printf("1. Viisi kertaa\n");
        printf("2. Käyttäjän nimi\n");
        printf("3. Salanumero\n");
        printf("4. Kymmenen kertaa\n");
        printf("5. Kokonaislukujen summa\n");
        printf("6. Valikko case\n");
        printf("0. Sulje\n");
        printf("Valitse ohjelma: ");
        scanf("%d", &valinta);

        switch (valinta) {
            case 1: viisiKertaa(); break;
            case 2: kayttajanNimi(); break;
            case 3: salanumero(); break;
            case 4: kymmenKerto(); break;
            case 5: kokonaisLuku(); break;
            case 6: valikkoCase(); break;
            case 0: printf("Suljetaan...\n"); return 0;
            default: printf("Väärä valinta. Kokkeile uudelleen.\n"); break;
        }
    }

    return 0;
}
