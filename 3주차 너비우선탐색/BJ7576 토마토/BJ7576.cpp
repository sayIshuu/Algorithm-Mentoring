//BJ7576 �丶�� ��5 �ʺ�켱Ž�� ��Ÿ���丵 3����
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*
    map�ۼ�
    ����üȰ���� ť.. x,y,time

    ���� map�� �ѹ��� ���� 1��ġ �� ã�Ƴ���.
    ������ 1 ��ġ�� ������������ ť�� vector<queue<Node>> list;�� �޴´�.
    �ݺ������� ť�� �ε����� ������
     �ݺ����ڵ忡�� bfs()�ѹ������� ����.
     bfs()�� �ȵ��� time�� ��.
    �䳻������ map�ѹ� �ӵ��� 0������ -1���
*/


int n,m;

typedef struct node
{
    int x;
    int y;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};



int main(void)
{
    cin >> m >> n; // ������ �� �̻��ϴ� �׸��̶� ������ 90�� �ٸ�.
    int map[n][m];
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j]==0) zero++;
        }  
    }
    if(zero==0)
    {
        cout << 0;
        return 0;
    }
    


    //1ã���� ť������ ���Ϳ� �ֱ�
    vector<queue<Node>> list;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
            {
                queue<Node> temp;
                temp.push({i,j});
                list.push_back(temp);
            }
        }   
    }


    int time = 0;
    while(true)
    {
        int temp = 0;
        for (int j = 0; j < list.size(); j++)
        {
            int k = list[j].size();
            while(k--)
            {
                // list[j]�� bfs�ѹ�����.
                int x = list[j].front().x;
                int y = list[j].front().y;
                list[j].pop();
                // ���� ��ġ���� �����¿�Ȯ��
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    // �̷� ������ ��� ��� ����
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    // �̵��� �� ���� ĭ�� ��� ����
                    if(map[nx][ny] != 0) continue;

                    // ó�� �湮 & �̵� ����
                    if (map[nx][ny] == 0)
                    {
                        //�湮üũ
                        map[nx][ny] = 1;
                        list[j].push({nx,ny});
                        temp++;
                    }
                }
            }
        }
        if(temp == 0) break;
        time++;
    } 
    


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }  
    }   

    cout << time;

    return 0;
}