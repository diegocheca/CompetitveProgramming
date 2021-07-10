typedef unsigned char xchar;
#define MAXN 1000000

int p[MAXN], r[MAXN], t, n;

bool sacmp(int a, int b) { return p[(a+t) %n] < p[(b+t) %n]; }
void bwt(const xchar *s, int nn) {
n = nn;
int bc[256];
memset(bc, 0, sizeof(bc));
forn(i, n) ++bc[s[i]];
forn(i, 255) bc[i+1]+=bc[i];
forn(i, n) r[--bc[s[i]]]=i;
forn(i, n) p[i]=bc[s[i]];

    int lnb,nb = 1;
    for(t = 1; t < n; t*=2) {
        lnb = nb; nb = 0;
        for(int i = 0, j = 1; i < n; i = j++) {
            /*calcular siguiente bucket*/
            while(j < n && p[r[j]] == p[r[i]]) ++j;
            if (j-i > 1) {
                sort(r+i, r+j, sacmp);
                int pk, opk = p[(r[i]+t) %n];
                int q = i, v = i;
                for(; i < j; i++) {
                    if (((pk = p[(r[i]+t) %n]) != opk) && !(q <= opk && pk < j)) { opk = pk; v = i; }
                    p[r[i]] = v;
                }
            }
            nb++;
        }
        if (lnb == nb) break;
    }
    // prim = p[0];
}

void lcp(const xchar* s, int* h) { /* h could be over r */
    int q = 0, j;
    forn(i,n) if (p[i]) {
        j = r[p[i]-1];
        while(q < n && s[(i+q) %n] == s[(j+q) %n]) ++q;
        h[p[i]-1] = q;
        if (q > 0) --q;
    }
}
