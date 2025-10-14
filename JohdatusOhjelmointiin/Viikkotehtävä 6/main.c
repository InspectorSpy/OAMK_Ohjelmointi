#include <stdio.h>
#include <locale.h>
#include <string.h>

// Tehtävä 1 alku
/*
Kirjoita ohjelma, joka kysyy käyttäjän nimen ja tallentaa sen tiedostoon.
*/
void saveName() {
    char name1[100];
    FILE *file = fopen("name1.txt", "w");
    if (file == NULL) {
        printf("Tiedoston avaaminen epäonnistui.\n");
        return;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

    printf("Anna nimesi: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = 0; // Poista rivinvaihto

    fprintf(file, "Nimi: %s\n", name1);
    fclose(file);
    printf("Nimi tallennettu tiedostoon name1.txt\n");
}
// Tehtävä 1 loppu

// Tehtävä 2 alku
/*
Luo jollain editorilla (esim. Notepad) tiedosto nimeltään source.txt jossa seuraavat tiedot:
Matti, Mainio, Oulu, 28
Jussi, Jonio, Turku, 32
Liisa, Joki, Tampere, 24
Aino, Virta, Oulu, 23
Liisa, Joki, Tampere, 28

Kirjoita sitten ohjelma, joka lukee tiedostoa ja kirjoittaa uuden tiedoston nimeltä target.txt,
jossa aikki pilkut on korvattu puolipisteellä:
*/
void lueTiedosto() {
    FILE *sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        printf("source.txt tiedoston avaaminen epäonnistui.\n");
        return;
    }

    FILE *targetFile = fopen("target.txt", "w");
    if (targetFile == NULL) {
        printf("target.txt tiedoston luominen epäonnistui.\n");
        fclose(sourceFile);
        return;
    }

    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (ch == ',') {
            fputc(';', targetFile);
        } else {
            fputc(ch, targetFile);
        }
    }

    fclose(sourceFile);
    fclose(targetFile);
    printf("Tiedot kopioitu tiedostoon target.txt\n");
}
// Tehtävä 2 loppu

// Tehtävä 3 alku
/*
Kirjoita ohjelma, joka laskee tiedostossa olevien sanojen ja rivien määrän.
Käytetään sääntönä, että sanojen erottimena toimii vain välilyönti.
*/
void laskeTiedosto() {
    FILE *file = fopen("source.txt", "r");
    if (file == NULL) {
        printf("Tiedoston avaaminen epäonnistui.\n");
        return;
    }

    int ch;
    int wordCount = 0;
    int lineCount = 0;
    int inWord = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            wordCount++;
        }
    }

    // Jos tiedosto ei ole tyhjä, lisää viimeinen rivi
    if (ch != '\n' && lineCount > 0) {
        lineCount++;
    }

    fclose(file);
    printf("Rivien määrä: %d\n", lineCount);
    printf("Sanojen määrä: %d\n", wordCount);
}
// Tehtävä 3 loppu

//Tehtävä 4 alku
/*
Kirjoita ohjelma, jossa on tietue nimeltään Student, jossa seuraavat kentät:
• id INT
• name CHAR(50)
• age INT
Luo Student-tyyppinen taulukko, johon voidaan tallentaa 5 alkiota.
Lisää koodi, jolla käyttäjältä kysellään viiden opiskelijan tiedot ja ne tallennetaan em. taulukkoon.
Lisää koodi, jolla em. opiskelijoiden tiedot tulostetaan ruudulle.
*/
void studentTietue() {
    typedef struct {
        int id;
        char name[50];
        int age;
    }
    Student;

    Student students[5];

    for (int i = 0; i < 5; i++) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

        printf("Anna opiskelijan %d ID: ", i + 1);
        scanf("%d", &students[i].id);

        while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

        printf("Anna opiskelijan %d nimi: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        printf("Anna opiskelijan %d ikä: ", i + 1);
        scanf("%d", &students[i].age);
    }

    printf("\nOpiskelijoiden tiedot:\n");
    for (int i = 0; i < 5; i++) {
        printf("Opiskelija %d:\n",i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Nimi: %s\n", students[i].name);
        printf("Ikä: %d\n", students[i].age);
    }
}
// Tehtävä 4 loppu

// Tehtävä 5 alku
/*
Kirjoita ohjelma, joka toimii kuten edellinen sovellus, mutta lopuksi ohjelma kysyy:
• Haluatko tallentaa tiedot (kyllä=1 / ei=2?
• Jos käyttäjä vastaa 1 eli kyllä), tiedot kirjoitetaan tiedostoon nimeltä: /temp/students_data.txt siten, että
• Kunkin opiskelijan tiedot kirjoitetaan omalle rivilleen
• Kenttien väliin tulee pilkku
• Tarkista esim. Notepadilla, että tiedoston muoto on oikein.
*/
void studentTietue2() {
    typedef struct {
        int id;
        char name[50];
        int age;
    }
    Student;

    Student students[5];

    for (int i = 0; i < 5; i++) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

        printf("Anna opiskelijan %d ID: ", i + 1);
        scanf("%d", &students[i].id);

        while ((c = getchar()) != '\n' && c != EOF); // Tyhjennä syöte

        printf("Anna opiskelijan %d nimi: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        printf("Anna opiskelijan %d ikä: ", i + 1);
        scanf("%d", &students[i].age);
    }

    int saveChoice;
    printf("Haluatko tallentaa tiedot (kyllä=1 / ei=2)? ");
    scanf("%d", &saveChoice);

    if (saveChoice == 1) {
        FILE *file = fopen("students_data.txt", "w");
        if (file == NULL) {
            printf("Tiedoston luominen epäonnistui.\n");
            return;
        }

        for (int i = 0; i < 5; i++) {
            fprintf(file, "%d,%s,%d\n", students[i].id, students[i].name, students[i].age);
        }

        fclose(file);
        printf("Tiedot tallennettu tiedostoon students_data.txt\n");
    } else {
        printf("Tiedot eivät tallentuneet.\n");
    }
}
// Tehtävä 5 loppu

// Tehtävä 6 alku
/*
Kirjoita ohjelma, joka kysyy käyttäjältä opiskelijan ID:n. Sitten ohjelma etsii tiedostosta
students_data.txt annettua ID:tä vastaavan opiskelijan tiedot ruudulle, jos annettua ID:tä
ei löydy, tulosta teksti, "Antamaasi ID:tä ei löydy".
*/
void etsiID(int id) {
    typedef struct {
        int id;
        char name[50];
        int age;
    }
    Student;

    FILE *file = fopen("students_data.txt", "r");
    if (file == NULL) {
        printf("Tiedoston avaaminen epäonnistui.\n");
        return;
    }

    Student student;
    int found = 0;

    while (fscanf(file, "%d,%49[^,],%d", &student.id, student.name, &student.age) == 3) {
        if (student.id == id) {
            printf("Opiskelija löydetty:\n");
            printf("ID: %d\n", student.id);
            printf("Nimi: %s\n", student.name);
            printf("Ikä: %d\n", student.age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Antamaasi ID:tä ei löydy.\n");
    }

    fclose(file);
}
// Tehtävä 6 loppu

// Tehtävä 7 alku
/*
Tee silmukka, jota suoritetaan niin kauan kuin tiedostossa on merkkejä.
Lue tiedostosta funktiolla fscanf() rivin ensimmäinen "sana" kokonaislukumuuttujaan id
Lue sitten fgets-funktiolla loppurivi merkkitaulukkoon data
Tutki sitten if-lauseella, vastaako luettu id käyttäjän antamaa arvoa
Jos vastaa tulosta, tulosta data ja lopeta silmukka break-komennolla
*Jos ei vastaa, jatka silmukkaa
*/
void ikiMerkki() {
    int searchId;
    printf("Anna etsittävä ID: ");
    scanf("%d", &searchId);

    etsiID(searchId);
}

// Tehtävä 7 loppu

// Pääohjelma
int main() {
    setlocale(LC_ALL, "");
    int valintaMain;

    while (1) {
        printf("\n--- Ohjelma Menu ---\n");
        printf("1. Tallenna nimi\n");
        printf("2. Lue tiedosto\n");
        printf("3. Laske tiedosto\n");
        printf("4. Opiskelijat\n");
        printf("5. Opiskelijat 2\n");
        printf("6. Etsi ID\n");
        printf("7. Iki merkki\n");
        printf("0. Sulje\n");
        printf("Valitse ohjelma: ");

        if (scanf("%d", &valintaMain) != 1) {
            printf("Virheellinen syöte. Yritä uudelleen.\n");
            while (getchar() != '\n'); // Tyhjennä syöte
            continue;
        }

        switch (valintaMain) {
            case 1: saveName(); break;
            case 2: lueTiedosto(); break;
            case 3: laskeTiedosto(); break;
            case 4: studentTietue(); break;
            case 5: studentTietue2(); break;
            case 6: {
                int searchId;
                printf("Anna opiskelijan ID: ");
                if (scanf("%d", &searchId) == 1) {
                    etsiID(searchId);
                } else {
                    printf("Virheellinen syöte.\n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 7: ikiMerkki(); break;
            case 0: printf("Suljetaan...\n"); return 0;
            default: printf("Väärä valinta. Kokkeile uudelleen.\n"); break;
        }
    }

    return 0;
}