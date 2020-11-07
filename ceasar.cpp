#include <iostream>
using namespace std;
string toCaesar(string sourceText)
{
	cout << "¬ведите сдвиг -> ";
	unsigned shift;
	cin >> shift;
	unsigned rusShift = shift % 33;
	unsigned engShift = shift % 26;
	shift %= 10;
	unsigned char let;
	string encodedText;
	for (int i = 0; i < sourceText.length(); i++)
	{
		let = sourceText[i];
		//English
		//capital
		if (let >= 65 && let <= 90)
		{
			let = (let + engShift) > 90 ? 65 + (let + engShift) % 90 - 1: let + engShift;
		}
		//lower case
		else if (let >= 97 && let <= 122)
		{
			let = (let + engShift) > 122 ? 97 + (let + engShift) % 122 - 1 : let + engShift;
		}
		//Russian
		//capital
		else if (let >= 192 && let <= 223 || let == 168)
		{
			if (let == 168) let = 198;
			else if (let >= 198) let++;
			let = (let + rusShift) > 224 ? 192 + (let + rusShift) % 224 - 1 : let + rusShift;
			if (let == 198) let = 168;
			else if (let >= 198) let--;
		}
		//lower case
		else if (let >= 224 && let <= 255 || let == 184)
		{
			if (let == 184) let = 229;
			else if (let <= 229) let--;
			let = (let + rusShift) > 255 ? 223 + (let + rusShift) % 255 - 1 : let + rusShift;
			if (let == 229) let = 184;
			else if (let <= 229) let++;
		}
		//numbers
		else if (let >= 48 && let <= 57)
		{
			let = (let + shift) > 122 ? 97 + (let + shift) % 122 - 1 : let + shift;
		}
		encodedText += let;
	}
	return encodedText;
}