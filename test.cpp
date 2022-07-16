#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char map[20][20];

typedef struct _Point
{
    char x;
    char y;
} Point;

typedef struct _Snake
{
    Point Data[10];
} Snake;

typedef struct _QNode
{
    Point pos;
    int dis;
    Snake snake;
} QNode;

QNode q[10000];
int qfront = -1, qend = 0;

int n, m;


Snake CurrentSnake;
int SnakeLen;
Point EndPoint;
bool vis[20][20];

const Point move[4] =
{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool check(const Point const* p, const Snake const* s)
{
    if (vis[p->x][p->y])
        return false;
    if (p->x < 0 || p->x >= n || p->y < 0 || p->y >= m)
        return false;
    if (map[p->x][p->y] == '#')
        return false;
    for (register int i = 1; i <= SnakeLen - 1; ++i)
    {
        if (s->Data[i].x == p->x && s->Data[i].y == p->y)
            return false;
    }
    if (SnakeLen == 2)
    {
        if (s->Data[2].x == p->x && s->Data[2].y == p->y)
            return false;
    }
    return true;
}

void move_snake(Snake* s, int dir)
{
    for (register int i = SnakeLen; i >= 2; --i)
        s->Data[i] = s->Data[i - 1];
    s->Data[1].x += move[dir].x;
    s->Data[1].y += move[dir].y;
}

void bfs()
{
    q[qend].dis = 0;
    q[qend].pos = CurrentSnake.Data[1];
    q[qend].snake = CurrentSnake;
    ++qend;
    vis[CurrentSnake.Data[1].x][CurrentSnake.Data[1].y] = true;

    while (qfront != qend - 1)
    {
        const QNode* now = &q[++qfront];
        
        if (now->pos.x == EndPoint.x && now->pos.y == EndPoint.y)
        {
            printf("%d", now->dis);
            return;
        }

        for (register int i = 0; i < 4; ++i)
        {
            QNode next;
            next.dis = now->dis + 1;
            next.pos.x = now->pos.x + move[i].x;
            next.pos.y = now->pos.y + move[i].y;

            if (check(&next.pos, &now->snake))
            {
                vis[next.pos.x][next.pos.y] = true;
                next.snake = now->snake;
                move_snake(&next.snake, i);
                q[qend++] = next;
            }
        }
    }

    printf("-1");
}

int main()
{
    scanf("%d%d", &n, &m);
    for (register int i = 0; i < n; ++i)
        scanf("%s", map[i]);

    for (register int i = 0; i < n; ++i)
    {
        for (register int j = 0; j < m; ++j)
        {
            if (map[i][j] >= '1' && map[i][j] <= '9')
            {
                const int snakeIdx = map[i][j] - '0';
                if (SnakeLen < snakeIdx)
                    SnakeLen = snakeIdx;
                CurrentSnake.Data[snakeIdx].x = i;
                CurrentSnake.Data[snakeIdx].y = j;
            }
            else if (map[i][j] == '@')
            {
                EndPoint.x = i;
                EndPoint.y = j;
            }
        }
    }

    bfs();

    return 0;
}