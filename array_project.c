#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
    srand(time(NULL));
    printf("=====아빠는 대머리 게임=====\n");
    int ans; //사용자 입력값
    int treatment = rand() %4; // 0~3 사이의 숫자 발모제 선택

    int cntshowbottle =0; // 이번게임에 보여주는 병의 갯수
    int prevshowbottle =0; // 이전 게임에 보여준 병의 갯수

    

    //3번의 기회 부여
    for(int i=1; i<=3; i++)
    {
        int bottle[4] ={0,0,0,0}; //4개의 병
        do
        {
            cntshowbottle = rand() %2 +2;
        } while (cntshowbottle == prevshowbottle);
        prevshowbottle = cntshowbottle;

        int isincluded =0; // 보여줄 병에 발모제가 포함되었는지 여부
        printf("\n\n >> %d 번째 시도: ",i);

        // 보여줄 병을 선택
        for(int j=0;j<cntshowbottle;j++)
        {
            int randbottle = rand() %4; // 0~3
            if(bottle[randbottle]==0)
            {
                bottle[randbottle]=1;
                if(randbottle == treatment)
                {
                    isincluded =1;
                }
            }
            else
            {
                j--;
            }
        }
        // 사용자에게 표시
        for(int k=0; k<4; k++)
        {
            if(bottle[k]==1)
                printf("%d ",k+1);
        }
        printf("물약을 머리에 바릅니다 \n\n");
        if(isincluded==1)
        {
            printf("성공!\n");
        }
        else
        {
            printf("실패!\n");
        }

        printf("\n ...계속하려면 아무키나 누르세요 ...");
        getchar();
    }

    printf("\n\n발모제는 몇번일까요?");
    scanf("%d",&ans);
    if(ans == treatment+1)
    {
        printf(">> 정답입니다 !\n");
    }
    else
    {
        printf(">> 오답입니다 ! 정답은 %d 입니다. \n",treatment+1);
    }
    return 0;
    
}