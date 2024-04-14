//D跑步锻炼
//题目描述
//小蓝每天都锻炼身体。正常情况下，小蓝每天跑1千米。如果某天是周一或者月初（1日），为了激励自己，小蓝要跑2千米。如果同时是周一或月初，小蓝也是跑2千米。小蓝跑步已经坚持了很长时间，从2000年1月1日周六（含）到2020年10月1日周四（含）。请问这段时间小蓝总共跑步多少千米？
//分析分析：
//我们在这个题目这里，主要就是要分析他的出去条件，我是直接通过模拟日期一天天的增加，因为每天1km是常态，然后再去判断是不是周一呀（取余运算），是不是月初，这样再来+1km
#include <stdio.h> 

int sum = 0;

// 判断是否是闰年
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算每日跑步情况
void dailyRun(int& year, int& month, int& day, int& weekday) {
	day ++;
	sum ++; // 每天跑步一次
	weekday = (weekday + 1) % 7;
	
	if (weekday == 1) // 如果是周一，额外跑一次
		sum ++;
	
	// 判断月份天数
	if (month == 2) {
		if ((isLeapYear(year) && day > 29) || (!isLeapYear(year) && day > 28)) {
			day = 1;
			month ++;
		}
	} else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		day = 1;
		month ++;
	} else if (day > 31) {
		day = 1;
		month ++;
	}
	
	// 判断年份
	if (month > 12) {
		month = 1;
		year ++;
	}
}

int main() {
	int year = 2000, month = 1, day = 1, weekday = 6; // 初始为2000年1月1日是星期六
	
	while (!(year == 2020 && month == 10 && day == 1)) {
		dailyRun(year, month, day, weekday);
	}
	
	printf("%d", sum + 2); // 别忘了第一天的两公里 8664
	return 0;
}

