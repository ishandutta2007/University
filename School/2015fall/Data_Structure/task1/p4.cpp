/*
4. 参加比赛有n个学院，学院编号为1……n。比赛分成m个男子项目，和w个女子项目。项目编号为男子1……m，女子m+1……m+w。不同的项目取前五名或前三名积分；
取前五名的积分分别为：7、5、3、2、1，前三名的积分分别为：5、3、2；哪些取前五名或前三名由学生自己设定。（m<=20,n<=20）
功能要求：

1)可以输入各个项目的前三名或前五名的成绩；

2)能统计各学院总分，

3)可以按学院编号或名称、学校总分、男女团体总分排序输出；

4)可以按学院编号查询学院某个项目的情况；可以按项目编号查询取得前三或前五名的学院。

5)数据存入文件并能随时查询

6)规定：输入数据形式和范围：可以输入学院的名称，运动项目的名称

输出形式：有中文提示，各学院分数为整形

界面要求：有合理的提示，每个功能可以设立菜单，根据提示，可以完成相关的功能要求。

存储结构：学生自己根据系统功能要求自己设计，但是要求运动会的相关数据要存储在数据文件中。

测试数据：1、全部合法数据；2、整体非法数据；3、局部非法数据。进行程序测试，以保证程序的稳定。测试数据及测试结果请在上交的资料中写明；
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
struct Department
{
	string name;
	int tot_score, bscore, gscore, id;
	int rank;
	Department(){}
	Department(string name, int id):name(name),id(id)
	{
		tot_score = bscore = gscore = 0;
	}

	void show()
	{
		printf("id: %d, score: %d, man_score: %d, woman_score: %d, rank: %d,  name:", id, tot_score,bscore,gscore, rank);
		cout << name <<endl;
	}
};
bool cmp_by_id(Department a, Department b)
{
	return a.id < b.id;
}
bool cmp_by_name(Department a, Department b)
{
	return a.name < b.name;
}
bool cmp_by_bscore(Department a, Department b)
{
	return a.bscore > b.bscore;
}
bool cmp_by_gscore(Department a, Department b)
{
	return a.gscore > b.gscore;
}
bool cmp_by_score(Department a, Department b)
{
	return a.tot_score > b.tot_score;
}
struct Event
{
	int tp;
	int top[10], score[10];
	Event(){}
	Event(int tp):tp(tp)
	{
		if(tp == 3)
			score[1] = 5,score[2] = 3, score[3] = 2;
		else
			score[1] = 7,score[2] = 5, score[3] = 3, score[4] = 2, score[5] = 1;
	}
};


vector<Department> departments;
int n, m;
vector<Event> ve;
map<int, int>mp;
char ts[8][20] = {"id", "tot score", "man score" , "women score", "name"};


void getscore()
{
	for(int i = 0, l = ve.size(); i < l; i++)
	{
		Event& dep = ve[i];
		for(int j = 1; j <= dep.tp; j++)
		{
			if(i >= m)
				departments[mp[dep.top[j]]].gscore += dep.score[j];
			else 
				departments[mp[dep.top[j]]].bscore += dep.score[j];
			departments[mp[dep.top[j]]].tot_score += dep.score[j];
		}
	}
}


int main()
{

	departments.clear();

	printf("Please input the N (for the number of departments)\n");
	// try
	// {
	// 	cin >> n >> m;
	// }
	// catch(exception &e)
	// {
	// 	cout << "Input error , error type :" << e.what() <<endl;
	// }

	cin >> n;


	for(int i = 0; i < n; i++)
	{
		printf("Please input the %dth department's information\nid   name\n", i+1);
		string name;
		int id;
		cin >> id >> name;
		while(mp.find(id) != mp.end())
		{
			printf("Same id found, input error\n check your input and try again\n");
			cin >> id >> name;
		}
		mp[id] = i;
		departments.push_back(Department(name, id));

	}
	printf("Reading Department's information succeeded\n\n");

	printf("Please input the number of man events\n");
	scanf("%d", &m);
	printf("Please input %d events and the ranklist\n", m);
	int tmpid;
	for(int i = 0; i < m; i++)
	{
		printf("Input the event type (3 or 5)\n");
		scanf("%d", &tmpid);
		ve.push_back(Event(tmpid));
		printf("Input the top %d departments in id form\n", tmpid);
		for(int j = 1; j <= tmpid; j++)
		{
			scanf("%d", &ve[i].top[j]);
		}
	}
	int w;
	printf("Please input the number of woman events\n");
	scanf("%d", &w);
	printf("Please input %d events and the ranklist\n", w);
	for(int i = 0; i < w; i++)
	{
		printf("Input the event type (3 or 5)\n");
		scanf("%d", &tmpid);
		ve.push_back(Event(tmpid));
		printf("Input the top %d departments in id form\n", tmpid);
		for(int j = 1; j <= tmpid; j++)
		{
			scanf("%d", &ve[i+m].top[j]);
		}
	}
	printf("Reading data finished\n");
	getscore();
	printf("Cal score finished\n");
	sort(departments.begin(), departments.end(), cmp_by_score);
	for(int i = 0, l = departments.size(); i < l; i++)
		departments[i].rank = i+1;

	printf("ranklist by score\n\n\n");
	for(int i = 0, l = departments.size(); i < l; i++)
	{
		departments[i].show();
	}

	// cout << " !!! " << endl;

	
	int cmd, precmd = 1;
	while(true)
	{
		printf("input your cammand(0 - 6)\n");
		printf("1 for sort the departments by id order\n");
		printf("2 for sort the departments by total score\n");
		printf("3 for sort the departments by man score\n");
		printf("4 for sort the departments by woman score\n");
		printf("5 for sort the departments by name order\n");
		printf("6 for save current list to file\n");
		printf("0 for exit\n");
		scanf("%d", &cmd);
		if(cmd == 1) sort(departments.begin(),departments.end(), cmp_by_id),precmd = 1;
		else if(cmd == 2) sort(departments.begin(),departments.end(), cmp_by_score), precmd = 2;
		else if(cmd == 3) sort(departments.begin(),departments.end(), cmp_by_bscore) ,precmd = 3;
		else if(cmd == 4) sort(departments.begin(),departments.end(), cmp_by_gscore), precmd = 4;
		else if(cmd == 5) sort(departments.begin(),departments.end(), cmp_by_name), precmd = 5;
		else if(cmd == 6)
		{
			freopen("data.out", "w", stdout);
			printf("List ordered by %s:\n", ts[precmd]);
			for(int i = 0, l = departments.size(); i < l; i++)
				departments[i].show();
			fclose(stdout);
		}
		else break;
	}

	return 0;
}