#include <iostream>
using namespace std;

class AL
{
    int v = 0, e;
    string cityName;
    int fuel;
    AL *next;

public:
    string city[100];
    int adjMatrix[100][100];
    AL *head[100];

    // Constructor (VERY IMPORTANT)
    AL()
    {
        for(int i = 0; i < 100; i++)
        {
            head[i] = NULL;
            city[i] = "";
            for(int j = 0; j < 100; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void createList();
    void addList();
    void displayList();

    void createMatrix();
    void addMatrix();
    void displayMatrix();
};


// ---------- CREATE LIST ----------
void AL::createList()
{
    cout << "Enter No.of Cities: ";
    cin >> v;

    for (int i = 0; i < v; i++)
    {
        head[i] = new AL;
        cout << "Enter City Name: ";
        cin >> city[i];
        head[i]->cityName = city[i];
        head[i]->next = NULL;
    }
}


// ---------- ADD LIST ----------
void AL::addList()
{
    cout << "Enter No.of Flights: ";
    cin >> e;

    string s, d;
    int f;

    for (int i = 0; i < e; i++)
    {
        cout << "Enter Source Destination: ";
        cin >> s >> d;

        cout << "Enter Fuel: ";
        cin >> f;

        for (int j = 0; j < v; j++)
        {
            if (s == city[j])
            {
                AL *newNode = new AL;
                newNode->cityName = d;
                newNode->fuel = f;
                newNode->next = NULL;

                AL *temp = head[j];
                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newNode;
                break;
            }
        }
    }
}


// ---------- DISPLAY LIST ----------
void AL::displayList()
{
    if(v == 0)
    {
        cout << "Create list first!\n";
        return;
    }

    cout << "\nAdjacency List:\n";

    for (int i = 0; i < v; i++)
    {
        if(head[i] == NULL)
            continue;

        cout << "\n" << city[i];

        AL *temp = head[i]->next;

        while (temp != NULL)
        {
            cout << " -> " << temp->cityName
                 << "(" << temp->fuel << ")";
            temp = temp->next;
        }
    }
}


// ---------- CREATE MATRIX ----------
void AL::createMatrix()
{
    cout << "Enter No.of Cities: ";
    cin >> v;

    for (int i = 0; i < v; i++)
    {
        cout << "Enter City Name: ";
        cin >> city[i];
    }
}


// ---------- ADD MATRIX ----------
void AL::addMatrix()
{
    if(v == 0)
    {
        cout << "Create matrix first!\n";
        return;
    }

    int f;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "Enter Fuel between "
                 << city[i] << " and "
                 << city[j] << ": ";
            cin >> f;

            adjMatrix[i][j] = f;
            adjMatrix[j][i] = f;
        }
    }
}


// ---------- DISPLAY MATRIX ----------
void AL::displayMatrix()
{
    if(v == 0)
    {
        cout << "Create matrix first!\n";
        return;
    }

    cout << "\nAdjacency Matrix:\n\n";

    cout << "      ";
    for (int i = 0; i < v; i++)
        cout << city[i] << "   ";
    cout << endl;

    for (int i = 0; i < v; i++)
    {
        cout << city[i] << "   ";

        for (int j = 0; j < v; j++)
            cout << adjMatrix[i][j] << "     ";

        cout << endl;
    }
}


// ---------- MAIN ----------
int main()
{
    AL g;
    int ch;

    do
    {
        cout << "\n--- FLIGHT NETWORK MENU ---\n";
        cout << "1. Create List\n";
        cout << "2. Add Flights (List)\n";
        cout << "3. Display List\n";
        cout << "4. Create Matrix\n";
        cout << "5. Add Flights (Matrix)\n";
        cout << "6. Display Matrix\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: g.createList(); break;
        case 2: g.addList(); break;
        case 3: g.displayList(); break;
        case 4: g.createMatrix(); break;
        case 5: g.addMatrix(); break;
        case 6: g.displayMatrix(); break;
        case 7: cout << "Exiting...\n"; break;
        default: cout << "Invalid Choice!\n";
        }

    } while (ch != 7);

    return 0;
}

// ================== OUTPUT PART =================


// --- FLIGHT NETWORK MENU ---
// 1. Create List
// 2. Add Flights (List)
// 3. Display List
// 4. Create Matrix
// 5. Add Flights (Matrix)
// 6. Display Matrix
// 7. Exit
// Enter Choice: 1
// Enter No.of Cities: 3
// Enter City Name: Mumbai
// Enter City Name: Shirdi
// Enter City Name: Pune

// --- FLIGHT NETWORK MENU ---
// 1. Create List
// 2. Add Flights (List)
// 3. Display List
// 4. Create Matrix
// 5. Add Flights (Matrix)
// 6. Display Matrix
// 7. Exit
// Enter Choice: 2
// Enter No.of Flights: 2
// Enter Source Destination: Mumbai
// Shirdi
// Enter Fuel: 250
// Enter Source Destination: Mumbai
// Pune
// Enter Fuel: 150

// --- FLIGHT NETWORK MENU ---
// 1. Create List
// 2. Add Flights (List)
// 3. Display List
// 4. Create Matrix
// 5. Add Flights (Matrix)
// 6. Display Matrix
// 7. Exit
// Enter Choice: 3

// Adjacency List:

// Mumbai -> Shirdi(250) -> Pune(150)
// Shirdi
// Pune
// --- FLIGHT NETWORK MENU ---
// 1. Create List
// 2. Add Flights (List)
// 3. Display List
// 4. Create Matrix
// 5. Add Flights (Matrix)
// 6. Display Matrix
// 7. Exit
// Enter Choice: 4
// Enter No.of Cities: 3
// Enter City Name: Mumbai
// Enter City Name: Shirdi
// Enter City Name: Pune

// --- FLIGHT NETWORK MENU ---
// 1. Create List
// 2. Add Flights (List)
// 3. Display List
// 4. Create Matrix
// 5. Add Flights (Matrix)
// 6. Display Matrix
// 7. Exit
// Enter Choice: 5
// Enter Fuel between Shirdi and Mumbai: 250
// Enter Fuel between Pune and Mumbai: 150
// Enter Fuel between Pune and Shirdi: 200

// --- FLIGHT NETWORK MENU ---
// 1. Create List
// 2. Add Flights (List)
// 3. Display List
// 4. Create Matrix
// 5. Add Flights (Matrix)
// 6. Display Matrix
// 7. Exit
// Enter Choice: 6

// Adjacency Matrix:

//       Mumbai   Shirdi   Pune   
// Mumbai   0     250     150     
// Shirdi   250     0     200     
// Pune   150     200     0     

// --- FLIGHT NETWORK MENU ---
// 1. Create List
// 2. Add Flights (List)
// 3. Display List
// 4. Create Matrix
// 5. Add Flights (Matrix)
// 6. Display Matrix
// 7. Exit
// Enter Choice: 7
