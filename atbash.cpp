#include <iostream>
using namespace std;

string toAtbash(string sourceText)
{
	unsigned char let;
	string encodedText;
	for (int i = 0; i < sourceText.length(); i++)
	{
		let = sourceText[i];
		//English
		//capital
		if (let >= 65 && let <= 90)
		{
			let = 90 - let + 65;
		}
		//lower case
		else if (let >= 97 && let <= 122)
		{
			let = 122 - let + 97;
		}
		//Russian
		//capital
		else if (let >= 192 && let <= 223 || let == 168)
		{
			if (let == 168) let = 198;
			else if (let >= 198) let++;
			let = 224 - (let - 192);
			if (let == 198) let = 168;
			else if (let >= 198) let--;
		}
		//lower case
		else if (let >= 224 && let <= 255 || let == 184)
		{
			if (let == 184) let = 229;
			else if (let <= 229) let--;
			let = 255 - (let - 224) - 1;
			if (let == 229) let = 184;
			else if (let <= 229) let++;
		}
		//numbers
		else if (let >= 48 && let <= 57)
		{
			let = 57 - let + 48;
		}
		encodedText += let;
	}
	return encodedText;
}