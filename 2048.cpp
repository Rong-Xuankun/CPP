#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //#include <curses.h>
#include <time.h>
#include <windows.h>/*色，清屏*/
#define size 4

//游戏移动函数
void Menu();
void Rules();
int random_num1();
int random_num2();
void begin();
void get_and_move(int *score);
int game_over();    /*判断游戏是否结束 :1.无空格 2.无空格但有连续相等数 3.出现2048 */
void if_continue(); /*判断是否继续游戏 :1.选择继续:Menu();2.不继续break;*/
void contain();     /*执行get_and_move前的函数，服务于if_move */
int if_move();

//图形界面绘制函数
void printTable(); //打印4*4方格
void paint(int a); //给数字上颜色
int color(int c);  //插入颜色

//全局变量
int table_n[size][size] = {0};      // table_n即为全篇使用二维数组
int copy_table_n[size][size] = {0}; //每次改变前存储table_n数组的数组
char name_file[] = "2048";

//在屏幕上输出游戏菜单函数
void Menu()
{
    system("cls"); //清屏
    printf("\t\tWelcome   to    2048\n");
    printf("\t\t  请输入选项：\n");
    printf("\t\t     1.游戏规则\n");
    printf("\t\t     2.开始游戏\n");
    printf("\t\t     3.退出游戏\n");

    int flag = 1; //定义一个标记
    while (flag != 0)
    {
        switch (getch()) /*要用getch,而不是getchar,报告中会指出*/
        {
        case '1':
            system("cls"); //清屏
            Rules();       //输出该游戏的规则
            Menu();        //返回输出主菜单
            flag = 0;      // flag==0，退出循环
            break;
        case '2':
            system("cls"); //清屏
            begin();       //执行游戏开始函数
            flag = 0;
            break;
        case '3':
            exit(0); //退出
            flag = 0;
        default:
            printf("请重新选择！\n");
        }
    }

    return;
}

//游戏规则函数
void Rules()
{
    printf("1.本游戏通过按键W、S、A、D(不区分大小写）四个键分别控制滑块上移、下移、左移和右移\n");
    printf("2.滑块移动的过程中，如有相邻且相等数字的滑块将会相加，并获得相应的分数\n");
    printf("3.当棋盘上的所有位置均有数字，且不能合成，则游戏结束\n");
    printf("4.当棋盘上出现2048，闯关成功，游戏结束\n");
    printf("5.计分规则：每次加的分数为两个想等数字滑块相加后的数字\n");
    system("PAUSE");
    system("cls");

    return;
}

int random_num1() //选择0~3随机数 ，用于随机行列
{
    srand(time(NULL));
    int a = rand() % 4;
    return a;
}
int random_num2() //选择2、4随机数 ，用于给空格赋值
{

    int a = rand() % 2; //任意产生0,1两个数
    a = a == 0 ? 2 : 4; // a==0时，将2赋给a,a==1时，将4赋给a
    return a;
}

//开始游戏
void begin()
{
    memset(table_n, 0, sizeof(table_n)); // memset();为初始化函数，将table_n[][]的值全部初始化为0
    memset(copy_table_n, 0, sizeof(copy_table_n));
    int score = 0, sign = 1;
    int j, k; // j为行数，k为列数

    while (1)
    {
        //输出整个游戏的主界面
        //该界面保持不动，直到游戏结束，作为提示信息
        printf("\t\t╔══════════════════════════════════════════════╗\n");
		printf("\t\t║     W E L C O M E    T O     2 0 4 8         ║\n");
		printf("\t\t╟──────────────────────────────────────────────╢\n");
		printf("\t\t║移动：              ┌───┐                     ║\n");
		printf("\t\t║                    │ W │                     ║\n");
		printf("\t\t║                ┌───┼───┼───┐                 ║\n");
		printf("\t\t║                │ A │ S │ D │                 ║\n");
		printf("\t\t║                └───┴───┴───┘                 ║\n");
		printf("\t\t╚══════════════════════════════════════════════╝\n");

        if (sign != 0)
        {
            int find = 0; //定义find的作用：find==1即为真，找到了空格并赋予随机数，find==0,未找到空格，break
            // 给j、k赋随机数
            j = random_num1();
            k = random_num1();

            for (; j < size; j++) //随机完了顺着找
            {
                for (; k < size; k++)       //循环的初始值在上面赋出来了，这里无需initialize
                    if (table_n[j][k] == 0) //若该点未赋值，则给该点随机赋一个值
                    {
                        table_n[j][k] = random_num2(); //在2、4中随机赋值
                        find = 1;
                        break;
                    }

                if (find != 0)
                    break;

                k = 0; //将列数置为0，从下一行的第一列开始查找
            }

            if (find == 0) //没找到就从右下角开始倒着找，如果再没找到那就是table满了
                for (j = size - 1; j >= 0; j--)
                {
                    for (k = size - 1; k >= 0; k--)
                        if (table_n[j][k] == 0)
                        {
                            table_n[j][k] = random_num2(); //在2、4中随机赋值
                            find = 1;
                            break;
                        }
                    if (find != 0)
                        break;
                }
        }

        printTable();                         //打印界面
        printf("\t\t当前得分:  %d\n", score); //打印得分
        contain();                            //保存棋盘
        get_and_move(&score);                 //输入指令并move
        sign = if_move();                     //判断棋盘是否变动
        if (game_over() != 0)
            break;

        system("cls"); //清屏
    }

    return;
}

void get_and_move(int *score)
{
    int row, column, t; // column为列，row为行
    int flag = 1;
    char ch;
    // flag的作用为标记，循环中应改变flag的值，循环的条件即flag为真
    while (flag != 0)
    {
        ch = getch(); //输入字符用getch()是为了体验感不要选择getchar()
        switch (ch)
        {
            /*滑块向上移动*/
        case 'w': //不区分大小写
        case 'W':
            /*向上聚集数字*/
            for (column = 0; column < 4; column++) //每一列的数都往最上方挪挪
            {
                for (t = 0; t < 4; t++) //需要t的原因：将每列四个数都往上挪，循环四遍以确定都挪上去了
                {
                    for (row = 3; row > 0; row--)
                    { //从每一列最后开始
                        if (table_n[row - 1][column] == 0)
                        {                                                    //遍历到的上面一个数为0
                            table_n[row - 1][column] = table_n[row][column]; //此时数赋给上一个数,此时数为0
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            /*竖直方向上，相邻且相同的数字相加*/
            for (column = 0; column < 4; column++)
            {
                for (row = 0; row < 3; row++)
                {
                    if (table_n[row][column] == table_n[row + 1][column])
                    {
                        table_n[row][column] += table_n[row + 1][column];
                        table_n[row + 1][column] = 0;
                        (*score) += table_n[row][column]; //积分
                    }
                }
            }
            /*向上聚集数字*/
            for (column = 0; column < 4; column++)
            {
                for (t = 0; t < 4; t++)
                {
                    for (row = 3; row > 0; row--)
                    {
                        if (table_n[row - 1][column] == 0)
                        {
                            table_n[row - 1][column] = table_n[row][column];
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            flag = 0; // flag==0,退出此次循环
            break;

        case 's':
        case 'S':
            /*向下聚集数字*/
            for (column = 0; column < 4; column++)
            {
                for (t = 0; t < 4; t++)
                {
                    for (row = 0; row < 3; row++)
                    { //向下是从每一列第一个开始
                        if (table_n[row + 1][column] == 0)
                        {
                            table_n[row + 1][column] = table_n[row][column];
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            /*竖直方向上，相邻且相同的数字相加*/
            for (column = 0; column < 4; column++)
            {
                for (row = 3; row > 0; row--)
                {
                    if (table_n[row][column] == table_n[row - 1][column])
                    {
                        table_n[row][column] += table_n[row - 1][column];
                        table_n[row - 1][column] = 0;
                        (*score) += table_n[row][column];
                    }
                }
            }
            /*向下聚集数字*/
            for (column = 0; column < 4; column++)
            {
                for (t = 0; t < 4; t++)
                {
                    for (row = 0; row < 3; row++)
                    {
                        if (table_n[row + 1][column] == 0)
                        {
                            table_n[row + 1][column] = table_n[row][column];
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            flag = 0;
            break;

        case 'a':
        case 'A':
            /*向左聚集数字*/
            for (row = 0; row < 4; row++)
            {
                for (t = 0; t < 4; t++)
                {
                    for (column = 3; column > 0; column--)
                    {
                        if (table_n[row][column - 1] == 0)
                        {
                            table_n[row][column - 1] = table_n[row][column];
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            for (row = 0; row < 4; row++)
            {
                for (column = 0; column < 3; column++)
                {
                    if (table_n[row][column] == table_n[row][column + 1])
                    {
                        table_n[row][column] += table_n[row][column + 1];
                        table_n[row][column + 1] = 0;
                        (*score) += table_n[row][column];
                    }
                }
            }
            for (row = 0; row < 4; row++)
            {
                for (t = 0; t < 4; t++)
                {
                    for (column = 3; column > 0; column--)
                    {
                        if (table_n[row][column - 1] == 0)
                        {
                            table_n[row][column - 1] = table_n[row][column];
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            flag = 0;
            break;

        case 'd':
        case 'D': /*向右聚集数字*/
            for (row = 0; row < 4; row++)
            {
                for (t = 0; t < 4; t++)
                {
                    for (column = 0; column < 3; column++)
                    {
                        if (table_n[row][column + 1] == 0)
                        {
                            table_n[row][column + 1] = table_n[row][column];
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            for (row = 0; row < 4; row++)
            {
                for (column = 3; column > 0; column--)
                {
                    if (table_n[row][column] == table_n[row][column - 1])
                    {
                        table_n[row][column] += table_n[row][column - 1];
                        table_n[row][column - 1] = 0;
                        (*score) += table_n[row][column];
                    }
                }
            }
            for (row = 0; row < 4; row++)
            {
                for (t = 0; t < 4; t++)
                {
                    for (column = 0; column < 3; column++)
                    {
                        if (table_n[row][column + 1] == 0)
                        {
                            table_n[row][column + 1] = table_n[row][column];
                            table_n[row][column] = 0;
                        }
                    }
                }
            }
            flag = 0;
            break;

        default:;
        }
    }

    return;
}

//判断游戏是否结束: 1.无空格 2.无空格但有连续相等数 3.出现2048
int game_over()
{
    int i, j, over = 1;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (table_n[i][j] == 0) //有空格
            {
                over = 0;
                break;
            }
        }

        if (over == 0)
            break; //跳出多重循环
    }

    if (over != 0)
        for (i = 0; i < size - 1; i++)
        {
            for (j = 0; j < size - 1; j++)
            {
                if (table_n[i][j] == table_n[i][j + 1] || table_n[i][j] == table_n[i + 1][j]) //无空格但有连续相等的两个数字
                {
                    over = 0;
                    break;
                }
            }

            if (over == 0)
                break; //跳出多重循环
        }
    if (over != 0)
        for (i = 0; i < size - 1; i++)
        {
            for (j = 0; j < size - 1; j++)
            {
                if (table_n[i][j] == 2048) //出现2048
                {
                    over = 1;
                    break;
                }
            }

            if (over == 1)
                break; //跳出多重循环
        }

    return over;
}

void if_continue() /*判断是否继续游戏 :1.选择继续:Menu();2.不继续break;*/
{
    printf("\t\t====游戏失败====\n");
    printf("\t\t是否继续：       \n");
    printf("\t\t     1.再来一把    \n");
    printf("\t\t     2.结束游戏    \n");

    char ch;
    while (1)
    {
        ch = getch();
        switch (ch)
        {
        case '1':
            system("cls");
            Menu();
            break;
        case '2':
            printf("END  GAME!");
            break;
        default:
            printf("输入错误！请重新选择！！\n");
        }
    }
    return;
}

void printTable() //打印方格
{
    int row, column; // row为行，column为列
    for (row = 0; row < size; row++)
    {
        if (row == 0)
            printf("\t\t\t┏━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┓\n"); // 4*4第一行
        else
            printf("\t\t\t┣━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━┫\n"); // 4*4二，三行

        printf("\t\t\t┃      ┃      ┃      ┃      ┃\n");

        for (column = 0; column < size; column++)
        {
            if (table_n[row][column] == 0)
            {
                if (column == 0)
                    printf("\t\t\t┃      ");
                else
                    printf("┃      ");
            }
            else
            { //否则放入与二维数组对应的数据
                if (column == 0)
                {
                    printf("\t\t\t┃");
                    paint(table_n[row][column]); //判断滑块的数值，给对应颜色
                    printf("%5d ", table_n[row][column]);
                    color(0); //恢复白色背景
                }
                else
                {
                    printf("┃");
                    paint(table_n[row][column]); //判断滑块的数值，给对应颜色
                    printf("%5d ", table_n[row][column]);
                    color(0); //恢复白色背景
                }
            }
        }

        printf("┃\n");
        printf("\t\t\t┃      ┃      ┃      ┃      ┃\n");
    }
    printf("\t\t\t┗━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┛\n");

    return;
}

int color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            BACKGROUND_INTENSITY | //背景颜色包含加剧
                                BACKGROUND_BLUE |  //背景色蓝
                                BACKGROUND_RED |   //背景色红
                                BACKGROUND_GREEN | //背景色绿
                                c);
    return 0;
}

void paint(int a)
{
    switch (a)
    {
    case 2:
        color(8);
        break;
    case 4:
        color(0);
        break;
    case 8:
        color(2);
        break;
    case 16:
        color(6);
        break;
    case 32:
        color(10);
        break;
    case 64:
        color(2);
        break;
    case 128:
        color(9);
        break;
    case 256:
        color(11);
        break;
    case 512:
        color(5);
        break;
    case 1024:
        color(13);
        break;
    case 2048:
        color(12);
        break;
    default:
        color(4);
        break;
    }

    return;
}

void contain()
{
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            copy_table_n[i][j] = table_n[i][j];
    return;
}

int if_move() //判断是否移动
{
    int i, j;
    int sign = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (copy_table_n[i][j] != table_n[i][j]) //遍历,把table_n[][]的值全赋给copy_table_n[][]
            {
                sign = 1;
                break;
            }
        }
        if (sign)
            break;
    }
    return sign;
}

int main()
{
    system("mode con cols=90 lines=30");
    system("title 2048 Made By RXK"); //程序标题
    system("color F0");               // F 表示背景颜色，0表示前景颜色
    Menu();

    system("PAUSE"); //暂停
    system("cls");   //清屏
    if_continue();

    return 0;
}
