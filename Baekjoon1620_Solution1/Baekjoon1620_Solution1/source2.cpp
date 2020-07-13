#include<iostream>
#include<unordered_map>
//#include <time.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	//clock_t start, end; 
	//double result;
	//start = clock();
	int n, m, index;
	char name[21];
	char quiz[21];
	unordered_map<string, int> pkmon;
	unordered_map<int, string> pkmonum;

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {
		cin >> name;
		pkmonum[i] = name;
		pkmon[name] = i + 1;
	}

	for (int j = 0; j < m; j++) {
		cin >> quiz;
		if (quiz[0] >= '0' && quiz[0] <= '9') {
			index = atoi(quiz) - 1;
			cout << pkmonum[index] << '\n';
		}
		else {
			cout << pkmon[quiz] << '\n';
		}
	}

//	end = clock(); 
//	result = (double)(end - start);
//	cout << "result : " << result << " microseconds" << '\n';
	return 0;
}
