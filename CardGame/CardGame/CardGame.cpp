#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>
using namespace std;

WORD redCard = 15 << 4 | 4;
WORD blackCard = 15 << 4 | 0;

struct Card
{
	string face;
	string suit;
	int value;

	vector<string> getDisplay()const
	{
		char suitC;
		string l1 = " " + face + suit +  "    ";
		string l2 = "    " + face + suit +" ";
		string::size_type len = l1.size();
		vector<string> lines = { l1,string(len,' '),string(len,' '),string(len,' '),l2 };
		return lines;
	}
};

void generateDeck(vector<Card>& deck)
{

	string face[] = { "A","2","3","4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10" ,"J","Q","K" };
	string suit[] = { "C","D","S","H" };
	for (int f = 0; f < 13; f++)
	{
		for (int s = 0; s < 4; s++)
		{
			Card c;
			c.suit = suit[s];
			c.face = face[f];
			if (f == 0)
			{
				c.value = 11;
			}
			else if (f >= 9)
			{
				c.value = 10;
			}
			else
			{
				c.value = f + 1;
			}

			deck.push_back(c);
		}

	}


}


void printCards(const vector<Card>& deck)
{
	HANDLE hnd1 = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int x = 0; x < 5; x++)
	{
		for (int i = 0; i < deck.size(); i++)
		{
			if(deck[i].suit == "H" || deck[i].suit == "D")
				SetConsoleTextAttribute(hnd1, redCard);
			else
				SetConsoleTextAttribute(hnd1, blackCard);

			cout << (deck[i].getDisplay())[x];
			SetConsoleTextAttribute(hnd1, 15);
			cout << " ";

			/*if (i % 10 == 0)
			{
				cout << endl;
			}*/
			//cout << deck[i].face << deck[i].suit << " ";
		}
		cout << endl;
	}
	
}

void guessingGame(const vector<Card>& deck)
{
	Card c = deck[0];
	string guessFace, guessSuit;
	cout << "1.Face Value" << endl;
	cout << "2.Suit Value" << endl;
	cout << "3.Both Face and Suit Value" << endl;
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Enter face value (A,2,3,4,5,6,7,8,9,10,J,Q,K )" << endl;
		cin >> guessFace;
		if (c.face == guessFace)
		{
			cout << "You win!!!" << endl;
		}
		else
		{
			cout << "You lost" << endl;
		}
		break;


	case 2:
		cout << "Enter suit value (C,D,H,S)" << endl;
		cin >> guessSuit;
		if (c.suit == guessSuit)
		{
			cout << "You win!!!" << endl;
		}
		else
		{
			cout << "You lost" << endl;
		}
		break;

	case 3:
		cout << "Enter face value: " << endl;
		cin >> guessFace;
		cout << "Enter suit value (C,D,H,S)" << endl;
		cin >> guessSuit;
		if (c.face == guessFace && c.suit == guessSuit)
		{
			cout << "You win!!!" << endl;
		}
		else
		{
			cout << "You lost" << endl;
		}
		break;

	}
}

int getScore(const vector<Card>& hand)
{
	int aceCount = 0;
	int total = 0;
	for(int i =0; i<hand.size(); i++)
	{ 
		int value = hand[i].value;
		if (value == 11)
		{
			aceCount++;
		}
		total += value;
	}
	while (aceCount > 0 && total > 21)
	{
		total -= 10;
		aceCount--;
	}

	return total;

}

int myrandom(int i) { return std::rand() % i; }




int main()
{
	vector<Card> deck;
	generateDeck(deck);
	std::srand(unsigned(std::time(0)));
	random_shuffle(deck.begin(), deck.end(),myrandom);
	//guessingGame(deck);

	vector<Card> dealer,player;
	dealer.push_back(deck.front());
	deck.erase(deck.begin());
	player.push_back(deck.front());
	deck.erase(deck.begin());

	dealer.push_back(deck.front());
	deck.erase(deck.begin());
	player.push_back(deck.front());
	deck.erase(deck.begin());

	string option;
	do 
	{
		printCards(player);
		cout << "You currently have " << getScore(player) << endl;

		cout << "Hit(H) or Stick(S)?" << endl;
		cin >> option;
		if (option == "H")
		{
			player.push_back(deck.front());
			deck.erase(deck.begin());
		}
	} while (option != "S");


	while (getScore(dealer) < 16)
	{
		dealer.push_back(deck.front());
		deck.erase(deck.begin());
	}
	
	int dealerScore = getScore(dealer);
	int playerScore = getScore(player);

	if (playerScore > 21)
	{
		cout << "Hard luck you bust!" << endl;
	}
	else if (dealerScore > 21)
	{
		cout << "Dealer has bust! You win!" << endl;

	}
	else if (playerScore > dealerScore)
	{
		cout << "You have beat the dealer. You have won!" << endl;
	}
	else
	{
		cout << "Dealer has beat you! You lost!" << endl;
	}
		
	cout << "Player score: " << playerScore<< endl;
	
	cout << "Dealer score: " << dealerScore<< endl;
	getScore(dealer);
		




}