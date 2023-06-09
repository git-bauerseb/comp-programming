#include <iostream>
#include <cstring>

using namespace std;


// UVa 11450
// Top-down DP

// state: (garmet, money)

const int MAX_GARMENT = 19;
const int MAX_MONEY = 200;
int memo[MAX_GARMENT+1][MAX_MONEY+1];

int M, C;
int price[25][25];  // [GARMENT][MODEL]

// State: (garment, money)
// Given a particular garment and a remaining amount of money,
// returns the maximum amount of money that can be spent or -1
// if no spending is possible without spending more than M
int topDown(int garment, int money) {
    if (money < 0) return -1;
    
    // At the end, compute best or print that no solution exists
    if (garment == C) {
        return M - money;
    }


    int& entry = memo[garment][money];
    if (entry >= 0) return entry;

    entry = -1;

    for (int i = 0; price[garment][i] >= 0; ++i) {
        entry = max(entry,
                topDown(garment+1, money - price[garment][i])
                );
    }

    return entry;
}

// state[g][m] := true if in garment g, a total price of m can be achieved
bool state[MAX_GARMENT+2][MAX_MONEY+2];

// Time complexity: O(n^3)
void bottomUp() {

    for (int model = 0; price[0][model] >= 0; ++model) {
        state[0][price[0][model]] = true;
    }

    for (int g = 1; g < C; ++g) {
        for (int model = 0; price[g][model] >= 0; ++model) {
            int cp = price[g][model];

            for (int money = cp; money <= M; ++money) {
                state[g][money] |= state[g-1][money-cp];
            }
        }
    }

    int largest = -1;
    for (int money = M; money >= 0; --money) {
        if (state[C-1][money]) {largest = money; break;}
    }

    if (largest >= 0) printf("%d\n", largest);
    else printf("no solution\n");
}

// Only use two rows because DP depends only on previous state
bool state2[2][MAX_MONEY+2];


void bottomUpSpaceEfficient() {

    for (int model = 0; price[0][model] >= 0; ++model) {
        state2[0][price[0][model]] = true;
    }

    // Keep track of where last row is
    bool last = false;

    for (int g = 1; g < C; ++g) {
        for (int model = 0; price[g][model] >= 0; ++model) {
            int cp = price[g][model];
            for (int money = cp; money <= M; ++money) {
                state2[1][money] |= state2[0][money-cp];
            }
        }

        // Swap rows
        std::swap(state2[0], state2[1]);
        memset(state2[1], false, sizeof state2[1]);
    }

    int largest = -1;
    for (int money = M; money >= 0; --money) {
        if (state2[0][money]) {largest = money; break;}
    }

    if (largest >= 0) printf("%d\n", largest);
    else printf("no solution\n");
}


// UVa 11450 sample problem
void sample() {
    int tt; cin >> tt;

    while (tt--) {
        // memset(memo, -1, sizeof memo);
        
        memset(price, -1, sizeof price);
        memset(state2, false, sizeof state2);

        cin >> M >> C;

        for (int g = 0; g < C; ++g) {
            int len; cin >> len;
            for (int i = 0; i < len; ++i) {
                cin >> price[g][i];
            }
        }

        bottomUpSpaceEfficient();
    }
}

int main() {
    sample();
    return 0;
}
