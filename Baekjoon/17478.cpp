#include <iostream>

using namespace std;

int n;

void print(int p, string str)
{
	for(int i=0; i<4*p; i++) cout << "_";
	cout << str << '\n';
}

void solve(int p)
{
	if(p == n){
		print(p, "\"����Լ��� ������?\"");
		print(p, "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"");
		print(p, "��� �亯�Ͽ���.");
		return; 
	}
	
	print(p, "\"����Լ��� ������?\"");
	print(p, "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.");
	print(p, "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.");
	print(p, "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"");
	
	solve(p+1);
	
	print(p, "��� �亯�Ͽ���."); 
}

int main()
{
	cin >> n;
	
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	solve(0);
	
	return 0;
}