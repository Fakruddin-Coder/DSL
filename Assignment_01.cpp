#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class BT
{
    string name;
    int age;
    int an;
    BT *LC, *RC;

public:
    BT *root;

    BT() { root = NULL; }

    void show(BT *node);

    void create();
    void addMember();
    void insertNode(BT *parent, BT *next);

    void inorder(BT *root);
    bool searchMember(BT *root, int key);
    int getHeight(BT *root);

    void displayLeafNodes(BT *root);
    void displayCurrentGeneration(BT *root, int h, int l);
    void displaySiblingNodes(BT *root);
    bool displayAncestors(BT *root, int key);
};

/* Display format */
void BT::show(BT *node)
{
    cout << left << setw(15) << node->name
         << setw(10) << node->age
         << setw(15) << node->an << endl;
}

/* Create root */
void BT::create()
{
    root = new BT;

    cout << "\nEnter Name: ";
    cin >> root->name;
    cout << "Enter Age: ";
    cin >> root->age;
    cout << "Enter Aadhaar Number: ";
    cin >> root->an;

    root->LC = root->RC = NULL;
}

/* Add member */
void BT::addMember()
{
    if (!root)
    {
        cout << "Create family first!\n";
        return;
    }

    BT *next = new BT;

    cout << "\nEnter Name: ";
    cin >> next->name;
    cout << "Enter Age: ";
    cin >> next->age;
    cout << "Enter Aadhaar Number: ";
    cin >> next->an;

    next->LC = next->RC = NULL;

    int parentKey;
    cout << "Enter Aadhaar of Parent: ";
    cin >> parentKey;

    if (!searchMember(root, parentKey))
    {
        cout << "Parent not found!\n";
        return;
    }

    insertNode(root, next);
}

/* Insert node */
void BT::insertNode(BT *parent, BT *next)
{
    char ch;
    cout << "Insert at Left or Right of " << parent->name << " (L/R): ";
    cin >> ch;

    if (ch == 'L' || ch == 'l')
    {
        if (!parent->LC)
            parent->LC = next;
        else
            insertNode(parent->LC, next);
    }
    else
    {
        if (!parent->RC)
            parent->RC = next;
        else
            insertNode(parent->RC, next);
    }
}

/* Inorder */
void BT::inorder(BT *root)
{
    if (!root) return;

    inorder(root->LC);
    show(root);
    inorder(root->RC);
}

/* Search */
bool BT::searchMember(BT *root, int key)
{
    if (!root) return false;

    if (root->an == key)
    {
        cout << "\nMember Details:\n";
        show(root);
        return true;
    }

    return searchMember(root->LC, key) ||
           searchMember(root->RC, key);
}

/* Height */
int BT::getHeight(BT *root)
{
    if (!root) return -1;
    return max(getHeight(root->LC), getHeight(root->RC)) + 1;
}

/* Leaf nodes */
void BT::displayLeafNodes(BT *root)
{
    if (!root) return;

    if (!root->LC && !root->RC)
        show(root);

    displayLeafNodes(root->LC);
    displayLeafNodes(root->RC);
}

/* Current generation */
void BT::displayCurrentGeneration(BT *root, int h, int l)
{
    if (!root) return;

    if (h == l)
        show(root);
    else
    {
        displayCurrentGeneration(root->LC, h, l + 1);
        displayCurrentGeneration(root->RC, h, l + 1);
    }
}

/* Siblings */
void BT::displaySiblingNodes(BT *root)
{
    if (!root) return;

    if (root->LC && root->RC)
    {
        show(root->LC);
        show(root->RC);
        cout << "----------------------\n";
    }

    displaySiblingNodes(root->LC);
    displaySiblingNodes(root->RC);
}

/* Ancestors */
bool BT::displayAncestors(BT *root, int key)
{
    if (!root) return false;

    if (root->an == key)
        return true;

    if (displayAncestors(root->LC, key) ||
        displayAncestors(root->RC, key))
    {
        show(root);
        return true;
    }

    return false;
}

/* MAIN */
int main()
{
    BT tree;
    int choice, key;

    do
    {
        cout << "\n========= FAMILY TREE MENU =========\n";
        cout << "1. Create Family\n";
        cout << "2. Add Member\n";
        cout << "3. Display Members (Inorder)\n";
        cout << "4. Search Member\n";
        cout << "5. Tree Height\n";
        cout << "6. Leaf Nodes\n";
        cout << "7. Current Generation\n";
        cout << "8. Sibling Nodes\n";
        cout << "9. Ancestors\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << left << setw(15) << "Name"
             << setw(10) << "Age"
             << setw(15) << "Aadhaar" << endl;
        cout << "--------------------------------------\n";

        switch (choice)
        {
        case 1:
            tree.create();
            break;

        case 2:
            tree.addMember();
            break;

        case 3:
            tree.inorder(tree.root);
            break;

        case 4:
            cout << "Enter Aadhaar Number to Search: ";
            cin >> key;
            if (!tree.searchMember(tree.root, key))
                cout << "Member Not Found\n";
            break;

        case 5:
            cout << "Height of Tree: "
                 << tree.getHeight(tree.root) << endl;
            break;

        case 6:
            tree.displayLeafNodes(tree.root);
            break;

        case 7:
            tree.displayCurrentGeneration(tree.root,
                tree.getHeight(tree.root), 0);
            break;

        case 8:
            tree.displaySiblingNodes(tree.root);
            break;

        case 9:
            cout << "Enter Aadhaar Number to find Ancestors: ";
            cin >> key;

            if (tree.searchMember(tree.root, key))
            {
                cout << "\nAncestors are:\n";
                tree.displayAncestors(tree.root, key);
            }
            else
                cout << "Member Not Found\n";
            break;

        case 10:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 10);

    return 0;
}
