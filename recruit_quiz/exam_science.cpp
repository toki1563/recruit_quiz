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
		// 等速直線運動
		constexpr int divisors[] = { 1, 2, 3, 4, 5 ,6, 10, 12, 15, 20, 30, 60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i]; // 自足
		int t = uniform_int_distribution<>(1, 10)(rd) * divisors[i]; // 時間
		questions.push_back({
			"時速" + to_string(v) + "kmで移動する車がある。\nこの車が" + to_string(v * t / 60) +
			"km移動するのにかかる時間を分単位で求めよ", to_string(t) });

		i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);	  // 初速
		v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i]; // 加速度
		t = uniform_int_distribution<>(1, 10)(rd) * divisors[i];	  // 移動時間
		questions.push_back({
			"ある車が" + to_string(v * t / 60) + "km離れた地点まで移動するのに" + to_string(t) +
			"分かかった。\nこの車の平均時速を求めよ", to_string(v) });

		// 等加速度直線運動
		// 公式 : v = v0 + atを使って解く
		int v0 = uniform_int_distribution<>(5, 10)(rd);	  // 初速
		int a = uniform_int_distribution<>(1, 5)(rd) * 2; // 加速度
		int t = uniform_int_distribution<>(1, 20)(rd);	  // 移動時間
		questions.push_back({
			"秒速" + to_string(v0) + "mで移動していた車が、進行方向に大きさ" + to_string(a) +
			"m/sで等加速度直線運動を始めた。\n加速を始めてから" + to_string(t) + 
			"秒後までに移動した距離をm単位で求めよ。", to_string(v0 * t + a * t * t / 2) });

		// 公式 : v^2 - v0^2 = 2axを使って解く
		a = -uniform_int_distribution<>(1, 5)(rd) * 2; // 加速度
		t = uniform_int_distribution<>(1, 10)(rd);     // 移動時間
		v0 = -a * t; // 初速
		questions.push_back({
			"秒速" + to_string(v0) + "mで移動していた車がブレーキをかけたところ、" +
			to_string(v0 * t + a * t * t / 2) + "m進んで停止した。\n" +
			"ブレーキの加速度をm/s^2単位で求めよ。", to_string(a) });

			return questions;
	}
}