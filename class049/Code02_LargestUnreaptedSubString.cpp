#include<bits/stdc++.h>

using namespace std;

class solution 
{
public:

    // 最长无重复字符字串的长度
    int maxLength(string& s)
    {
        int left = 0, right = 0, n = s.size(), ans = 0;
        // map 记录字符出现的位置
        unordered_map<char, int> isExisted;
        while (right < n)
        {
            if (isExisted.count(s[right]))
            {
                left = max(left, isExisted[s[right]] + 1);
            }
            ans = max(ans, right - left + 1);
            isExisted[s[right]] = right;
            right++;
        }
        return ans;
    }
};

int main()
{	
	string s = "abbcdnea";
	solution solve;
	int res = solve.maxLength(s);
	cout << res << endl;
	return 0;
}
