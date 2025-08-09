#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

struct EdgeInfo {
    int to;
    int distance;          // km
    string busName;        // বাসের নাম
    int fare;              // প্রতি যাত্রীর ভাড়া (টাকা)
};

int main() {
    vector<string> places = {
        "Airport", "Badda", "Banasree", "South_Banasree", "Bashaboo",
        "Jatrabari", "Rampura", "Aftabnagar", "Puran_Dhaka", "EWU"
    };
    int n = places.size();

    unordered_map<string, int> idx;
    for(int i = 0; i < n; i++) idx[places[i]] = i;

    vector<vector<EdgeInfo>> graph(n);

    // বাসের নাম, দূরত্ব, ভাড়া সহ দুই দিকের রাস্তা যুক্ত করার জন্য ফাংশন
    auto addEdge = [&](string u, string v, int dist, string busName, int fare) {
        graph[idx[u]].push_back({idx[v], dist, busName, fare});
        graph[idx[v]].push_back({idx[u], dist, busName, fare});
    };

    // রোড এবং বাস/ভাড়া ডাটা (অনুমানিক)
    addEdge("Airport", "Badda", 7, "BRTC বাস", 36);
    addEdge("Badda", "Banasree", 5, "Hanif Paribahan", 29);
    addEdge("Banasree", "South_Banasree", 2, "Hanif Paribahan", 15);
    addEdge("South_Banasree", "Aftabnagar", 3, "Sabbir Paribahan", 20);
    addEdge("Aftabnagar", "EWU", 2, "Sabbir Paribahan", 12);

    addEdge("Bashaboo", "Jatrabari", 4, "Greenway", 22);
    addEdge("Jatrabari", "Rampura", 3, "Greenway", 16);
    addEdge("Rampura", "Aftabnagar", 4, "Greenway", 18);
    addEdge("Puran_Dhaka", "Rampura", 6, "Shyamoli", 28);

    // Dijkstra Algorithm
    auto dijkstra = [&](string start, string end) {
        vector<int> dist(n, INF), parent(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int s = idx[start], t = idx[end];
        dist[s] = 0;
        pq.push({0, s});

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(u == t) break;
            if(d > dist[u]) continue;

            for(auto &edge : graph[u]) {
                int v = edge.to;
                int w = edge.distance;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[t] == INF) {
            cout << "No path found from " << start << " to " << end << ".\n";
            return;
        }

        // Path reconstruction
        vector<int> path;
        for(int cur = t; cur != -1; cur = parent[cur]) path.push_back(cur);
        reverse(path.begin(), path.end());

        cout << "\nShortest distance from " << start << " to " << end << " is " << dist[t] << " km.\n";
        cout << "Route:\n";

        int totalFare = 0;
        for(size_t i = 0; i + 1 < path.size(); i++) {
            int u = path[i], v = path[i+1];
            // Find edge info between u and v
            for(auto &edge : graph[u]) {
                if(edge.to == v) {
                    cout << places[u] << " → " << places[v] << " : Bus - " << edge.busName
                         << ", Distance: " << edge.distance << " km"
                         << ", Fare: " << edge.fare << " BDT\n";
                    totalFare += edge.fare;
                    break;
                }
            }
        }
        cout << "Total Estimated Fare: " << totalFare << " BDT\n\n";
    };

    cout << "Enter your starting location (e.g. Airport, Badda, Banasree, South_Banasree, Bashaboo, Jatrabari, Rampura, Aftabnagar, Puran_Dhaka): ";
    string startPlace;
    getline(cin, startPlace);

    if(idx.find(startPlace) == idx.end()) {
        cout << "Invalid starting location. Please check spelling and try again.\n";
        return 1;
    }

    dijkstra(startPlace, "EWU");

    return 0;
}
