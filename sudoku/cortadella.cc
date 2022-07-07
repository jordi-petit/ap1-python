#include <iostream>
#include <vector>

using namespace std;

// Data structures
using Grid = vector<vector<int>>; // Matrix of the sudoku
using Used = vector<vector<bool>>; // To represent conflicts

// Structure to represent the information required to
// solve a Sudoku (grid and matrices of conflicts)
struct Sudoku {
    Grid G; // the main grid
    Used Rows; // conflicts for rows
    Used Columns; // conflicts for columns
    Used Squares; // conflicts for squares
};

// Function to initialize the Sudoku structure.
// Post: The Sudoku initialized as empty.
void initSudoku(Sudoku& S)
{
    S.G = Grid(9, vector<int>(9, 0)); // 9x9 matrix, all zeros
    // And now the matirces for conflicts: no conflicts at the beggining
    S.Rows = S.Columns = S.Squares = Used(9, vector<bool>(10, false));
}

// Function to write a cell of the sudoku.
// Pre:  S is a Sudoku partially filled in.
// Post: Cell (r,c) is filled in with value v if no conflict is
//       produced. The Sudoku is not changed in case of conflict.
// Returns true if no conflict, or false otherwise.
bool writeCell(Sudoku& S, int r, int c, int v)
{
    int sq = 3 * (r / 3) + c / 3;
    if (S.Rows[r][v] or S.Columns[c][v] or S.Squares[sq][v])
        return false;
    S.Rows[r][v] = S.Columns[c][v] = S.Squares[sq][v] = true;
    S.G[r][c] = v;
    return true;
}

// Reads a sudoku from cin.
// Pre: the input has 81 digits in {‘0’,…,‘9’}
// Post: The Sudoku S has been read from cin.
// Returns true if the Sudoku is correct, or false otherwise.
bool readSudoku(Sudoku& S)
{

    initSudoku(S); // empty Sudoku

    for (int r = 0; r < 9; ++r) { // Read all rows and columns
        for (int c = 0; c < 9; ++c) {
            char digit;
            cin >> digit;
            int n = int(digit - '0'); // Convert to int
            if (n != 0 and not writeCell(S, r, c, n))
                return false;
        }
    }

    return true; // Correct sudoku
}

// Writes a sudoku into cout.
// Pre:  S is a complete Sudoku.
// Post: The Sudoku has been printed into cout.
void writeSudoku(const Sudoku& S)
{
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c)
            cout << S.G[r][c];
        cout << endl;
    }
}

// Erases a cell of the sudoku.
// Pre:  The Sudoku S has a value in cell (r,c).
// Post: Cell (r,c) has been erased.
void eraseCell(Sudoku& S, int r, int c)
{
    int v = S.G[r][c]; // Gets the value
    S.G[r][c] = 0; // Erases the value

    // Cleans the conflict matrices for the value
    int sq = 3 * (r / 3) + c / 3;
    S.Rows[r][v] = S.Columns[c][v] = S.Squares[sq][v] = false;
}

// Main function to solve the sudoku (recursively).
// S is a sudoku partially filled in.
// All the cells previous to (r,c) have already been filled in.
// If the Sudoku is solvable without modifying the previous cells,
// then it solves it and returns true.
// If the Sudoku is not solvable, it returns false.
// Post: if solvable, the complete sudoku is filled in.
//       if not solvable, the sudoku is not modified.
bool solveSudokuRec(Sudoku& S, int r, int c)
{
    if (r == 9)
        return true; // Yupee! (Sudoku completed)

    int next_r = r + c / 8; // Next row (increase when c=8)
    int next_c = (c + 1) % 9; // Next column (0 if c+1=9)

    // If cell is not empty, don’t touch and go to next cell
    if (S.G[r][c] != 0)
        return solveSudokuRec(S, next_r, next_c);

    // Try all possible values from 1 to 9
    for (int v = 1; v <= 9; ++v) {
        if (writeCell(S, r, c, v)) {
            if (solveSudokuRec(S, next_r, next_c))
                return true; // Yupee!
            eraseCell(S, r, c); // Backtrack
        }
    }

    return false;
}

// Pre: S is a correct and possibly incomplete Sudoku.
// Returns true if the Sudoku is solvable, or false otherwise.
// Post: If solvable, the S contains a solution.
bool solveSudoku(Sudoku& S)
{
    return solveSudokuRec(S, 0, 0);
}

// The program reads a Sudoku and tries to solve it.
// In case it is solvable, it writes a solution.
int main()
{
    Sudoku S;
    if (not readSudoku(S)) {
        cout << "The Sudoku is incorrect." << endl;
    } else if (not solveSudoku(S)) {
        cout << "The Sudoku has no valid solution." << endl;
    } else {
        writeSudoku(S);
    }
}
