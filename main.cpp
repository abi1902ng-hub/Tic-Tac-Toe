/*
 ============================================================
   TIC TAC TOE — Console Game in C++
   Features: Loops, Arrays, Conditions, Win/Draw Detection,
             Colourful ANSI Output, Score Tracking, Replay
 ============================================================
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ── ANSI Colour Codes ──────────────────────────────────────
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"
#define BG_BLUE "\033[44m"
#define BG_DARK "\033[40m"

// ── Game State ─────────────────────────────────────────────
char board[3][3];
int  scoreX = 0, scoreO = 0, draws = 0;

// ── Utilities ──────────────────────────────────────────────
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printBanner() {
    cout << BOLD << CYAN;
    cout << "  ╔════════════════════════════╗\n";
    cout << "  ║  " << MAGENTA << "T I C  T A C  T O E" << CYAN << "       ║\n";
    cout << "  ╚════════════════════════════╝\n" << RESET;
}

void printScoreboard() {
    cout << BOLD << BG_DARK;
    cout << "\n  ┌──────────────────────────────────────────────┐\n";
    cout << "  │  " << RED  << "✕  Player 1: " << scoreX
         << "   " << CYAN << "○  Player 2: " << scoreO
         << "   " << YELLOW << "Draws: " << draws
         << RESET << BOLD << BG_DARK << "  │\n";
    cout << "  └──────────────────────────────────────────────┘\n" << RESET;
}

void initBoard() {
    int k = 1;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            board[r][c] = '0' + k++;
}

// Colour-code a cell: number = grey hint, X = red, O = cyan
string cellStr(char ch) {
    if (ch == 'X') return string(RED)  + BOLD + " X " + RESET;
    if (ch == 'O') return string(CYAN) + BOLD + " O " + RESET;
    return string(WHITE) + " " + ch + " " + RESET;
}

void printBoard() {
    cout << "\n";
    for (int r = 0; r < 3; r++) {
        cout << "  ";
        for (int c = 0; c < 3; c++) {
            cout << cellStr(board[r][c]);
            if (c < 2) cout << BOLD << YELLOW << "│" << RESET;
        }
        cout << "\n";
        if (r < 2) {
            cout << BOLD << YELLOW
                 << "  ───┼───┼───\n" << RESET;
        }
    }
    cout << "\n";
}

// ── Win / Draw Logic ───────────────────────────────────────
bool checkWinner(char p) {
    // Rows & cols
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    // Diagonals
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}

bool isBoardFull() {
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (board[r][c] != 'X' && board[r][c] != 'O')
                return false;
    return true;
}

// ── Input Validation ───────────────────────────────────────
int getMove(char player) {
    int move;
    string colour = (player == 'X') ? RED : CYAN;
    while (true) {
        cout << colour << BOLD << "  Player " << (player == 'X' ? "1 (✕)" : "2 (○)")
             << RESET << " → Enter cell (1-9): ";
        if (cin >> move && move >= 1 && move <= 9) {
            int r = (move - 1) / 3, c = (move - 1) % 3;
            if (board[r][c] != 'X' && board[r][c] != 'O')
                return move;
            cout << RED << "  ✗ Cell taken! Try another.\n" << RESET;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "  ✗ Invalid input. Enter 1–9.\n" << RESET;
        }
    }
}

// ── Main Game Loop ─────────────────────────────────────────
void playTicTacToe() {
    initBoard();
    char current = 'X';

    while (true) {
        clearScreen();
        printBanner();
        printScoreboard();
        printBoard();

        // Show whose turn
        string colour = (current == 'X') ? RED : CYAN;
        cout << colour << BOLD
             << "  ► Player " << (current == 'X' ? "1 (✕)" : "2 (○)")
             << "'s turn\n" << RESET;

        int move = getMove(current);
        int r = (move - 1) / 3, c = (move - 1) % 3;
        board[r][c] = current;

        if (checkWinner(current)) {
            clearScreen();
            printBanner();
            printScoreboard();
            printBoard();
            if (current == 'X') scoreX++; else scoreO++;
            cout << GREEN << BOLD;
            cout << "  ╔══════════════════════════════╗\n";
            cout << "  ║  🏆  Player "
                 << (current == 'X' ? "1 (✕)" : "2 (○)")
                 << " WINS!       ║\n";
            cout << "  ╚══════════════════════════════╝\n" << RESET;
            break;
        }

        if (isBoardFull()) {
            clearScreen();
            printBanner();
            printScoreboard();
            printBoard();
            draws++;
            cout << YELLOW << BOLD;
            cout << "  ╔═══════════════════════╗\n";
            cout << "  ║  🤝  It's a DRAW!      ║\n";
            cout << "  ╚═══════════════════════╝\n" << RESET;
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }
}

int main() {
    clearScreen();
    char replay;
    do {
        playTicTacToe();
        printScoreboard();
        while (true) {
            cout << MAGENTA << BOLD << "\n  Play again? (y/n): " << RESET;
            cin >> replay;
            if (replay == 'y' || replay == 'Y' || replay == 'n' || replay == 'N') break;
            cout << RED << "  ✗ Invalid input! Please enter 'y' for Yes or 'n' for No.\n" << RESET;
        }
    } while (replay == 'y' || replay == 'Y');

    cout << GREEN << BOLD << "\n  Thanks for playing! Goodbye! 👋\n\n" << RESET;
    return 0;
}
