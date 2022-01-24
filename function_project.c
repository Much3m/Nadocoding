#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int getRandomnum(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void)
{
    //문이 5개가 있고, 각 문마다 점점 어려운 퀴즈 출제
    //맞히면 통과 틀리면 실패

    srand(time(NULL));
    int count =0;
    int q;
    for(int i=1; i<=5; i++)
    {
        // x * y = ?
        int num1= getRandomnum(i);
        int num2= getRandomnum(i);
        showQuestion(i,num1,num2);

        int ans = -1;
        scanf("%d",&ans);
        if(ans == -1)
        {
            printf("프로그램을 종료합니다 \n");
            exit(0);
        }
        else if (ans == num1 * num2)
        {
            //성공
            success();
            count ++;
        }
        else
        {
            //실패
            fail();

        }
        q++;

    }

    printf("당신은 %d 문제중 %d문제를 맞혔습니다.\n",q,count);

    return 0;
}

int getRandomnum(int level)
{
    return rand() %(level*7)+1;
}

void showQuestion(int level, int num1, int num2)
{
    printf("\n\n############ %d번째 퀴즈 ############\n",level);
    printf("\n \t %d x %d는? \n\n",num1,num2);
    printf("######################################");
    printf("\n 비밀번호를 입력하세요 (종료 -1) : ");
}

void success()
{
    printf("\n\n >> 정답입니다 ! \n");
}

void fail()
{
    printf("\n\n >> 오답입니다 ! \n");
}