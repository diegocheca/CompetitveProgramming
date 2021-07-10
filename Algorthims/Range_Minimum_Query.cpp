/*
Range Minimum Query hn, log ni (get y set)
Description: MAXN es la cantidad maxima de elementos q maneja esta estructua. 
pget(i, j) incluye i y no incluye j. init(n) O(n). 
Funciona con cualquier operador “+” asociativo y con elemento neutro “0” Se inicializa asi:
cin >> n; tipo* v = rmq.init(n); forn(i, n) cin >> v[i]; rmq.updall();

*/
#define MAXN 100000
struct rmq {
    int MAX;
    tipo vec[4*MAXN];
    tipo* init(int n) {
    MAX = 1 << (32-__builtin_clz(n));
    fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
    return vec+MAX;
}
void updall() { dforn(i, MAX) vec[i] = vec[2*i] + vec[2*i+1]; } // + = 
    operacion
void pset(int i, tipo vl) {
    vec[i+=MAX] = vl;
    while(i) { i /= 2; vec[i] = vec[2*i] + vec[2*i+1]; } // + = operacion
}
tipo pget(int i, int j) { return _pget(i+MAX, j+MAX); }
tipo _pget(int i, int j) {
tipo res = 0; // 0 = elemento neutro
if (j-i <= 0) return res;
if (i %2) res += vec[i++]; // + = operacin
res += _pget(i/2, j/2); // + = operacin
if (j %2) res += vec[--j]; // + = operacin