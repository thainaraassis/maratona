* biblioteca padrão do C++

### template 

```cpp
#include <bits/stdc++.h> // compilado de muitas bibliotecas de cpp
using namespace std; // poupa escrever "std::" antes de cada função

// PARA ENTRADAS MUITO GRANDES -> aqui é definida a macro "_", que será colocado mais na frente no código
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second

// útil para debug
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    return 0;
}

```

### vector

* array com muitas funcionalidades extra
* aloca memória automaticamente, garante economia de espaço 

```cpp
vector<int> v; // vector<tipo> nome
vector<vector<ll>>;

vector<int> v(n); // escolher tamanho inicial 
vector<int> v(n, 1); // inicializa o vetor com tamanho n e com o valor 1

// acessar exatamente igual array
vector<vector<int>> v(10, vector<int>(3));
v[3][2] = 4;

```
* **push_back()** -> coloca elemento no final do vetor O(1)
* **pop_back()** -> remove elemento do finall O(1)
* **clear()** -> limpa o vetor O(n)
* **size()** -> retorna o tamanho do objeto O(1)
* **empty()** -> diz se o vetor está vazio O(1)

Para fazer buscas binárias em vetores ordenados, podemos usar lower_bound e upper_bound. Essas funções retornam iteradores, que veremos mais adiante.

* Se v é um vector<int> ordenado, o primeiro elemento de v que é maior ou igual a 10 está na posição lower_bound(v.begin(),v.end(),10)-v.begin().
* Se v é um vector<int> ordenado, o primeiro elemento de v que é estritamente maior que 10 está na posição upper_bound(v.begin(),v.end(),10)-v.begin().

### pair

* classe que guarda dois elementos que podem ser de dois tipos diferentes
* útil quando tem duas informações linkadas

```cpp
pair<int, float> p; // pair<tipo, tipo2> nome

p = {valor1, valor2};
p.first; p.second;
```

=> funções min e max

* recebem dois (ou mais parametros) do mesmo tipo que sejam comparáveis
* compara dois pares -> primeiro o primeiro elemento, desempata no segundo

### set

* semelhante ao conjunto na matemática
* útil para eliminar elementos repetidos
* estrutura ordenado

```cpp
set<int> s;
s.insert(5); // O(log s)
s.erase(5);
s.size();
s.count(5); //retorna se um elemento esta no set ou não

s.find(5) // se o elemento está no conjunto, retorna um iterador para ele. Senão, retorna um iterador para "final" do conjunto. Assim, um valor x está em s se, e somente se, s.find(x)!=s.end(). O(log n).
```

### map

* permite usar um tipo qualquer como chave de acesso para algum elemento 
* é uma estrutura ordenada

```cpp
map<string, int> mp; 
mp["riobossomo"] = 1;

// no map quando você acessa uma posição ele cria ela, no int inicia como 0
```

### sort

* ordena os elementos

```cpp
// Ordena todo o vetor v
sort(v.begin(),v.end());

// Ordena o vetor v de [in´ıcio, in´ıcio+n)
sort(v.begin(),v.begin()+n);

// Ordena o vetor v do maior elemento para o menor
sort(v.begin(),v.end(),greater<>());
``` 

### range-based for

* para ter modificação do valor original deve usar "&";

```cpp
vector<int> v = {0,1,2};
for(auto& i : v) i = i+1;
for(auto i : v) cout << i << " ";
cout << endl;
// saida 1 2 3

// set
set<pair<int,char>> s;

s.insert({2,'a'});
s.insert({1,'b'});

for(auto p : s) cout << p.f << " " << p.s << endl;

// saida -> ordena pelo primeiro elemento, por isso printa na ordem diferente do que foi inserido 
// 1 b
// 2 a

// map
map<int,char> m;

m[2] = 'b';
m[1] = 'a';

for(auto i : m) cout << i.f << " " << i.s << endl;

// 1 b (chave e valor)
// 2 a
```