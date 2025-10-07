#include <bits/stdc++.h>
using namespace std;
#define ll long long
class dsu
{
private:
    vector<ll> pai, sz;
public:
    dsu(ll n) :  pai(n+1), sz(n+1, 1){
        for (int i = 0; i < n; i++)
            pai[i]=i;        
    }
    int find(ll idx){
        return pai[idx]==idx ? idx:pai[idx]=find(pai[idx]);
    }
    void join(ll id_p, ll id_f ){
        id_p=find(id_p),id_f=find(id_f);
        if(id_p==id_f) return;
        if(sz[id_f] > sz[id_p]) swap(id_f, id_p);

		pai[id_f] = id_p;
		sz[id_p] += sz[id_f];

    }
};

