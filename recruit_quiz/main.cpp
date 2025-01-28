#include "question.h"
#include "exam_mathematics.h"
#include "exam_japanese.h"
#include "exam_english.h"
#include "exam_science.h"
#include "exam_geography.h"
#include "exam_politics.h"
#include "exam_economics.h"
#include "utility.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
	// ���ȃf�[�^�z��
	static const struct
	{
	  const char* name;        // ���Ȗ�
	  QuestionList(*create)(); // ���쐬�֐��̃A�h���X
	} 
	subjectData[] = 
	{
	  { "���w", CreateMathematicsExam },
	  { "����", CreateJapaneseExam },
	  { "�p��", CreateEnglishWordExam },
	  { "����", CreatePhysicsExam },
	  { "�n��", CreatePrefecturesExam },
	  { "����", CreatePoliticsExam },
	  { "�o��", CreateEconomicsExam },
	};

	vector<Question> questions(3);	

	cout << "[���N���[�g�΍�N�C�Y]\n";

	cout << "���Ȃ�I��ł�������\n";
	cout << "0=�����e�X�g\n";
	for (int i = 0; i < size(subjectData); i++)
	{
		cout << i + 1 << '=' << subjectData[i].name << '\n';
	}	

	vector<int> questionCounts(size(subjectData)); // �e���Ȃ̖�萔
	int subject;
	cin >> subject;
	if (subject == 1)
	{
		questions = CreateMathematicsExam();
	}
	else if (subject == 2) 
	{
		questions = CreateMathematicsExam();
	}
	else if (subject == 3)
	{
		questions = CreateEnglishWordExam();
		QuestionList phraseExam = CreateEnglishPhraseExam();
		questions.insert(questions.end(), phraseExam.begin(), phraseExam.end());
	}
	else if (subject == 4)
	{
		questions = CreatePhysicsExam();
	}
	else if (subject == 5)
	{
		questions = CreatePrefecturesExam();
	}
	else if (subject == 6) 
	{
		questions = CreatePoliticsExam();
	}
	else if (subject == 7) 
	{
		questions = CreateEconomicsExam();
	}
	if (subject > 0 && subject <= size(subjectData)) 
	{
		questions = subjectData[subject - 1].create();
	}
	else if (subject == 0)
	{
		// �����e�X�g
		questions.clear();
		for (int i = 0; i < size(subjectData); i++)
		{
			QuestionList tmp = subjectData[i].create();
			questions.insert(questions.end(), tmp.begin(), tmp.end());
			questionCounts[i] = (int)tmp.size();
		}
	}

	vector<int> correctCounts(size(subjectData));  // �e���Ȃ̐�����
	int currentSubjectNo = 0;     // �o�蒆�̋��Ȕԍ�
	int currentAnsweredCount = 0; // �񓚍ς݂̖�萔
	for (const auto& e : questions)
	{
		cout << e.q << "\n";
		string answer;
		cin >> answer;

		// ���͂��ꂽ������SJIS����ASCII�ɕϊ�����
		const string ascii = ConvertSjisNumberToAscii(answer);
		// �ϊ������������ꍇ��ASCII������ɒu��������
		if (!ascii.empty())
		{
			answer = ascii;
		}

		if (answer == e.a)
		{
			cout << "����!\n";
			correctCounts[currentSubjectNo]++; // �������𑝂₷
		}
		else if (e.b.empty())
		{
			// �������ЂƂ����̏ꍇ
			cout << "�ԈႢ!!������" << e.a << "\n";
		}
		else
		{
			// ��������������ꍇ�A�����ꂩ�ƈ�v����ΐ����Ƃ���
			bool isMatch = false;
			for (const auto& b : e.b)
			{
				if (answer == b)
				{
					isMatch = true; // ��v���铚������������
					break;
				}
			}
			// ��r���ʂ��o��
			if (isMatch)
			{
				cout << "�����I\n";
				correctCounts[currentSubjectNo]++; // �������𑝂₷
			}
			else
			{
				cout << "�ԈႢ�I�@������" << e.a << "(�܂���";
				for (auto& b : e.b)
				{
					cout << "�A" << b;
				}
				cout << ")\n";
			}
		} // if answer == e.a

		// �u�񓚍ςݖ�萔�v���u���Ȃ̖�萔�v�ȏ�ɂȂ�����A���̋��Ȃɐi��
		if (subject == 0) 
		{
			currentAnsweredCount++; // �񓚍ςݖ�萔�𑝂₷
			if (currentAnsweredCount >= questionCounts[currentSubjectNo])
			{
				currentSubjectNo++; // ���̋��Ȃɐi��
				currentAnsweredCount = 0; // �񓚍ςݖ�萔�����Z�b�g
			}
		} // if subject == 0
	}// forquestions

	// ���т�\��
	cout << "\n--- ���� ---\n";
	if (subject > 0 && subject <= size(subjectData)) 
	{
	  cout << subjectData[subject - 1].name << ": "
	    << correctCounts[0] << '/' << questions.size() << '\n';
	} 
	else if (subject == 0) 
	{
	  // ���Ȃ��Ƃ̐��т�\�����A�������̍��v���v�Z
	  size_t totalCorrectCount = 0; // �������̍��v
	  for (int i = 0; i < size(subjectData); i++)
	  {
	    cout << subjectData[i].name << ": "
	      << correctCounts[i] << '/' << questionCounts[i] << '\n';
	    totalCorrectCount += correctCounts[i];
	  }
	  cout << "���v: " << totalCorrectCount << '/' << questions.size() << '\n';
	}

	// ���т��t�@�C���ɏo�͂���
	static const char filename[] = "���N���[�g�΍􎎌����ѕ\.txt";
	ofstream ofs(filename, ios_base::app);
	if (!ofs)
	{
	  cerr << "�G���[: " << filename << "���J���܂���\n";
	} 
	else
	{
		// ���݂̎���(���萢�E��)���擾
		const time_t t = time(nullptr);
		
		// ���萢�E�������ԍ\���̌^�ɕϊ�
		tm examDate;
		localtime_s(&examDate, &t);
		
		// ���ԍ\���̂𕶎���ɕϊ�
		char strDate[100];
		strftime(strDate, size(strDate), "%Y/%m/%d(%a) %T", &examDate);

		if (subject > 0 && subject <= size(subjectData))
		{
			// ���ȃe�X�g�̏ꍇ�A�����������Ȃ̐��т������o�͂��A����ȊO�͋󗓂Ƃ���
			ofs << strDate;
			for (int i = 0; i < size(subjectData); i++)
			{
				ofs << ',';
				if (i == subject - 1)
				{
					ofs << correctCounts[0] << '/' << questions.size();
				}
			}
			ofs << '\n';
			cout << "���т�" << filename << "�ɏo�͂��܂���\n";
		}
		else if (subject == 0)
		{
			// �����e�X�g�̏ꍇ�A���ׂĂ̋��Ȃ̐��т��o�͂���
			ofs << strDate;
			for (int i = 0; i < size(subjectData); i++)
			{
				ofs << ',' << correctCounts[i] << '/' << questionCounts[i];
			}
			ofs << '\n';
			cout << "���т�" << filename << "�ɏo�͂��܂���\n";
		}
	} // if !ofs
}