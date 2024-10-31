#include<bits/stdc++.h>

using namespace std;

// 全排列
// process1(): 得到从i位置往后的的全排列 开头位置 后续的每个数字 
// 都需来来一遍开头位置 得出每个数字在开头位置的可能的排列 当成黑盒
void process1(vector<string>& s, int i, vector<string>& res)
{
	if (i == s.size())
	{
		string path;
		for (string& str : s)
		{
			path += str;
		}
		res.push_back(path);
	}
	else
	{
		for (int j = i; j < s.size(); j++)
		{
			swap(s[i], s[j]);
			process1(s, i + 1, res);
			swap(s[i], s[j]);
		}
	}
}

bool compare(string&s1, string& s2)
{
	return s1 < s2;
}

// 暴力
string way1(vector<string>& s)
{
	vector<string> res;
	process1(s, 0, res);
	sort(res.begin(), res.end(), compare);
	return res[0];
}

// 排序
bool cmp(string& s1, string& s2)
{
	return s1 + s2 < s2 + s1;
}

string way2(vector<string>& s)
{
	sort(s.begin(), s.end(), cmp);
	string res;
	for (string& str : s)
	{
		res += str;
	}
	return res;
}

// 对数器
vector<string> getRandomStr(int maxLenOfString, int maxLenOfVecStr)
{
	vector<string> res;
	int len = rand() % maxLenOfVecStr + 1;
	for (int i = 0; i < len; i++)
	{
		int strLen = rand() % maxLenOfString + 1;
		string str;
		for (int j = 0; j < strLen; j++)
		{
			str += rand() % 10 + 'a';
		}
		res.push_back(str);
	}
	return res;
}

// 力扣 最大数 题解
bool cmpLargetsNumber(const string& s1, const string& s2)
{
	return s1 + s2 > s2 + s1;
}
string largestNumber(vector<int>& nums) {
    vector<string> numbers;
    for (int &num : nums)
    {
		// 数字转换成字符串
		numbers.push_back(to_string(num));
    }
    sort(numbers.begin(), numbers.end(), cmpLargetsNumber);
    if (numbers[0] == "0")
    {
        return "0";
    }
    string res;
    for (string& s : numbers)
    {
        res += s;
    }
    return res;
}

int main()
{
	int maxLenOfString = 5;
	int maxLenOfVecStr = 10;
	int times = 10;

	srand(time(0));
	
	for (int i = 0; i < times; i++)
	{
		vector<string> str = getRandomStr(maxLenOfString, maxLenOfVecStr);
		string ans1 = way1(str);
		string ans2 = way2(str);
		if (ans1 != ans2)
		{
			cout << "error" << endl;
			cout << "str1: " << ans1 << endl;
			cout << "str2: " << ans2 << endl;
			cout << endl;
		}
		else 
		{
			cout << "yes" << endl;
			cout << endl;
		}
	}
	
	return 0;

}







