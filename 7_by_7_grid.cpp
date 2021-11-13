#include <bits/stdc++.h>

#define DIRECTIONS 4

using namespace std;

typedef long long ll;
typedef long unsigned int lui;

void search(vector<bool>&, int&, int, int);
void search_possible_directions(const int&, const vector<bool>&,
                                pair<bool, int>[]);

int main() {
    // faster input and output
    ios::sync_with_stdio(0);
    cin.tie(0);

    int grid_size;
    cin >> grid_size;

    vector<bool> grid(grid_size * grid_size, false);
    int paths = 0;

    search(grid, paths, 0, 0);

    cout << "#Paths: " << paths << "\n";

    return 0;
}

void search(vector<bool>& grid, int& paths, int squares, int pos) {
    grid[pos] = true;

    if ((lui) pos == grid.size() - 1) {
        if ((lui) squares == grid.size() - 1) {
            paths++;
        }
        return;
    }

    pair<bool, int> possible_directions[DIRECTIONS] = { make_pair(false, -1) };
    
    search_possible_directions(pos, grid, possible_directions);

    for (int i = 0; i < DIRECTIONS; i++) {
        if (!possible_directions[i].first) {
            continue;
        }
        search(grid, paths, squares+1, possible_directions[i].second);
        grid[possible_directions[i].second] = false;
    }
}

void search_possible_directions(const int& pos, const vector<bool>& grid,
                                pair<bool, int> possible_directions[]) {
    const int ROWS = sqrt(grid.size());
    const int COL = pos % ROWS;
    // const int ROW = pos / ROWS;

    for (int i = 0; i < DIRECTIONS; i++) {
        switch (i) {
            case 0:
                if (!(COL == 0 || grid[pos - 1])) {
                    possible_directions[i].first = true;
                    possible_directions[i].second = pos - 1;
                }
                break;
            case 1:
                if (!((lui) (pos + ROWS) > grid.size() || grid[pos + ROWS])) {
                    possible_directions[i].first = true;
                    possible_directions[i].second = pos + ROWS;
                }
                break;
            case 2:
                if (!(pos - ROWS < 0 || grid[pos - ROWS])) {
                    possible_directions[i].first = true;
                    possible_directions[i].second = pos - ROWS;
                }
                break;
            case 3:
                if (!(COL == ROWS - 1 || grid[pos + 1])) {
                    possible_directions[i].first = true;
                    possible_directions[i].second = pos + 1;
                }
                break;
        }
    }
}
