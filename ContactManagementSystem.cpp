#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define Max 1000

struct Contact
{
    std::string name;
    int gender;
    int age;
    std::string phone;
    std::string address;
};

struct ContactBook
{
    std::unordered_map<std::string, Contact> contactMap;
    int contactCount = 0;
};

void menu();
void addContact(ContactBook &, Contact);
void showContacts(ContactBook &);
// int hasContact(ContactBook &, string);
void delContact(ContactBook &);
void findContact(ContactBook &);
void editContact(ContactBook &);
void formatContacts(ContactBook &);

int main()
{
    int select;
    bool appRuns = true;

    // address book instance that contains the hashmap with the Contact struct as its value
    ContactBook contactbook;
    Contact contact;

    // accessing the hashmap and setting its bucket size to Max --> 1000
    contactbook.contactMap.reserve(Max);

    // setting my contact count to 0
    contactbook.contactCount = 0;

    while (appRuns)
    {
        menu();
        std::cin >> select;

        switch (select)
        {
        case 1:
            addContact(contactbook, contact);
            break;

        case 2:
            showContacts(contactbook);
            break;

        case 3:
            delContact(contactbook);
            break;

        case 4:
            findContact(contactbook);
            break;

        case 5:
            editContact(contactbook);
            break;

        case 6:
            formatContacts(contactbook);
            break;

        case 7:
            std::cout << "Thank You For Using Contact Management System! We Hope To See You Again Soon." << std::endl;
            system("pause");
            appRuns = false;
            break;
        }
    }

    system("pause");
    return 0;
}

void menu()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "******  Contact Management System ******" << std::endl;
    std::cout << "******       1. Add Contact        *****" << std::endl;
    std::cout << "******       2. Show Contact       *****" << std::endl;
    std::cout << "******       3. Delete Contact     *****" << std::endl;
    std::cout << "******       4. Find Contact       *****" << std::endl;
    std::cout << "******       5. Edit Contact       *****" << std::endl;
    std::cout << "******       6. Format Contact     *****" << std::endl;
    std::cout << "******       7. Exit               *****" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "****************************************" << std::endl;
}

void addContact(ContactBook &contactbook, Contact contact)
{
    if (contactbook.contactCount == Max)
    {
        std::cout << "Address book is full!" << std::endl;
    }

    else
    {
        // Get name for contact
        std::string getName;
        std::cout << "Enter name: " << std::endl;
        std::cin >> getName;
        std::getline(std::cin, getName);

        // Get age for contact
        int getGender;
        std::cout << "Please enter gender: \n1 --> Male\n2 --> Female" << std::endl;
        std::cin >> getGender;

        // Verify whether the user input a 1 or 2 for the gender
        while (getGender < 1 || getGender > 2)
        {
            std::cout << "Error: you did not answer correctly!" << std::endl;
            std::cout << "Please enter gender: \n1 --> Male\n2 --> Female" << std::endl;
            std::cin >> getGender;
        }

        // Get age for contact
        int getAge;
        std::cout << "Please enter age: " << std::endl;
        std::cin >> getAge;

        // Get phone number for contact
        std::string getPhone;
        std::cout << "Please enter phone number (no spaces): " << std::endl;

        // insert a Try Catch block here just incase a user has a space between its number

        std::cin >> getPhone;
        std::getline(std::cin, getPhone); // just incase the user does enter a space I dont want the code to break

        std::cout << "phone number: " << getPhone << ".length(): " << getPhone.length() << ".size()" << getPhone.size() << std::endl;
        // Makes sure phone numbers is atleast 10-digits
        while (getPhone.length() != 10)
        {
            std::cout << "Error: you did not answer correctly!" << std::endl;
            std::cout << "Please enter phone number (no spaces): " << std::endl;
        }

        // Gets contact address
        std::string getAddr;
        std::cout << "Please enter an address: " << std::endl;
        std::cin >> getAddr;
        std::getline(std::cin, getAddr);

        // [getName, getGender, getAge, getPhone, getAddr]
        // contact.name = getName;
        // contact.gender = getGender;
        // contact.age = getAge;
        contact.phone = getPhone;
        contact.address = getAddr;

        // contactbook.contactMap[getName] = contact;

        // increment the contact counter in the Contact Book
        contactbook.contactCount += 1;

        // std::cout << "Contact " << getName << " added successfully!!" << std::endl;
        std::cout << std::endl;
    }
}

void showContacts(ContactBook &contactbook)
{
    if (contactbook.contactCount == 0)
    {
        std::cout << "There are no contacts saved.." << std::endl;
    }
    else
    {
        for (auto i : contactbook.contactMap)
        {
            std::cout << "Contact Name: " << i.first << "Gender: " << (i.second.gender != 2 ? "Male" : "Female") << "Age: " << i.second.age << "Phone-Number: " << i.second.phone << "Address: " << i.second.address << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// int hasContact(ContactBook &contact, string name)
// {
//     // for (int i = 0; i < contact.contactCount; i++)
//     // {
//     //     if (contact.contactArr[i].name == name)
//     //     {
//     //         return i;
//     //     }
//     // }
//     // return -1;
// }

void delContact(ContactBook &contact)
{
}

void findContact(ContactBook &contact)
{
}

void editContact(ContactBook &contact)
{
}

void formatContacts(ContactBook &contact)
{
}