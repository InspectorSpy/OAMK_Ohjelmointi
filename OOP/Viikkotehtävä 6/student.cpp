/*
1. Toteuta C++ projektiisi oheisen UML luokkadiagrammin mukainen  Student luokka.
2. Saat tehtävän oheistiedostona kuvan mukaisen pääohjelmatiedoston. Kopioi siitä tehtävät C++ projektiisi main.cpp tiedostoon ja tee case 0,1,2,3 ja 4 kohtiin määritetyt tehtävät.
*/

#include <iostream>
#include "student.h"

using namespace std;

Student::Student(string name, int age) : name(name), age(age) {

}

string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

void Student::printStudentInfo() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}