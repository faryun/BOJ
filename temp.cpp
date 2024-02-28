#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team
{
    int num;
    int solved;
    int time;
};

bool compare(const Team& t1, const Team& t2)
{
    //푼 문제수가 같으면
    if(t1.solved == t2.solved) return t1.time < t2.time;
    else return t1.solved >= t2.solved;
}

int main()
{
    //전처리
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //정답 관리
    vector<vector<int>> ac;

    //패널티 관리
    vector<vector<int>> pen;

    //팀 정보 관리
    vector<Team> team_t;

    int teams, problem, log;
    cin >> teams >> problem >> log;
    
    team_t.resize(teams + 1);
    ac.resize(problem + 1);
    pen.resize(problem + 1);
    
    for(int t = 1; t < team_t.size(); t++) 
    {
        team_t[t].num = t;
        team_t[t].solved = 0;
        team_t[t].time = 0;
    }

    for(int l = 0; l < log; l++)
    {
        int time, team, p;
        string res;
        cin >> time >> team >> p >> res;

        //이미 푼 문제
        if(find(ac[p].begin(), ac[p].end(),team) != ac[p].end()) continue;

        //정답시
        if(res == "AC")
        {
            ac[p].push_back(team);
            team_t[team].solved++;
            team_t[team].time += time + pen[p][team] * 20;
        }

        else pen[p][team]++;
    }

    //정렬
    sort(team_t.begin()+1,team_t.end(),compare);

    //결과 출력
    for(int o = 1; o < team_t.size(); o++) cout << team_t[o].num << " " << team_t[o].solved << " " << team_t[o].time << "\n";
}