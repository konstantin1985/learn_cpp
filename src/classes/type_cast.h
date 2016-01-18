/*
 * type_cast.h
 *
 *  Created on: Jan 18, 2016
 *      Author: konstantin
 */

#ifndef TYPE_CAST_H_
#define TYPE_CAST_H_

class Grand{
	int hold;

public:
	Grand(int h = 0) : hold(h) {}
	virtual ~Grand() {};
	virtual void Speak() const {std::cout << "I'm a grand class!\n";}
	virtual int Value() const {return hold;}
};

class Superb : public Grand{
public:
	Superb(int h = 0) : Grand(h) {}
	void Speak() const {std::cout << "I'm a superb class!\n";}
	virtual void Say() const
		{std::cout << "I hold the superb value of " << Value() << "!\n";}
};

class Magnificent : public Superb{
	char ch;
public:
	Magnificent(int h, char c = 'A') : Superb(h), ch(c) {}
	void Speak() const {std::cout << "I'm a magnificent class!\n";}
	void Say() const {std::cout << "I hold the character " << ch << " and the integer " << Value() << "!\n";}

};

Grand * GetOne(int t);

void TypeCastTestFirst();


#endif /* TYPE_CAST_H_ */
