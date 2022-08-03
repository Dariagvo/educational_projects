#include <stdio.h>
#include <math.h>

#define screenX 82
#define screenY 27
#define score_screenY 3
#define score_screenX 82
#define number_score 27
#define racy_base 13
#define rack_l_base_x 1
#define rack_r_base_x 80
#define ball_base_x 41
#define ball_base_y 13

void field(int l, int r, int ballx, int bally, int score1, int score2);
int act_racket(int button, char rack, int now);
int action();
int move_ball(int ball, int touch, int way_ud, int way_rl, char axis);
int result_check(int score1, int score2, int ballx);

int main() {
    int score1 = 20, score2 = 20;
    int rackL = racy_base, rackR = racy_base;
    int ballx = ball_base_x, bally = ball_base_y;
    int way_ud = 1, way_rl = 1;
    int touch = 0;

    while (1) {
        field(rackL, rackR, ballx, bally, score1, score2);

        int button = action();
        if (button != 42) {
            if (button == 3) {
                printf("Thank you for the game! The score is %d : %d.\n",
                       score1, score2);
                break;
            }

            if ((ballx == 2 &&
                 (bally == rackL || bally == rackL + 1
                  || bally == rackL - 1)) ||
                (ballx == screenX - 3 &&
                 (bally == rackR || bally == rackR + 1
                  || bally == rackR - 1))) {
                touch = 1;
            }

            ballx = move_ball(ballx, touch, way_ud, way_rl, 'x');
            bally = move_ball(bally, touch, way_ud, way_rl, 'y');

            if (bally < 0) {
                if (touch) {
                    way_rl *= -1;
                    ballx *= -1;
                } else {
                    way_ud *= -1;
                }
                bally *= -1;
            }

            if (button != 10) {
                rackL -= act_racket(button, 'l', rackL);
                rackR -= act_racket(button, 'r', rackR);
            }
        }

        int res = result_check(score1, score2, ballx);
        if (res == 4 || res == -4) {
            ballx = ball_base_x;
            bally = ball_base_y;
            if (res == 4) {
                score2++;
            } else {
                score1++;
            }
        } else if (res == 5) {
            printf("CONGRATULATIONS, PLAYER 2!!!!!! YOU WON!!!!!!"
                   "The score is %d: 21.\n",
                   score1);
            break;
        } else if (res == -5) {
            printf("CONGRATULATIONS, PLAYER 1!!!!!! YOU WON!!!!!!"
                   "The score is 21 : %d.\n",
                   score2);
            break;
        }
        touch = 0;
    }
    return 0;
}

void field(int l, int r, int ballx, int bally, int score1, int score2) {
    for (int i = 0; i < score_screenY; i++) {
        for (int j = 0; j < score_screenX; j++) {
            if ((j == 0 && i != 0) || (j == score_screenX - 1 && i != 0)) {
                printf("|");
            } else if (i == 1) {
                if (j == 1) {
                    printf("Player 1: %02d | Player 2: %02d", score1, score2);
                } else if (j < score_screenX - 1 && j > number_score) {
                    printf(" ");
                }
            } else if ((i == 0 && j != 0 && j != (screenX - 1)) ||
                       (i == score_screenY - 1 && j != 0 &&
                        j != score_screenX - 1)) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }


    for (int i = 0; i < screenY; i++) {
        for (int j = 0; j < screenX; j++) {
            if (j == ballx && i == bally) {
                printf("@");
            } else if ((j == 0 && i != 0 && i != screenY - 1) ||
                (j == screenX - 1 && i != 0 && i != screenY - 1) ||
                (j == screenX / 2 && i != 0 && i != screenY - 1)) {
                printf("|");
            } else if ((j == rack_l_base_x &&
                        (i == l || i == l + 1 || i == l - 1)) ||
                       (j == rack_r_base_x &&
                        (i == r || i == r + 1 || i == r - 1))) {
                printf("0");
            } else if ((i == 0 && j != 0 && j != (screenX - 1)) ||
                       (i == screenY - 1 && j != 0 && j != screenX - 1)) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int act_racket(int button, char rack, int now) {
    int add = 0;

    if (rack == 'l') {
        if (button == 1 && now > 2) {
            add = 1;
        } else if (button == -1 && now < screenY - 3) {
            add = -1;
        }
    } else if (rack == 'r') {
        if (button == 2 && now > 2) {
            add = 1;
        } else if (button == -2 && now < screenY - 3) {
            add = -1;
        }
    }
    return add;
}

int action() {
    char button = getchar();

    int ans = 42;
    if (button == (' ')) {
        ans = 10;
    } else if (button == 'a') {
        ans = 1;
    } else if (button == 'z') {
        ans = -1;
    } else if (button == 'k') {
        ans = 2;
    } else if (button == 'm') {
        ans = -2;
    } else if (button == 'q') {
        ans = 3;
    }
    return ans;
}

int move_ball(int ball, int touch, int way_ud, int way_rl, char axis) {
    int new = ball;
    if (ball == 1 || ball == screenY - 2) {
        if (axis == 'x') {
            new += way_rl;
        }
        if (axis == 'y') {
            new += way_ud;
            new *= -1;
        }
    } else if (touch == 1) {
        if (axis == 'x') {
            new -= way_rl;
        } else if (axis == 'y') {
            new -= way_ud;
        }
        new *= -1;
    } else {
        if (axis == 'x') {
            new += way_rl;
        } else if (axis == 'y') {
            new -= way_ud;
        }
    }
    return new;
}

int result_check(int score1, int score2, int ballx) {
    int result = 0;
    if (ballx == 1) {
        result = -4;
    } else if (ballx == screenX - 1) {
        result = 4;
    }
    if (score1 == 21) {
        result = -5;
    } else if (score2 == 21) {
        result = 5;
    }

    return result;
}
