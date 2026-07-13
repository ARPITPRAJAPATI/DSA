#include <bits/stdc++.h>
using namespace std;

long long maximumTP(int foods,long long maxFoods,vector<long long>& v,vector<long long>& d
) {
   priority_queue<pair<long long, int>> pq;
    for(int i=0;i<foods;i++){
        pq.push({v[i],i});
    }
    long long ans = 0;
    for(long long meal = 0;meal<maxFoods;meal++){
        pair<long long , int > current = pq.top();
        pq.pop();

        long long currentFood = current.first;
        if (currentFood <= 0) {
            break;
        }
        int currentfoodIndex = current.second;
        ans = ans + current.first;
        currentFood = currentFood - d[currentfoodIndex];
        pq.push({currentFood,currentfoodIndex});
    }
    return ans;
}

int main() {
    int foods;
    cin >> foods;

    long long maxFoods;
    cin >> maxFoods;

    vector<long long> v(foods);
    for (int i = 0; i < foods; i++) {
        cin >> v[i];
    }

    vector<long long> d(foods);
    for (int i = 0; i < foods; i++) {
        cin >> d[i];
    }

    long long answer = maximumTP(foods, maxFoods, v, d);

    cout << answer;
    return 0;
}



