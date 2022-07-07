#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //支持字符串的操作
#define MAX 6       //妃子的最多数量
int main()
{
    /*----------------游戏说明start---------------------*/
    printf("这是一个皇帝选妃的游戏，一共进行10天\n");
    printf("游戏规则：\n");
    printf("1、最多只能有6个妃子\n");
    printf("2、皇帝每增加一个妃子，其余妃子好感度减10\n");
    printf("3、皇帝每打入冷宫一个妃子，其余妃子好感度加10\n");
    printf("4、如果10天内有三个或以上的妃子好感度低于60则游戏失败\n");
    /*-----------------游戏说明end-----------------------*/
    int day = 1;          //控制天数
    char emperorName[50]; //用来存放皇帝的名号
    int i, j;             //循环变量
    int temp;             //临时变量
    int count = 5;        //当前后宫中拥有的妃子数量
    int choice;           //皇帝的选择
    int judLoves = 0;
    //妃子性名数组，最多容纳N个字符串，每个字符串的最大长度为12个字符
    char names[MAX][12] = {"杨玉环", "貂蝉", "西施", "王昭君", "赵飞燕"};
    //级别数组，最多容纳5个字符串，每个字符串最大长度为12个字符
    char levelNames[5][12] = {"贵人", "嫔妃", "贵妃", "皇贵妃", "皇后"};
    //用来存放每个妃子的等级，与levelNames联用。-1表示未启用
    int level[MAX] = {0, 0, 0, 0, 0, -1};
    //用来存放每个妃子的好感度，-1表示未启用
    int loves[MAX] = {100, 100, 100, 100, 100, -1};
    //爱妃姓名临时变量
    char tempName[12];
    //用来存放爱妃名字所对应的下标
    int nameIndex = -1;
    /*-----------------游戏功能start---------------------*/
    printf("陛下，请输入您的名号：");
    scanf("%s", emperorName);
    printf("欢迎《%s》陛下驾临后宫，万岁万岁万万岁！\n", emperorName);
    while (day <= 10)
    {

        printf("1、皇帝下旨选妃：\t\t（增加功能）\n");
        printf("2、翻牌宠幸：\t\t(修改状态功能)\n");
        printf("3、打入冷宫！\t\t(删除功能)\n");
        printf("4、单独召见爱妃!\t\t(查找功能)\n");
        printf("第%d天", day);
        printf("陛下请选择：");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: //皇帝下旨选妃，增加功能
            //增加前要判断，爱妃是否满员
            if (count < MAX)
            {
                printf("陛下，请输入您要增加的爱妃：");
                scanf("%s", tempName);
                strcpy(names[count], tempName);
                level[count] = 0;
                loves[count] = 100;
                count++;
                for (i = 0; i < count - 1; i++)
                {
                    loves[i] -= 10;
                }
            }
            else
            {
                printf("陛下，后宫已满，请注意龙体！");
            }
            break;
        case 2: //翻牌宠幸，修改状态功能
            printf("请陛下输入要宠幸的爱妃：");
            scanf("%s", tempName);
            nameIndex = -1;
            for (i = 0; i < count; i++)
            {
                if (strcmp(tempName, names[i]) == 0)
                {
                    nameIndex = i;
                    break;
                }
            }
            if (nameIndex == -1)
            {
                //说明没有找到
                printf("陛下，后宫没有这个爱妃！请重新选择！");
                break;
            }
            else
            {
                //更改选中人物状态
                if (level[nameIndex] < 4)
                {
                    level[nameIndex]++;
                }
                else
                {
                    level[nameIndex] = 4;
                }
                loves[nameIndex] += 10;

                //更改其它人物状态
                for (i = 0; i < count; i++)
                {
                    if (i != nameIndex)
                    {
                        loves[i] -= 10;
                    }
                }
            }

            break;
        case 3: //打入冷宫，删除功能
            printf("请陛下下旨将哪位娘娘打入冷宫：");
            scanf("%s", tempName);
            for (i = 0; i < count; i++)
            {
                if (strcmp(tempName, names[i]) == 0)
                {
                    nameIndex = i;
                    break;
                }
            }
            if (nameIndex == -1)
            {
                printf("虚惊一场，无人打入冷宫！");
            }
            else
            {
                for (i = nameIndex; i < count - 1; i++)
                {
                    strcpy(names[i], names[i + 1]);
                    level[i] = level[i + 1];
                    loves[i] = loves[i + 1];
                }
                count--;
            }
            for (i = 0; i < count; i++)
            {
                loves[i] += 10;
            }
            break;
        case 4: //单独召见，查找功能
            printf("请陛下下旨召见哪位爱妃陪伴：");
            scanf("%s", tempName);
            for (i = 0; i < count; i++)
            {
                if (strcmp(tempName, names[i]) == 0)
                {
                    nameIndex = i;
                    break;
                }
            }
            if (nameIndex == -1)
            {
                printf("陛下，后宫中没有这个妃子！");
                break;
            }
            else
            {
                level[i]++;
                loves[i] += 10;
            }
            break;
        default:
            printf("君无戏言，陛下请再次确认！");
        }
        //后宫实时状态显示（按级别排序）；
        printf("现在的爱妃状态：\n");
        printf("%s\t%s\t%s\n", "姓名", "级别", "好感度");
        for (i = 0; i < count - 1; i++)
        {
            for (j = 0; j < count - 1 - i; j++)
            {
                if (level[j] < level[j + 1])
                {
                    //级别交换
                    temp = level[j];
                    level[j] = level[j + 1];
                    level[j + 1] = temp;
                    //好感度交换
                    temp = loves[j];
                    loves[j] = loves[j + 1];
                    loves[j + 1] = temp;
                    //姓名交换
                    strcpy(tempName, names[j]);
                    strcpy(names[j], names[j + 1]);
                    strcpy(names[j + 1], tempName);
                }
            }
        }
        for (i = 0; i < count; i++)
        {
            printf("%s\t%s\t%d\n", names[i], levelNames[level[i]], loves[i]);
        }
        //如果有三个以上的妃子好感度低于50则结束游戏
        for (i = 0; i < count; i++)
        {
            if (loves[i] <= 50)
                judLoves++;
        }
        if (judLoves >= 3)
        {
            printf("后宫暴乱，游戏失败！");
            return 0;
        }
        day++;
    }
    printf("万花丛中老司机，和谐后宫！");
    /*-----------------游戏功能end-----------------------*/
    // sleep(10);
    // system("clear");
}