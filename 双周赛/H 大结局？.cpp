#include<bits/stdc++.h>
using namespace std;

double a[10],b[10];
double ans = 0;

double prob(int team,const vector<int>& players,const int seed_of[])
{
	int n = players.size();
	if(n == 1)
	{
		if(players[0] == team) return 1.0;
		else return 0.0;
	}
	vector<int> left,right;
	for(int i = 0;i < n/2;i++)
	{
		left.push_back(players[i]);
		right.push_back(players[i + n / 2]);
	}
	
	double left_prob = prob(team,left,seed_of);
	double right_prob = prob(team,right,seed_of);
	
	
	double beat_right_prob = 0.0;
	for(auto opp : right)
	{
		double opp_win = prob(opp,right,seed_of);
		if(opp_win > 0)
		{
			double opp_p,team_p;
			if(seed_of[opp] > seed_of[team])
			{
				opp_p = b[opp];
				team_p = a[team];
			}
			else
			{
				opp_p = a[opp];
				team_p = b[team];
			}
			double beat = team_p / (team_p + opp_p);
			beat_right_prob += opp_win * beat;
		}
	}
	
	double beat_left_prob = 0.0;
	for(auto opp : left)
	{
		double opp_win = prob(opp,left,seed_of);
		if(opp_win > 0)
		{
			double opp_p,team_p;
			if(seed_of[opp] > seed_of[team])
			{
				opp_p = b[opp];
				team_p = a[team];
			}
			else
			{
				opp_p = a[opp];
				team_p = b[team];
			}
			double beat = team_p / (team_p + opp_p);
			beat_left_prob += opp_win * beat;
		}
	}
	return left_prob * beat_right_prob + right_prob * beat_left_prob;
}

int main()
{
	for(int i = 0;i < 8;i++) cin >> a[i] >> b[i];
	vector<int> teams(8);
	for(int i = 0;i < 8;i++) teams[i] = i;
	double best = 0.0;
	do
	{
		int seed_of[8];
		for(int i = 0;i < 8;i++)
		{
			seed_of[teams[i]] = i + 1;
		}
		vector<int> all = teams;
		ans = max(ans,prob(0,all,seed_of));
	}while(next_permutation(teams.begin(),teams.end()));
	
	cout << setprecision(12) << ans << endl;
}