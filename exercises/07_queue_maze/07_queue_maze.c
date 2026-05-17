#include <stdio.h>
#include <string.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

typedef struct {
	int row;
	int col;
} Point;

int main(void)
{
	Point queue[MAX_ROW * MAX_COL];
	int front = 0, rear = 0;
	int visited[MAX_ROW][MAX_COL] = {0};
	Point parent[MAX_ROW][MAX_COL];
	int found = 0;
	int dr[4] = {1, 0, -1, 0};
	int dc[4] = {0, 1, 0, -1};

	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			parent[i][j].row = -1;
			parent[i][j].col = -1;
		}
	}

	queue[rear++] = (Point){0, 0};
	visited[0][0] = 1;

	while (front < rear) {
		Point cur = queue[front++];
		if (cur.row == MAX_ROW - 1 && cur.col == MAX_COL - 1) {
			found = 1;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nr = cur.row + dr[i];
			int nc = cur.col + dc[i];
			if (nr < 0 || nr >= MAX_ROW || nc < 0 || nc >= MAX_COL) {
				continue;
			}
			if (maze[nr][nc] == 1 || visited[nr][nc]) {
				continue;
			}
			visited[nr][nc] = 1;
			parent[nr][nc] = cur;
			queue[rear++] = (Point){nr, nc};
		}
	}

	if (!found) {
		printf("No path!\n");
		return 0;
	}

	Point path[MAX_ROW * MAX_COL];
	int len = 0;
	Point cur = {MAX_ROW - 1, MAX_COL - 1};
	while (cur.row != -1 && cur.col != -1) {
		path[len++] = cur;
		cur = parent[cur.row][cur.col];
	}

	for (int i = 0; i < len; i++) {
		printf("(%d, %d)\n", path[i].row, path[i].col);
	}

	return 0;
}
