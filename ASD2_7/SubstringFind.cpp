#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<size_t> getPosOfSubstrings(const string& text, const string& toSearch) {
	string str = toSearch + "#" + text;
	for (auto& c : str)
		c = tolower(c);
	//clog << toSearch.length() << '\n';
	vector<size_t> pi(str.size());
	for (int i = 1; i < pi.size(); i++) {
		int j = pi[i - 1];
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			j++;
		pi[i] = j;
	}
	vector<size_t> res;
	for (int i = 0; i < pi.size(); i++) {
		if (pi[i] == toSearch.size())
			res.push_back(i - 2 * toSearch.size());
	}
	return res;
}