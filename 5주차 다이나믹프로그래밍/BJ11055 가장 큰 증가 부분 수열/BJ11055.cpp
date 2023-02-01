//BJ11055 ���� ū ���� �κ� ���� ��2 ��Ÿ���丵5���� ���̳������α׷���
#include <iostream>
#include <vector>
using namespace std;

int arr[1001];

long ans = 0;

vector<int> stack;
vector<int> ansStack;

void updateAnswer()
{
    int count = 0;
    for (int i = 0; i < stack.size(); i++)
    {
        count += stack[i];
    }
    if(ans < count)
    {
        ans = count;
        ansStack.clear();
        ansStack.assign(stack.begin(), stack.end());
    }       
}


int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    

    for (int i = 0; i < n; i++)
    {
        if(stack.empty())
        {
            stack.push_back(arr[i]);
            updateAnswer();
        }
        else
        {
            if(arr[i] > ansStack.back())
            {
                stack.clear();
                stack.assign(ansStack.begin(), ansStack.end());
            }
            while (!stack.empty() && stack.back() >= arr[i])
            {
                stack.pop_back();
            }
            stack.push_back(arr[i]);
            updateAnswer();
        }        
    }
    
    
    cout << ans << endl;

    return 0;
}