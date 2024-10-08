#include <iostream>
using namespace std;

int main()
{
	cout << "[リクルート対策クイズ]\n";
	cout << "13×(-5)の答えは？\n";

	int answer;
	cin >> answer;

	if (answer == 13 * -5)
	{
		cout << "正解!正解は" << 13 * -5 << "\n";
	}
}