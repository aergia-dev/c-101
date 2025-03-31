/*
    bit manipulation
    리눅스에서 파일 권한 개념을 사용
    "#define"은 배우지 않는 개념이지만 책 찾아 보고 진행해 보시죠
*/

#include <stdio.h>

#define READ 4    // 100
#define WRITE 2   // 010
#define EXECUTE 1 // 001

#define USER 2  // 소유자(왼쪽부터 첫 번째 위치)
#define GROUP 1 // 그룹(중간 위치)
#define OTHER 0 // 기타(오른쪽 위치)

// 권한을 8진수로 출력하는 함수
void printPermission(unsigned int perm)
{
    printf("%o\n", perm);
}

// 1. 권한을 부여하는 함수를 완성하세요
unsigned int grantPermission(unsigned int current_perm, int user_type, unsigned int permission)
{
    // 여기에 코드 작성
}

// 2. 권한을 제거하는 함수를 완성하세요
unsigned int revokePermission(unsigned int current_perm, int user_type, unsigned int permission)
{
    // 여기에 코드 작성
}

// 3. 특정 권한이 있는지 확인하는 함수를 완성하세요
int hasPermission(unsigned int current_perm, int user_type, unsigned int permission)
{
    // 여기에 코드 작성
}

int main()
{
    // 초기 권한: 644 (rw-r--r--)
    unsigned int perm = 0644;

    // 1. 소유자에게 실행 권한 추가
    perm = grantPermission(perm, USER, EXECUTE);
    printPermission(perm); // 예상 출력: 744

    // 2. 그룹에 쓰기 권한 추가
    perm = grantPermission(perm, GROUP, WRITE);
    printPermission(perm); // 예상 출력: 764

    // 3. 다른 사용자의 모든 권한 제거
    perm = revokePermission(perm, OTHER, READ | WRITE | EXECUTE);
    printPermission(perm); // 예상 출력: 760

    // 4. 권한 확인
    printf("소유자 실행 권한: %d\n", hasPermission(perm, USER, EXECUTE));    // 예상 출력: 1
    printf("그룹 읽기 권한: %d\n", hasPermission(perm, GROUP, READ));        // 예상 출력: 1
    printf("기타 사용자 읽기 권한: %d\n", hasPermission(perm, OTHER, READ)); // 예상 출력: 0

    return 0;
}