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

// �����ǂ݂ňӖ��̈قȂ銴���̖����쐬����
QuestionList CreateHomophoneExam()
{
	const struct
	{
		const char* reading;   // �ǂ�		
		struct
		{
			const char* kanji;   // ����			
			const char* meaning; // �Ӗ�			
		} words[3];
	}
	data[] = {
	{ "����", {
	{ "����", "�������s���Ƃ��A���ԁB" },
	{ "���@" , "�������s���̂ɂ悢�@��" }}},
	{ "��������", {
	{ "�z��", "���ۂɂ͌o�����Ă��Ȃ��������v���`������" },
	{ "�n��", "�V�������̂����グ�邱��" }}},
	{ "�ق��傤", {
	{ "�ۏ�", "�ԈႢ���Ȃ��m���ł���Ɩ񑩂��邱��" },
	{ "�ۏ�", "������n�ʂȂǂ��ێ������悤�ɕی삵��邱��" },
	{ "�⏞", "�����������Ȃ��Ă��Ȃ�����" }}},
	{ "�������傤", {
	{ "�Ώ�", "�s�ׂ̖ڕW�ƂȂ����" },
	{ "�Ώ�", "�Q�̐}�`�╨�����݂��ɂ荇���Ă��邱��" },
	{ "�Ώ�", "����ׂ邱�ƁA�Ⴂ���ۗ�����" }}},
	{ "����܂�", {
	{ "�ӂ�", "���s�ɂ��ċ��������߂�" },
	{ "���", "�Ԉ�������f������" }}},
	{ "�����߂�", {
	{ "�[�߂�", "���╨��n���ׂ��Ƃ���ɓn��" },
	{ "���߂�", "����Ă��镨���𗎂������ĉ��₩�ȏ�Ԃɂ���" },
	{ "�C�߂�", "�s����l�i�𐳂�������A�w���Z�|�Ȃǂ��w��Őg�ɂ���" }}},
	{ "���傤����",{
	{ "�Љ�", "���m�̐l��W�c���������킹�邱��" },
	{ "�Ɖ�", "�₢���킹�Ċm���߂邱��" }}},
	{ "�����傤",{
	{ "�ُ�", "���i�ƈقȂ�悤��" },
	{ "�ُ�", "�p��`���قȂ�悤��" }}},
	{ "���傤����",{
	{ "���s", "�������ƕ������Ă��Ė����ɕ������s������" },
	{ "���d", "�����̗����咣�������ԓx�ŉ����ʂ����Ƃ��邱��" }}},
	{ "��������",{
	{ "����", "�����̖{���̎p��`" },
	{ "����", "�����̖{���̏��" }}},
	{ "���傤��",{
	{ "����", "�����͂␨���ɂ���ċ��ꂳ���邱��" },
	{ "����", "�����قǑf���炵�����̂���" }}},
	{ "��������",{
	{ "��S", "���҂ǂ���ɕ������^��Ŗ������邱��" },
	{ "���S", "�����l����s���𔽏Ȃ��A�ǂ��S�ɉ��߂邱��" }}},
	{ "���߂�",{
	{ "��߂�", "�ꏊ�A�ʒu�A�n�ʂȂǂ������̂��̂ɂ���" },
	{ "���߂�", "����������������Ђ˂����肵�āA�ɂ݂̂Ȃ��悤�ɂ���" },
	{ "�߂�", "���𓮂����Ă����Ԃ��ӂ���" }}},
	{ "����",{
	{ "�ނ�", "������h�����d����" },
	{ "�T��", "����܂����N�����Ȃ��悤�T���߂ɍs������" }}},
	};

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	const vector<int> indices = CreateRandomIndices(size(data));
	random_device rd;

	const int type = uniform_int_distribution<>(0, 1)(rd);
	for (int i = 0; i < quizCount; i++)
	{
		const auto& e = data[indices[i]];

		// �v�f�����v�Z
		int count = 0;
		for (; count < size(e.words); count++)
		{
			if (!e.words[count].kanji)
			{
				break;
			}
		}

		// �������ԍ���I��
		const int correctNo = uniform_int_distribution<>(1, count)(rd);

		// ��蕶���쐬
		const vector<int> answers = CreateRandomIndices(count);
		string s = "�u" + string(e.words[answers[correctNo - 1]].kanji) + "�v�̈Ӗ��Ƃ��Đ������ԍ���I��";
		for (int j = 0; j < count; j++)
		{
			s += "\n  " + to_string(j + 1) + ":" + e.words[answers[j]].meaning;

		}
		questions.push_back({ s, to_string(correctNo) });

		return questions;
	}
}

// �΋`��̖����쐬����
QuestionList CreateAntonymExam()
{
	const struct 
	{
		const char* kanji[2];
	}
	data[] =
	{
		{ "�Ӑ}(����)", "����(����)" }, { "���v(����悤)", "����(���傤���イ)" },
		{ "�̈�(����)", "�ߎ�(������)" }, { "�B��(�����܂�)", "����(�߂���傤)" },
		{ "�ْ�(���񂿂傤)", "�o��(������)" }, { "�ߑa(����)", "�ߖ�(���݂�)" },
		{ "�h�](�����Ă�)", "���J(������)" }, { "����(���傤��)", "���Y(��������)" },
		{ "�ْ[(������)", "����(�����Ƃ�)" }, { "���h(���񂯂�)", "�y��(�����ׂ�)" },
		{ "�x��(��������)", "���f(�䂾��)" }, { "�A�[(���̂�)", "���(���񂦂�)" },
		{ "�͊�(������)", "����(����񂽂�)" }, { "����(���񂻂�)", "����(�������)" },
		{ "�܎^(���傤����)", "�l�|(�΂Ƃ�)" }, { "����(���イ����)", "���[(�܂�����)" },
		{ "��^(��������)", "���](�����Ђ傤)" }, { "�n��(��������)	", "�͕�(���ق�)" },
		{ "�ߌ�(������)", "����(���񂯂�)" }, { "���f(������)", "�ؔ�(����)" },
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
		const int correctNo = uniform_int_distribution<>(1, 4)(rd);
		answers[correctNo - 1] = correctIndex;

		// ��蕶���쐬
		const int object = uniform_int_distribution<>(0, 1)(rd);
		const int other = (object + 1) % 2;
		string s = "�u" + string(data[correctIndex].kanji[object]) +
			"�v�̑΋`��Ƃ��Đ������ԍ���I��";
		for (int j = 0; j < 4; j++)
		{
			s += "\n  " + to_string(j + 1) + ":" + data[answers[j]].kanji[other];

		}
		questions.push_back({ s, to_string(correctNo) });

	}
	return questions;
}

// �ދ`��̖����쐬����

QuestionList CreateSynonymExam()
{
	const struct
	{
		int count;            // �v�f��
		const char* kanji[4]; // �ދ`��̔z��
	} 
	data[] = 
	{
		{ 2, "����(���イ����)", "����(��������)" },
		{ 3, "���(�悤����)", "���(�悤����)", "����(��������)" },
		{ 3, "����(�������傤)", "�܏�(�������傤)", "���c(���傤��)" },
		{ 3, "���Q(�΂���)", "���o(���������)", "�o�F(��������傭)" },
		{ 4, "�n�m(���キ��)", "�ʋ�(�����傤)", "�m��(������)", "����(������)" },
		{ 2, "���v(���񂩂�)", "�ϑJ(�ւ񂹂�)" },
		{ 2, "����(������)", "���(�Ђ߂�)" },
		{ 2, "�ˋ�(������)", "���\(���傱��)" },
		{ 2, "�@�q(���т�)", "�v��(���񂻂�)" },
		{ 3, "�ύ�(������)", "�ڍ�(���傤����)", "�q��(������)" },
		{ 3, "���J(�Ă��˂�)	)", "����(���񂬂�)", "���d(�Ă����傤)" },
		{ 3, "��^(����)", "�v��(��������)", "�s��(�����傭)" },
		{ 3, "�뜜(����)", "���O(���˂�)", "�J��(�䂤���)" },
		{ 3, "�h��(�����ӂ�)	", "���S(���񂵂�)", "����(����߂�)" },
		{ 3, "����(����)", "�Ŏ�(������)", "�n��(�ڂ�����)" },


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
		const int correctNo = std::uniform_int_distribution<>(1, 4)(rd);
		answers[correctNo - 1] = correctIndex;

		// �o�肷��ދ`���I��
		const auto& e = data[indices[i]];
		const int object = std::uniform_int_distribution<>(0, e.count - 1)(rd);

		// ��蕶���쐬
		string s = "�u" + string(data[correctIndex].kanji[object]) +
			"�v�̗ދ`��Ƃ��Đ������ԍ���I��";
		for (int j = 0; j < 4; j++)
		{
			if (j == correctIndex)
			{
				// �o�肷���u�ȊO�v�̗ދ`��𐳉��Ƃ��đI��
				int other = std::uniform_int_distribution<>(0, e.count - 2)(rd);
				if (other >= object)
				{
					other++;
				}
				s += "\n  " + to_string(j + 1) + ":" + e.kanji[other];
			}
			else
			{
				// �듚��I��
				const auto& f = data[answers[j]];
				const  int k = std::uniform_int_distribution<>(0, f.count - 1)(rd);
				s += "\n  " + to_string(j + 1) + ":" + f.kanji[k];
			}
		}
		questions.push_back({ s, to_string(correctNo) });
	}
	return questions;
}