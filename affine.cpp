#include <iostream>
#include <time.h>
using namespace std;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
unsigned keyGen(unsigned key, unsigned lang)
{
	while (gcd(key, lang) != 1)
	{
		srand((unsigned)time(NULL));
		srand((unsigned)rand());
		key = rand() % lang + 2;
	}
	return key;
}
string toAffine(string sourceText)
{
	unsigned char let;
	unsigned x;
	unsigned rusKey = 0;
	unsigned engKey = 0;
	unsigned numbKey = 0;
	srand((unsigned)time(NULL));
	srand((unsigned)rand());
	unsigned shift = rand() % 50;
	string encodedText;
	for (int i = 0; i < sourceText.length(); i++)
	{
		let = sourceText[i];
		//English
		//capital
		if (let >= 65 && let <= 90)
		{
			x = let - 65;
			if (!engKey) engKey = keyGen(engKey, 26);
			let = 65 + (engKey * x + shift) % 26;
		}
		//lower case
		else if (let >= 97 && let <= 122)
		{
			x = let - 97;
			if (!engKey) engKey = keyGen(engKey, 26);
			let = 97 + (engKey * x + shift) % 26;
		}
		//Russian
		//capital
		else if (let >= 192 && let <= 223 || let == 168)
		{
			if (!rusKey) rusKey = keyGen(rusKey, 33);
			if (let == 168) let = 198;
			else if (let >= 198) let++;
			x = let - 192;
			let = 192 + (rusKey * x + shift) % 33;
			if (let == 198) let = 168;
			else if (let >= 198) let--;
		}
		//lower case
		else if (let >= 224 && let <= 255 || let == 184)
		{
			if (!rusKey) rusKey = keyGen(rusKey, 33);
			if (let == 184) let = 229;
			else if (let <= 229) let--;
			x = let - 223;
			let = 223 + (rusKey * x + shift) % 33;
			if (let == 229) let = 184;
			else if (let <= 229) let++;
		}
		//numbers
		else if (let >= 48 && let <= 57)
		{
			if (!numbKey) numbKey = keyGen(numbKey, 10);
			let = 48 + (numbKey * x + shift) % 33;
		}
		encodedText += let;
	}
	if (engKey) cout << "Ключ для латиницы - " << engKey << endl;
	if (rusKey) cout << "Ключ для кириллицы - " << rusKey << endl;
	if (numbKey) cout << "Ключ для цифер - " << numbKey << endl;
	cout << "Сдвиг - " << shift << endl;
	return encodedText;
}