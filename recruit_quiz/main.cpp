#include <iostream>
#include <string>
#include <random>
using namespace std;

// –â‘è•¶‚Æ“š‚¦‚ğ‚Ü‚Æ‚ß‚é\‘¢‘Ì
struct Question
{
	string q; // –â‘è•¶
	int a; // “š‚¦
};


int main()
{
	Question questions[3];

	random_device rd;
	mt19937 rand(rd());

	// Š|‚¯Z
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	questions[0].q = to_string(x) + "~" + to_string(y);
	questions[0].a = x * y;

	// Š„‚èZ
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	questions[1].q = to_string(x) + "€" + to_string(y);
	questions[1].a = x / y;

	// •¡G‚È®
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	questions[2].q =
		to_string(x) + "-(" + to_string(y) + "+" + to_string(z) + ")€" + to_string(w);
	questions[2].a = x - (y + z) / w;

	cout << "[ƒŠƒNƒ‹[ƒg‘ÎôƒNƒCƒY]\n";

	for (const auto& e : questions)
	{
		cout << e.q << "‚Ì“š‚¦‚ÍH\n";
		int answer;
		cin >> answer;
		if(answer == e.a)
		{
			cout << "³‰ğ!\n";
		}
		else
		{
			cout << "ŠÔˆá‚¢!!³‰ğ‚Í" << e.a << "\n";
		}
	}// forquestions
}