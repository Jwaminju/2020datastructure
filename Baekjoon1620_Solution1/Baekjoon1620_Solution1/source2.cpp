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

/* hash_map을 쓰지 않은 이유
visual stdio에서 unordered_map을 쓰라고 경고가 떴다.

Visual C++의 hash_map은 map보다 빠르지도 않고 특히 hash_map과 같은 자료구조를 사용하는 컨테이너로 마이크로소프트사에서 만든 CAtlMap에 비해 속도가 아주 느리다.
성능이 중요한 곳에 hash_map을 사용한다면 VC++에 있는 것을 사용하지 말고 자체적으로 잘 만들어진 hash 함수롤 사용하거나, C++ 오픈 소스 라이브러리인 boost에 있는 unordered_map을 사용하는 것이 좋을 것 같다.
Windows 플랫폼에서만 사용한다면 CAtlMap을 사용하는 것도 좋다.

출처: https://gamdekong.tistory.com/73 [not to be programmer. to be the one]
*/