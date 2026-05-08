#include <iostream>
using namespace std;

#define MAX 20

class OBST
{
    string item[MAX];
    int p[MAX], q[MAX];
    int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX];
   

public:
    int n;
    void accept();
    void build();
    void preorder(int i, int j);
    void displayTable();
    void displayTree(int i, int j, string space);
};

void OBST::accept()
{
    cout << "Enter Number Of Items: ";
    cin >> n;

    cout << "Enter Items:\n";
    for (int i = 1; i <= n; i++)
        cin >> item[i];

    cout << "Enter Successful Frequencies (p):\n";
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    cout << "Enter Unsuccessful Frequencies (q):\n";
    for (int i = 0; i <= n; i++)
        cin >> q[i];
}

void OBST::build()
{
    for (int i = 0; i <= n; i++)
    {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len;

            w[i][j] = w[i][j - 1] + p[j] + q[j];
            c[i][j] = 9999;

            for (int k = i + 1; k <= j; k++)
            {
                int cost = c[i][k - 1] + c[k][j] + w[i][j];

                if (cost < c[i][j])
                {
                    c[i][j] = cost;
                    r[i][j] = k;
                }
            }
        }
    }

    cout << "\nOBST Built Successfully\n";
}

void OBST::preorder(int i, int j)
{
    if (i >= j)
        return;

    int root = r[i][j];

    cout << item[root] << " ";

    preorder(i, root - 1);
    preorder(root, j);
}

void OBST::displayTable()
{
    cout << "\nRoot Table:\n";

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << r[i][j] << "\t";
        }
        cout << endl;
    }
}

void OBST::displayTree(int i, int j, string space)
{
    if (i >= j)
        return;

    int root = r[i][j];

    cout << space << item[root] << endl;

    displayTree(i, root - 1, space + "   L-> ");
    displayTree(root, j, space + "   R-> ");
}

int main()
{
    OBST o;

    o.accept();
    o.build();

    cout << "\nPreorder Traversal:\n";
    o.preorder(0, o.n);

    cout << "\n\nRoot Table:\n";
    o.displayTable();

    cout << "\nTree Structure:\n";
    o.displayTree(0, o.n, "");

    return 0;
}


// Enter Number Of Items: 4

// Enter Items:
// do
// else
// if
// while

// Enter Successful Frequencies (p):
// 3
// 3
// 1
// 1

// Enter Unsuccessful Frequencies (q):
// 2
// 3
// 1
// 1
// 1


// OBST Built Successfully


// Preorder Traversal:
// else do if while


// Root Matrix (R):
// 0	1	1	2	2
// 0	0	2	2	2
// 0	0	0	3	3
// 0	0	0	0	4
// 0	0	0	0	0


// Tree Structure:
// else
//    L-> do
//    R-> if
//       R-> while