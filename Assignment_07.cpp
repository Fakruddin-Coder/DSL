#include <iostream>
using namespace std;

class Hash
{
    int prn;
    string name;

public:
    void create();
    void insert();
    void display();
    void search();
    void del();
    void modify();

    friend int main();
} h[10];

void Hash::create()
{
    for (int i = 0; i < 10; i++)
    {
        h[i].prn = -1;
        h[i].name = "";
    }

    cout << "Hash Table Created Successfully\n";
}

void Hash::insert()
{
    int n;

    cout << "Enter Number Of Students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int key;
        string nm;

        cout << "\nEnter PRN: ";
        cin >> key;

        cout << "Enter Name: ";
        cin >> nm;

        int loc = key % 10;
        int count = 0;

        while (h[loc].prn != -1 && count < 10)
        {
            count++;
            loc = (key % 10 + count * count) % 10;
        }

        if (count == 10)
        {
            cout << "Hash Table Full\n";
            return;
        }

        h[loc].prn = key;
        h[loc].name = nm;

        cout << "Record Inserted At Location "
             << loc << endl;
    }
}

void Hash::display()
{
    cout << "\nHash Table:\n";
    cout << "Loc\tPRN\tName\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t"
             << h[i].prn << "\t"
             << h[i].name << endl;
    }
}

void Hash::search()
{
    int key;

    cout << "\nEnter PRN To Search: ";
    cin >> key;

    int loc = key % 10;
    int count = 0;

    while (count < 10)
    {
        if (h[loc].prn == key)
        {
            cout << "Record Found\n";
            cout << "Name: " << h[loc].name << endl;
            return;
        }

        count++;
        loc = (key % 10 + count * count) % 10;
    }

    cout << "Record Not Found\n";
}

void Hash::del()
{
    int key;

    cout << "\nEnter PRN To Delete: ";
    cin >> key;

    int loc = key % 10;
    int count = 0;

    while (count < 10)
    {
        if (h[loc].prn == key)
        {
            h[loc].prn = -1;
            h[loc].name = "";

            cout << "Record Deleted\n";
            return;
        }

        count++;
        loc = (key % 10 + count * count) % 10;
    }

    cout << "Record Not Found\n";
}

void Hash::modify()
{
    int key;

    cout << "\nEnter PRN To Modify: ";
    cin >> key;

    int loc = key % 10;
    int count = 0;

    while (count < 10)
    {
        if (h[loc].prn == key)
        {
            cout << "Enter New Name: ";
            cin >> h[loc].name;

            cout << "Record Modified\n";
            return;
        }

        count++;
        loc = (key % 10 + count * count) % 10;
    }

    cout << "Record Not Found\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n====== HASH TABLE MENU ======\n";
        cout << "1. Create\n";
        cout << "2. Insert\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Delete\n";
        cout << "6. Modify\n";
        cout << "7. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h[0].create();
            break;

        case 2:
            h[0].insert();
            break;

        case 3:
            h[0].display();
            break;

        case 4:
            h[0].search();
            break;

        case 5:
            h[0].del();
            break;

        case 6:
            h[0].modify();
            break;

        case 7:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 7);

    return 0;
}



// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 1

// Hash Table Created Successfully


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 2

// Enter Number Of Students: 3

// Enter PRN: 11
// Enter Name: Ali
// Record Inserted At Location 1

// Enter PRN: 21
// Enter Name: Ahmed
// Record Inserted At Location 2

// Enter PRN: 31
// Enter Name: Khan
// Record Inserted At Location 5


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 3


// Hash Table:
// Loc     PRN     Name

// 0       -1
// 1       11      Ali
// 2       21      Ahmed
// 3       -1
// 4       -1
// 5       31      Khan
// 6       -1
// 7       -1
// 8       -1
// 9       -1


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 4

// Enter PRN To Search: 21

// Record Found
// Name: Ahmed


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 6

// Enter PRN To Modify: 31

// Enter New Name: Zaid

// Record Modified


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 3


// Hash Table:
// Loc     PRN     Name

// 0       -1
// 1       11      Ali
// 2       21      Ahmed
// 3       -1
// 4       -1
// 5       31      Zaid
// 6       -1
// 7       -1
// 8       -1
// 9       -1


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 5

// Enter PRN To Delete: 21

// Record Deleted


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 3


// Hash Table:
// Loc     PRN     Name

// 0       -1
// 1       11      Ali
// 2       -1
// 3       -1
// 4       -1
// 5       31      Zaid
// 6       -1
// 7       -1
// 8       -1
// 9       -1


// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Modify
// 7. Exit

// Enter Your Choice: 7

// Exiting Program...