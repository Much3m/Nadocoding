#include <stdio.h>
int main(void)
{
    /* printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n");
    printf("Hello, World\n"); */

    // ++
   /*  int a=10;
    printf("a는 %d\n",a);
    a++;
    printf("a는 %d\n",a);
    a++;
    printf("a는 %d\n",a); */

    /* int b =20;
    printf("b는 %d\n",++b); // 문장에서 ++ 먼저 수행
    printf("b는 %d\n",b++); // 문장을 수행하고 나서 다음줄로 넘어갈 때 ++
    printf("b는 %d\n",b); //b를 출력.
    return 0; */

    /* int i=1;
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++);
    printf("Hello, World %d\n",i++); */

    //반복문 
    //for, while do, while
    //for(선언;조건;증감)
    /* for(int i=1; i<=10; i++)
    {
        printf("Hello, World %d\n",i);
    } */

    //while(조건)
    /* int i=1;
    while(i<=10)
    {
        printf("Hello,World%d\n",i++);
        // i++;
    } */

    //do {} while(조건)
    /* int i=1;
    do
    {
        printf("Hello, World%d\n",i++);
    }
    while(i<=10); */

    /* //2중 반복문
    for (int i=1; i<=3; i++)
    {
        printf("첫번째 반복문 %d \n",i);

        for(int j=1;j<=5;j++)
        {
            printf("    두번째 반복문 %d\n",j);
        }

    } */

    /* //구구단
    for(int i=2;i<=9;i++)
    {
        printf("%d단\n",i);
        for(int j=1;j<=9;j++)
        {
            printf("  %d x %d = %d\n",i,j,i*j);
        }
        printf("\n");
    } */

    //별 만들기
    
    /* int n;
    printf("별탑의 층:");
    scanf("%d",&n);
    for(int i=1; i<=n ; i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    } */

    /* //별탑 거꾸로
    int n;
    printf("별탑의 층:");
    scanf("%d",&n);

    for(int i=n ; i>=1 ; i--)
    {
        for(int j=1; j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    } */

    /* //별탑 거꾸로 2
    for(int i=0;  i<5; i++)
    {
        for(int j=i; j<5-1; j++)
        {
            printf(" ");
        }
        for(int k=0 ; k<=i; k++)
        {
            printf("*");
        }
        printf("\n");
    } */

    /* //별탑 거꾸로 3
    int n;
    printf("별탑의 층: ");
    scanf("%d",&n);
    for(int i=0; i<n+1; i++)
    {
        for(int j=i; j<n; j++)
        {
            printf(" ");
        }
        for(int k=0; k<i ; k++)
        {
            printf("*");
        }
        printf("\n");
    } */

    //피라미드 프로젝트
    int floor;
    printf("몇층으로 쌓을건가?");
    scanf("%d",&floor);

    for(int i=0; i<floor; i++)
    {
        for(int j=i; j<floor-1;j++)
        {
            printf(" ");
        }
        for(int k=0;k<2*i+1;k++)
        {
            printf("*");
        }
        printf("\n");
    }


    

}