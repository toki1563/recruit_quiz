#include "exam_science.h"
#include "utility.h"
#include <random>
using namespace std;

QuestionList CreatePhysicsExam()
{
	QuestionList questions;
	questions.reserve(10);
	random_device rd;

	{
		// ���������^��
		constexpr int divisors[] = { 1, 2, 3, 4, 5 ,6, 10, 12, 15, 20, 30, 60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i]; // ����
		int t = uniform_int_distribution<>(1, 10)(rd) * divisors[i]; // ����
		questions.push_back({
			"����" + to_string(v) + "km�ňړ�����Ԃ�����B\n���̎Ԃ�" + to_string(v * t / 60) +
			"km�ړ�����̂ɂ����鎞�Ԃ𕪒P�ʂŋ��߂�", to_string(t) });

		i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);	  // ����
		v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i]; // �����x
		t = uniform_int_distribution<>(1, 10)(rd) * divisors[i];	  // �ړ�����
		questions.push_back({
			"����Ԃ�" + to_string(v * t / 60) + "km���ꂽ�n�_�܂ňړ�����̂�" + to_string(t) +
			"�����������B\n���̎Ԃ̕��ώ��������߂�", to_string(v) });

		// �������x�����^��
		// ���� : v = v0 + at���g���ĉ���
		int v0 = uniform_int_distribution<>(5, 10)(rd);	  // ����
		int a = uniform_int_distribution<>(1, 5)(rd) * 2; // �����x
		t = uniform_int_distribution<>(1, 20)(rd);	  // �ړ�����
		questions.push_back({
			"�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��A�i�s�����ɑ傫��" + to_string(a) +
			"m/s�œ������x�����^�����n�߂��B\n�������n�߂Ă���" + to_string(t) +
			"�b��܂łɈړ�����������m�P�ʂŋ��߂�B", to_string(v0 * t + a * t * t / 2) });

		// ���� : v^2 - v0^2 = 2ax���g���ĉ���
		a = -uniform_int_distribution<>(1, 5)(rd) * 2; // �����x
		t = uniform_int_distribution<>(1, 10)(rd);     // �ړ�����
		v0 = -a * t; // ����
		questions.push_back({
			"�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��u���[�L���������Ƃ���A" +
			to_string(v0 * t + a * t * t / 2) + "m�i��Œ�~�����B\n" +
			"�u���[�L�̉����x��m/s^2�P�ʂŋ��߂�B", to_string(a) });
	}

	{
		// �d�͉����x
		int t = uniform_int_distribution<>(1, 10)(rd); // �ړ�����
		int x = 98 * t * t / 2; // 10�{���邱�ƂŁA�����_�ȉ���1�ʂ܂Ő����Ƃ��ĕ\��
		string answer = to_string(x / 10); // �������𕶎���
		if (x % 10)
		{
			// ������������ꍇ�͏������𕶎���
			answer += '_';
			answer += '0' + x % 10;
		}
		questions.push_back({
		"�d�͉����x��9.8m/s^2�Ƃ���B\n�\���ɍ����ʒu���畨�̂�Â��ɗ��Ƃ��ƁA���̂�" +
		to_string(t) + "�b�Ԃ�Xm��������B\n" + "X�̒l�������_�ȉ���1�ʂ܂ŋ��߂�(��C��R�͂Ȃ����̂Ƃ���)�B",
		answer });

		int v0 = uniform_int_distribution<>(1, 10)(rd); // ����
		t = uniform_int_distribution<>(1, 10)(rd);	    // �ړ�����
		int v = v0 * 10 - 98 * t; // ���x
		answer.clear();
		if (v < 0)
		{
			v = -v;
			answer = '-';
		}
		answer += to_string(v / 10);
		if (v % 10)
		{
			answer += '.';
			answer += '0' + v % 10;
		}
		questions.push_back({
		"�d�͉����x��9.8m/s^2�Ƃ���B\n����" + to_string(v0) +
		"m/s�ŕ��̂������œ��������A" + to_string(t) +
		"�b��̕��̂̑��x��Xm/s�ł���B\n" + "X�̒l�������_�ȉ���1�ʂ܂ŋ��߂�(��C��R�͂Ȃ����̂Ƃ���)�B",
			answer });
	}

	{ // ����
		int s = uniform_int_distribution<>(5, 20)(rd); // ��ʐ�
		int h = uniform_int_distribution<>(2, 10)(rd); // ����
		int v = s * h + 5; // �̐ς����߁A�l�̌ܓ��̂���5��������
		string answer = to_string(v / 100); // �������𕶎���ɕϊ�
		v /= 10;           // �����_�ȉ���2�ʂɓ����镔�����̂Ă�
		if (v % 10)// �����_�ȉ���1�ʂ�0�ȊO�Ȃ�A�������𕶎���ɉ�����
		{      
			answer += '.';
			answer += '0' + v % 10;
				
		}
		questions.push_back({
		"����100g�̕��̂ɂ͂��炭�d�͂�1N�Ƃ���B\n��ʐ�" + to_string(s) + "cm^2�A����" +
		to_string(h) + "cm�̉~�������S�ɐ����ɒ��߂��B\n" +
		"���̂Ƃ��A���̉~���ɓ������͂�X�j���[�g���ł���B\n" +
		"X�̒l�������_�ȉ���2�ʂ��l�̌ܓ����ċ��߂�B",
		answer });

		int x = uniform_int_distribution<>(20, 50)(rd) * 10;  // �d��(��)
		int y = uniform_int_distribution<>(x / 2, x - 1)(rd); // �d��(����)
		int z = x - y + 5;
		answer = to_string(z / 100);
		z /= 10;
		if (z % 10) 
		{
			answer += '.';
			answer += '0' + z % 10;
		}
		questions.push_back({
		"����100g�̕��̂ɂ͂��炭�d�͂�1N�Ƃ���B\n���镨�̂̏d�����΂˂͂���ł͂���ƁA" +
		to_string(x) + "g���������B\n" + "���̕��̂����S�ɐ��ɓ��ꂽ�Ƃ���A�΂˂͂����" +
		to_string(y) + "g���������B\n���̂Ƃ��A���̂ɂ͂��炭���͂�X�j���[�g���ł���B\n" +
		"X�̒l�������_�ȉ���2�ʂ��l�̌ܓ����ċ��߂�B",
		answer });

		int p0 = uniform_int_distribution<>(1, 9)(rd) * 100; // ���x
		s = uniform_int_distribution<>(5, 10)(rd);           // ��ʐ�
		h = uniform_int_distribution<>(5, 10)(rd);           // ����
		z = h * p0 + 50;
		answer = to_string(z / 1000);
		z /= 100;
		if (z % 10) 
		{
			answer += '.';
			answer += '0' + z % 10;
		}
		questions.push_back({
		"���x" + to_string(p0) + "kg/m^3�A��ʐ�" + to_string(s) + "cm^2�A����" +
		to_string(h) + "cm�̕��̂𐅂ɒ��߂悤�Ƃ����Ƃ���AXcm����ŐÎ~�����B\n" +
		"X�̒l�������_�ȉ���1�ʂ܂ŋ��߂�B",
		answer });
	} // ����


	{ // �΂�
		int a = uniform_int_distribution<>(10, 30)(rd);    // ���R��(cm)
		int x = uniform_int_distribution<>(1, a / 2)(rd);  // ���R������̕ω���(cm)
		int m = uniform_int_distribution<>(1, 20)(rd) * 10;// ����(g)
		int k = 100 * m / x + 5;            // k��100�{�����߁A�l�̌ܓ��̂���5�𑫂�
		string answer = to_string(k / 100); // �������𕶎���ɕϊ�
		k /= 10;      // �����_�ȉ���2�ʂɓ����镔�����̂Ă�
		if (k % 10) { // �����_�ȉ���1�ʂ�0�ȊO�Ȃ�A�������𕶎���ɉ�����
		answer += '.';
		answer += '0' + k % 10;
		
		questions.push_back({
		"�d�͉����x��10m/s^2�Ƃ���B\n����" + to_string(x) + "cm�̂΂˂̐�[��" +
		to_string(m) + "g�̏d������āA�V�䂩��݂艺�����B\n����ƁA�΂˂̒�����" +
		to_string(a + x) + "cm�ɂȂ����B\n" +
		"���̂΂˂́u�΂˒萔�v�������_�ȉ���Q�ʂ��l�̌ܓ����ċ��߂�B",
		answer });

		int k1 = uniform_int_distribution<>(1, 10)(rd); // �΂˒萔1(N/m)
		int k2 = uniform_int_distribution<>(1, 9)(rd);  // �΂˒萔2(N/m)
		if (k2 >= k1) 
		{
			k2++;
		}
		m = uniform_int_distribution<>(1, 10)(rd) * 10; // ����(g)
		x = 100 * m * (k1 + k2) / (k1 * k2) + 5;
		answer = to_string(x / 100);
		x /= 10;
		if (x % 10) 
		{
			answer += '.';
			answer += '0' + x % 10;
		}
		questions.push_back({
		"�d�͉����x��10m/s^2�Ƃ���B\n�΂˒萔��" + to_string(k1) + "��" + to_string(k2) +
		"��2�̂΂˂𒼗�ɂȂ��A" + to_string(m) + "g�̏d������ēV�䂩��݂艺�����B\n" +
		"����ƁA�΂˂̒��������킹��Xcm�L�тĐÎ~�����B\n" +
		"X�̒l�������_�ȉ���Q�ʂ��l�̌ܓ����ċ��߂�B",
		answer });

		k1 = uniform_int_distribution<>(1, 10)(rd); // �΂˒萔1(N/m)
		k2 = uniform_int_distribution<>(1, 10)(rd); // �΂˒萔2(N/m)
		m = uniform_int_distribution<>(1, 10)(rd) * 10; // ����(g)
		x = 100 * m / (k1 + k2) + 5;
		answer = to_string(x / 100);
		x /= 10;
		if (x % 10)
		{
			answer += '.';
			answer += '0' + x % 10;
		}
		questions.push_back({
		"�d�͉����x��10m/s^2�Ƃ���B\n�΂˒萔��" + to_string(k1) + "��" + to_string(k2) +
		"�̂Q�{�̂΂˂𐅕��ȓV��ɌŒ肵�A�΂˂̉��[�ɖ؂̖_�𐅕��Ɏ��t�����B\n" +
		"���̖_�̒����Ɏ���" + to_string(m) + "g�̏d���݂艺�����B\n" +
		"����ƁA�΂˂̒��������ꂼ��Xm�����L�тĐÎ~�����B\n" +
		"X�̒l�������_�ȉ���Q�ʂ��l�̌ܓ����ċ��߂�B",
		answer });
	} // �΂�

	{ // �U��q
		int l = uniform_int_distribution<>(1, 10)(rd); // ����(m)�̕�����
		int m = uniform_int_distribution<>(1, 10)(rd); // ����(g)
		questions.push_back({
		"����" + to_string(l * l) + "m�̎��Ɏ���" + to_string(m) +
		"kg�̏d������A�킸���ɗh�炵���Ƃ���A������X�b�ł������BX�̒l�����߂�B\n" +
		"�Ȃ��A�d�͉����xg�Ɖ~�����΂ɂ��āA�� = ��g�����藧���̂Ƃ���B",
		to_string(2 * l) });

		l = uniform_int_distribution<>(1, 10)(rd); // ����(m)
		m = uniform_int_distribution<>(1, 10)(rd); // ����(kg)
		int max_v = (int)sqrt(20 * l); // ���x�̏��(2gh=v^2�������Ƃ���)
		int v = uniform_int_distribution<>(1, max_v)(rd); // ���x
		questions.push_back({
		"�d�͉����x��10m/s^2�Ƃ���B\n����" + to_string(l) + "m�̎��Ɏ���" + to_string(m) +
		"kg�̂�����������U��q������B\n���̂�������ŉ��_���獂��" +
		to_string(v * v * 100 / 20) + "cm�̈ʒu�ŐÂ��ɕ������B\n" +
		"���̂Ƃ��A�����肪�ŉ��_��ʉ߂���Ƃ��̑��x��m/s�P�ʂŋ��߂�B",
		to_string(v) });
	} // �U��q

		return questions;
}