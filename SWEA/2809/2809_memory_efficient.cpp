#include <iostream>
#include <set>

int count = 0;
// SWEA 2809 : N-Queen, 고전적인 문제
void solve(const int& N, int row, std::set<std::pair<int,int>> impossible_block) // i,j는 놓을 수 없다는 뜻
{
    // 마지막 행이면 count++
    if(N==row){
        count++;
        return;
    }
    // 놓을 수 있는 지 체크하면서, 다음에 둘 칸 찾기
    for(int column=0; column < N; column++)
    {
        //놓을 수 있는 column 이라면
        if(impossible_block.find(std::make_pair(row,column)) == impossible_block.end())
        {
            std::set<std::pair<int,int>> next = impossible_block;
            // impossible_column에 현재 column 추가하기
            for(int i=0; i<N; i++)
            next.insert(std::make_pair(i,column));

            // 대각선도 추가하기
            for(int i = 1; i+column<N; i++)
            {
                // 우하단 대각선
                next.insert(std::make_pair(row+i,column+i));
            }
            for(int i = 1; column-i>=0; i++)
            {
                // 좌하단 대각선
                next.insert(std::make_pair(row+i,column-i));
            }
            // 놓고 다음 행으로 가기
            solve(N, row+1, next);
        }
        else continue;
    }
}


int main(){
    int T;
    std::cin >> T;
    for(int i=0;i<T;i++)
    {
        int tmp;
        std::cin >> tmp;
        std::set<std::pair<int,int>> impossible_block;
        solve(tmp, 0, impossible_block);
        std::cout << "#" << i+1 << " " << count << "\n";
        count = 0;
    }
    return 0;
}