#include <iostream>
using namespace std;

class BST
{
public:
    int seatNo, cet;
    string name, status;
    BST *LC, *RC;
};

BST *root = NULL;

// ---------- Benchmark Root ----------
void createBenchmarkRoot()
{
    root = new BST;
    root->seatNo = 0;
    root->name = "Benchmark";
    root->cet = 90;
    root->status = "IIT";
    root->LC = root->RC = NULL;

    cout << "Benchmark Root Created (CET = 90)\n";
}

// ---------- Insert ----------
BST *insertNode(BST *root, BST *temp)
{
    if (root == NULL)
        return temp;

    if (temp->seatNo < root->seatNo)
        root->LC = insertNode(root->LC, temp);
    else if (temp->seatNo > root->seatNo)
        root->RC = insertNode(root->RC, temp);
    else
    {
        cout << "Seat Number already exists!\n";
        return root;
    }

    return root;
}

void addStudent()
{
    BST *temp = new BST;

    cout << "\nEnter Seat No : ";
    cin >> temp->seatNo;
    cout << "Enter Name    : ";
    cin >> temp->name;
    cout << "Enter CET     : ";
    cin >> temp->cet;

    temp->status = (temp->cet > 90) ? "IIT" : "Non-IIT";
    temp->LC = temp->RC = NULL;

    root = insertNode(root, temp);
    cout << "Student Added Successfully!\n";
}

// ---------- Inorder ----------
void inorder(BST *root)
{
    BST *st[100];
    int top = -1;
    BST *temp = root;

    while (temp || top != -1)
    {
        while (temp)
        {
            st[++top] = temp;
            temp = temp->LC;
        }
        temp = st[top--];

        if (temp->seatNo != 0)
            cout << temp->seatNo << "\t" << temp->name
                 << "\t" << temp->cet << "\t" << temp->status << endl;

        temp = temp->RC;
    }
}

// ---------- Preorder ----------
void preorder(BST *root)
{
    BST *st[100];
    int top = -1;
    st[++top] = root;

    while (top != -1)
    {
        BST *temp = st[top--];

        if (temp->seatNo != 0)
            cout << temp->seatNo << "\t" << temp->name
                 << "\t" << temp->cet << "\t" << temp->status << endl;

        if (temp->RC)
            st[++top] = temp->RC;
        if (temp->LC)
            st[++top] = temp->LC;
    }
}

// ---------- Postorder ----------
void postorder(BST *root)
{
    BST *st1[100], *st2[100];
    int top1 = -1, top2 = -1;

    st1[++top1] = root;

    while (top1 != -1)
    {
        BST *temp = st1[top1--];
        st2[++top2] = temp;

        if (temp->LC)
            st1[++top1] = temp->LC;
        if (temp->RC)
            st1[++top1] = temp->RC;
    }

    while (top2 != -1)
    {
        BST *temp = st2[top2--];

        if (temp->seatNo != 0)
            cout << temp->seatNo << "\t" << temp->name
                 << "\t" << temp->cet << "\t" << temp->status << endl;
    }
}

// ---------- Search by Seat No ----------
void searchStudent(BST *root, int key)
{
    while (root)
    {
        if (root->seatNo == key)
        {
            cout << "\nStudent Found:\n";
            cout << root->seatNo << "\t" << root->name
                 << "\t" << root->cet << "\t" << root->status << endl;
            return;
        }
        if (key < root->seatNo)
            root = root->LC;
        else
            root = root->RC;
    }
    cout << "Student Not Found!\n";
}

// ---------- Count ----------
int countNodes(BST *root)
{
    if (!root)
        return 0;
    return countNodes(root->LC) + countNodes(root->RC) + (root->seatNo != 0);
}

// ---------- Height ----------
int height(BST *root)
{
    if (!root)
        return -1;
    int l = height(root->LC);
    int r = height(root->RC);
    return (l > r ? l : r) + 1;
}

// ---------- Min / Max ----------
BST *findMin(BST *root)
{
    while (root->LC)
        root = root->LC;
    return root;
}
BST *findMax(BST *root)
{
    while (root->RC)
        root = root->RC;
    return root;
}

// ---------- IIT / Non-IIT ----------
void listByStatus(BST *root, string s)
{
    if (!root)
        return;
    listByStatus(root->LC, s);
    if (root->status == s)
        cout << root->seatNo << "\t" << root->name << "\t" << root->cet << endl;
    listByStatus(root->RC, s);
}

// ---------- Delete by Seat No ----------
BST *deleteBySeatNo(BST *root, int seat)
{
    if (!root)
        return NULL;

    if (seat < root->seatNo)
        root->LC = deleteBySeatNo(root->LC, seat);
    else if (seat > root->seatNo)
        root->RC = deleteBySeatNo(root->RC, seat);
    else
    {
        if (!root->LC)
        {
            BST *temp = root->RC;
            delete root;
            return temp;
        }
        if (!root->RC)
        {
            BST *temp = root->LC;
            delete root;
            return temp;
        }

        BST *temp = findMin(root->RC);

        root->seatNo = temp->seatNo;
        root->name = temp->name;
        root->cet = temp->cet;
        root->status = temp->status;

        root->RC = deleteBySeatNo(root->RC, temp->seatNo);
    }
    return root;
}

// ---------- MAIN ----------
int main()
{
    createBenchmarkRoot();
    int ch, key;

    do
    {
        cout << "\n===== STUDENT BST SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Traversals\n";
        cout << "3. Search by Seat No\n";
        cout << "4. Total Students\n";
        cout << "5. Topper Student\n";
        cout << "6. First 3 Toppers\n";
        cout << "7. IIT Students\n";
        cout << "8. Non-IIT Students\n";
        cout << "9. Height of Tree\n";
        cout << "10. Lowest CET Student\n";
        cout << "11. Delete Student by Seat No\n";
        cout << "12. Exit\n";
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            addStudent();
            break;

        case 2:
            cout << "\n--- INORDER ---\n";
            inorder(root);
            cout << "\n--- PREORDER ---\n";
            preorder(root);
            cout << "\n--- POSTORDER ---\n";
            postorder(root);
            break;

        case 3:
            cout << "Enter Seat No: ";
            cin >> key;
            searchStudent(root, key);
            break;

        case 4:
            cout << "Total Students: " << countNodes(root) << endl;
            break;

        case 5:
        {
            BST *t = findMax(root);
            cout << t->seatNo << "\t" << t->name
                 << "\t" << t->cet << "\t" << t->status << endl;
        }
        break;

        case 6:
        {
            BST *st[100];
            int top = -1, count = 0;
            BST *temp = root;

            while ((temp || top != -1) && count < 3)
            {
                while (temp)
                {
                    st[++top] = temp;
                    temp = temp->RC;
                }
                temp = st[top--];

                if (temp->seatNo != 0)
                {
                    cout << temp->seatNo << "\t" << temp->name
                         << "\t" << temp->cet << endl;
                    count++;
                }
                temp = temp->LC;
            }
        }
        break;

        case 7:
            cout << "\nIIT Students:\n";
            listByStatus(root, "IIT");
            break;

        case 8:
            cout << "\nNon-IIT Students:\n";
            listByStatus(root, "Non-IIT");
            break;

        case 9:
            cout << "Height of Tree: " << height(root) << endl;
            break;

        case 10:
        {
            BST *t = findMin(root);
            cout << t->seatNo << "\t" << t->name
                 << "\t" << t->cet << "\t" << t->status << endl;
        }
        break;

        case 11:
            cout << "Enter Seat No to Delete: ";
            cin >> key;
            root = deleteBySeatNo(root, key);
            cout << "Student Deleted Successfully!\n";
            break;

        case 12:
            cout << "Program Ended.\n";
            break;
        }

    } while (ch != 12);
}


// ---------------   OUTPUT   -------------
// Benchmark Root Created (CET = 90)

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 1

// Enter Seat No : 123
// Enter Name    : Sakib
// Enter CET     : 92
// Student Added Successfully!

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 1

// Enter Seat No : 132
// Enter Name    : Rohit
// Enter CET     : 87
// Student Added Successfully!

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 1

// Enter Seat No : 143
// Enter Name    : Krishna
// Enter CET     : 95
// Student Added Successfully!

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 2

// --- INORDER ---
// 123	Sakib	92	IIT
// 132	Rohit	87	Non-IIT
// 143	Krishna	95	IIT

// --- PREORDER ---
// 123	Sakib	92	IIT
// 132	Rohit	87	Non-IIT
// 143	Krishna	95	IIT

// --- POSTORDER ---
// 143	Krishna	95	IIT
// 132	Rohit	87	Non-IIT
// 123	Sakib	92	IIT

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 3
// Enter Seat No: 143

// Student Found:
// 143	Krishna	95	IIT

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 4
// Total Students: 3

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 5
// 143	Krishna	95	IIT

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 6
// 143	Krishna	95
// 132	Rohit	87
// 123	Sakib	92

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 7

// IIT Students:
// 0	Benchmark	90
// 123	Sakib	92
// 143	Krishna	95

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 8

// Non-IIT Students:
// 132	Rohit	87

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 9
// Height of Tree: 3

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 10
// 0	Benchmark	90	IIT

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 11
// Enter Seat No to Delete: 123
// Student Deleted Successfully!

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 2

// --- INORDER ---
// 132	Rohit	87	Non-IIT
// 143	Krishna	95	IIT

// --- PREORDER ---
// 132	Rohit	87	Non-IIT
// 143	Krishna	95	IIT

// --- POSTORDER ---
// 143	Krishna	95	IIT
// 132	Rohit	87	Non-IIT

// ===== STUDENT BST SYSTEM =====
// 1. Add Student
// 2. Display Traversals
// 3. Search by Seat No
// 4. Total Students
// 5. Topper Student
// 6. First 3 Toppers
// 7. IIT Students
// 8. Non-IIT Students
// 9. Height of Tree
// 10. Lowest CET Student
// 11. Delete Student by Seat No
// 12. Exit
// Enter Choice: 12
// Program Ended.
