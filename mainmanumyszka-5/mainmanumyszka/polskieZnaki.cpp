#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>
#include<algorithm>

int main3 ()
{
	std::string answer = "ciastko";

	std::string text;

	getline(std::cin, text);

	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] > 64 && text[i] < 91)
		{
			text[i] += 32;
		}
	}

	text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());

	std::cout << text;

	if (text == answer)
		std::cout << "\nTrue\n";
	else
		std::cout << "\nFalse\n";

	return 0;
}