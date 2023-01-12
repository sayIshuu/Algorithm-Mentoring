// BJ1051 �������簢�� ��4 ��Ÿ���丵 2����
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    int n,m;
    cin >> n >> m;
    
    int array[n][m];

    string arr[n];

    int solution = 1;

    // �Է¹����� 2�����迭�� �ϳ��ϳ� ����ֱ�
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
        for (int j = 0; j < m; j++)
        {
            array[i][j] = (arr[i])[j] - '0';    // ����ȯ ���
        }           
    }


    /* �˰��� �߻�ȭ
    (0,0)==(0,m) > (0,0)==(0,m-1) ...
    (1,0)==(1,m) > ...
    ...
    (n,0)==(n,m)...������ ���´�? ��m��-��m�� ���̷� �����ؼ� Ȯ�κ񱳹ݺ� break;
    ����==��n��-��n�� �ι� üũ�ؼ� �ȵǸ� �ٽ� �ݺ��� ���ư��� �Ǹ� solution �ʱ�ȭ
    */
    int tempLength = 1;
    for (int x = 0; x < n; x++) 
    {
        for (int y = 0; y < m; y++)
        {
            for (int p = 0; p < m-y; p++)
            {
                if(array[x][y]==array[x][m-p])
                {
                    tempLength = m-p-y+1;
                    if(array[x+tempLength-1][y]==array[x][y] && array[x+tempLength-1][m-p]==array[x][y] && tempLength*tempLength > solution)
                    {
                        solution = tempLength*tempLength;
                    }
                }
            }
        }   
    }   

    cout << solution << endl;    

    return 0;
}