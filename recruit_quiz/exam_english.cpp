#include "exam_english.h"
#include "utility.h"
#include <random>
 using namespace std;

 // �p��̖��
 QuestionList CreateEnglishWordExam()
 {
	 const struct {
		 const char* word; // �p�P��
		 const char* reading; // �ǂ�
		 const char* meaning; // �Ӗ�

	 } data[] = {
 { "state", "�X�e�[�g", "���" },
 { "business", "�r�W�l�X", "���ƁA�d��" },
 { "abstract", "�A�u�X�g���N�g", "���ۓI��" },
 { "concrete", "�R���N���[�g", "��̓I��" },
 { "digital", "�f�W�^��", "�����ŏ���`����" },
 { "analogue", "�A�i���O", "�ގ����Ă���A�ގ���" },
 { "exchange", "�G�N�X�`�F���W", "�����A���ցA�ב�" },
 { "infrastructure", "�C���t���X�g���N�`��", "�����\���A��ՂƂȂ�{�݂�ݔ�" },
 { "knowledge", "�i���b�W", "�m��" },
 { "credit", "�N���W�b�g", "�M�p" },
 { "routine", "���[�e�B��", "����" },
 { "management", "�}�l�W�����g", "�o�c" },
 { "account", "�A�J�E���g", "����" },
 { "unique", "���j�[�N", "���I��" },
 { "variety", "�o���G�e�B", "���l��" },
 { "schedule", "�X�P�W���[��", "�\��" },
 { "agenda", "�A�W�F���_", "�ۑ�" },
 { "technology", "�e�N�m���W�[", "�Ȋw�Z�p" },
 { "collaboration", "�R���{���[�V����", "����" },
 { "tax", "�^�b�N�X", "�ŋ�" },
 { "stock", "�X�g�b�N", "�݌�" },
 { "product", "�v���_�N�g", "���i" },
 { "booking", "�u�b�L���O", "�\��" },
 { "weight", "�E�F�C�g", "�d��" },
 { "comliance", "�R���v���C�A���X", "�@��" },
 { "receipt", "���V�[�g", "�̎���" },

	 };

	 constexpr int quizCount = 5;
	 QuestionList questions;
	 questions.reserve(quizCount);
	 const vector<int> indices = CreateRandomIndices(size(data));
	 random_device rd;

	 // ���̎�ނ������_���ɑI��
	 const int type = uniform_int_distribution<>(0, 3)(rd);
	 switch (type)
	 {
	 case 0: // �Ӗ�����p�P��𓚂���
		 for (int i = 0; i < quizCount; i++) 
		 {
			 const auto& e = data[indices[i]];
			 questions.push_back(
				 { "�u" + string(e.meaning) + "�v���Ӗ�����p�P��𓚂���",
				 e.word });
			 break;
		 }
		 break;
	 case 1: // �u�ǂ݁v����p�P��𓚂���
		 for (int i = 0; i < quizCount; i++) 
		 {
			 const auto & e = data[indices[i]];
			 questions.push_back({
			 "�J�^�J�i�̓ǂ݁u" + string(e.reading) + "�v�ɑΉ�����p�P��𓚂���",
			 e.word });
			 
		 }
		 break;
	 case 2: // �p�P�ꂩ��u�ǂ݁v�𓚂���
		 for (int i = 0; i < quizCount; i++) 
		 {
			 const auto & e = data[indices[i]];
			 questions.push_back({
			 string(e.word) + "�̓ǂ݂��J�^�J�i�œ�����",
			 e.reading });
			 
		 }
		 break;
	 case 3: // �p�P��̈Ӗ��𓚂���
		 for (int i = 0; i < quizCount; i++)
		 {
			 // �Ԉ�����ԍ��������_���ɑI��
			 const int correctIndex = indices[i];
			 vector<int> answers = CreateWrongIndices(size(data), correctIndex);

			 // �����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			 const int correctNo = std::uniform_int_distribution<>(1, 3)(rd);
			 answers[correctNo - 1] = correctIndex;

			 // ��蕶���쐬
			 string s = "�u" + string(data[correctIndex].word) + "�v�̈Ӗ��Ƃ��Đ������ԍ���I��\n";
			 s += std::string("  1:") + data[answers[0]].meaning + "\n";
			 s += std::string("  2:") + data[answers[1]].meaning + "\n";
			 s += std::string("  3:") + data[answers[2]].meaning;

			 questions.push_back({ s, to_string(correctNo) });

		 }
		 break;
	 } // switch(type)

	 return questions;
 }

 // �p��̒�^���̖����쐬����
 QuestionList CreateEnglishPhraseExam()
 {
	 const struct {
		 const char* phrase;      // ��^���̌`
		 const char* meaning;     // ��^���̈Ӗ�
		 const char* example;     // �p��̗ᕶ
		 const char* translation; // �ᕶ�̓��{���
		 int blankCount;          // ���̌��̐�
		 int blankOptions[3];     // ���̌��ɂȂ�P��̈ʒu

	 } data[] =
	 {
		 { "too [A] to [B]", "�ƂĂ�[A]�Ȃ̂�[B]�ł��Ȃ�",
		 "The tea was too hot to drink.", "�������M�����Ĉ��߂Ȃ������B",
		 2, { 3, 5 }},
		 { "be looking forward to [A]", "[A]���y���݂ɂ���",
		 "I'm looking forward to seening you", "���Ȃ��ɉ�̂��y���݂ɂ��Ă��܂��B",
		 3, { 1, 2, 3 }},
		 { "according to [A]", "[A]�ɂ���",
		 "Acoording to the weather forcast, today is rain.", "�V�C�\��ɂ��ƁA�����͉J���B",
		 2, { 0, 1 }},
		 { "as soon as [A]", "[A]����Ƃ�����",
		 "As soon as I arrive, I will call you.", "���������炷���ɓd�b���܂��B",
		 3, { 0, 1, 2 }},
		 { "be not supposed to [A]", "[A]���Ă͂����Ȃ����ƂɂȂ��Ă���",
		 "You are not supposed to enter this room.", "���̕����ɓ����Ă͂����܂���B",
		 3, { 2, 3, 4 }},
	 };

	 constexpr int quizCount = 5;
	 QuestionList questions;
	 questions.reserve(quizCount);
	 const vector<int> indices = CreateRandomIndices(size(data));
	 random_device rd;
	 
	 // ���̎�ނ������_���ɑI��
	 int type = uniform_int_distribution<>(0, 2)(rd);
	 switch (type) {
	 case 0: // �󗓂ɂ͂���P��𓚂���
		 for (int i = 0; i < quizCount; i++) {
			 const auto& e = data[indices[i]];

			 // �ᕶ��P��ɕ���
			 vector<string> words;
			 const char* start = e.example;
			 for (const char* p = e.example; *p; p++) 
			 {
				 if (*p == ' ') 
				 {
					 words.push_back(string(start, p));
					 start = p + 1;
				 }
			 }
			 words.push_back(string(start));

			 // ���ɂ���P��̈ʒu��I��
			 int n = uniform_int_distribution<>(0, e.blankCount - 1)(rd);
			 int blankIndex = e.blankOptions[n];

			 // ���ɂ���ʒu�̒P��𓚂��Ƃ���
			 string a = words[blankIndex];

			 // ���ɂ���ʒu�̒P����u�󗓁v�ɒu��������
			 +words[blankIndex] = "[ ? ]";

			 // �P��𕶂ɕ���
			 string s = words[0];
			 for (int j = 1; j < words.size(); j++)
			 {
				 s += " " + words[j];

			 }

			 // ��蕶�Ɠ�����ǉ�
			 questions.push_back({
			 "[ ? ]�ɓK�؂Ȍ�����ĉp��������������\n" + string(e.translation) + "\n" + s,
			 a });

		 }
		 break;
		 
	 case 1: // ��^���̈Ӗ��𓚂���
		 for (int i = 0; i < quizCount; i++)
		 {
			 // �Ԉ�����ԍ��������_���ɑI��
			 const int correctIndex = indices[i];
			 vector<int> answers = CreateWrongIndices(size(data), correctIndex);

			 // �����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			 const int correctNo = std::uniform_int_distribution<>(1, 3)(rd);
			 answers[correctNo - 1] = correctIndex;

			 // ��蕶���쐬
			 string s = "�u" + string(data[correctIndex].phrase) + "�v�̈Ӗ��Ƃ��Đ������ԍ���I��\n";
			 s += std::string("  1:") + data[answers[0]].meaning + "\n";
			 s += std::string("  2:") + data[answers[1]].meaning + "\n";
			 s += std::string("  3:") + data[answers[2]].meaning;

			 questions.push_back({ s, to_string(correctNo) });
		 }
		 break;
		 
	 case 2: // �Ӗ��̍�����^���𓚂���
		 for (int i = 0; i < quizCount; i++)
		 {
			 // �Ԉ�����ԍ��������_���ɑI��
			 const int correctIndex = indices[i];
			 vector<int> answers = CreateWrongIndices(size(data), correctIndex);
			 
			 // �����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			 const int correctNo = std::uniform_int_distribution<>(1, 3)(rd);
			 answers[correctNo - 1] = correctIndex;
			 
			 // ��蕶���쐬
			 string s = "�u" + string(data[correctIndex].meaning) + "�v�ɑΉ������^����I��\n";
			 s += std::string("  1:") + data[answers[0]].phrase + "\n";
			 s += std::string("  2:") + data[answers[1]].phrase + "\n";
			 s += std::string("  3:") + data[answers[2]].phrase;
			 
			 questions.push_back({ s, to_string(correctNo) });
		 }
		 break;
		 
	 } // switch (type)
	 
	return questions;
 }