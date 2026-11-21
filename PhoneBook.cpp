#include "PhoneBook.h"
#include <fstream>


Abonent::Abonent(const char* n, const char* h,
    const char* w, const char* m, const char* i)
    : name(new char[strlen(n) + 1]) {

    strcpy_s(name, strlen(n) + 1, n);
    strcpy_s(homePhone, h);
    strcpy_s(workPhone, w);
    strcpy_s(mobilePhone, m);
    strcpy_s(info, i);
}


Abonent::~Abonent() {
    delete[] name;
}


void Abonent::Show() const {
    std::cout << "\nPIB: " << name;
    std::cout << "\nHome phone: " << homePhone;
    std::cout << "\nWork phone: " << workPhone;
    std::cout << "\nMobile phone: " << mobilePhone;
    std::cout << "\nAdditional info: " << info << "\n";
}


PhoneBook::PhoneBook()
    : abonents(new Abonent* [2]), count(0), capacity(2) {
}


PhoneBook::~PhoneBook() {
    for (int i = 0; i < count; ++i) {
        delete abonents[i];
    }

    delete[] abonents;
}


void PhoneBook::AddAbonent(const char* name, const char* home,
    const char* work, const char* mobile, const char* info) {

    if (count == capacity) {
        capacity *= 2;

        Abonent** temp = new Abonent * [capacity];

        for (int i = 0; i < count; ++i) {
            temp[i] = abonents[i];
        }

        delete[] abonents;
        abonents = temp;
    }

    abonents[count] = new Abonent(name, home, work, mobile, info);
    ++count;

    std::cout << "\nAbonent added\n";
}


void PhoneBook::DeleteAbonent(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(abonents[i]->GetName(), name) == 0) {

            delete abonents[i];

            for (int j = i; j < count - 1; ++j) {
                abonents[j] = abonents[j + 1];
            }

            --count;

            std::cout << "\nAbonent deleted\n";
            return;
        }
    }

    std::cout << "\nAbonent not foun\n";
}


void PhoneBook::SearchAbonent(const char* name) const {
    for (int i = 0; i < count; ++i) {
        if (strcmp(abonents[i]->GetName(), name) == 0) {
            abonents[i]->Show();
            return;
        }
    }

    std::cout << "\nAbonent not found\n";
}


void PhoneBook::ShowAll() const {
    if (count == 0) {
        std::cout << "\nPhone book is empty\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        abonents[i]->Show();
    }
}


void PhoneBook::SaveToFile() const {
    std::ofstream file("phonebook.txt");

    if (!file.is_open()) {
        std::cout << "\nFile error\n";
        return;
    }

    file << count << '\n';

    for (int i = 0; i < count; ++i) {
        file << abonents[i]->GetName() << '\n';
        file << abonents[i]->GetHomePhone() << '\n';
        file << abonents[i]->GetWorkPhone() << '\n';
        file << abonents[i]->GetMobilePhone() << '\n';
        file << abonents[i]->GetInfo() << '\n';
    }

    file.close();

    std::cout << "\nData saved\n";
}


void PhoneBook::LoadFromFile() {
    std::ifstream file("phonebook.txt");

    if (!file.is_open()) {
        std::cout << "\nFile not found\n";
        return;
    }

    int amount;
    file >> amount;
    file.ignore(1000, '\n');

    if (!file || amount < 0) {
        std::cout << "\nFile error\n";
        return;
    }

 
    for (int i = 0; i < count; ++i) {
        delete abonents[i];
    }

    count = 0;

    char name[100];
    char home[30];
    char work[30];
    char mobile[30];
    char info[200];

    for (int i = 0; i < amount; ++i) {

        if (!file.getline(name, 100)) break;
        if (!file.getline(home, 30)) break;
        if (!file.getline(work, 30)) break;
        if (!file.getline(mobile, 30)) break;
        if (!file.getline(info, 200)) break;

        AddAbonent(name, home, work, mobile, info);
    }

    file.close();

    std::cout << "\nData loaded\n";
}
