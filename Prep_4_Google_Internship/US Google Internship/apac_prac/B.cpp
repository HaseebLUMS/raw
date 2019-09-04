#include <cstring>
#include <cstdio>

constexpr int N = 50;

constexpr int dx[] = {-1, 0, +1, 0};
constexpr int dy[] = {0, -1, 0, +1};

int T, n, m, h[N + 9][N + 9];
int low, sum;
bool vis[N + 9][N + 9], use[N + 9][N + 9];

int dfs(int k, int x, int y) {
	vis[x][y] = true;
	int num = 1;
	for (int d = 0; d < 4; ++d) {
		int _x = x + dx[d], _y = y + dy[d];
		if (h[_x][_y] == k && !vis[_x][_y]) num += dfs(k, _x, _y);
		if (!vis[_x][_y] && low > h[_x][_y]) low = h[_x][_y];
	}
	return num;
}

void set(int k, int x, int y, int v) {
	use[x][y] = true;
	h[x][y] = v;
	for (int d = 0; d < 4; ++d) {
		int _x = x + dx[d], _y = y + dy[d];
		if (h[_x][_y] == k && !use[_x][_y]) set(k, _x, _y, v);
	}
}

int main() {
	scanf("%d", &T);
	for (int tT = 1; tT <= T; ++tT) {
		sum = 0;
		scanf("%d%d", &n, &m);
		memset(h, 0, sizeof h);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", h[i] + j);
		for (int k = 1; k <= 1000; ++k) {
			memset(vis, 0, sizeof vis);
			memset(use, 0, sizeof use);
			for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
				if (h[i][j] == k && !vis[i][j]) {
					low = 1000;
					int num = dfs(k, i, j);
					if (low > k) {
						set(k, i, j, low);
						sum += num * (low - k);
					}
				}
		}
		printf("Case #%d: %d\n", tT, sum);
	}
	return 0;
}
