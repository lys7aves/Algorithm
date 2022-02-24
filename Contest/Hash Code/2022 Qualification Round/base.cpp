#include <bits/stdc++.h>

#define pii pair<int,int>

#define MAXC 100010
#define MAXP 100010
#define MAXS 810

using namespace std;

struct ProjectSkillInfo{
	int level, skill, num, contributor;
};
bool cmp_level(const ProjectSkillInfo &x, const ProjectSkillInfo &y){
	return x.level > y.level;
}
bool cmp_num(const ProjectSkillInfo &x, const ProjectSkillInfo &y){
	return x.num < y.num;
}

struct ContributorInfo{
	int id, N;
	int skills[MAXS];
};

struct ProjectInfo{
	int id, executed_num;
	int D, S, B, R;
	vector<ProjectSkillInfo> skills;
	double sort_standard;
};
bool cmp_sort_standard(const ProjectInfo &x, const ProjectInfo &y){
	return x.sort_standard > y.sort_standard;
}

int C, P;
int executed_cnt;
int end_time[MAXC];
bool chk_contributor[MAXC];

int skill_cnt;
unordered_map<string, int> skill_map;
string contributor_vec[MAXC], skill_vec[MAXS], project_vec[MAXP];

ContributorInfo contributors[MAXC];
set<pii> skills[MAXS];		// <level, name>
ProjectInfo projects[MAXP];

void input_data();
void test_function();
void sort_project();
int set_project(int project_id);	// return score
void print_result();

int main()
{
	int i, j, start_time, score;
	
	freopen("input_data/a_an_example.in.txt","r",stdin);
	//freopen("input_data/b_better_start_small.in.txt","r",stdin);
	//freopen("input_data/c_collaboration.in.txt","r",stdin);
	//freopen("input_data/d_dense_schedule.in.txt","r",stdin);
	//freopen("input_data/e_exceptional_skills.in.txt","r",stdin);
	//freopen("input_data/f_find_great_mentors.in.txt","r",stdin);
	freopen("output_data/a.out.txt","w",stdout);
	//freopen("output_data/b.out.txt","w",stdout);
	//freopen("output_data/c.out.txt","w",stdout);
	//freopen("output_data/d.out.txt","w",stdout);
	//freopen("output_data/e.out.txt","w",stdout);
	//freopen("output_data/f.out.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	input_data();
	
	
	sort_project();
	
	start_time = 0;
	score = 0;
	for(i=0; i<P; i++){
		score += set_project(i);
	}
	
	print_result();
	
	//test_function();
	
	return 0;
}

void input_data()
{
	int i, j, level, skill_num;
	string name, skill, project;
	
	cin >> C >> P;
	
	for(i=0; i<C; i++){
		cin >> name >> contributors[i].N;
		contributors[i].id = i;
		contributor_vec[i] = name;
		
		for(j=0; j<contributors[i].N; j++){
			cin >> skill >> level;
			
			if(skill_map.find(skill) == skill_map.end()){
				skill_map[skill] = skill_cnt;
				skill_vec[skill_cnt] = skill;
				skill_cnt++;
			}
			skill_num = skill_map[skill];
			contributors[i].skills[skill_num] = level;
			
			skills[skill_num].insert({level, i});
		}
	}
	
	for(i=0; i<P; i++){
		cin >> project >> projects[i].D >> projects[i].S >> projects[i].B >> projects[i].R;
		projects[i].id = i;
		project_vec[i] = project;
		
		for(j=0; j<projects[i].R; j++){
			cin >> skill >> level;
			
			skill_num = skill_map[skill];
			
			projects[i].skills.push_back({level, skill_num, j, 0});
		}
		
		sort(projects[i].skills.begin(), projects[i].skills.end(), cmp_level);
	}
}

void test_function()
{
	int i, j;
	
	cout << "# Project\n";
	for(i=0; i<P; i++){
		cout << project_vec[projects[i].id];
		printf(" %d %d %d %d\n", projects[i].D, projects[i].S, projects[i].B, projects[i].R);
		
		for(j=0; j<projects[i].R; j++){
			cout << skill_vec[projects[i].skills[j].skill] << ' ' << projects[i].skills[j].level << '\n';
		}
	}
	
	cout << '\n';
	cout << "# Skill\n";
	for(i=0; i<skill_cnt; i++){
		cout << skill_vec[i] << " : ";
		for(auto it=skills[i].begin(); it!=skills[i].end(); it++){
			cout << "(" << contributor_vec[it->second] << "," << it->first << ") ";
		}
		cout << '\n';
	}
}

void sort_project()
{
   int i;
   int D_rate=0,S_rate=0,B_rate=1;
   
    auto D_max = *max_element(projects, projects+P,
                             [](const ProjectInfo& a,const ProjectInfo& b) { return a.D < b.D; }); 

   auto S_max = *max_element(projects, projects+P,
                             [](const ProjectInfo& a,const ProjectInfo& b) { return a.S < b.S; }); 

   auto B_max = *max_element(projects, projects+P,
                             [](const ProjectInfo& a,const ProjectInfo& b) { return a.B < b.B; }); 
   
   for(i=0; i<P; i++){
   		//projects[i].sort_standard = i;
         projects[i].sort_standard = D_rate * (1.0 * projects[i].D/D_max.D) + S_rate * (1.0-(1.0 * projects[i].S/S_max.S)) + B_rate * (1.0 * projects[i].B/B_max.B);
         //cout << projects[i].id << " " << projects[i].sort_standard << " \n";
   }

   sort(projects, projects+P, cmp_sort_standard);
}

int set_project(int project_id)	// return score
{
	int i, skill, level, start_time, score;
	
	for(i=0; i<C; i++) chk_contributor[i] = false;
	
	//cout << project_vec[projects[project_id].id] << '\n';
	start_time = 0;
	for(i=0; i<projects[project_id].R; i++){
		skill = projects[project_id].skills[i].skill;
		level = projects[project_id].skills[i].level;
		
		auto best_it=skills[skill].end();
		for(auto it=skills[skill].begin(); it!=skills[skill].end(); it++){
			if(it->first < level) continue;
			if(chk_contributor[it->second]) continue;
			
			if(best_it == skills[skill].end() || end_time[best_it->second] > end_time[it->second]){
				best_it = it;
			}
		}
		
		if(best_it == skills[skill].end()) return 0;
		
		projects[project_id].skills[i].contributor = best_it->second;
		start_time = max(start_time, end_time[best_it->second]);
		chk_contributor[best_it->second] = true;
		//cout << skill_vec[skill] << " : " << contributor_vec[best_it->second] << '\n';
	}
	
	score = projects[project_id].S - max(0, (start_time+projects[project_id].D) - projects[project_id].B);
	if(score <= 0) return 0;
	
	executed_cnt++;
	projects[project_id].executed_num = start_time+1;
	for(i=0; i<projects[project_id].R; i++){
		end_time[projects[project_id].skills[i].contributor] = start_time + projects[project_id].D;
	}
	
	return score;
}

void print_result()
{
	int i, j;
	
	for(i=0; i<P; i++){
		projects[i].sort_standard = -projects[i].executed_num;
	}
	sort_project;
	
	cout << executed_cnt << '\n';
	for(i=0; i<P; i++){
		if(projects[i].executed_num == 0) continue;
		
		cout << project_vec[projects[i].id] << '\n';
		
		sort(projects[i].skills.begin(), projects[i].skills.end(), cmp_num);
		for(j=0; j<projects[i].R; j++){
			cout << contributor_vec[projects[i].skills[j].contributor] << ' ';
		}
		cout << '\n';
	}
}
