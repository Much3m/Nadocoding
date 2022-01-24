#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define cLOCKS_PER_SEC 10

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int level;
int arrayFish[6];
int *cursor; // 물을 줄 물고기를 선택

// 물고기 6마리가 있다.
// 어항이 있는 사막에 살고있다.
// 사막이 너무 더워서 물이 아주 빨리 증발한다.
// 물이 다 증발하기전에 물을 줘야한다.
// 물고기는 점점 커져서 나중에는 ... 냠냠


int main(void)
{
    long starttime = 0; //게임 시작시간
    long totaltime = 0; //총 경과 시간
    long prevtime = 0; //직전 경과 시간 (최근에 물을 준 시간)

    int num; // 몇번 어항에 물을 줄것인지 선택 . 사용자 입력

    initData();

    cursor = arrayFish;
    starttime = clock() ; // 현재 시간을 ms단위로 반영
    while(1)
    {
        printfFishes();
        printf("몇 번 어항에 물을 주시겠어요?");
        scanf("%d",&num);

        //입력값 체크
        if(num<1 || num>6)
        {
            printf("\n 입력값이 범위를 벗어났습니다.\n");
            continue;
        }

        totaltime = (clock()-starttime)/cLOCKS_PER_SEC;
        printf("총 경과시간 : %ld초\n",totaltime);

        //직전 물 준 시간 이후로 흐른 시간
        prevtime = totaltime - prevtime;
        printf("최근 경과시간 : %ld초 \n",prevtime);

        //어항의 물을 감소
        decreaseWater(prevtime);

        //물을 준다
        //1. 어항의 물이 0이면? 물을 주지 않는다.3
        if(cursor[num-1]<=0)
        {
            printf("%d번 물고기는 이미 죽었습니다... 물을 주지 않습니다 \n",num);

        }

        //2. 어항의 물이 0이 아닌경우 : 100을 넘지 않는지 체크한다.

        else if (cursor[num-1]+1 <= 100)
        {
            printf(" %d번 어항에 물을 줍니다\n",num);
            cursor[num-1] += 1;
        }

        //레벨업을 할건지 확인 (레벨업은 20초마다 한번씩 수행)
        if(totaltime / 20 > level-1)
        {
            level ++; // 레벨 상승. 
            printf("======Level Up !!======\n");
            if(level ==5)
            {
                printf("\n\n축하합니다 최고 레벨을 달성 하였습니다. 게임을 종료합니다.\n");
                exit(0);
            }
        }

        //모든 물고기가 죽었는지 확인.
        if(checkFishAlive(0)==0)
        {
            printf("모든 물고기가 죽었습니다.\n");
            exit(0);
        }
        else
        {
            printf("물고기가 아직 살아있어요!\n");
        }
        prevtime = totaltime ;
        //10초 --> 15초 (5초: prevtime) - > 25초 (10초???) --> tot time 을 prevtime에 백업
    }

    return 0;
}

void initData()
{
    level =1;
    for(int i=0;i<6;i++)
    {
        arrayFish[i] = 100; // 어항의 물높이
    }
}

void printfFishes()
{
    printf("%3d번 %4d번 %4d번 %4d번 %4d번 %4d번 \n",1,2,3,4,5,6);
    for (int i =0; i<6; i++)
    {
        printf(" %4d  ",arrayFish[i]);
        
    }
    printf("\n");
}

void decreaseWater(long elapsedTime)
{
    for(int i=0 ; i<6; i++)
    {
        arrayFish[i] -= (level *2 * (int)elapsedTime); // 3은 난이도 조절을 위한 값
        if(arrayFish[i]<0)
        {
            arrayFish[i]=0;
        }
    }
}

int checkFishAlive()
{
    for(int i=0; i<6;i++)
    {
        if(arrayFish[i]>0)
        return 1; // 참
    }
    return 0;
}