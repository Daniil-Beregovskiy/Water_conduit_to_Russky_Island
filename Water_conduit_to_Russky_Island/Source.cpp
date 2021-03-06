#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct S { int x; int y; };
struct couple { int a; int b; };

const int alotof = 2000000000;
int N, M, x2, y2;
vector <S> key_a;
vector <S> key_b;
bool key_stop_a = false, key_stop_b = false, i_onebegin = false;
vector <vector <couple>> dist;

vector <int> left_right(4);
vector <int> down_up(4);


int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	char time;
	S arg, t;
	bool f_key = true;
	couple time_S;
	int i_;
	fin >> N >> M;

	dist.resize(N + 2);

	// Заполнение массива
	for (int i = 1; i < N + 1; i++)
	{
		time_S.a = -1; time_S.b = -1;
		dist[i].push_back(time_S);
	}
	for (int i = 1; i < N + 1; i++)
	{
		fin >> time;
		if (time == '#') {
			time_S.a = 0; time_S.b = 0;
			dist[i].push_back(time_S);
		}
		else {
			time_S.a = -1; time_S.b = -1;
			dist[i].push_back(time_S);
		}

		for (int j = 2; j < M + 1; j++)
		{
			fin >> time;
			if (time == '#') {
				time_S.a = alotof; time_S.b = alotof;
				dist[i].push_back(time_S);
			}
			else {
				time_S.a = -1; time_S.b = -1;
				dist[i].push_back(time_S);
			}
		}
	}
	for (int i = 0; i < M + 2; i++)
	{
		time_S.a = -1; time_S.b = -1;
		dist[0].push_back(time_S);
		dist[N + 1].push_back(time_S);
	}
	for (int i = 1; i < N + 1; i++)
	{
		time_S.a = -1; time_S.b = -1;
		dist[i].push_back(time_S);
	}
	//
	left_right[0] = 1;
	left_right[1] = 0;
	left_right[2] = -1;
	left_right[3] = 0;
	down_up[0] = 0;
	down_up[1] = -1;
	down_up[2] = 0;
	down_up[3] = 1;

	//////////

	for (int i = 1; i < N + 1; i++) {
		if (dist[i][1].a == 0 && key_stop_a == false) {
			arg.x = i;
			arg.y = 1;
			dfs_a(arg);
			i_ = i;
		}
	}
	for (int i = N; i > 0; i--) {
		if (dist[i][1].b == 0 && key_stop_b == false) {
			arg.x = i;
			arg.y = 1;
			if (i_ == i)
				i_onebegin = true;
			dfs_b(arg);
		}
	}

	///////

	if (!key_stop_a && !key_stop_b)
		fout << "NO";
	else
	{
		if (key_a.size() == key_b.size()) {
			for (int i = 0; i < key_a.size(); i++)
			{
				if (key_a[i].x != key_b[i].x || key_a[i].y != key_b[i].y)
					f_key = false;
			}
		}
		else
			f_key = false;

		if (f_key) {
			fout << "YES" << endl;
			fout << key_a.size() << " ";
			for (int i = 0; i < key_a.size(); i++)
			{
				t = key_a.front();
				fout << key_a[i].x << " " << key_a[i].y << "  ";
			}
		}
		else {
			fout << "MULTIPLE" << endl;
			fout << key_a.size() << " ";
			for (int i = 0; i < key_a.size(); i++)
			{
				t = key_a.front();
				fout << key_a[i].x << " " << key_a[i].y << "  ";
			}
			fout << endl << key_b.size() << " ";
			for (int i = 0; i < key_b.size(); i++)
			{
				t = key_b.front();
				fout << key_b[i].x << " " << key_b[i].y << "  ";
			}
		}
	}

	cout << key_a.size() - 1 << endl;
	for (int i = 0; i < key_a.size(); i++)
	{
		t = key_a.front();
		cout << "(" << key_a[i].y << " " << key_a[i].x << ")  ";
	}

	cout << endl << endl << key_b.size() - 1 << endl;
	for (int i = 0; i < key_b.size(); i++)
	{
		t = key_b.front();
		cout << "(" << key_b[i].y << " " << key_b[i].x << ")  ";
	}

	cin >> N;
}