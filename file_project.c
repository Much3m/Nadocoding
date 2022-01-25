#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>



#define MAX 10000

// 비밀번호를 입력받아서 
// 맞는경우에는 비밀일기를 읽어와서 보여주고 계속 작성하도록 한다.
// 틀린경우 경고메세지를 표시하고 종료한다.
int main(void)
{
    //fgets fputs 활용
    char line[MAX];     //파일에서 불러온 내용을저장할 변수
    char contents[MAX]; // 일기장에 입력할 내용
    char password[20];  //비밀번호 입력
    char c;             //비밀번호 입력시 키값 확인용 (마스킹)

    printf(" 비밀일기에 오신것을 환영합니다 \n");
    printf("비밀번호를 입력하세요 :");

    //getchar : 엔터를 입력받아야 동작
    //getch   : 키 입력시 바로 동작

    int i =0;
    while(1)
    {
            c = getc(stdin);
            if(c== 13) // enter
            {
                password[i] = '\0';
                break;
            }
            else// 입력중
            {
                printf("*");
                password[i] = c;
            }
            i++;
    }

    printf("\n\n === 비밀번화 확인중 ===\n\n");
    if(strcmp(password , "skehzheld")==0) //비밀번호 일치
    {
        printf(" ==== 비밀번호 확인 완료 ===\n\n");
        char * filename = "/Users/kimminsuk/Desktop/secrect.txt";
        FILE *file = fopen(filename , "a+b"); //파일이 없으면 생성, 파일이 있으면 append를 한다.
        if(file == NULL)
        {
            printf("파일 열기 실패 \n\n");
            return 1;
        }

        while(fgets(line,MAX,file)!=NULL)
        {
            printf("%s",line);
        }
        printf("\n\n 내용을 계속 작성하세요 ! 종료하시려면 EXIT를 입력해주세요!n");

        while(1)
        {
            scanf("%[^\n]",contents); //줄바꿈이 나오기 전까지 읽어들임
            getchar(); //enter입력 flush처리

            if(strcmp(contents , "EXIT")==0)
            {
                printf("비밀일기 입력을 종료합니다\n\n");
                break;
            }
            fputs(contents,file);
            fputs("\n",file);
        }
        fclose(file);
    }
    else
    {
        printf(" ==== 비밀번호 오류 ====\n");
        printf(" 누구냐? 뒤질래? \n");
    }

    return 0;
}