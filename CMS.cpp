#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Contact structure to store name, phone number, and email
struct Contact {
    string name;
    string phoneNumber;
    string email;
};

// Function declarations
void addContact(vector<Contact> &contacts);
void viewContacts(const vector<Contact> &contacts);
void editContact(vector<Contact> &contacts);
void deleteContact(vector<Contact> &contacts);
void loadContacts(vector<Contact> &contacts);
void saveContacts(const vector<Contact> &contacts);

// Main function
int main() {
    vector<Contact> contacts;

    // Load existing contacts from the file
    loadContacts(contacts);

    int choice;
    do {
        // Display menu
        cout << "\nContact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                cout << "Exiting..." << endl;
                saveContacts(contacts); // Save contacts to file before exiting
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new contact
void addContact(vector<Contact> &contacts) {
    Contact newContact;
    cout << "Enter Name: ";
    cin.ignore(); // To consume any leftover newline characters
    getline(cin, newContact.name);
    cout << "Enter Phone Number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter Email: ";
    getline(cin, newContact.email);

    contacts.push_back(newContact);

    cout << "Contact added successfully!" << endl;
}

// Function to view all contacts
void viewContacts(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << "Contact " << i + 1 << ":" << endl;
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone Number: " << contacts[i].phoneNumber << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << "---------------------" << endl;
    }
}

// Function to edit an existing contact
void editContact(vector<Contact> &contacts) {
    int index;
    cout << "Enter the contact number to edit: ";
    cin >> index;

    if (index <= 0 || index > contacts.size()) {
        cout << "Invalid contact number." << endl;
        return;
    }

    index--; // Convert to 0-based index

    cout << "Enter new Name (current: " << contacts[index].name << "): ";
    cin.ignore();
    getline(cin, contacts[index].name);
    cout << "Enter new Phone Number (current: " << contacts[index].phoneNumber << "): ";
    getline(cin, contacts[index].phoneNumber);
    cout << "Enter new Email (current: " << contacts[index].email << "): ";
    getline(cin, contacts[index].email);

    cout << "Contact updated successfully!" << endl;
}

// Function to delete a contact
void deleteContact(vector<Contact> &contacts) {
    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;

    if (index <= 0 || index > contacts.size()) {
        cout << "Invalid contact number." << endl;
        return;
    }

    index--; // Convert to 0-based index
    contacts.erase(contacts.begin() + index);

    cout << "Contact deleted successfully!" << endl;
}

// Function to load contacts from a file
void loadContacts(vector<Contact> &contacts) {
    ifstream file("contacts.txt");
    if (file.is_open()) {
        Contact contact;
        while (getline(file, contact.name) && getline(file, contact.phoneNumber) && getline(file, contact.email)) {
            contacts.push_back(contact);
        }
        file.close();
    }
}

// Function to save contacts to a file
void saveContacts(const vector<Contact> &contacts) {
    ofstream file("contacts.txt");
    if (file.is_open()) {
        for (const auto &contact : contacts) {
            file << contact.name << endl;
            file << contact.phoneNumber << endl;
            file << contact.email << endl;
        }
        file.close();
    }
}
