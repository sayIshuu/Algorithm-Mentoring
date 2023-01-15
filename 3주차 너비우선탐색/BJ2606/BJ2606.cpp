//BJ2606 ���̷��� ��3 ��Ÿ���丵 3���� ������ �ʺ�켱Ž��
#include <iostream>
//#include <list>
#include <vector> // �ǵ����� list�� �ƴ� vector�� ��������Ʈ �� ť �����غ�����
#include <queue>
using namespace std;

/* ���� ���̵�� - 2 ��������Ʈ �̿��� ����
�׷��� ������ ���ÿ� �� ����� ��������Ʈ �ۼ� by vector
ť ����, 1 push...1�湮üũ
ť �Ǿ� ���(1) ��������Ʈ �����ͼ� �湮üũ �� ť�� push�ϰ� �湮üũ, 1 pop
�ݺ�
ť empty�Ǹ� ����. pop�Ҷ����� count�ؼ� ������ count-1;
*/
// �ʺ�켱Ž���� ���Լ����� ť�� �����Ѵ�.

int main(void)
{
    //��������
    int n; 
    cin >> n;
    //��ũ����
    int l;
    cin >> l;

    vector<vector<int>> nearList(101);
    vector<int> v;     // -1 �Ű澲��
    nearList.push_back(v);
    int check[101] = {0,};  // 0�̸� �ش�Ǵ� ���� �湮 ���Ѱ� 1�̸� �� => �״�� �������� Ȱ���ص� ��.

    //��������Ʈ �����
    for (int i = 0; i < l; i++)
    {
        int x,y;
        cin >> x >> y;
        nearList[x].push_back(y);
        nearList[y].push_back(x);
    }
    

    queue<int> q;
    int count = -1;

    q.push(1);
    check[1] = 1;

    while (!q.empty())
    {
        //ť �Ǿ� ����� ��������Ʈ(nearList[q.front()])�� ť�� push
        for (int i = 0; i < nearList[q.front()].size(); i++)
        {
            if(check[nearList[q.front()][i]] == 0)
            {
                q.push(nearList[q.front()][i]);
                check[nearList[q.front()][i]] = 1;
            }
        }
        q.pop();
        count++;
    }
    
    
    cout << count << endl;
    
    return 0;
}


//test vector nearlist���� ũ�� ���� ���ϴ¹�
//test while������ queue.push(nearlist) �Ǵ���