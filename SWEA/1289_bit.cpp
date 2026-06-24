#include <iostream>
#include <vector>
#include <string>

//1289. 원재의 메모리 복구하기, 난이도: D3

int solve(const std::string& test_case)
{
    int length = test_case.length();
    int count = 0;
    // 00...00으로 초기화
    uint64_t restore_str = 0;
    for(int i=0;i<length;i++)
    {
        if(test_case[i]=='1')
        {
            // 이미 1이면 넘어가기
            if(restore_str & ((uint64_t)1 << (length-i-1))) continue;
            else {
                count++;
                // 1로 만들고 나머지도 모두 1로
                restore_str |= (((uint64_t)1 << (length-i)) - 1);
            } 
        }
        else if(test_case[i]=='0')
        {
            // 이미 0이면 넘어가기
            if(((restore_str >> (length-i-1) & 1)) == 0) continue;
            else {
                count++;
                // 0으로 만들고 나머지도 모두 0으로
                restore_str &= ((~(uint64_t)1) << (length-i-1));
            }
        }
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