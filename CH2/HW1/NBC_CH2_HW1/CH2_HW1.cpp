#include <iostream>
#include <array>

using namespace std;

// �հ�
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

// ���
float arravg(const int sum, const int size)
{
    return float(sum) / float(size);
}

// �������� ����
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

// �������� ����
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
    <�ʼ� ���>
    - ����ڷκ��� 5���� ���ڸ� �Է� �޾� �迭�� �����ϰ� �̵��� �հ�� ����� ����ؼ� ������ּ���!
    - 5���� ���ڸ� �Է� �޴� ������ �迭�� Ȱ���ҰԿ�!
    - �հ� ����� ���ϴ� ������ main�Լ��� �ѹ��� �ۼ����� ���� ���� �Լ��� �������ֽô� ������ �ؿ�!
    */

    cout << "5���� ���ڸ� ���ʴ�� �Է����ּ���." << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    sum = arrsum(arr);
    avg = arravg(sum, 5);

    cout << "�հ� : " << sum << endl << "��� : " << avg << endl;

    /*
    <���� ���>
    - ������ �������� ���İ� �������� ������ �����ؾ� �մϴ�.
    - ���� 1�� �Է� ������ �������� ����, ���� 2�� �Է� ������ �������� ������ �ϵ��� �������ּ���.
    - `algorithm` ����� `sort` �Լ��� ������� �ʰ� ���� �����غ�����.
    - �������� ���İ� �������� ���� ������ ���� �Լ��� �����غ���!
    */

    do
    {
        cout << endl << "���� ����� ���� ���ּ���. [1. ��������] [2. ��������]" << endl;

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
            cout << "�ش�Ǵ� ���� ����� �������� �ʽ��ϴ�." << endl;
            break;
        }
    } while (type != 1 && type != 2);

    for (auto& iter : arr)
    {
        cout << iter << " ";
    }

    cout << endl << "���� �Ϸ�!" << endl;

    return 0;
}
