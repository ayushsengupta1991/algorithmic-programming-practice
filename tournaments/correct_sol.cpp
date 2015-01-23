#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> i3;
int T, C=1, n, m;
char M[128][128];
bool perigo[128][128][4];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int xini, xfim, yini, yfim;
int dini[128][128];
bool enfilered[128][128][4];
int dist[128][128][4];

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++) {
            scanf("%s",M[i]);
            for (int j=0;j<m;j++) {
                if (M[i][j]=='S') {
                    xini = i;
                    yini = j;
                } else if (M[i][j]=='G') {
                    xfim = i;
                    yfim = j;
                } else if (M[i][j]=='<') {
                    M[i][j] = 'L';
                    dini[i][j] = 0;
                } else if (M[i][j]=='^') {
                    M[i][j] = 'L';
                    dini[i][j] = 1;
                } else if (M[i][j]=='>') {
                    M[i][j] = 'L';
                    dini[i][j] = 2;
                } else if (M[i][j]=='v') {
                    M[i][j] = 'L';
                    dini[i][j] = 3;
                }
            }
        }

        // calibra
        memset(perigo,false,sizeof(perigo));
        for (int k=0;k<4;k++) {
            for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (M[i][j]=='L') {
                int dir = (dini[i][j]+k)%4;
                int ni = i+dx[dir];
                int nj = j+dy[dir];
                while (0 <= ni and ni < n and 0 <= nj and nj < m and M[ni][nj] != '#' and M[ni][nj] != 'L') {
                    perigo[ni][nj][k] = true;
                    ni = ni+dx[dir];
                    nj = nj+dy[dir];
                }
            }
        }
        queue<i3> Q;
        memset(enfilered,false,sizeof(enfilered));
        Q.push(i3(ii(xini,yini),0));
        enfilered[xini][yini][0] = true;
        dist[xini][yini][0] = 0;
        int resp = -1;
        while (!Q.empty()) {
            int i = Q.front().first.first;
            int j = Q.front().first.second;
            int k = Q.front().second;
            int du = dist[i][j][k];
            Q.pop();
            k = (k+1)%4;
            for (int kk=0;kk<4;kk++) {
                int ni = i+dx[kk];
                int nj = j+dy[kk];
                if (!(0 <= ni and ni < n and 0 <= nj and nj < m)) continue;
                if (M[ni][nj]=='#' or M[ni][nj]=='L') continue;
                if (perigo[ni][nj][k]) continue;
                if (ii(ni,nj) == ii(xfim, yfim)) {
                    resp = du+1;
                    goto fim;
                }
                if (enfilered[ni][nj][k]) continue;
                Q.push(i3(ii(ni,nj),k));
                enfilered[ni][nj][k] = true;
                dist[ni][nj][k] = du + 1;
            }
        }
        fim:;
        if (resp==-1) printf("impossible\n");
        else printf("%d\n",resp);
    }

    return 0;
}

