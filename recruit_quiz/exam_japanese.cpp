#include "exam_japanese.h"
#include "utility.h"
#include <random>
using namespace std;

// �����̓ǂݎ����쐬����

QuestionList CreateKanjiExam()
{
	static const struct
	{
		const char* kanji;   // ����
		const char* reading; // �ǂ�
		const char* meaning; // �Ӗ�
	}data[] =
	{
		{"�s��", "������", "�l�������W�܂��ĕ�炷�Ƃ���A��"},
		{"���", "�Ȃ���", "(�����Ƌ���)��ӂ���������"},
		{"���E", "��������", "���������̌��ʁA�����Ȃ��Ȃ邱��"},
		{"�}��", "�͂�ꂢ", "�{��}�\�̏��߂ɁA�g������񑩎����ӏ������ɂ�������"},
		{"���", "�₭���傤", "�񑩂��Č��߂邱�ƁA�_��"},
		{"�K��", "�Ђ��傤", "�K�������Ȃ�ƌ��܂��Ă��邱��"},
		{"�m��", "����", "�������悭�������Ă����l�A�e�����F�l"},
		{"����", "��������", "�_�ЁA���@�̕~�n��"},
		{"�j�]", "�͂���", "���������܂������Ȃ��Ȃ邱��"},
		{"�S�D", "�����ł�", "�ЂƂ̍l������s���ɂ�����邱��"},
		{"�ᖡ", "�����", "������O����ɒ��ׂ邱��"},
		{"����", "�������܂��", "�h�ӂ������Ď󂯂�A�u�󂯂�v�A�u�����v�̌�����"},
		{"����", "����", "�ق�̏����̋󂫎���"},
		{"�M��", "���Ă�����", "��ł��ꂱ�ꂢ����A�D������Ɉ���"},
		{"�D�`", "����", "�H�ו����ς��Ƃ��ɏo��a�݂₦���݂̐����A�Ɠ��̌�"},
		{"����", "�������悢", "�v���؂肪�悢�A���ɔ����邱�Ƃ��Ȃ�"},
		{"�؊�", "���������", "���K���؂邱�ƁA�����m�̒����I�ȋ��K�݂̑��؂�"},
		{"�|��", "������", "���Ԃ������Ĉ�Ă邱��"},
		{"����", "�����ނ�", "����ꏊ�A�����֌������čs��"},
		{"���a", "�����؂�", "���N�łȂ���ԁA�a�C"},
		{"�V��", "���ɂ�", "��c��X�������������Ă���M�p�̂���X"},
	};

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	const vector<int> indices = CreateRandomIndices(size(data));
	random_device rd;

	// ���̎�ނ�I��
	int type = uniform_int_distribution<>(0, 1)(rd);
	if (type == 0)
	{
		// �����̓ǂ݂𓚂�����
		for (int i = 0; i < quizCount; i++)
		{
			const auto& e = data[indices[i]];
			questions.push_back({ "�u" + string(e.kanji) + "�v�̓ǂ݂��Ђ炪�Ȃœ�����", e.reading });
		}
	}
	else
	{
		// �������n��𓚂�����
		for (int i = 0; i < quizCount; i++)
		{
			// �Ԉ�����ԍ��������_���ɑI��
			const int correctIndex = indices[i];
			vector<int> answers = CreateWrongIndices(size(data), correctIndex);

			// �����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			const int correctNo = uniform_int_distribution<>(1, 3)(rd);
			answers[correctNo - 1] = correctIndex;

			// ��蕶���쐬
			string s = "�u" + string(data[correctIndex].meaning) +
				"�v���Ӗ�����n��̔ԍ���I��";
			for (int j = 0; j < 3; j++)
			{
				s += "\n  " + to_string(j + 1) + ":" + data[answers[j]].kanji;

			}

			questions.push_back({ s, to_string(correctNo) });

		}

	} // if type

	return questions;
}

// ���p��̈Ӗ��𓚂�������쐬����
QuestionList CreateIdiomExam()
{
	static const struct
	{
		const char* idiom;   // ���p��
		const char* meaning; // �Ӗ�
	} data[] =
	{
	{ "�C�̂����Ȃ�", "�C�Â���������Ȃ�" },
	{ "�Ր��ɐG���", "�S���犴������" },
	{ "������������", "���_���񕜂���" },
	{ "���������", "�؋��ƂȂ錾�t�𕷂��o��" },
	{ "�f(�ʂ�)�ɓB", "�����ڂ��Ȃ�" },
	{ "��K����ږ�", "��肭�ǂ��Č��ʂ��Ȃ�"},
	{ "�ӕ\����", "�\�z�O�Ȃ��Ƃ����ċ�������"},
	{ "�ւ�����𓾂Ȃ�", "�֎~���Ȃ��Ă͂Ȃ�Ȃ�"},
	{ "�Ղ̔��𓥂�", "�i��Ŋ댯�Ȃ��Ƃ�����"},
	{ "�ڂ���@�֔�����", "���̉�]�������čs�����f����"},
	{ "��͐l�̈�(����)�Ȃ炸", "�e�؂ȍs���́A�����ꎩ���̂��߂ɂȂ�"},
	{ "�؂ɉ�", "���C�������Ă���l(����)"},
	{ "���R�̐�", "�l�̎��s���A�����̍s���𐳂��Q�l�ɂ���"},
	{ "������(�̂�)����", "�]�T�̂Ȃ��n��������������"},
	{ "�g����q��", "���𓊂��o���o��œw�͂���"}
	};
	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	const vector<int> indices = CreateRandomIndices(size(data));
	random_device rd;

	for (int i = 0; i < quizCount; i++)
	{
		// �Ԉ�����ԍ��������_���ɑI��
		const int correctIndex = indices[i];
		vector<int> answers = CreateWrongIndices(size(data), correctIndex);

		// �����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
		const int correctNo = uniform_int_distribution<>(1, 3)(rd);
		answers[correctNo - 1] = correctIndex;

		// ��蕶���쐬
		string s = "�u" + string(data[correctIndex].idiom) + "�v�̈Ӗ��Ƃ��Đ������ԍ���I��";
		for (int j = 0; j < 3; j++)
		{
			s += "\n  " + to_string(j + 1) + ":" + data[answers[j]].meaning;

		}
		questions.push_back({ s, to_string(correctNo) });
	}
	return questions;
}