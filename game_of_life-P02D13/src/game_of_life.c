/*
    Remember to check the code with:
    1. cppcheck --enable=all --suppress=missingIncludeSystem game_of_life.c 
    2. python3 ../materials/linters/cpplint.py --extensions=c game_of_life.c
*/
#include <ncurses.h>
#include <unistd.h>

#define N 27
#define M 82

int atlas();
int MC(int **gen_1, int **gen_2);
int genesis(int **gen_1, int **gen_2, int *biomass_1, int *biomass_2, FILE* F);
void connect(int **gen);
void darvin(int **gen_1, int **gen_2);
int scan(int **gen, int I, int J);
void gen_reset(int **gen_1, int **gen_2);
void output(int **gen);
int dead_stop(int **gen);
int harmony(int **gen_1, int **gen_2);

int main() {
    initscr();
    if (atlas())
        printw("n/a");
    endwin();
    return 0;
}

// main control sq
int atlas() {
    // printw("atlas()\n");
    int flag = 0;
    int *gen_1[N], *gen_2[N];
    int biomass_1[N * M], biomass_2[N * M];
    for (int i = 0; i < N; i++) {
        gen_1[i] = biomass_1 + i * M;
        gen_2[i] = biomass_2 + i * M;
    }
    FILE* F;
    int number; scanw("%d", &number);
    switch (number) {
        case 1: F = fopen("init/gliders", "rt");     break;
        case 2: F = fopen("init/gosper", "rt");      break;
        case 3: F = fopen("init/oscillators", "rt"); break;
        case 4: F = fopen("init/pulsar", "rt");      break;
        case 5: F = fopen("init/spaceships", "rt");  break;
    }
    flag = genesis(gen_1, gen_2, biomass_1, biomass_2, F);
    fclose(F);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    float h_time = 1;
    output(gen_1);
    printw("| Speed: %.2f |\n", h_time);
    while (!flag) {
        int key = getch();
        flushinp();
        if (key == KEY_UP && h_time != 2)
            h_time += 0.25;
        if (key == KEY_DOWN && h_time != 0.25)
            h_time -= 0.25;
        if (key == 'q')
            flag = 1;
        if (!flag) {
            usleep(1000 * 1000 * h_time);
            clear();
            flag = MC(gen_1, gen_2);
            printw("| Speed: %.2f |\n", h_time);
        }
        // refresh();
    }
    return flag;
}

int MC(int **gen_1, int **gen_2) {
    int flag = 0;
    darvin(gen_1, gen_2);
    flag = dead_stop(gen_2);
    if (!flag) {
        flag = harmony(gen_1, gen_2);
        if (!flag) {
            connect(gen_2);
            gen_reset(gen_1, gen_2);
            // printw("\e[1;1H\e[2J");
            output(gen_2);
        }
    }
    return flag;
}

// memory allocation and gen_1 input
int genesis(int **gen_1, int **gen_2, int *biomass_1, int *biomass_2, FILE* F) {
    // printw("genesis()\n");
    int flag = 0;
    for (int i = 1; i < N - 1 && !flag; i++) {
        for (int j = 1; j < M - 1 && !flag; j++) {
            fscanf(F, "%d", &gen_1[i][j]);
            if (gen_1[i][j] > 1 || gen_1[i][j] < 0)
                flag = 1;
        }
    }
    connect(gen_1);
    connect(gen_2);
    return flag;
}

// makes the thor surface
void connect(int **gen) {
    for (int i = 1; i < M - 1; i++) {
        gen[0][i] = gen[N - 2][i];
        gen[N - 1][i] = gen[1][i];
    }
    for (int i = 1; i < N - 1; i++) {
        gen[i][0] = gen[i][M - 2];
        gen[i][M - 1] = gen[i][1];
    }
    gen[0][0] = gen[N - 2][M - 2];
    gen[N - 1][M - 1] = gen[1][1];
    gen[0][M - 2] = gen[N - 2][1];
    gen[N - 1][0] = gen[1][M - 2];
}

// main sequence of life
void darvin(int **gen_1, int **gen_2) {
    // printw("darvin()\n");
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            gen_2[i][j] = scan(gen_1, i, j);
        }
    }
}

/*
    returns 1 if dot will live and 0 if it will perish
    scans around the dot and counts how many dots are alive
*/
int scan(int **gen, int I, int J) {
    // printw("scan()\n");
    int state = 0, count = 0;
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (gen[I - 1 + k][J - 1 + l])
                count++;
        }
    }
    if (gen[I][J]) {
        count--;
        if ((count < 2) || (count > 3))
            state = 0;
        else
            state = 1;
    } else {
        if (count == 3)
            state = 1;
        else
            state = 0;
    }
    return state;
}

// simply copies gen_2 into gen_1 for the next iteration
void gen_reset(int **gen_1, int **gen_2) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            gen_1[i][j] = gen_2[i][j];
        }
    }
}

// simple output
void output(int **gen) {
    int alive = 0, dead = 0;
    // printw("output()\n");
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (gen[i][j] == 1) {
                printw("XX");
                alive++;
            } else {
                printw("::");
                dead++;
            }
            if (j != M - 1)
                printw(" ");
        }
        printw("\n");
    }
    printw("| Alive:%d | Dead:%d | ", alive, dead);
}

// returns 1 if everything is dead
int dead_stop(int **gen) {
    // printw("dead_stop()\n");
    int flag = 1;
    for (int i = 1; i < N - 1 && flag; i++) {
        for (int j = 1; j < M - 1 && flag; j++) {
            if (gen[i][j])
                flag = 0;
        }
    }
    return flag;
}

/* 
    returns 1 if gen_1 and gen_2 are in harmony(equal)
    and returns 0 if they are not
*/
int harmony(int **gen_1, int **gen_2) {
    // printw("harmony()\n");
    int flag = 1;
    for (int i = 1; i < N - 1 && flag; i++) {
        for (int j = 1; j < M - 1 && flag; j++) {
            if (gen_1[i][j] != gen_2[i][j])
                flag = 0;
        }
    }
    return flag;
}
