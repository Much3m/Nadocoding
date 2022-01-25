#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//10마리의 서로 다른 동물 ( 각 카드 2장씩 ).
//2개의 입력을 받아서 -> 같은 동물 찾으면 뒤집기.
// 모든 동물 쌍을 찾으면 게임 종료.
// 총 실패횟수 알려주기.
void initAnimalArray();
int arrayAnimal[4][5]; // 카드 총 20장 4x5배열
char *strAnimal[10];
int checkAnimal[4][5]; // 뒤집힘 여부 확인.
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();


int main(void)
{
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();
    shuffleAnimal(); 

    int failCount =0; //실패 횟수

    while(1)
    {
        int select1 =0; // 사용자 선택수1
        int select2 =0; // 사용자 선택수2

        printAnimals();
        printQuestion();

        printf("뒤집을 카드 2개를 고르세요 : ");
        scanf("%d %d",&select1, &select2);
        if(select1 == select2)
            continue;
        
        // 좌표에 해당하는 카드를 뒤집어 보고 같은지 확인하기.
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        if((checkAnimal[firstSelect_x][firstSelect_y]==0 &&
            checkAnimal[secondSelect_x][secondSelect_y]==0)
            &&
            (arrayAnimal[firstSelect_x][firstSelect_y]==
            arrayAnimal[secondSelect_x][secondSelect_y])
            )
        {
            printf("\n\n 빙고 ! : %s 발견 ! \n\n",strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y] =1;
            checkAnimal[secondSelect_x][secondSelect_y] =1;
        }
        else
        {
            printf("\n\n 땡 !! ");
            printf("%d : %s\n", select1 , strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2 , strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            failCount ++;
        }
        if(foundAllAnimals()==1)
        {
            printf(" 게임이 종료 되었습니다 ! \n\n");
            printf("실패한 횟수는 %d 입니다. ",failCount);
            
            break;
        }
    }


    return 0;
}

void initAnimalArray()
{
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<5;j++)
        {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName()
{
    strAnimal[0] = "원숭이" ;
    strAnimal[1] = "하마" ;
    strAnimal[2] = "강아지" ;
    strAnimal[3] = "고양이" ;
    strAnimal[4] = "돼지" ;
    strAnimal[5] = "코끼리" ;
    strAnimal[6] = "기린" ;
    strAnimal[7] = "낙타" ;
    strAnimal[8] = "타조" ;
    strAnimal[9] = "호랑이" ;

}

void shuffleAnimal()
{
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y= conv_pos_y(pos);

            arrayAnimal[x][y]=i;
        }
    }
}

//빈공간 찾기
int getEmptyPosition()
{
    while(1)
    {
        int randPos = rand() %20; //0-19사이의 숫자 찾기
        int x= conv_pos_x(randPos);
        int y= conv_pos_y(randPos);
        if(arrayAnimal[x][y]==-1)
        {
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x)
{
    return x/5;
}

int conv_pos_y(int y)
{
    return y%5;
}


void printAnimals()
{
    printf("\n =======================================\n\n");
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("  %8s",strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n =======================================\n\n");
}

void printQuestion()
{
    int seq=0;
    printf("\n\n 문제 \n");
    for(int i=0;i<4;i++)
    {
        for(int j=0; j<5; j++)
        {
            if(checkAnimal[i][j] != 0)
            {
            printf("%10s",strAnimal[arrayAnimal[i][j]]);
            }
            else
            {
                printf("%8d",seq);
            }
            seq ++;
        }printf("\n");
    }
    
    
}

int foundAllAnimals()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(checkAnimal[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}



