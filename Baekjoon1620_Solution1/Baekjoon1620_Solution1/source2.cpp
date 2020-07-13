#include<iostream>
#include<unordered_map>
#include<vector>
#include<cctype>
#include<string>
using namespace std;

int main() {
	int n, m, index;
	string name, quiz;
	unordered_map<string, int> pkmon;
	vector<string> map;

	cin >> n;
	cin >> m;

	if (n < 1 && n > 100000 || m < 1 && m > 100000)
		return 0;

	for (int i = 0; i < n; i++) {
		cin >> name;
		map.push_back(name);
		pkmon.insert({ name, i + 1 });			// make_pair
	}

	for (int j = 0; j < m; j++) {
		cin >> quiz;
		if (isdigit(quiz[0])) {
			index = stoi(quiz) - 1;
			cout << map[index] << endl;
		}
		else {
			cout << pkmon[quiz] << endl;
		}
	}

	return 0;
}

/* hash_map�� ���� ���� ����
visual stdio���� unordered_map�� ����� ��� ����.

Visual C++�� hash_map�� map���� �������� �ʰ� Ư�� hash_map�� ���� �ڷᱸ���� ����ϴ� �����̳ʷ� ����ũ�μ���Ʈ�翡�� ���� CAtlMap�� ���� �ӵ��� ���� ������.
������ �߿��� ���� hash_map�� ����Ѵٸ� VC++�� �ִ� ���� ������� ���� ��ü������ �� ������� hash �Լ��� ����ϰų�, C++ ���� �ҽ� ���̺귯���� boost�� �ִ� unordered_map�� ����ϴ� ���� ���� �� ����.
Windows �÷��������� ����Ѵٸ� CAtlMap�� ����ϴ� �͵� ����.

��ó: https://gamdekong.tistory.com/73 [not to be programmer. to be the one]
*/