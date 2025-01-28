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
using namespace std;

int main()
{
	// 教科データ配列
	static const struct
	{
	  const char* name;        // 教科名
	  QuestionList(*create)(); // 問題作成関数のアドレス
	} 
	subjectData[] = 
	{
	  { "数学", CreateMathematicsExam },
	  { "国語", CreateJapaneseExam },
	  { "英語", CreateEnglishWordExam },
	  { "物理", CreatePhysicsExam },
	  { "地理", CreatePrefecturesExam },
	  { "政治", CreatePoliticsExam },
	  { "経済", CreateEconomicsExam },
	};

	vector<Question> questions(3);	

	cout << "[リクルート対策クイズ]\n";

	cout << "教科を選んでください\n";
	cout << "0=総合テスト\n";
	for (int i = 0; i < size(subjectData); i++)
	{
		cout << i + 1 << '=' << subjectData[i].name << '\n';
	}	
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
		// 総合テスト
		questions.clear();
		for (int i = 0; i < size(subjectData); i++)
		{
			QuestionList tmp = subjectData[i].create();
			questions.insert(questions.end(), tmp.begin(), tmp.end());
		}
	}

	for (const auto& e : questions)
	{
		cout << e.q << "\n";
		string answer;
		cin >> answer;

		// 入力された答えをSJISからASCIIに変換する
		const string ascii = ConvertSjisNumberToAscii(answer);
		// 変換が成功した場合はASCII文字列に置き換える
		if (!ascii.empty())
		{
			answer = ascii;
		}

		if (answer == e.a)
		{
			cout << "正解!\n";
		}
		else if (e.b.empty())
		{
			// 答えがひとつだけの場合
			cout << "間違い!!正解は" << e.a << "\n";
		}
		else
		{
			// 答えが複数ある場合、いずれかと一致すれば正解とする
			bool isMatch = false;
			for (const auto& b : e.b)
			{
				if (answer == b)
				{
					isMatch = true; // 一致する答えが見つかった
					break;
				}
			}
			// 比較結果を出力
			if (isMatch)
			{
				cout << "正解！\n";
			}
			else
			{
				cout << "間違い！　正解は" << e.a << "(または";
				for (auto& b : e.b)
				{
					cout << "、" << b;
				}
				cout << ")\n";
			}
		} // if answer == e.a
	}// forquestions
}