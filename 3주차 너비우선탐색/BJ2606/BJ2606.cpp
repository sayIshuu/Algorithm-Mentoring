//BJ2606 ���̷��� ��3 ��Ÿ���丵 3���� ������
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    //��������
    int n; 
    cin >> n;
    //��ũ����
    int l;
    cin >> l;

    list<int> arr[n];     // -1 �Ű澲��
    int check[n] = {0,};  // 0�̸� �ش�Ǵ� ���� �湮 ���Ѱ�

    //��������Ʈ �����
    for (int i = 0; i < l; i++)
    {
        int x,y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    //�ʺ�켱Ž�� ����
    list<int> q;

    q.push_front(1);
    check[0] = 1;

    int count = 0;

    for (int i = 0; i <= arr[q.front-1].size()/*q�� �Ǿտ����� ��������Ʈ*/; i++)
    {
        if (check[arr[q.front-1].front()-1] == 0)
        {
            check[arr[q.front-1].front()-1] = 1;
            q.push_back(arr[q.front-1].pop_front());
            count++;
        }
    }



    cout << count << endl;
    return 0;
}
