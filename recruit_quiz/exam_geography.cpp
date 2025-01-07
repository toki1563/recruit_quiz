#include "exam_geography.h"
#include "utility.h"
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

// �s���{���̖����쐬����
QuestionList CreatePrefecturesExam()
 {
	// �s���{���f�[�^
	struct PrefectureData
	 {
		string name;             // �s���{����
		string capital;          // �������ݒn
		vector<string> features; // ����
	};
	vector<PrefectureData> data;

	{ // �s���{���f�[�^��ǂݍ���
		constexpr char filename[] = "japanese_prefectures.txt";
		ifstream ifs(filename);
		if (!ifs) 
		{
			cerr << "�G���[: " << filename << "��ǂݍ��߂܂���\n";
			return {};
		}
		string s;
		while (true) 
		{
			getline(ifs, s); // 1�s�ǂݎ��
			if (!ifs) 
			{
				break; // �t�@�C���I�[�ɒB�����̂ŏI��
			}
			const vector<string> v = Split(s, ',');
			data.push_back({ v[0], v[1], vector<string>(v.begin() + 2, v.end()) });
		}
	} // �s���{���f�[�^��ǂݍ���

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	vector<int> indices = CreateRandomIndices((int)data.size());
	random_device rd;
	
	const int type = uniform_int_distribution<>(0, 2)(rd);
	switch (type) {
	case 0: // ��������s���{���𓚂���
		for (int i = 0; i < quizCount; i++) {
			// �����ȊO�̓����������_���ɑI��
			const int correctIndex = indices[i];
			vector<int> answers = CreateWrongIndices((int)data.size(), correctIndex);

			// �����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			const int correctNo = std::uniform_int_distribution<>(1, 3)(rd);
			answers[correctNo - 1] = correctIndex;

			// ��蕶���쐬
			string s = "�ȉ��̓��������s���{���̔ԍ���I��\n";

			// �s���{���̓����������_���ȏ��ԂŘA�����A��蕶�ɒǉ�
			const auto& features = data[correctIndex].features;
			vector<int> featureIndices = CreateRandomIndices((int)features.size());
			s += features[featureIndices[0]];
			for (int j = 1; j < features.size(); j++)
			{
				s += ", ";
				s += features[featureIndices[j]];
			}

			// �����ƂȂ�s���{�����蕶�ɒǉ�
			for (int j = 0; j < 3; j++)
			{
				s += "\n  " + to_string(j + 1) + ":" + data[answers[j]].name;
			}

			// ��蕶�Ɠ����̃y�A����z��ɒǉ�
			questions.push_back({ s, to_string(correctNo) });
		}
		break;

	case 1: // �s���{��������킷�����𓚂���
		for (int i = 0; i < quizCount; i++) {
			// �����ȊO�̓����������_���ɑI��
			const int correctIndex = indices[i];
			vector<int> answers = CreateWrongIndices((int)data.size(), correctIndex);

			// �����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			const int correctNo = std::uniform_int_distribution<>(1, 3)(rd);
			answers[correctNo - 1] = correctIndex;

			// ��蕶���쐬
			string s = "�u" + data[correctIndex].name + "�v�̓���������킷�ԍ���I��";
			for (int j = 0; j < 3; j++)
			{
				const auto& features = data[answers[j]].features;
				const int n = uniform_int_distribution<>(0, (int)features.size() - 1)(rd);
				s += "\n  " + to_string(j + 1) + ":" + features[n];
			}

			// ��蕶�Ɠ����̃y�A����z��ɒǉ�
			questions.push_back({ s, to_string(correctNo) });

		}
		break;

	case 2: // �s���{�����猧�����ݒn�𓚂���
	{
		// �s���{�����ƌ������ݒn���قȂ�s���{���̃��X�g�����
		vector<pair<string, string>> differentNames;
		for (const auto& e : data)
		{
			// �s���{�����ƌ������ݒn���̒������قȂ邩�A�����̂P�������������������񂪈قȂ�ꍇ�A
			// �u�s���{�����ƌ������ݒn���قȂ郊�X�g�v�ɒǉ�����
			if (e.name.size() != e.capital.size() || memcmp(e.name.data(), e.capital.data(), e.name.size() - 2) != 0)
			{
				differentNames.push_back({ e.name, e.capital });
			}
		}
		// �쐬�������X�g���烉���_���ɏo�肷��
		vector<int> indices = CreateRandomIndices((int)differentNames.size());
		for (int i = 0; i < quizCount; i++)
		{
			const int correctIndex = indices[i];
			questions.push_back({
			"�u" + differentNames[correctIndex].first + "�v�̌������ݒn�𓚂���",
			differentNames[correctIndex].second });
		}
		break;
	}
	} // switch (type)
	return questions;
}