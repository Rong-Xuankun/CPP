#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Snake;

typedef struct
{
    Snake snake_location[10];
    int step;
} Q; // 队列

int n, m;
char graph[20][20];
int numbers_of_snake = 0;
int numbers_of_path = 0;
Q init_snake;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int vis[20][20][100000];
int vis2[20][20];

int in(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void init_graph_snake()
{
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(graph[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] >= '0' && graph[i][j] <= '9')
            {
                init_snake.snake_location[graph[i][j] - '0'].x = i;
                init_snake.snake_location[graph[i][j] - '0'].y = j;
                graph[i][j] = '.';
                numbers_of_snake++;
            }
        }
    }
    init_snake.step = 0;
    // for (int i = 1; i <= numbers_of_snake; i++)
    // {
    //     printf("%d %d\n", init_snake.snake_location[i].x, init_snake.snake_location[i].y);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     puts(graph[i]);
    // }
}

int count_shape(Q snake)
{
    int sum = 0;
    for (int i = 1; i < numbers_of_snake; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int next_x = snake.snake_location[i].x + dir[j][0];
            int next_y = snake.snake_location[i].y + dir[j][1];
            if (next_x == snake.snake_location[i + 1].x && next_y == snake.snake_location[i + 1].y)
            {
                sum = j + sum * 4;
            }
        }
    }
    return sum;
}

int has_snakebody(Q snake, int x, int y)
{
    for (int i = 1; i <= numbers_of_snake; i++)
    {
        if (snake.snake_location[i].x == x && snake.snake_location[i].y == y)
        {
            return 1;
        }
    }
    return 0;
}

void bfs1()
{
    Q queue[100000];
    Q queue_top;
    Q queue_tmp;
    int l = 0;
    int r = 0;

    queue[r++] = init_snake;

    while (l < r)
    {
        queue_top = queue[l++];
        if (graph[queue_top.snake_location[1].x][queue_top.snake_location[1].y] == '@')
        {
            printf("%d", queue_top.step);
            exit(0);
        }
        if (vis[queue_top.snake_location[1].x][queue_top.snake_location[1].y][count_shape(queue_top)] == 1)
            continue;

        vis[queue_top.snake_location[1].x][queue_top.snake_location[1].y][count_shape(queue_top)] = 1;
        //printf("%d %d\n", queue_top.snake_location[numbers_of_snake].x, queue_top.snake_location[numbers_of_snake].y);
        for (int i = 0; i < 4; i++)
        {
            int next_x = queue_top.snake_location[1].x + dir[i][0];
            int next_y = queue_top.snake_location[1].y + dir[i][1];
            if (in(next_x, next_y) == 1 && (((next_x == queue_top.snake_location[numbers_of_snake].x && next_y == queue_top.snake_location[numbers_of_snake].y && numbers_of_snake > 2) || (graph[next_x][next_y] == '.' || graph[next_x][next_y] == '@') && has_snakebody(queue_top, next_x, next_y) == 0)))
            {
                // printf("%d\n", i);
                queue_tmp = queue_top;
                for (int j = numbers_of_snake; j >= 2; j--)
                {
                    queue_tmp.snake_location[j].x = queue_tmp.snake_location[j - 1].x;
                    queue_tmp.snake_location[j].y = queue_tmp.snake_location[j - 1].y;
                    //printf("%d %d\n", queue_tmp.snake_location[j].x, queue_tmp.snake_location[j].y);
                }
                queue_tmp.snake_location[1].x = next_x;
                queue_tmp.snake_location[1].y = next_y;
                queue_tmp.step += 1;
                queue[r++] = queue_tmp;
                //printf("%d %d\n", r, l);
            }
        }
    }
    printf("-1");
    exit(0);
}

void bfs2()
{
    Q queue[100];
    Q queue_top;
    Q queue_tmp;
    int l = 0;
    int r = 0;

    queue[r++] = init_snake;

    while (l < r)
    {
        queue_top = queue[l++];

        if (graph[queue_top.snake_location[1].x][queue_top.snake_location[1].y] == '@')
        {
            printf("%d", queue_top.step);
            exit(0);
        }

        if (vis2[queue_top.snake_location[1].x][queue_top.snake_location[1].y] == 1)
        {
            continue;
        }

        vis2[queue_top.snake_location[1].x][queue_top.snake_location[1].y] = 1;

        for (int i = 0; i < 4; i++)
        {
            queue_tmp = queue_top;
            int next_x = queue_top.snake_location[1].x + dir[i][0];
            int next_y = queue_top.snake_location[1].y + dir[i][1];
            if (in(next_x, next_y) == 1 && (graph[next_x][next_y] == '.' || graph[next_x][next_y] == '@'))
            {
                queue_tmp.snake_location[1].x = next_x;
                queue_tmp.snake_location[1].y = next_y;
                queue_tmp.step += 1;
                queue[r++] = queue_tmp;
            }
        }
    }
    printf("-1");
    exit(0);
}

int main()
{
    init_graph_snake(); // 初始化地图和蛇的位置
    if (numbers_of_snake > 1)
    {
        bfs1();
    }
    else
    {
        bfs2();
    }
    return 0;
}