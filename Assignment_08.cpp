#include <iostream>
using namespace std;

class Heap
{
    int a[100];
    int size = 0;

public:
    void create();
    void insert(int val);
    void heapify(int i);
    void del();
    void deleteParticular();
    void display();

    friend int main();
};

void Heap::create()
{
    int n;

    cout << "Enter Number Of Elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;

        cout << "Enter Element: ";
        cin >> val;

        insert(val);
    }

    cout << "Heap Created Successfully\n";
}

void Heap::insert(int val)
{
    size++;
    a[size] = val;

    int i = size;

    while (i > 1)
    {
        int parent = i / 2;

        if (a[parent] < a[i])
        {
            swap(a[parent], a[i]);
            i = parent;
        }
        else
        {
            break;
        }
    }

    cout << "Element Inserted Successfully\n";
}

void Heap::heapify(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= size && a[left] > a[largest])
    {
        largest = left;
    }

    if (right <= size && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(largest);
    }
}

void Heap::del()
{
    if (size == 0)
    {
        cout << "Heap Is Empty\n";
        return;
    }

    cout << "Deleted Root Element: " << a[1] << endl;

    a[1] = a[size];
    size--;

    heapify(1);
}

void Heap::deleteParticular()
{
    if (size == 0)
    {
        cout << "Heap Is Empty\n";
        return;
    }

    int val;

    cout << "Enter Element To Delete: ";
    cin >> val;

    int index = -1;

    for (int i = 1; i <= size; i++)
    {
        if (a[i] == val)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Element Not Found\n";
        return;
    }

    a[index] = a[size];
    size--;

    heapify(index);

    cout << "Element Deleted Successfully\n";
}

void Heap::display()
{
    if (size == 0)
    {
        cout << "Heap Is Empty\n";
        return;
    }

    cout << "\nHeap Elements: ";

    for (int i = 1; i <= size; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

int main()
{
    Heap h;

    int choice;

    do
    {
        cout << "\n====== MAX HEAP MENU ======\n";
        cout << "1. Create Heap\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Root Element\n";
        cout << "4. Delete Particular Element\n";
        cout << "5. Display Heap\n";
        cout << "6. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h.create();
            break;

        case 2:
        {
            int val;

            cout << "Enter Element To Insert: ";
            cin >> val;

            h.insert(val);
            break;
        }

        case 3:
            h.del();
            break;

        case 4:
            h.deleteParticular();
            break;

        case 5:
            h.display();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 6);

    return 0;
}



// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 1

// Enter Number Of Elements: 5

// Enter Element: 10
// Element Inserted Successfully

// Enter Element: 20
// Element Inserted Successfully

// Enter Element: 5
// Element Inserted Successfully

// Enter Element: 6
// Element Inserted Successfully

// Enter Element: 1
// Element Inserted Successfully

// Heap Created Successfully


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 5


// Heap Elements: 20 10 5 6 1


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 2

// Enter Element To Insert: 25

// Element Inserted Successfully


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 5


// Heap Elements: 25 10 20 6 1 5


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 3

// Deleted Root Element: 25


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 5


// Heap Elements: 20 10 5 6 1


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 4

// Enter Element To Delete: 10

// Element Deleted Successfully


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 5


// Heap Elements: 20 6 5 1


// ====== MAX HEAP MENU ======
// 1. Create Heap
// 2. Insert Element
// 3. Delete Root Element
// 4. Delete Particular Element
// 5. Display Heap
// 6. Exit

// Enter Your Choice: 6

// Exiting Program...