    #include<iostream>
    #include<map>
    #include<vector>

    using namespace std;

    class roadMap {
    public:
        roadMap(int N) {
            data = new map<int, int>[N];
            size = N;
        }
        ~roadMap() {
            delete[] data;
        }
        void road(int a, int b, int Cost) {
            data[a][b] = Cost;
            data[b][a] = Cost;
        }
        void search(int a, int b, int fuel) {
            vector<int> route;
            bool visited[size];
            for (int i= 0; i< size; i++) visited[i] = false;
            int c = 1;
            if (findRoute(a, b, fuel, visited, route, c, fuel)) {
                cout << "POSSIBLE: " << c << " fill(s),";
                for (int i:route) {
                    cout << " " << i;
                }
                cout << endl;
            }else{
                cout << "IMPOSSIBLE" << endl;
            }
        }
    private:
        bool findRoute(int curr, int to, int fuel, bool visited[], vector<int> &route, int &c, int ipol) {
            route.push_back(curr);
            visited[curr] = true;

            for (pair<int, int> i:data[curr]) {
                int goesTo = i.first;
                int Cost = i.second;
                if (goesTo == to && Cost <= fuel) {
                    if (Cost > ipol) c++;
                    route.push_back(to);
                    return true;
                }
                else if (!visited[goesTo] && Cost <= fuel) {
                    int d = c;
                    int ipol2 = ipol;
                    if (Cost > ipol) {
                        d++;
                        ipol2 = fuel;
                    }
                    ipol2 -= Cost;
                    if (findRoute(goesTo, to, fuel, visited, route, d, ipol2)) {
                        c = d;
                        return true;
                    }
                }
            }
            route.pop_back();
            return false;
        }
        map<int, int> *data;
        int size;
    };

    int main() {
        int N, M, U, V, L, Q, A, B, C;
        cin >> N >> M;
        roadMap s(N);
        for (int i= 0; i< M; i++) {
            cin >> U >> V >> L;
            s.road(U, V, L);
        }
        cin >> Q;
        for (int i= 0; i< Q; i++) {
            cin >> A >> B >> C;
            s.search(A, B, C);
        }
    }
