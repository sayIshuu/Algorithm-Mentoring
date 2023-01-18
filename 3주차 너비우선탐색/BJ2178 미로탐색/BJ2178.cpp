//BJ2178 �̷�Ž�� ��1 �˰�����丵 3���� �ʺ�켱Ž��
#include <iostream>
#include <string>
#include <queue>
using namespace std;


//�������̵�� : ������ �ʺ�켱Ž���� �ִܰŸ��� ���س���. ���������� ����

//ť�� ��Ұ� �� ����ü
typedef struct node
{
    int N;
    int M;
    int level;
}Node;


int main(void)
{
    //============2�����迭�� �̷� ����===============
    int n,m;
    cin >> n >> m;
    int miro[n][m]; //�ε������� -1 ����

    for (int i = 0; i < n; i++)
    {
        //�ڸ������� ��,������ ���ϱ⺸�� ���ڿ��� �ް� �ѱ��ھ� ����ȯ
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            miro[i][j] = temp[j]-'0';
        }
    }


    //ť�� �̷��� ��ġ������ ������ �־���� => ����ü
    //(0,0)�� �������� ���� �־���
    //�����¿� üũ�ؼ� Ǫ�����ָ鼭 �̷ΰ��� 0���� ��ȯ => �湮üũ
    //Ǫ���Ҷ� ���� �Ÿ��� ���������� �ξ� Ǫ���� ������ ��Ұ�
    //�Ÿ������� ������ �ְ���.
    //������ �����ϸ� �Ÿ����� ����ϰ� break;

    queue<Node> q;
    q.push({0,0,1});
    
    while (!q.empty())
    {
        Node front = q.front();
        //������ �����ϸ� ������ ���� ����ϰ� ��
        if(q.back().N == n-1 && q.back().M == m-1)
        {
            cout << q.back().level;
            break;
        }
        //��
        if(front.N+1 >= 0 && front.N+1 < n)
        {
            if(miro[front.N+1][front.M] == 1)
            {
                q.push({front.N+1,front.M,front.level+1});
            }
        }
        //��
        if(front.M+1 >= 0 && front.M+1 < m)
        {
            if(miro[front.N][front.M+1] == 1)
            {
                q.push({front.N,front.M+1,front.level+1});
            }
        }
        //��
        if(front.N-1 >= 0 && front.N-1 < n)
        {
            if(miro[front.N-1][front.M] == 1)
            {
                q.push({front.N-1,front.M,front.level+1});
            }
        }
        //��
        if(front.M-1 >= 0 && front.M-1 < m)
        {
            if(miro[front.N][front.M-1] == 1)
            {
                q.push({front.N,front.M-1,front.level+1});
            }
        }

        //�Ǿճ�� �湮üũ�ϰ� ��
        miro[front.N][front.M] = 0;
        q.pop(); 
    }
    return 0;
}
