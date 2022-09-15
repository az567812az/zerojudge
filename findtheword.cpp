#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
char matrix[76][76];
int slen = -1,sr = -1,sc = -1,er = -1,ec = -1,r = -1,c = -1;
string goal;
vector<pair<int,int>> arr;
void find_pos()
{
	for(int i=0;i<r;i++)
	{ 
		for(int j=0;j<c;j++)
		{ 
			if(matrix[i][j] == goal[0])
				arr.push_back(make_pair(i,j));
		} 
	} 
}
void dfs(int nr,int nc,int cnt)
{
	if(goal[cnt] != matrix[nr][nc]) return;
	if(nr<0 || nr>=r || nc<0 || nc >= c) return;
	if(cnt == slen-1)
	{
		if(er!=-1)
			er = min(er,nr);
		else
			er = nr;
		if(ec!=-1)
			ec = min(ec,nc);
		else
			ec = nc;
		return;
	}
	dfs(nr-1,nc,cnt+1);
	dfs(nr+1,nc,cnt+1);
	dfs(nr,nc-1,cnt+1);
	dfs(nr,nc+1,cnt+1);
	
}
int main()
{
	fastio
	cin>>r>>c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>matrix[i][j];
	cin>>goal;  
	slen = goal.size();
	find_pos(); 
	int x;
	for(x=0;x<arr.size();x++)
	{
		dfs(arr[x].first,arr[x].second,0);
		if(ec != -1 && er != -1)
		{
			cout<<arr[x].first+1<<" "<<arr[x].second+1<<"\n"<<er+1<<" "<<ec+1; 
			break;
		}
	}
	if(x == arr.size()) cout<<"NO\n";
		
	return 0;
}
