
#include <iostream>
#include "PhoneBook.h"

int main() {
    PhoneBook book;

    int choice;

    char name[100];
    char home[30];
    char work[30];
    char mobile[30];
    char info[200];

    do {
        std::cout << "\n===== PHONE BOOK =====\n";
        std::cout << "1. Add abonent\n";
        std::cout << "2. Delete abonent\n";
        std::cout << "3. Search abonent\n";
        std::cout << "4. Show all abonents\n";
        std::cout << "5. Save to file\n";
        std::cout << "6. Load from file\n";
        std::cout << "0. Exit\n";

        std::cout << "\nChoose: ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch (choice) {

        case 1:
            std::cout << "Enter PIB: ";
            std::cin.getline(name, 100);

            std::cout << "Enter home phone: ";
            std::cin.getline(home, 30);

            std::cout << "Enter work phone: ";
            std::cin.getline(work, 30);

            std::cout << "Enter mobile phone: ";
            std::cin.getline(mobile, 30);

            std::cout << "Enter additional info: ";
            std::cin.getline(info, 200);

            book.AddAbonent(name, home, work, mobile, info);
            break;

        case 2:
            std::cout << "Enter PIB to delete: ";
            std::cin.getline(name, 100);

            book.DeleteAbonent(name);
            break;

        case 3:
            std::cout << "Enter PIB to search: ";
            std::cin.getline(name, 100);

            book.SearchAbonent(name);
            break;

        case 4:
            book.ShowAll();
            break;

        case 5:
            book.SaveToFile();
            break;

        case 6:
            book.LoadFromFile();
            break;

        case 0:
            std::cout << "\nGoodbye\n";
            break;

        default:
            std::cout << "\nWrong choice\n";
        }

    } while (choice != 0);

    return 0;
}
