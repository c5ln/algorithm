#include <iostream>
#include <vector>
#include <string>

//1289. 원재의 메모리 복구하기, 난이도: D3

// 사실 시뮬레이션 안 해봐도, 이전과 다를 때만 연산을 하므로 이렇게 하면 된다.
int solve(const std::string& test_case)
{
    int count=0;
    char prev='0';
    for (char c : test_case)
    {
        if (c != prev) count++;
        prev = c;
    }
    return count;
}

int main()
{
    int T;
    std::string tmp;
    std::vector<std::string> origin; 
    
    // 입력 받기, tmp의 길이는 1이상 50이하
    std::cin >> T;
    for(int i=0;i<T;i++){
        std::cin >> tmp;
        origin.push_back(tmp);
    }
    
    //최소 수정 횟수 구하기
    for (int i=0; i<T; i++){
        int answer = solve(origin.at(i));
        std::cout << "#" << i+1 << " " << answer << "\n"; 
    }
    return 0;
}