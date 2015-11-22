/*
 * strategy.h
 *
 *  Created on: Nov 10, 2015
 *      Author: konstantin
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <iostream>

class Strategy;

class TestBed{

public:
	TestBed(){
		strategy = NULL;
	}
	void SelectStrategy(int type, char symbol);
	void DoIt();

private:
	Strategy * strategy;

};

class Strategy{

public:
	Strategy(char symbol) : symbol_(symbol){};
	virtual ~Strategy(){};
	void Format(){
		std::string a = "Kozel";
		Append(a);
	};

protected:
	char symbol_;

private:
	virtual void Append(std::string s) = 0;

};

class AppendLeft : public Strategy{

public:
	AppendLeft(char symbol) : Strategy(symbol){};

private:
	void Append(std::string s){
		std::cout << "AppendLeft::Append" << std::endl;
		std::cout << std::string(10, symbol_) << s << std::endl;

	};

};

class AppendRight : public Strategy{

public:
	AppendRight(char symbol) : Strategy(symbol){};

private:
	void Append(std::string s){
		std::cout << "AppendRight::Append" << std::endl;
		std::cout << s << std::string(10, symbol_) << std::endl;
	};

};

void TestBed::SelectStrategy(int type, char symbol){

	if(type == 1){
		strategy = new AppendLeft(symbol);
	}
	else if(type == 2){
		strategy = new AppendRight(symbol);
	}


}

void TestBed::DoIt(){
	strategy->Format();
}



/*
TestBed tb;
tb.SelectStrategy(1, 'r');
tb.DoIt();
*/


#endif /* STRATEGY_H_ */
