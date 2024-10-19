#include <iostream>
#include <vector>
#include <windows.h>
#include <csignal>

using namespace std;

struct Cell
{
    string password;
    int order = 0;
};

int getSize();
void printMatrix();
void createMatrix(int rows, int cols);
void postomat();
int checkUser();
int checkCellS(int num);
int postProd(int num);

vector<vector<Cell>> matrix;
int rows, cols;

HANDLE hConsole;

BOOL WINAPI CtrlHandler(DWORD signal)
{
    if (signal == CTRL_C_EVENT)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        exit(0);
    }
    return TRUE;
}

int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    cout << "\tPlease choose the size of the poster:\n";
    cout << "\t1 < 6 x 2\n";
    cout << "\t2 < 6 x 4\n";
    cout << "\tEnter the num: ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    int size = getSize();
    rows = 6;
    cols = size;

    createMatrix(rows, cols);
    postomat();

    return 0;
}

void postomat()
{
    for (;;)
    {
        cout << "\n\tPlease select the status:\n";
        cout << "\t1 < User\t2 < Courier\t3 < GetPostomat\n\t";
        checkUser();
    }
}

void printMatrix()
{
    cout << "\n\nGenerated Matrix (" << rows << "x" << cols << "):\n";
    for (const auto &row : matrix)
    {
        for (const auto &cell : row)
        {
            if (cell.order == 0)
            {
                cout << "[ Empty ]";
            }
            else
            {
                cout << "[ " << cell.order << " ]";
            }
        }
        cout << endl;
    }
}

int checkUser()
{
    int user, productCode;
    cin >> user;

    switch (user)
    {
    case 1:
        cout << "\tEnter the product code:\n\t";
        cin >> productCode;
        if (checkCellS(productCode))
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            cout << "\tThe product was taken away\n";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        return 1;

    case 2:
        cout << "\tEnter the product code:\n\t";
        cin >> productCode;
        if (!postProd(productCode))
        {
            cout << "\tNo empty cells available\n";
        }
        return 2;

    case 3:
        printMatrix();
        return 3;

    default:
        cout << "\tPlease enter the correct data\n";
    }
    return checkUser();
}

int postProd(int num)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j].order == 0)
            {
                matrix[i][j].order = num;
                //  string password;
                cout << "\tEnter password: ";
                cin >> matrix[i][j].password;
                cout << "\tProduct " << num << " placed at (" << i << ", " << j << ")\n";
                return 1;
            }
        }
    }
    return 0;
}

int checkCellS(int num)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j].order == num)
            {
                string password;
                while (matrix[i][j].password != password)
                {
                    cout << "\tEnter password: ";
                    cin >> password;
                    if (password != matrix[i][j].password)
                    {
                        cout << "\tPassword not correct!\n";
                        return 0;
                    }
                }
                matrix[i][j].order = 0;
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

                cout << "\tProduct " << num << " taken from (" << i << ", " << j << ")\n";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                return 1;
            }
        }
    }
    cout << "\n\tElement " << num << " not found in the matrix.\n";
    return 0;
}

int getSize()
{
    int num;
    cin >> num;

    switch (num)
    {
    case 1:
        return 2;
    case 2:
        return 4;
    default:
        cout << "This size does not exist, please enter one 1 or 2\n";
    }
    return getSize();
}

void createMatrix(int rows, int cols)
{
    matrix.resize(rows, vector<Cell>(cols));

    cout << "\n\nGenerated Matrix (" << rows << "x" << cols << "):\n\n";
    for (const auto &row : matrix)
    {
        for (const auto &cell : row)
        {
            cout << "[ Empty ]";
        }
        cout << endl;
    }
}
