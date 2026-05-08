#include <iostream>
using namespace std;

int key[100];
int chain[10];
int n;

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

    friend int main();
} h[10];

void Hash::create()
{
    cout << "Enter The Number Of Students: ";
    cin >> n;

    for (int i = 0; i < 10; i++)
    {
        h[i].prn = -1;
        h[i].name = "";
        chain[i] = -2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter PRN: ";
        cin >> key[i];
    }
}

void Hash::insert()
{
    for (int i = 0; i < n; i++)
    {
        int loc = key[i] % 10;
        int pos = loc;
        int count = 0;

        while (h[loc].prn != -1 && count < 10)
        {
            loc = (loc + 1) % 10;
            count++;
        }

        if (count == 10)
        {
            cout << "Hash Table Is Full\n";
            return;
        }

        h[loc].prn = key[i];

        cout << "Enter Name For " << key[i] << ": ";
        cin >> h[loc].name;

        // Chain Update
        if (pos != loc)
        {
            int temp = pos;

            while (chain[temp] != -2)
            {
                temp = chain[temp];
            }

            chain[temp] = loc;
        }
    }
}

void Hash::display()
{
    cout << "\nHash Table:\n";
    cout << "Loc\tPRN\tName\tChain\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t"
             << h[i].prn << "\t"
             << h[i].name << "\t"
             << chain[i] << endl;
    }
}

void Hash::search()
{
    int p;

    cout << "\nEnter PRN To Search: ";
    cin >> p;

    int loc = p % 10;

    while (loc != -2)
    {
        if (h[loc].prn == p)
        {
            cout << "Data Found: " << h[loc].name << endl;
            return;
        }

        loc = chain[loc];
    }

    cout << "Data Not Found...\n";
}

void Hash::del()
{
    int p;

    cout << "\nEnter PRN To Delete: ";
    cin >> p;

    int loc = p % 10;
    int prev = -1;

    while (loc != -2)
    {
        if (h[loc].prn == p)
        {
            h[loc].prn = -1;
            h[loc].name = "";

            if (prev == -1)
            {
                chain[loc] = -2;
            }
            else
            {
                chain[prev] = chain[loc];
                chain[loc] = -2;
            }

            cout << "Record Deleted\n";
            return;
        }

        prev = loc;
        loc = chain[loc];
    }

    cout << "Record Not Found...\n";
}

int main()
{
    int ch;

    do
    {
        cout << "\n====== HASH TABLE MENU ======\n";
        cout << "1. Create\n";
        cout << "2. Insert\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
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
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice...\n";
        }

    } while (ch != 6);

    return 0;
}




// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Exit
// Enter Your Choice: 1

// Enter The Number Of Students: 3
// Enter PRN: 11
// Enter PRN: 21
// Enter PRN: 31

// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Exit
// Enter Your Choice: 2

// Enter Name For 11: Ali
// Enter Name For 21: Ahmed
// Enter Name For 31: Khan

// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Exit
// Enter Your Choice: 3

// Hash Table:
// Loc     PRN     Name    Chain

// 0       -1              -2
// 1       11      Ali     2
// 2       21      Ahmed   3
// 3       31      Khan    -2
// 4       -1              -2
// 5       -1              -2
// 6       -1              -2
// 7       -1              -2
// 8       -1              -2
// 9       -1              -2

// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Exit
// Enter Your Choice: 4

// Enter PRN To Search: 21
// Data Found: Ahmed

// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Exit
// Enter Your Choice: 5

// Enter PRN To Delete: 21
// Record Deleted

// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Exit
// Enter Your Choice: 3

// Hash Table:
// Loc     PRN     Name    Chain

// 0       -1              -2
// 1       11      Ali     3
// 2       -1              -2
// 3       31      Khan    -2
// 4       -1              -2
// 5       -1              -2
// 6       -1              -2
// 7       -1              -2
// 8       -1              -2
// 9       -1              -2

// ====== HASH TABLE MENU ======
// 1. Create
// 2. Insert
// 3. Display
// 4. Search
// 5. Delete
// 6. Exit
// Enter Your Choice: 6

// Exiting Program...