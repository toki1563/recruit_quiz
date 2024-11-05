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