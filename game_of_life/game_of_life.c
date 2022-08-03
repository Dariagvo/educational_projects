#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define Y 25
#define X 80

int **matrix_malloc();
void input_matrix(int **a);
void run_game(int **a, int **b);
void life_act(int **a, int **b);
int check_neighbours(int **a, int y, int x);
void draw(int **a);

int main() {
    int ** arr;
    int ** arr_2;
    arr = matrix_malloc();
    arr_2 = matrix_malloc();
    input_matrix(arr);
    run_game(arr, arr_2);

    for (int i = 0; i < Y; i++) {
        free(arr[i]);
    }
    free(arr);
    for (int i = 0; i < Y; i++) {
        free(arr_2[i]);
    }
    free(arr_2);
    return 0;
}

int **matrix_malloc() {
    int ** ans = malloc(Y * sizeof(int*));
    for (int i = 0; i < Y; i++) {
        ans[i] = malloc(X * sizeof(int));
    }
    return ans;
}

void input_matrix(int **a) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
}

void run_game(int **a, int **b) {
    initscr();
    int ticks = 0;
    int speed = 10;
    char c = ' ';
    nodelay(stdscr, true);
    noecho();
    while (c != 'q' && c != 'Q') {
        if (freopen("/dev/tty", "r+", stdin) != NULL) {
            clear();
            if (ticks % 2 == 0) {
                life_act(a, b);
                draw(b);
            } else {
                life_act(b, a);
                draw(a);
            }
            ticks++;
            c = getch();
            if ((c == 'a' || c == 'A') && speed < 50000)
                speed *= 10;
            if ((c == 'z' || c == 'Z') && speed > 1)
                speed /= 10;
            refresh();
            usleep(5000000/speed + 500000);
        }
    }
    endwin();
}

void life_act(int **a, int **b) {
    int n;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            n = check_neighbours(a, i, j);
            if (a[i][j] == 0) {
                if (n == 3) {
                    b[i][j] = 1;
                } else {
                    b[i][j] = 0;
                }
            } else {
                if (n < 2 || n > 3) {
                    b[i][j] = 0;
                } else {
                    b[i][j] = 1;
                }
            }
        }
    }
}

int check_neighbours(int **a, int y, int x) {
    int neighbours = 0;
    int m = 0, n = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            m = y + i;
            n = x + j;
            if (m < 0)
                m += Y;
            else if (m > Y - 1)
                m -= Y;
            if (n < 0)
                n += X;
            else if (n > X - 1)
                n -= X;
            if (a[m][n] == 1)
                neighbours++;
        }
    }
    return neighbours;
}

void draw(int **a) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (a[i][j] == 1) {
                printw("#");
            } else if (a[i][j] == 0) {
                printw(" ");
            }
        }
    }
}
