#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
           projects.emplace_back(capital[i], profits[i]); 
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap; // Heap para maior lucro
        
        int j = 0;
        for (int i = 0; i < k; ++i) {
            while (j < n && projects[j].first <= w) {
                maxHeap.push(projects[j].second); // Coloca no heap os projetos que
                j++;                              // cabem no orçamento atual
            }

            if (maxHeap.empty()) break;           // Não existe projeto viável

            w += maxHeap.top();                   // Maior lucro possível no momento
            maxHeap.pop();                        // e aumenta o orçamento
        }

        return w;
    }
};

int main() {
    Solution s;
    int k = 3, w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,2};

    cout << s.findMaximizedCapital(k, w, profits, capital) << "\n";

    return 0;
}
