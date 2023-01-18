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
    queue<Node> q;
    //������ �� �Ǿ�ĭ Ǫ�� �� �湮üũ, ������ 1���� ����.
    q.push({0,0,1});
    miro[0][0] = 0;
    
    while (!q.empty())
    {
        Node front = q.front();
        int x = front.N;
        int y = front.M;
        //������ �����ϸ� ������ ���� ����ϰ� ��
        if(q.back().N == n-1 && q.back().M == m-1)
        {
            cout << q.back().level << endl;
            break;
        }

        //�����¿� ����, �湮üũ�ؼ� push�� ���ÿ� �湮üũ����.
        //��
        if(x+1 >= 0 && x+1 < n)
        {
            if(miro[x+1][y] == 1)
            {
                q.push({x+1,y,front.level+1});
                miro[x+1][y] = 0;
            }
        }
        //��
        if(y+1 >= 0 && y+1 < m)
        {
            if(miro[x][y+1] == 1)
            {
                q.push({x,y+1,front.level+1});
                miro[x][y+1] = 0;
            }
        }
        //��
        if(x-1 >= 0 && x-1 < n)
        {
            if(miro[x-1][y] == 1)
            {
                q.push({x-1,y,front.level+1});
                miro[x-1][y] = 0;
            }
        }
        //��
        if(y-1 >= 0 && y-1 < m)
        {
            if(miro[x][y-1] == 1)
            {
                q.push({x,y-1,front.level+1});
                miro[x][y-1] = 0;
            }
        }

        //�Ǿճ�� ��
        q.pop(); 
    }
    return 0;
}