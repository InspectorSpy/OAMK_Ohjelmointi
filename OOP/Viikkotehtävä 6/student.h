/*
1. Toteuta C++ projektiisi oheisen UML luokkadiagrammin mukainen  Student luokka.
2. Saat tehtävän oheistiedostona kuvan mukaisen pääohjelmatiedoston. Kopioi siitä tehtävät C++ projektiisi main.cpp tiedostoon ja tee case 0,1,2,3 ja 4 kohtiin määritetyt tehtävät.
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
    private:
        string name;
        int age;
    public:
        Student(string name, int age);
        string getName() const;
        int getAge() const;
        void printStudentInfo() const;
};

#endif