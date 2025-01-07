#include "exam_politics.h"
#include "utility.h"
#include <fstream>
#include <iostream>
#include <random>
#include <unordered_map>
using namespace std;

// ���{�̐����̖����쐬����
QuestionList CreatePoliticsExam()
{
	// �������f�[�^
	struct PoliticsData
	{
		string genre;           // �W������
		string text;            // ��蕶
		vector<string> answers; // �󗓂ɓ��铚���̔z��
	};

	unordered_map<string, vector<PoliticsData>> data;

	{ // �������f�[�^��ǂݍ���
		constexpr char filename[] = "japanese_politics.txt";
		ifstream ifs(filename);
		if (!ifs) {
			cerr << "�G���[: " << filename << "��ǂݍ��߂܂���\n";
			return {};
			
		}
		
		while (true)
		{
		string s;
		getline(ifs, s);
		if (!ifs) 
		{
			break; // �t�@�C���I�[�ɒB�����̂ŏI��
		}
		const vector<string> v = Split(s, ',');
		const string & genre = v[0]; // �W���������擾
		data[genre].push_back({ genre, v[1], vector<string>(v.begin() + 2, v.end()) });
		}
	} // �������f�[�^��ǂݍ���

	constexpr int genreCount = 2; // �o�肷��W��������
	constexpr int quizCount = 5;  // �e�W�������̏o�萔
	QuestionList questions;
	questions.reserve(genreCount * quizCount);
	random_device rd;
	
	// �����_���ɑI�񂾂Q�̃W����������A�W���������Ń����_���ɑI�񂾂T����o�肷��
	const vector<int> genreIndices = CreateRandomIndices((int)data.size());
	for (int i = 0; i < genreCount; i++)
	{
		// �o�肷��W��������I��
		auto itr = data.begin();
		advance(itr, genreIndices[i]);   // �Q�ƈʒu���w�肵���Ƃ���܂Ői�߂�
		const auto & genre = itr->second; // �l(�W�������̃f�[�^�z��)�����o��

		// �W���������Ń����_���ɂT��I��
		const vector<int> questionIndices = CreateRandomIndices((int)genre.size());
		for (int j = 0; j < quizCount; j++) 
		{
			const auto & question = genre[questionIndices[j]]; // �I�񂾖��f�[�^

			// �󗓂̈ʒu�Ɛ��𒲂ׂ�
			// �󗓂́u�J���g���ʁv�Ɓu���g���ʁv�̃y�A�A�܂�{}�ŕ\�����
			vector<int> blanks; // �󗓂̈ʒu�̔z��
			for (int k = 0; k < question.text.size() - 1; k++) 
			{
				if (question.text[k] == '{' && question.text[k + 1] == '}') 
				{
					blanks.push_back(k);
				}
			}

			// �󗓂̂����P�������_���ɑI��
			const int index = uniform_int_distribution<>(0, (int)blanks.size() - 1)(rd);

			// ��蕶�̃R�s�[���쐬���A�I�΂�Ȃ������󗓂��u�����v�ɒu��������
			string s = "[" + question.genre + "] ���̕��͂�[ ? ]�ɓ���P��𓚂���\n";
			int from = 0; // �R�s�[���̐擪�ʒu
			for (int k = 0; k < blanks.size(); k++) 
			{
				const int end = blanks[k]; // �󗓂̈ʒu
				s.append(question.text, from, end - from); // �󗓂̎�O�܂ł͈̔͂��R�s�[
				
				if (k != index)
				{
					s += question.answers[k]; // �I�΂�Ȃ������󗓂̏ꍇ�͓������R�s�[
				}
				else 
				{
					s.append("[ ? ]"); // �I�΂ꂽ�󗓂̏ꍇ�́u�\���p�̋󗓕�����v���R�s�[
				}
				from = end + 2; // �R�s�[���̈ʒu���X�V
				
			}
			s.append(question.text, from); // ��蕶�̖����������R�s�[
			
			questions.push_back({ s, question.answers[index] });
		} // for j < quizCount
	} // for i < genreCount

	return questions;
}

