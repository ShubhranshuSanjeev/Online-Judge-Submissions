#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	string S;
	cin >> t;
	while(t > 0)
	{
		cin >> S;
		int count = 0;
		for(int i = 0; i < S.size(); i++)
			if(S[i] == '1') count+=1;
		if(count%2 == 0) cout << "LOSE" << endl;
		else cout << "WIN" << endl;
		t--;
	}
	return 0;
}

