#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define Max 1000

unordered_map<string, vector<int, string>> contact_map;

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
    Contact contactArr[Max];
    int contactCount = 0;
};

/*
temp = ["Mike", 1, 25, "2024556655", "123 max street"]

max=1000
contactArr[
    ["John", 1, 25, "4104676702", "123 min street"],
    ["Mike", 1, 25, "2024556655", "123 max street"],
    ["Teqwon", 1, 25, "4434445555", "123 alt street]
]


*/

void menu();
void addContact(ContactBook &);
void showContacts(ContactBook &);
int hasContact(ContactBook &, string);
void delContact(ContactBook &);
void findContact(ContactBook &);
void editContact(ContactBook &);
void formatContacts(ContactBook &);

int main()
{
    int select = 0;

    ContactBook contact;
    contact.contactCount = 0;

    while (true)
    {
        menu();

        cin >> select;
        switch (select)
        {
        case 1:
            addContact(contact);
            break;

        case 2:
            showContacts(contact);
            break;

        case 3:
            delContact(contact);
            break;

        case 4:
            findContact(contact);
            break;

        case 5:
            editContact(contact);
            break;

        case 6:
            formatContacts(contact);
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

void addContact(ContactBook &contact)
{
    if (contact.contactCount == Max)
    {
        cout << "Contact-Book is full!" << endl;
    }
    else
    {
        // Get name for contact
        string getName;
        cout << "Enter name: " << endl;
        cin >> getName;
        contact.contactArr[contact.contactCount].name = getName;

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
                contact.contactArr[contact.contactCount].gender = getGender;
                break;
            }
            cout << "Please enter (1 -> Male) or (2 -> Female) Thank You!" << endl;
        }

        // Get age for contact
        int getAge;
        cout << "Please enter age: " << endl;
        cin >> getAge;
        contact.contactArr[contact.contactCount].age = getAge;

        // Get phone number for contact
        string getPhone;
        cout << "Please enter phone number (no spaces): " << endl;

        // Makes sure phone numbers is atleast 10-digits
        while (true)
        {
            cin >> getPhone;
            if (getPhone.size() == 10)
            {
                contact.contactArr[contact.contactCount].phone = getPhone;
                break;
            }
            cout << "Please make sure you enter a 10-digit phone number, Thank You!" << endl;
        }

        // Gets contact address
        string getAddr;
        cout << "Please enter an address: " << endl;
        cin >> getAddr;
        contact.contactArr[contact.contactCount].address = getAddr;

        // increment the contact counter in the Contact Book
        contact.contactCount += 1;
        cout << "Contact " << contact.contactArr[contact.contactCount].name << "added successfully!!" << endl;
    }
}

void showContacts(ContactBook &contact)
{
    if (contact.contactCount == 0)
    {
        cout << "There are no contacts saved.." << endl;
    }
    else
    {
        for (int i = 0; i < contact.contactCount; i++)
        {
            cout << "Contact #" << i + 1 << " --> Name: " << contact.contactArr[i].name << "Gender: " << (contact.contactArr[i].gender != 2 ? "Male" : "Female") << "Age: " << contact.contactArr[i].age << "Phone-Number: " << contact.contactArr[i].phone << "Address: " << contact.contactArr[i].address << endl;
        }
    }
    system("pause");
    system("cls");
}

int hasContact(ContactBook &contact, string name)
{
    for (int i = 0; i < contact.contactCount; i++)
    {
        if (contact.contactArr[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

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