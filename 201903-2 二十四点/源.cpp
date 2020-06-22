#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	stack<int> a;
	stack<char>b;
	string s;
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9') {
				a.push(s[i] - '0');
			}
			else {
				if (s[i] == 'x' || s[i] == '/') {
					int t = a.top();
					a.pop();
					if (s[i] == 'x') {
						i++;
						t = t * (s[i] - '0');
					}
					if (s[i] == '/') {
						i++;
						t = t / (s[i] - '0');
					}
					a.push(t);
				}
				else {
					b.push(s[i]);
				}
			}
		}
		int sum = 0;
		while(b.empty()==0){
			char c = b.top();
			b.pop();
			int t = a.top();
			a.pop();
			if (c == '+')
				sum += t;
			if (c == '-')
				sum -= t;
		}
		sum += a.top();
		a.pop();
		if (sum == 24)
			cout << "Yes"<<endl;
		else
			cout << "No" << endl;
	}
}