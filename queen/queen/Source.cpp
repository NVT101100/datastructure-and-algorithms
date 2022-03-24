#include<conio.h>
#include<math.h>
#include <iostream>
using namespace std;
int a[30];
//row=index and column=value
char hang[8] = { '1','2','3','4','5','6','7','8' };
char cot[8] = { 'a','b','c','d','e','f','g','h' };
struct square
{
public:
    char hang;
    char cot;
}square[8][8];

class chess
{
public:
    void create(int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                square[i][j].hang = hang[i];
                square[i][j].cot = cot[j];
            }
    }
    void display(int n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                cout << square[i][j].cot << square[i][j].hang << "\t";
            }
            cout << endl << endl;
        }
    }
};

int place(int pos)
{
    int i;
    for (i = 1; i < pos; i++)
    {
        if ((a[i] == a[pos]) || ((abs(a[i] - a[pos]) == abs(i - pos))))
            return 0;
    }
    return 1;
}
void print_sol(int n)
{
    int i, j;
    for (i = n; i > 0; i--)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i] == j)
                cout << "Q\t";
            else
                cout << square[i-1][j-1].cot<<square[i-1][j-1].hang<<"\t";
        }
        cout << endl;
    }
}
void queen(int n)
{
    int k = 1;
    int count = 0;
    a[k] = 0;
    while (k != 0)
    {
        do
        {
            a[k]++;
        } while ((a[k] <= n) && !place(k));
        if (a[k] <= n)
        {
            if (k == n)
            {
                count++;
                cout << "cach lam thu: " << count << endl;
                print_sol(n);
                cout << endl;
                system("pause");
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
            k--;
    }
}
int main()
{
    int  n;
    cout<<"Enter the number of Queens\n";
    cin >> n;
    chess board;
    board.create(n);
    board.display(n);
    queen(n);
    return 0;
}