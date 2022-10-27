/*
ID: duttaso2
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> allOrders;
void getAllPairs(int remaining, vector<int>& order, vector<bool>& picked) {
    if (remaining == 0) {
        allOrders.push_back(order);
        return;
    }

    int pos = 0;
    while (pos < picked.size() && picked[pos]) {
        pos++;
    }

    int firstPos = pos;
    order.push_back(firstPos);
    picked[firstPos] = true;
    pos++;

    while (pos < picked.size()) {
        if (!picked[pos]) {
            picked[pos] = true;
            order.push_back(pos);
            getAllPairs(remaining - 2, order, picked);
            picked[pos] = false;
            order.pop_back();
        }

        pos++;
    }

    picked[firstPos] = false;
    order.pop_back();
}

int startType;
bool detectLoop(int start, int prevNode, int node, vector<vector<int>>& pairEdges, vector<vector<int>>& xAxisEdges, vector<bool>& visited, int prev = -1) {
    int edge =  prevNode * 100 + node;
    if (prevNode != -1 && visited[edge])
        return true;

    if (prevNode != -1)
        visited[edge] = true;

    bool value = false;
    for (int i = 0; i < pairEdges[node].size() && !value && prev != 0; i++) {
        if (prev == -1)
            startType = 0;
        value = detectLoop(start, node, pairEdges[node][i], pairEdges, xAxisEdges, visited, 0);
    }

    for (int i = 0; i < xAxisEdges[node].size() && !value && prev != 1; i++) {
        if (prev == -1)
            startType = 1;
        value = detectLoop(start, node, xAxisEdges[node][i], pairEdges, xAxisEdges, visited, 1);
    }

    if (prevNode != -1)
        visited[edge] = false;

    return value;
}

bool isLoop(vector<int>& pairs, vector<vector<int>>& xAxisEdges) {
    vector<vector<int>> pairEdges(pairs.size());
    for (int i = 0; i < pairs.size(); i += 2) {
        pairEdges[pairs[i]].push_back(pairs[i + 1]);
        pairEdges[pairs[i + 1]].push_back(pairs[i]);
    }

    bool isLoopDetected = false;
    for (int i = 0; i < pairs.size(); i++) {
        vector<bool> visited(1212, false);
        if (detectLoop(i, -1, i, pairEdges, xAxisEdges, visited)) {
            isLoopDetected = true;
            break;
        }
    }

    return isLoopDetected;
}

class comparator {
    public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

int main(void) {
    FILE *in, *out;
    in = fopen("wormhole.in", "r");
    out = fopen("wormhole.out", "w");
    
    int n, x, y;
    vector<pair<int, int>> positions;

    fscanf(in, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(in, "%d %d", &x, &y);
        positions.push_back({x, y});
    }

    sort(positions.begin(), positions.end(), comparator());

    vector<vector<int>> xAxisEdges(positions.size());
    for (int i = 1; i < positions.size(); i++) {
        if (positions[i].second == positions[i - 1].second) {
            xAxisEdges[i - 1].push_back(i);
        }
    }

    vector<bool> picked(n, false);
    vector<int> order;
    getAllPairs(n, order, picked);

    int ctr = 0;
    for (int i = 0; i < allOrders.size(); i++) {
        if (isLoop(allOrders[i], xAxisEdges))
            ctr++;
    }

    fprintf(out, "%d\n", ctr);
    fclose(in);
    fclose(out);

    return 0;
}