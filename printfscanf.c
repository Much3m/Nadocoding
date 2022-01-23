#include <stdio.h>

int main(void)
{
    //정수형 변수 예제
    /* int age = 12; // 정수형 자료 int , 변수명 age
    printf("%d\n",age); //%d 정수형 
    age =13; //처음에만 선언해도됨
    printf("%d\n",age); //%d 정수형 */

    //실수형 변수 예제
    /*float f = 46.5f;
    printf("%.2f\n",f);

    double d= 4.428;
    printf("%.2lf\n",d); */

    /* const int YEAR = 2000;
    printf("태어난 년도 :%d\n",YEAR);
    // YEAR = 2001; 상수라 변할수 없음. */

    //printf
    //연산
    //int add = 3+7; //10
    //printf("3 + 7 = %d\n",add);
    //printf("%d x %d = %d\n",30,79,30*79);

    //scanf
    //키보드 입력을 받아서 저장
    /*int input;
    printf("값을 입력하세요:");
    scanf("%d",&input);
    printf("입력값 : %d\n",input); */

    /* int one,two,three;
    printf("3개의 정수를 입력하세요: ");
    scanf("%d %d %d",&one,&two,&three);
    printf("첫번째 값: %d\n",one);
    printf("두번째 값: %d\n",two);
    printf("세번째 값: %d\n",three);*/

    //문자(한글자), 문자열(여러글자)
    /* char c = 'A';
    printf("%c\n",c); */

    /* char str[256];
    printf("문자열을 입력하세요:");
    scanf("%s",str); // 문자열 받을때는 &필요없음, 크기 필요함
    printf("%s\n",str); */

    //프로젝트
    //경찰관이 범죄자의 정보를 입수 (조서작성)
    // 이름 나이 몸무게 키 범죄명
    char name[256];
    printf("이름이 뭐에요?");
    scanf("%s",name);

    int age;
    printf("몇살이에요?");
    scanf("%d",&age);

    float weight;
    printf("몸무게는 몇 kg 이에요?");
    scanf("%f",&weight);

    double height;
    printf("키는 몇 cm 이에요?");
    scanf("%lf",&height);

    char what[256];
    printf("무슨 범죄를 저질렀나요?");
    scanf("%s",what);

    // 조서 내용 출력
    printf(" \n\n ---범죄자 정보---\n\n");
    printf("이름      :%s\n",name);
    printf("나이      :%d\n",age);
    printf("몸무게    :%.2f\n",weight);
    printf("키       :%.2lf\n",height);
    printf("범죄명    :%s\n",what);
    return 0;
}