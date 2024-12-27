#include <iostream>
#include <array>

using namespace std;

// 합계
template <typename T, size_t N>
int arrsum(const array<T, N>& arr)
{
    int sum = 0;

    for (auto& element : arr)
    {
        sum += element;
    }

    return sum;
}

// 평균
float arravg(const int sum, const int size)
{
    return float(sum) / float(size);
}

// 오름차순 정렬
template <typename T, size_t N>
void ascsort(array<T, N>& arr)
{
    int temp = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 내림차순 정렬
template <typename T, size_t N>
void descsort(array<T, N>& arr)
{
    int temp = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    array<int, 5> arr;
    int sum = 0;
    float avg = 0.0f;
    int type = 0;

    /*
    <필수 기능>
    - 사용자로부터 5개의 숫자를 입력 받아 배열에 저장하고 이들의 합계와 평균을 계산해서 출력해주세요!
    - 5개의 숫자를 입력 받는 공간은 배열을 활용할게요!
    - 합과 평균을 구하는 동작은 main함수에 한번에 작성하지 말고 각각 함수를 구현해주시는 것으로 해요!
    */

    cout << "5개의 숫자를 차례대로 입력해주세요." << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    sum = arrsum(arr);
    avg = arravg(sum, 5);

    cout << "합계 : " << sum << endl << "평균 : " << avg << endl;

    /*
    <도전 기능>
    - 정렬은 오름차순 정렬과 내림차순 정렬이 가능해야 합니다.
    - 숫자 1을 입력 받으면 오름차순 정렬, 숫자 2를 입력 받으면 내림차순 정렬을 하도록 구현해주세요.
    - `algorithm` 헤더의 `sort` 함수를 사용하지 않고 직접 구현해보세요.
    - 오름차순 정렬과 내림차순 정렬 동작을 각각 함수로 구현해봐요!
    */

    do
    {
        cout << endl << "정렬 방식을 선택 해주세요. [1. 오름차순] [2. 내림차순]" << endl;

        cin >> type;

        switch (type)
        {
        case 1:
            ascsort(arr);
            break;
        case 2:
            descsort(arr);
            break;
        default:
            cout << "해당되는 정렬 방식이 존재하지 않습니다." << endl;
            break;
        }
    } while (type != 1 && type != 2);

    for (auto& iter : arr)
    {
        cout << iter << " ";
    }

    cout << endl << "정렬 완료!" << endl;

    return 0;
}
