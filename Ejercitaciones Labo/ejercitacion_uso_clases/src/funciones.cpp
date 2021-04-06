#include <vector>
#include <map>
#include "algobot.h"

using namespace std;

// Ejercicio 1
bool en(int x, vector<int> s){
    for (int i = 0; i < s.size(); i++){
        if (x == s[i]) return 1;
    }
    return false;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        if (!en(s[i],res)) res.push_back(s[i]);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set_a;
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        if (set_a.count(s[i]) == 0){
            set_a.insert(s[i]);
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> set_a;
    for (int i = 0; i < a.size(); ++i) {
        set_a.insert(a[i]);
    }
    set<int> set_b;
    for (int i = 0; i < b.size(); ++i) {
        set_b.insert(b[i]);
    }
    return set_a == set_b;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> set_a;
    for (int i = 0; i < a.size(); ++i) {
        set_a.insert(a[i]);
    }
    set<int> set_b;
    for (int i = 0; i < b.size(); ++i) {
        set_b.insert(b[i]);
    }
    return set_a == set_b;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> m;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i]]++;
    }
    return m;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s){
    map<int,int>m = contar_apariciones(s);
    vector<int> res;
    for (pair<int, int> p : m) {
        if (p.second == 1) res.push_back(p.first);
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (auto elem : a){
        if (b.count(elem) != 0) res.insert(elem);
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> m;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i] % 10].insert(s[i]);
    }
    return m;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res = str;
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < tr.size(); ++j) {
            if (tr[j].first == str[i]) res[i] = tr[j].second;
        }
    }
    return res;
}

// Ejercicio 10
set<LU> interseccionLU(set<LU> a, set<LU> b) {
    set<LU> res;
    for (auto elem : a){
        if (b.count(elem) != 0) res.insert(elem);
    }
    return res;
}

bool integrantes_repetidos(vector<Mail> s) {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size() && j != i ; ++j) {
            set<LU> inter = interseccionLU(s[i].libretas(), s[j].libretas());
            if (inter.size() != 0 && inter.size() != s[i].libretas().size()) return true;

        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for (int i = 0; i < s.size(); ++i) {
        if (res[s[i].libretas()].fecha() < s[i].fecha() && s[i].adjunto()) res[s[i].libretas()] = s[i];
    }
  return res;
}

//:D