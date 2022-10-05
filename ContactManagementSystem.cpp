#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define Max 1000

struct Contact
{
    string name;
    int gender = 1;
    int age = 0;
    string phone;
    string address;
};

struct ContactBook
{
    unordered_map<string, Contact> contactMap;
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
    int select = 0;
    
    // address book instance that contains the hashmap with the Contact struct as its value
    ContactBook contactbook;
    Contact contact;

    // accessing the hashmap and setting its bucket size to Max --> 1000
    contactbook.contactMap.reserve(Max);

    // setting my contact count to 0
    contactbook.contactCount = 0;

    while (true)
    {
        menu();

        cin >> select;
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

        case 0:
            cout << "Thank You For Using Contact Management System! We Hope To See You Again Soon." << endl;
            system("pause");
            break;
            return 0;

        default:
            break;
        }
    }
    system("pause");
    return 0;
}

void menu()
{
    cout << "****************************************" << endl;
    cout << "******  Contact Management System ******" << endl;
    cout << "******       1. Add Contact        *****" << endl;
    cout << "******       2. Show Contact       *****" << endl;
    cout << "******       3. Delete Contact     *****" << endl;
    cout << "******       4. Find Contact       *****" << endl;
    cout << "******       5. Edit Contact       *****" << endl;
    cout << "******       6. Format Contact     *****" << endl;
    cout << "******       0. Exit               *****" << endl;
    cout << "****************************************" << endl;
    cout << "****************************************" << endl;
}

void addContact(ContactBook &contactbook, Contact contact)
{
    if (contactbook.contactCount == Max)
    {
        cout << "Address book is full!" << endl;
    }

    else
    {
        // Get name for contact
        string getName;
        cout << "Enter name: " << endl;
        cin >> getName;

        // Get age for contact
        int getGender;
        cout << "Please enter gender: " << endl;
        cout << "1 --> Male" << endl;
        cout << "2 --> Female" << endl;

        // Verify whether the user input a 1 or 2 for the gender
        while (true)
        {
            cin >> getGender;
            if (getGender == 1 || getGender == 2)
            {
                break;
            }
            cout << "Please enter (1 -> Male) or (2 -> Female) Thank You!" << endl;
        }

        // Get age for contact
        int getAge;
        cout << "Please enter age: " << endl;
        cin >> getAge;

        // Get phone number for contact
        string getPhone;
        cout << "Please enter phone number (no spaces): " << endl;

        // Makes sure phone numbers is atleast 10-digits
        while (true)
        {
            cin >> getPhone;
            if (getPhone.size() == 10)
            {
                break;
            }
            cout << "Please make sure you enter a 10-digit phone number, Thank You!" << endl;
        }

        // Gets contact address
        string getAddr;
        cout << "Please enter an address: " << endl;
        cin >> getAddr;

        // [getName, getGender, getAge, getPhone, getAddr]
        contact.name = getName;
        contact.gender = getGender;
        contact.age = getAge;
        contact.phone = getPhone;
        contact.address = getAddr;


        contactbook.contactMap[getName] = contact;

        // increment the contact counter in the Contact Book
        contactbook.contactCount += 1;

        cout << "Contact " << getName << " added successfully!!" << endl;
        cout << endl;
    }
}

void showContacts(ContactBook &contactbook)
{
    if (contactbook.contactCount == 0)
    {
        cout << "There are no contacts saved.." << endl;
    }
    else
    {
        for (auto i: contactbook.contactMap)
        {
            cout << "Contact Name: " << i.first << "Gender: " << (i.second.gender != 2 ? "Male" : "Female") << "Age: " << i.second.age << "Phone-Number: " << i.second.phone << "Address: " << i.second.address << endl;
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