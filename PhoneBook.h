#pragma once

#include <iostream>
#include <cstring>

class Abonent {
private:
    char* name;
    char homePhone[30];
    char workPhone[30];
    char mobilePhone[30];
    char info[200];

public:
    explicit Abonent(const char* n, const char* h,
        const char* w, const char* m, const char* i);

    ~Abonent();

    void Show() const;

  
    const char* GetName() const {
        return name;
    }

    const char* GetHomePhone() const {
        return homePhone;
    }

    const char* GetWorkPhone() const {
        return workPhone;
    }

    const char* GetMobilePhone() const {
        return mobilePhone;
    }

    const char* GetInfo() const {
        return info;
    }
};

class PhoneBook {
private:
    Abonent** abonents;
    int count;
    int capacity;

public:
    PhoneBook();
    ~PhoneBook();

    void AddAbonent(const char* name, const char* home,
        const char* work, const char* mobile, const char* info);

    void DeleteAbonent(const char* name);
    void SearchAbonent(const char* name) const;
    void ShowAll() const;

    void SaveToFile() const;
    void LoadFromFile();

    
    int GetCount() const {
        return count;
    }
};


