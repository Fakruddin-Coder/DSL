#include<iostream>
#include<algorithm>
using namespace std;

/*
    Family Tree using Binary Tree
    Each node stores: Name, Age, Aadhaar Number
*/

class BT
{
    string name;
    int age;
    int an;
    BT *LC, *RC;

public:
    void createRoot();
    void addMember();
    void insertNode(BT *root, BT *next);
    void preorder(BT *root);
    void postorder(BT *root);
    void inorder(BT *root);
    bool search(BT *root, int key);
    int height(BT *root);
    void printLeafNodes(BT *root);
    void printLastGeneration(BT *root, int h, int level);
    void printSiblings(BT *root);
    void printAncestors(BT *root, int key);
} b, *root = NULL;


// ================= CREATE ROOT =================
void BT::createRoot()
{
    cout << "\n========== CREATE FAMILY ROOT ==========\n";

    root = new BT;

    cout << "Enter Name           : ";
    cin >> root->name;

    cout << "Enter Age            : ";
    cin >> root->age;

    cout << "Enter Aadhaar Number : ";
    cin >> root->an;

    root->LC = root->RC = NULL;

    cout << "Root member added successfully!\n";
}


// ================= ADD MEMBER =================
void BT::addMember()
{
    BT *next;
    int choice;

    do {
        cout << "\n========== ADD NEW FAMILY MEMBER ==========\n";

        next = new BT;

        cout << "Enter Name           : ";
        cin >> next->name;

        cout << "Enter Age            : ";
        cin >> next->age;

        cout << "Enter Aadhaar Number : ";
        cin >> next->an;

        next->LC = next->RC = NULL;

        insertNode(root, next);

        cout << "\nDo you want to add more members? (1/0): ";
        cin >> choice;

    } while (choice == 1);
}


// ================= INSERT NODE =================
void BT::insertNode(BT *root, BT *next)
{
    char ch;

    cout << "Insert to Left or Right of current node? (L/R): ";
    cin >> ch;

    if (ch == 'L' || ch == 'l')
    {
        if (root->LC == NULL)
            root->LC = next;
        else
            insertNode(root->LC, next);
    }
    else if (ch == 'R' || ch == 'r')
    {
        if (root->RC == NULL)
            root->RC = next;
        else
            insertNode(root->RC, next);
    }
}


// ================= TRAVERSALS =================
void BT::preorder(BT *root)
{
    if (root == NULL) return;
    cout << root->name << "\t" << root->age << "\t" << root->an << endl;
    preorder(root->LC);
    preorder(root->RC);
}

void BT::postorder(BT *root)
{
    if (root == NULL) return;
    postorder(root->LC);
    postorder(root->RC);
    cout << root->name << "\t" << root->age << "\t" << root->an << endl;
}

void BT::inorder(BT *root)
{
    if (root == NULL) return;
    inorder(root->LC);
    cout << root->name << "\t" << root->age << "\t" << root->an << endl;
    inorder(root->RC);
}


// ================= SEARCH =================
bool BT::search(BT *root, int key)
{
    if (root == NULL) return false;

    if (root->an == key)
    {
        cout << "\nMember Found:\n";
        cout << root->name << "\t" << root->age << "\t" << root->an << endl;
        return true;
    }

    return search(root->LC, key) || search(root->RC, key);
}


// ================= HEIGHT =================
int BT::height(BT *root)
{
    if (root == NULL) return -1;

    int leftHeight = height(root->LC);
    int rightHeight = height(root->RC);

    return max(leftHeight, rightHeight) + 1;
}


// ================= LEAF NODES =================
void BT::printLeafNodes(BT *root)
{
    if (root == NULL) return;

    if (root->LC == NULL && root->RC == NULL)
        cout << root->name << "\t" << root->age << "\t" << root->an << endl;

    printLeafNodes(root->LC);
    printLeafNodes(root->RC);
}


// ================= LAST GENERATION =================
void BT::printLastGeneration(BT *root, int h, int level)
{
    if (root == NULL) return;

    if (h == level)
        cout << root->name << "\t" << root->age << "\t" << root->an << endl;
    else
    {
        printLastGeneration(root->LC, h, level + 1);
        printLastGeneration(root->RC, h, level + 1);
    }
}


// ================= SIBLINGS =================
void BT::printSiblings(BT *root)
{
    if (root == NULL) return;

    if (root->LC != NULL && root->RC != NULL)
    {
        cout << root->LC->name << "\t" << root->LC->age << "\t" << root->LC->an << endl;
        cout << root->RC->name << "\t" << root->RC->age << "\t" << root->RC->an << endl;
    }

    printSiblings(root->LC);
    printSiblings(root->RC);
}


// ================= ANCESTORS =================
void BT::printAncestors(BT *root, int key)
{
    if (root == NULL) return;

    if (root->an == key) return;

    if (search(root->LC, key) || search(root->RC, key))
        cout << root->name << "\t" << root->age << "\t" << root->an << endl;

    printAncestors(root->LC, key);
    printAncestors(root->RC, key);
}


// ================= MAIN MENU =================
int main()
{
    int choice, key, t;

    do {
        cout << "\n\n=====================================\n";
        cout << "        FAMILY TREE MANAGEMENT       \n";
        cout << "=====================================\n";
        cout << "1. Create Family Root\n";
        cout << "2. Add Family Member\n";
        cout << "3. Display All Members\n";
        cout << "4. Search Member by Aadhaar\n";
        cout << "5. Show Generation Count\n";
        cout << "6. Show Leaf Members\n";
        cout << "7. Show Last Generation Members\n";
        cout << "8. Show Sibling Members\n";
        cout << "9. Show Ancestors\n";
        cout << "10. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: b.createRoot(); break;
        case 2: b.addMember(); break;
        case 3:
            cout << "\n--- Inorder ---\n";
            b.inorder(root);
            cout << "\n--- Postorder ---\n";
            b.postorder(root);
            cout << "\n--- Preorder ---\n";
            b.preorder(root);
            break;
        case 4:
            cout << "Enter Aadhaar Number: ";
            cin >> key;
            if (!b.search(root, key))
                cout << "Member not found!\n";
            break;
        case 5:
            cout << "Total Generations: " << b.height(root) << endl;
            break;
        case 6:
            cout << "\nLeaf Members:\n";
            b.printLeafNodes(root);
            break;
        case 7:
            cout << "\nLast Generation Members:\n";
            b.printLastGeneration(root, b.height(root), 0);
            break;
        case 8:
            cout << "\nSibling Members:\n";
            b.printSiblings(root);
            break;
        case 9:
            cout << "Enter Aadhaar Number: ";
            cin >> t;
            b.printAncestors(root, t);
            break;
        case 10:
            cout << "\nThank you! Program Ended.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 10);

    return 0;
}


// ============= OUTPUT ================



// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 1

// ========== CREATE FAMILY ROOT ==========
// Enter Name           : sakib
// Enter Age            : 24
// Enter Aadhaar Number : 123
// Root member added successfully!


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 2

// ========== ADD NEW FAMILY MEMBER ==========
// Enter Name           : aman
// Enter Age            : 24
// Enter Aadhaar Number : 132
// Insert to Left or Right of current node? (L/R): L

// Do you want to add more members? (1/0): 1

// ========== ADD NEW FAMILY MEMBER ==========
// Enter Name           : shahid
// Enter Age            : 67
// Enter Aadhaar Number : 125
// Insert to Left or Right of current node? (L/R): R

// Do you want to add more members? (1/0): 0


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 3

// --- Inorder ---
// aman	24	132
// sakib	24	123
// shahid	67	125

// --- Postorder ---
// aman	24	132
// shahid	67	125
// sakib	24	123

// --- Preorder ---
// sakib	24	123
// aman	24	132
// shahid	67	125


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 4
// Enter Aadhaar Number: 132

// Member Found:
// aman	24	132


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 5
// Total Generations: 1


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 6

// Leaf Members:
// aman	24	132
// shahid	67	125


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 7

// Last Generation Members:
// aman	24	132
// shahid	67	125


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 8

// Sibling Members:
// aman	24	132
// shahid	67	125


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 9
// Enter Aadhaar Number: 132

// Member Found:
// aman	24	132
// sakib	24	123


// =====================================
//         FAMILY TREE MANAGEMENT       
// =====================================
// 1. Create Family Root
// 2. Add Family Member
// 3. Display All Members
// 4. Search Member by Aadhaar
// 5. Show Generation Count
// 6. Show Leaf Members
// 7. Show Last Generation Members
// 8. Show Sibling Members
// 9. Show Ancestors
// 10. Exit
// -------------------------------------
// Enter your choice: 10

// Thank you! Program Ended.


// === Code Execution Successful ===