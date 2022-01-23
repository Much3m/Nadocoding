#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
    /* // 버스를 탄다고 가정 학생/일반인 구분 (20세기준)
    //if(조건){....} else{...}
    int age =25;
    if(age>=20)
        printf("일반인 입니다.\n");
    else
        printf("학생입니다.\n"); */
    
    
    
    /* //초등(8~13) / 중등(14~16) / 고등(17~19)으로 구분하면?
    //if / else if / else
    int age;
    printf("당신의 나이는? : ");
    scanf("%d",&age);

    if(8<=age && age<=13) //AND 논리연산자
    {
        printf("초등학생입니다.\n");
    }
    else if (14<= age && age<=16)
    {
        printf("중학생입니다.\n");
    }
    else if (age>=17 && age<=19)
    {
        printf("고등학생입니다.\n");
    }
    else
        printf("성인입니다.\n"); */

    /* // break , continue
    // 1~30번있는 반에서 1~5까지 조별발표
    for(int i=1; i<=30; i++)
    {
        if(i>=6)
        {
            printf("나머지 학생은 집에 가세요\n");
            break; // for문을 탈출함.
        }
        printf("%d번 학생은 발표 준비하세요\n",i);
    } */

   /*  //1~30번중 7번은 결석, 7번을 제외하고 6~10까지 발표
    for (int i=1; i<=30; i++)
    {
        if(i>=6 && i<=10)
        {
            if(i==7)
            {
                printf("%d 번 학생은 결석입니다.\n",i);
                continue; // 이후의 문장을 무시하고 바로 다음 루프로 이동.
            }
            printf("%d 번 학생은 발표 준비하세요\n",i);
        }
    } */


  
  
  
   /*  // && ||
    int a,b,c,d;
    printf("a의 값: ");
    scanf("%d",&a);
    printf("b의 값: ");
    scanf("%d",&b);
    printf("c의 값: ");
    scanf("%d",&c);
    printf("d의 값: ");
    scanf("%d",&d);
    if (a==b  && c==d )
    {
        printf("a와 b는 같고 c와 d도 같습니다.\n");
    }
    else if (a==b || c==d)
    {
        printf("a와 b 또는 c와 d의 값이 같습니다.\n");
    }
    else
    {
        printf("값이 서로 다르네요.\n");
    } */

    
    
    
    /* //가위0 바위1 보2
    srand(time(NULL));
    int i = rand() %3;
    if(i==0)
    {
        printf("가위\n");
    }
    else if (i==1)
    {
        printf("바위\n");
    }
    else if(i==2)
    {
        printf("보\n");
    }
    else
        printf("몰라요\n"); */

    
    
    
    /* srand(time(NULL));
    int i = rand() %3; //0~2반환
    switch (i)
    {
        case 0 : printf("가위\n"); break;
        case 1 : printf("바위\n"); break;
        case 2 : printf("보\n"); break;
        default : printf("몰라유\n");
    }

    //스위치문은 만족하는 부분 아래로 모두 출력 --> break문이 필요함. */

    // UP & DOWN 프로젝트
    srand(time(NULL));
    int num = rand() %100+1; // 1~100 까지의 난수 생성.
    printf("숫자 : %d\n",num);
    int answer = 0;
    int chance = 5;

    while (chance>0)
    {
        printf("\n\n남은 기회 : %d번\n",chance--);
        printf("1~100사이의 숫자를 맞춰보세요 :");
        scanf("%d",&answer);
        if(num>answer)
        {
            printf("Up!\n");
        }
        else if (num<answer)
        {   
             printf("Down!\n");
        }
        else if (num == answer)
        {
            printf("\n\n#########Correct!#########\n"); 
            break;
        }
        else
            printf("알 수 없는 오류 발생 !! \n");

    }

    if (chance ==0)
    {
        printf("\n\n게임에서 패배하셨습니다!\n");
    }
    
    
    
    return 0;
}