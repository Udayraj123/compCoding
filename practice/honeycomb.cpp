// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int offsets_i_e[6] = { -1, -1, 0, 1, 0,-1 };
int offsets_i_o[6] = { -1,  0, 1, 1, 1, 0 };
int offsets_j[6] =    { 0,  1, 1, 0, -1,-1 };

bool valid(int i, int j, int n, int m){
	return 	(i > -1 && j > -1 && i < n && j < m);
}

int dfs(int curr_sum, int level, int i, int j, int n, int m, vector < vector <int> > mat, vector < vector <bool> >visited){
	curr_sum += mat[i][j];
	if (level == 0){
		cout << ">> ("<< i << "," << j << ") : " << curr_sum << endl;
		return curr_sum;
	}
	visited[i][j] = true;	
	//for each valid ngh, dfs level-1
	int* offsets_i = (j % 2 == 0) ? offsets_i_e : offsets_i_o; 
	int i_, j_, max_sum=0;
	for (int k = 0; k < 6; k++){
		i_ = i + offsets_i[k];
		j_ = j + offsets_j[k];
		if (valid(i_, j_, n, m) && visited[i_][j_] == false)//valid unvisited coord
		{
			cout << mat[i][j] << ") to : " << mat[i_][j_] << "(" << curr_sum << ")" << endl;
			max_sum = max(max_sum, dfs(curr_sum, level - 1, i_, j_, n, m, mat, visited));
		}
	}
	visited[i][j] = false;
	return max_sum;
}


int sum_ngh(int i, int j, int n, int m, vector < vector <int> > mat){
	vector<int> items;
	int* offsets_i = (j % 2 == 0) ? offsets_i_e : offsets_i_o;
	int i_, j_,sum;
	for (int k = 0; k < 6; k++){
		i_ = i + offsets_i[k];
		j_ = j + offsets_j[k];
		if (valid(i_, j_, n, m))//valid coord
		{
			//cout << i << ',' << j << ") valid : " << i_ << ',' << j_ << " : " << mat[i_][j_]<< endl;
			items.push_back(mat[i_][j_]);
			//cout << "done\n";
		}
	}
	//TODO :implement own sort
	sort(items.begin(), items.end());
	sum = mat[i][j];
	int l = items.size()-1;
	for (int k = 0; k < min(l+1,3); k++){
		sum += items[l-k];
	}
	return sum;	
}
int main(int argc, _TCHAR* argv[])
{
	int t=1, n, m, max_sum,sum;
	//cin >> t;
	while (t--){
		cin >> n >> m;
		vector < vector <int> > mat(n, vector <int>(m));//n rows m columns
		vector < vector <bool> > visited(n, vector <bool>(m));//n rows m columns
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
				visited[i][j] = false;
				cout<< mat[i][j] << " ";
			}
			cout << endl;
		}
		max_sum = 0;

		/*
		3 4 150 450 100 320 120 130 160 110 10 60 200 220
		*/
		// for each node, do DFS of depth 4. and also check top 3 neighbours of it.

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++){
				cout << mat[i][j] << endl;
				sum = sum_ngh(i, j, n,m,mat);
				cout <<  endl;
				max_sum = max(max_sum, sum);
				sum = dfs(0, 3, i, j, n, m, mat, visited);//dfs will reset visited array while backtracking.
				max_sum = max(max_sum, sum);
			}
		}
		cout << max_sum << endl;
	}
	return 0;
}

