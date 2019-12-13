#define scd second
#define fst first
#define pb push_back
#define mkp make_pair
#define all(x) x.begin(), x.end()
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vint> vvint;
typedef vector<vlong> vvlong;
typedef list<int> lint;
typedef list<ll> llong;
typedef list<pii> lpii;
typedef list<pll> lpll;
typedef list<lint> llint;
typedef list<llong> lllong;

/**
 * problem : Course Schedule II
 * description : https://leetcode.com/problems/course-schedule-ii/
 * 
 * Algorithm :
 * 1. lets construct a directed graph with following rule
 *      - if cource p prerequisites cource r then create an edge [r-->p]
 * 2. use dijkstra algorithm where the nodes are sorted based on in-degree
 * 3. as vertices are popped from queue store them in a vector and 
 *    return it if all vertices can be visited else return empty.
 */

class Solution {
public:
    vint findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vint graph[numCourses];
        vint in_degree(numCourses,0), order;
        for(auto x : prerequisites){
            graph[x[1]].pb(x[0]);
            in_degree[x[0]]++;
        }
        set<pii> pq;
        for(int i=0; i<numCourses; i++){
            if(in_degree[i]==0){
                pq.insert({in_degree[i],i});
            }
        }
        while(!pq.empty()){
            auto p=*pq.begin();
            pq.erase(pq.begin());
            order.pb(p.scd);
            for(auto x : graph[p.scd]){
                in_degree[x]--;
                if(in_degree[x]==0){
                    pq.insert({in_degree[x],x});
                }
            }
        }

        for(int i=0; i<numCourses; i++){
            if(in_degree[i]!=0) return {};
        }
        return order;
    }
};