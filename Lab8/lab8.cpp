#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    list<int> line;  // шеренга
    unordered_map<int, list<int>::iterator> pos; // номер -> позиція
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (pos.find(y) == pos.end()) {
            // якщо немає — в кінець
            line.push_back(x);
            auto it = line.end();
            --it;
            pos[x] = it;
        }
        else {
            // вставка перед y
            auto it = pos[y];
            auto inserted = line.insert(it, x);
            pos[x] = inserted;
        }
    }
    for (int x : line) {
        cout << x << " ";
    }
    return 0;
}