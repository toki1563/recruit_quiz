#include <iostream>
#include <string>
#include <random>
using namespace std;

// ��蕶�Ɠ������܂Ƃ߂�\����
struct Question
{
	string q; // ��蕶
	int a; // ����
};


int main()
{
	Question questions[3];

	random_device rd;
	mt19937 rand(rd());

	// �|���Z
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	questions[0].q = to_string(x) + "�~" + to_string(y);
	questions[0].a = x * y;

	// ����Z
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	questions[1].q = to_string(x) + "��" + to_string(y);
	questions[1].a = x / y;

	// ���G�Ȏ�
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	questions[2].q =
		to_string(x) + "-(" + to_string(y) + "+" + to_string(z) + ")��" + to_string(w);
	questions[2].a = x - (y + z) / w;

	cout << "[���N���[�g�΍�N�C�Y]\n";

	for (const auto& e : questions)
	{
		cout << e.q << "�̓����́H\n";
		int answer;
		cin >> answer;
		if(answer == e.a)
		{
			cout << "����!\n";
		}
		else
		{
			cout << "�ԈႢ!!������" << e.a << "\n";
		}
	}// forquestions
}