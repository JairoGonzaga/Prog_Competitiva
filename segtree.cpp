#include <bits/stdc++.h>
using namespace std;
#define ll long long
class segtree
{
private:
    ll* vetor;
public:
    segtree(ll N){
        vetor = new ll[N*4];
    }
    ~segtree(){
        delete[] vetor;
    }
    void build(ll vet[], ll esq, ll direita, ll v){
        if(esq == direita){
            vetor[v] == vet[esq]; 
        }else{
            int newindc = (esq+direita)/2;
            build(vet,esq,newindc,v*2);
            build(vet,newindc+1,direita,v*2+1);
            vetor[v]=vetor[v*2]+vetor[v*2+1];

        }
    }
    ll sum(ll v, ll esq, ll direita, ll l, ll r){

        if(l>r) return 0;
        if(l==esq && r == direita) return vetor[v];
        ll ni = (esq+direita)/2;
        return sum(v*2, esq, ni, l, min(r, ni)) + sum(v*2+1, ni+1, direita, max(l, ni+1), r);
        
    }
    ll minimo(ll v, ll esq, ll direita, ll l, ll r){

        if(l>r) return LLONG_MAX;
        if(l==esq && r == direita) return vetor[v];
        ll ni = (esq+direita)/2;
        return min(minimo(v*2, esq, ni, l, min(r, ni)), minimo(v*2+1, ni+1, direita, max(l, ni+1), r));
        
    }
    ll maximo(ll v, ll esq, ll direita, ll l, ll r){

        if(l>r) return LLONG_MIN;
        if(l==esq && r == direita) return vetor[v];
        ll ni = (esq+direita)/2;
        return max(maximo(v*2, esq, ni, l, min(r, ni)), maximo(v*2+1, ni+1, direita, max(l, ni+1), r));
        
    }
    void update(int v, int esq, int direita, int pos, int new_val) {
    if (esq == direita) {
        vetor[v] = new_val;
    } else {
        int tm = (esq + direita) / 2;
        if (pos <= tm)
            update(v*2, esq, tm, pos, new_val);
        else
            update(v*2+1, tm+1, direita, pos, new_val);
        vetor[v] = vetor[v*2] + vetor[v*2+1];
    }
}
};

