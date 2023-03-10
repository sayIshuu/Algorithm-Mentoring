//BJ12865 평범한 배낭 골5 언타멘토링5주차 다이나믹쿠프로그래밍구
#include <iostream>
using namespace std;
//점화식을...뭐가 늘어나는거지..
//갯수도 달라지고, 준서근성도 달라지고, 물건종류도 매번 다 다른데 어떻게 규칙을 찾지
//포기.

//==============================================================================
// 멘토링 이후.
// 배낭 풀이법이란게 있으니 어떻게 이렇게 생각하지 보단 알고리즘 듣고, 익히는 정도로.
// 물건 갯수 (경우의 수) 늘려가며 (새로운물건을 넣었을 때 가치) + (이전 상황에서 새로운 물건 무게 제했을때 최대가치) vs 안넣었을때 가치
// 하나씩 늘려간다.
// 중요한 포인트는 이전 상황의 최선의 가치가 기록되어 있다는 점.

// 2차원 배열로 열은 가방무게, 행은 물건 갯수, 값은 최대가치. 마지막 값이 최대 가치
int bag[102][100020];

int main(void)
{
    int n,k;
    cin >> n >> k;

    int stuff[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> stuff[i][0] >> stuff[i][1];
    }
    

    //stuff[0][0] = 첫번째 물건 무게 stuff[0][1] = 첫번째 물건 가치
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if(stuff[i-1][0] <= j)
            {
                //안넣은게 더 클때
                if(bag[i-1][j] > stuff[i-1][1]+bag[i-1][j-stuff[i-1][0]])
                {
                    bag[i][j] = bag[i-1][j];
                }
                else
                {
                    bag[i][j] = stuff[i-1][1]+bag[i-1][j-stuff[i-1][0]];
                }
            }
            else{
                bag[i][j] = bag[i-1][j];
            }
        }   
    }

    cout << bag[n][k] << endl;
    return 0;
}