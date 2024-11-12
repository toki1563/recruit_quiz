#include "exam_science.h"
#include "utility.h"
#include <random>
using namespace std;

QuestionList CreatePhysicsExam()
{
	QuestionList questions;
	questions.reserve(10);
	random_device rd;

	{// ���������^��
		constexpr int divisors[] = { 1, 2, 3, 4, 5 ,6, 10, 12, 15, 20, 30, 60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i]; // ����
		int t = uniform_int_distribution<>(1, 10)(rd) * divisors[i]; // ����
		questions.push_back({
			"����" + to_string(v) + "km�ňړ�����Ԃ�����B\n���̎Ԃ�" + to_string(v * t / 60) +
			"km�ړ�����̂ɂ����鎞�Ԃ𕪒P�ʂŋ��߂�", to_string(t) });

		i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i]; // ����
		t = uniform_int_distribution<>(1, 10)(rd) * divisors[i]; // ����
		questions.push_back({
			"����Ԃ�" + to_string(v * t / 60) + "km���ꂽ�n�_�܂ňړ�����̂�" + to_string(t) +
			"�����������B\n���̎Ԃ̕��ώ��������߂�", to_string(v) });


			return questions;
	}
}