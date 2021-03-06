#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long unsigned int lui;

#define NUM_DIRECTIONS 4

enum Direction {
    Up, Down,
    Right, Left,
};

constexpr Direction DIRECTIONS[] = { Up, Down, Right, Left };

void search(vector<bool>&, int&, const pair<int, int>&, int, int);

int main() {
    // faster input and output
    ios::sync_with_stdio(0);
    cin.tie(0);

    int grid_size;
    cin >> grid_size;

    vector<bool> grid(grid_size * grid_size, false);
    int paths = 0;
    pair<int, int> rows_and_cols = make_pair(grid_size, grid_size);

    search(grid, paths, rows_and_cols, 0, 0);

    cout << "#Paths: " << paths << "\n";

    return 0;
}

void search(vector<bool>& grid, int& paths, 
            const pair<int, int>& rc, int visited,
            int pos) {
    grid[pos] = true;

    if ((lui) pos == grid.size() - 1) {
        if ((lui) visited == grid.size() - 1) {
            paths++;
        }
        return;
    }

    vector<int> valid_positions;
    int next_pos_sum = 0;

    for (Direction dir : DIRECTIONS) {
        int next_pos = 0;

        switch (dir) {
            case Up:
                next_pos = pos - rc.first;
                break;
            case Down:
                next_pos = pos + rc.first;
                break;
            case Right:
                next_pos = (pos % rc.first) + 1 == rc.second ? -1 : pos + 1;
                break;
            case Left:
                next_pos = (pos % rc.first) - 1 < 0 ? -1 : pos - 1;
                break;
        }

        if ((next_pos >= 0 && next_pos < rc.first * rc.second) &&
             !grid[next_pos]) {
            valid_positions.push_back(next_pos);
            next_pos_sum += next_pos;
        }
    }

    if (valid_positions.size() == NUM_DIRECTIONS / 2 &&
        next_pos_sum == pos * (NUM_DIRECTIONS / 2)) {
        return;
    }

    for (int next_pos : valid_positions) {
        search(grid, paths, rc, visited+1, next_pos);
        grid[next_pos] = false;

        if (pos == 0) {
            paths *= 2;
            break;
        }
    }
}
