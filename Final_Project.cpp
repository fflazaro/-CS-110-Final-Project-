#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	string name;
	cout << "Though you may not know where this is going, USER, input your name." << endl;
	getline(cin, name);
MENU:
	cout << "You're a long way from home, " << name << "... \n\n\n";
	cout << "Welcome to the ESCAPE GAME.\nDuring this game, you will be faced with three rooms and will have to find a way out of all of them.\n\n";
	int choice;
	cout << "Please Select 1 then Press ENTER to Begin.\n\n";
	cin >> choice;
	bool runGame = true;
	while (runGame == true)
	{
		//Garage Variables
		int hasOpener = 0;
		int hasNote = 0;
		bool gdoorOpen = false;
		char coffeeDrink;
		//Medieval Variables
		int medievalOptions;
		int mdoorOpen = 0;
		int knightCount = 0;
		int keyCount = 0;
		//Pirate Variables
		string person;
		int iSecret;
		string riddle1;
		string riddle2;
		string riddle3;
		switch (choice)
		{
		case 1:
			cout << "Welcome to the Garage.\n\nYes, we could choose anywhere to make you escape from and we chose a room whose whole wall is a giant door. You're welcome.\nJust visualize your space in your head. While you are not actually trapped here, *BAM* now your mental consciousness is. Just investigate objects we point out to you, and sometimes investigate them even if you already did. And try not to die. That is annoying... for both of us. I don't like having to repeat these directions a bunch of times.\n\n" << name << " surveys the garage.\n\n" << name << " sees the following:\nThe Garage Door (1)\nThe Door to Inside(2)\nThe TV (3)\nThe Garbage Can (4)\n\nAt any time press 0 to view your options. \n\nWhich would you like to interact with?\n";
			int firstChoice;
			int secondChoice;
			int firstTime;
			cin >> firstChoice;
			do
			{
				switch (firstChoice)
				{
				case 0:
					cout << "Please select which you would like to interact with:\n(1) GARAGE DOOR\n(2) DOOR TO INSIDE\n(3) TV\n(4) GARBAGE CAN\n";
					cin >> firstChoice;
					break;
				case 1:
					if (hasOpener == 0)
					{
						cout << "\nThe garage door seems to be closed. If only you had a garage door opener.\n";
						cin >> firstChoice;
						break;
					}
					else if (hasOpener == 1)
					{
						cout << "You press the garage door opener and the garage door begins to make a loud rumbling noise. It begins to raise. \nAnd slowly... \nIt reveals... \nA brick wall. \nYeah, you knew this would be too easy.\n";
						hasOpener++;
						cin >> firstChoice;
						break;
					}
					else if (hasOpener >= 2)
					{
						cout << "You look at the brick wall again and begin to feel depressed. What if there is a brick wall behind the actual door too?\nNo.\nYou must believe in a way out.\nYou want to investigate the objects again.\n";
						cin >> firstChoice;
						break;
					}
				case 2:
					if (hasNote == 0)
					{
						cout << "There is a keypad and a small monitor on this door. You try a few combinations but decide to work smarter, not harder. You take a break from the lock.\n";
						cin >> firstChoice;
						break;
					}
					else if (hasNote == 1)
					{
						cout << "You go to the keypad and begin the game.\n\n\n";
						int secret;
						int guess;
						srand(time(NULL));
						secret = rand() % 100 + 1;
						cout << "Please guess a number between 1 and 100." << endl;
						cin >> guess;
						while (guess != secret)
						{
							if (guess > secret) {
								cout << "Your guess is too high!" << endl;
							}
							if (guess < secret) {
								cout << "Your guess is too low!" << endl;
							}
							cin >> guess;
						}
						if (guess == secret)
						{
							cout << "Good Job! You guessed right!" << endl;
							guess++;
							gdoorOpen = true;
							cout << "The door opens and you walk through.";
						}
						break;
					}
				case 3:
					cout << "The TV displays only static.\n";
					cin >> firstChoice;
					break;
				case 4:
					if (hasOpener >= 1 && hasNote >= 1) {
						cout << "\nYou look inside the garbage can. \nSomebody left their (5) old coffee cup in it. Which would you like to interact with?\n";
					CTEST: cin >> secondChoice;
						switch (secondChoice)
						{
						case 0:
							cout << "Please select which you would like to interact with:\n(5) Old Coffee Cup\n";
							goto CTEST;
							break;
						case 5:
							cout << "\nYou examine the old coffee cup. Ew! There is some left and it is all curdled and disgusting! Do you want to drink it? (y/n)\n";
							cin >> coffeeDrink;
							if (coffeeDrink == 'y')
							{
								cout << "You bring it up to your mouth and pour it down your throat. It's a little chewy. You begin to feel sick. Maybe that was a bad idea. Is this what it feels like to die?\n\n\n\n\n\nYes. Yes it is. You should be more careful next time.\n";
								cout << "\n\n\n\n\n\n\nYou died.\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
								goto MENU;
							}
							else {
								cout << "You throw the coffee cup back in the garbage. Smart choice... \nYou stopped examining the garbage can.\n";
							}
							break;
						default:
							cout << "Please enter the number of the object you wish to interact with.\n";
							goto CTEST;
							break;
						}
					}
					else if (hasOpener >= 1 && hasNote == 0) {
						cout << "\nYou look inside the garbage can. \nSomebody left their (5) old coffee cup in it. Also there is (6) a crumpled piece of paper. Which would you like to interact with?\n";
					CNTEST: cin >> secondChoice;
						switch (secondChoice)
						{
						case 0:
							cout << "Please select which you would like to interact with:\n(5) Old Coffee Cup\n(6) Crumpled Piece of Paper\n";
							goto CNTEST;
							break;
						case 5:
							cout << "\nYou examine the old coffee cup. Ew! There is some left and it is all curdled and disgusting! Do you want to drink it? (y/n)\n";
							cin >> coffeeDrink;
							if (coffeeDrink == 'y')
							{
								cout << "You bring it up to your mouth and pour it down your throat. It's a little chewy. You begin to feel sick. Maybe that was a bad idea. Is this what it feels like to die?\n\n\n\n\n\nYes. Yes it is. You should be more careful next time.\n";
								cout << "\n\n\n\n\n\n\nYou died.\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
								goto MENU;
							}
							else {
								cout << "You throw the coffee cup back in the garbage. Smart choice... \nYou stopped examining the garbage can.\n";
							}
							break;
						case 6:
							cout << "\nYou grab the crumpled piece of paper and uncrumple it. \nIt reads: To enter the house, you must guess the number that the padlock is thinking of. Go try it now.\n";
							hasNote = true;
							cout << "You stopped examining the garbage can.\n";
							break;
						default:
							cout << "Please enter the number of the object you wish to interact with.\n";
							goto CNTEST;
							break;
						}
					}
					else if (hasOpener == 0 && hasNote >= 1) {
						cout << "\nYou look inside the garbage can. \nSomebody left their (5) old coffee cup in it. Also there is (7) a garage door opener. Which would you like to interact with?\n";
					COTEST: cin >> secondChoice;
						switch (secondChoice)
						{
						case 0:
							cout << "Please select which you would like to interact with:\n(5) Old Coffee Cup\n(7) Garage Door Opener\n";
							goto COTEST;
							break;
						case 5:
							cout << "\nYou examine the old coffee cup. Ew! There is some left and it is all curdled and disgusting! Do you want to drink it? (y/n)\n";
							cin >> coffeeDrink;
							if (coffeeDrink == 'y')
							{
								cout << "You bring it up to your mouth and pour it down your throat. It's a little chewy. You begin to feel sick. Maybe that was a bad idea. Is this what it feels like to die?\n\n\n\n\n\nYes. Yes it is. You should be more careful next time.\n";
								cout << "\n\n\n\n\n\n\nYou died.\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
								goto MENU;
							}
							else {
								cout << "You throw the coffee cup back in the garbage. Smart choice... \nYou stopped examining the garbage can.\n";
							}
							break;
						case 7:
							cout << "You grab the garage door opener and put it in your pocket. You want to go interact with the garage door again and try it out.\n";
							hasOpener++;
							cout << "You stopped examining the garbage can.\n";
							break;
						default:
							cout << "Please enter the number of the object you wish to interact with.\n";
							goto COTEST;
							break;
						}
					}
					else if (hasOpener == 0 && hasNote == 0) {
						cout << "\nYou look inside the garbage can. \nSomebody left their (5) old coffee cup in it. Also there is (6) a crumpled piece of paper and (7) a garage door opener. Which would you like to interact with?\n";
					CONTEST: cin >> secondChoice;
						switch (secondChoice)
						{
						case 0:
							cout << "Please select which you would like to interact with:\n(5) Old Coffee Cup\n(6) Crumpled Piece of Paper\n(7) Garage Door Opener\n";
							goto CONTEST;
							break;
						case 5:
							cout << "\nYou examine the old coffee cup. Ew! There is some left and it is all curdled and disgusting! Do you want to drink it? (y/n)\n";
							cin >> coffeeDrink;
							if (coffeeDrink == 'y')
							{
								cout << "You bring it up to your mouth and pour it down your throat. It's a little chewy. You begin to feel sick. Maybe that was a bad idea. Is this what it feels like to die?\n\n\n\n\n\nYes. Yes it is. You should be more careful next time.\n";
								cout << "\n\n\n\n\n\n\nYou died.\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
								goto MENU;
							}
							else {
								cout << "You throw the coffee cup back in the garbage. Smart choice... \nYou stopped examining the garbage can.\n";
							}
							break;
						case 6:
							cout << "\nYou grab the crumpled piece of paper and uncrumple it. \nIt reads: To enter the house, you must guess the number that the padlock is thinking of. Go try it now.\n";
							hasNote++;
							cout << "You stopped examining the garbage can.\n";
							break;
						case 7:
							cout << "You grab the garage door opener and put it in your pocket. You want to go interact with the garage door again and try it out.\n";
							hasOpener++;
							cout << "You stopped examining the garbage can.\n";
							break;
						default:
							cout << "Please enter the number of the object you wish to interact with.\n";
							goto CONTEST;
							break;
						}
					}
					cin >> firstChoice;
					break;
				default:
					cout << "Please enter the number of the object you wish to interact with.\n";
					cin >> firstChoice;
					break;
				}
			} while (gdoorOpen == false);
		case 2:
			//This is the medieval room
			//intro//
			cout << "\n\nWelcome to the Medieval Room" << endl << endl;
			cout << "We see you have come far warrior/hero (if you actually completed the previous levels). If you found the short cut, then the only person you are trolling is yourself. We both know what you're capable of, " << name << "." << endl << endl << "Anyways, you know how this works already. Take a look around, " << name << ". Make yourself useful in this forbidden place. You can really lose yourself here." << endl << endl;
			cout << name << " takes a look around, as instructed from the creators of this code." << endl << endl;
			cout << name << " sees the following: " << endl << "The Iron Maiden(1)" << endl << "The Shiny Knight(2)" << endl << "The Obviously Placed Chest(3)" << endl << endl << "And lastly... The only thing you've been caring about till now. The only reason why you're still living in the first place. The only thing that isn't the bane of your existence.... THE DOOR(4)" << endl << endl << "What would you like to check out, " << name << "?" << endl << endl;
			cout << "Remember that you can enter 0 to see your options at any time.";
			//switch//
			cin >> medievalOptions;
			while (mdoorOpen == 0) {
				//variables//
			MMENU: switch
				(medievalOptions) {
			case 0:
				cout << name << " sees the following:\n(1) The Iron Maiden\n(2) The Shiny Knight\n(3) The Obviously Placed Chest\n(4) The Door\n";
				cin >> medievalOptions;
				break;
			case 1:
				//iron maiden variables//
				char ironMaiden;
				//intro//
				cout << name << " takes a look around but of course, the iron maiden has stolen their eye." << endl;
				cout << "We mean, how could it not anyways?" << endl;
				cout << name << " sees a shiny key inside. It's placed at the very back corner of the iron maiden. ";
				cout << "Unlike most iron maidens, this one is bigger in size. Does this mean you have to climb in?(y/n)" << endl << endl;
				//decision//
				cin >> ironMaiden;
				cout << endl;
				if (ironMaiden == 'y') {
					cout << "So, you have chosen death?" << endl;
					cout << "Wrong choice, buddy." << endl;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou died.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					goto MENU;
					//back to the main menu//
				}
				else {
					cout << "Is it just us, " << name << ", or have you actually gotten smarter over the levels?" << endl;
					cout << "What would you like to explore next?" << endl << endl;
					cin >> medievalOptions;
				}
				break;
			case 2:
				//shiny knight variables//
				char shinyKnight;
				//intro//
				cout << endl;
				cout << "The Shiny Knight is definitely a must see in this limited tour attraction. Luckily, you have all of eternity to gawk at it." << endl << endl;
				cout << name << " looks at the knight with absolute fake enthusiam and astonishment. They take notice of the beautiful sword the knight holds. Fancy taking it?(y/n)" << endl << endl;
				//decision//
				cin >> shinyKnight;
				if (shinyKnight == 'y') {
					knightCount++;
					cout << endl;
					//cout << knightCount << endl;
					cout << name << " takes the sword in pure amazement and places it in the inventory." << endl;
					cout << "What would you like to explore next?" << endl << endl;
					cin >> medievalOptions;
				}
				else {
					cout << endl;
					cout << "For shame. We guess taking swords just isn't your thing." << endl;
					cout << "What would you like to explore next?" << endl << endl;
					cin >> medievalOptions;
				}
				break;
			case 3:
				//the obviously placed chest variables//
				char chaliceDrink;
				//intro + decision//
				cout << endl;
				cout << "The chest is by far the most overrated object in this room besides the key. But, of course, you had to take a gander at it." << endl << endl;
				cout << name << " goes over to the chest only to find a lock and chain on it." << endl << endl;
				/*cout << knightCount << endl;
				knightCount++;
				cout << knightCount << endl;*/
				if (knightCount > 0) {
					cout << "It seems you have a sword, mighty warrior. I think you know where this is going." << endl << endl;
					cout << name << " breaks the chain open with the amaaaaaazing sword." << endl;
					cout << "The chain breaks off and the chest 'magically' swings open. Inside is only a chalice with wine. Would you like to take a swig?(y/n) " << endl << endl;
					cin >> chaliceDrink;
					cout << endl;
					if (chaliceDrink == 'y') {
						keyCount++;
						cout << name << " takes a long drink and is shocked when they feel the key pop into their mouth. " << name << " spits out the key. It lands right back into the chalice full of wine and " << name << " cooties. That's one way of finding the key." << endl;
						cout << "What would you like to explore next?" << endl << endl;
						cin >> medievalOptions;
					}
					else {
						cout << "Guess warriors just don't like partying." << endl;
						cout << "What would you like to explore next?" << endl << endl;
						cin >> medievalOptions;
					}
				}
				else {
					cout << "Judging by the looks of you, it seems you don't have any note worthy items in your inventory. And even then, we're not sure if you're strong enough to break it in the first place with your bare fists. Oh well." << endl;
					cout << "What would you like to explore next?" << endl << endl;
					cin >> medievalOptions;
				}
				break;
			case 4:
				cout << endl;
				cout << "Of course, checking out the door is the first thing you should do. We mean, what can you do? Knock on it? Bang on it? Kick it down?" << endl;
				cout << "Do you even have the key?" << endl;
				/*cout << keyCount << endl;
				keyCount++;
				cout << keyCount << endl;*/
				if (keyCount > 0) {
					cout << endl;
					cout << "Wowie! Looks like you do have a key from drinking the mystery 'wine' in the obviously placed chest. Lucky! Well, you finished the level, but it only gets weirder from here on out." << endl << endl << endl;
					mdoorOpen++;
					//go back to the main menu//
					//testing purposes//
					/*
					cout << "What would you like to explore next?" << endl << endl;
					cout << "USER sees the following: " << endl << "The Iron Maiden(1)" << endl << "The Shiny Knight(2)" << endl << "The Obviously Placed Chest(3)" << endl << "The only exit, aka, THE DOOR(4)" << endl << endl << "What would you like to check out, USER?" << endl << endl;
					cin >> medievalOptions;
					*/
				}
				else {
					cout << "By the looks of it, it seems you're just have some pocket change. Oh well. Back to the options." << endl;
					cout << "What would you like to explore next?" << endl << endl;
					cin >> medievalOptions;
				}
				break;
			default:
				cout << "Please enter the number of the object you wish to interact with.";
				cin >> medievalOptions;
				goto MMENU;
			}
			}
			//don't put a break after this statement, we want it to fallthrough
		case 3:
			//The following code goes after pirate room
		  //variables//
			//intro//
			cout << "Welcome to Pirate's Cove!" << endl << endl;
			cout << "It seems you've made it to the final room, huh? I guess you really are stubborn enough to find your way out." << endl << endl;
			cout << "Well, this is the last room and it isn't that hard at all, " << name << ". We bet you could even code it too." << endl << endl;
			cout << name << " looks around the pirate ship they are on. " << endl << endl;
			cout << "A pirate approaches " << name << " with a parrot perched on top of his shoulder." << endl << endl;
			cout << "'Ahoy " << name << ", how didya get yerself on this fancy ship?' The pirate grumbles." << endl << endl;
			cin.ignore();
			getline(cin, person);
			cout << endl;
			cout << "The parrot hanging on the poor fellow's shoulder gawks and yaks at " << name << ", saying " << "'" << person << "'" << " " << "'" << person << "'" << endl << endl;
			cout << "The pirate croaked to his parrot 'Ahh, excuz me birdy' Then the pirate turns his gaze to you and utters 'He always fergets the point of yer bein here. Mind gettin em to stop bein annoyin and remember owr goal?'" << endl << endl;

			getline(cin, person);
			while (person != "RIDDLE")
			{
				srand(time(NULL));
				iSecret = rand() % 4 + 0;
				switch (iSecret) {
				case 1:
					cout << endl;
					cout << "The parrot screams: " << person << endl;
					getline(cin, person);
					break;
				case 2:
					cout << endl;
					cout << "The parrot howls: " << person << endl;
					getline(cin, person);
					break;
				case 3:
					cout << endl;
					cout << "The parrot yells: " << person << endl;
					cout << "The pirate staggers close to " << name << "'s face with mischief." << endl;
					cout << "'Say RIDDLE and maybe he'll remember owr mission.'" << endl << endl;
					getline(cin, person);
					break;
				case 4:
					cout << endl;
					cout << "The parrot whispers " << person << endl;
					getline(cin, person);
					break;
				}
			}
			//riddles//
			//intro + riddle1//
			cout << endl << endl;
			cout << "The parrot turns cocks its head at " << name << " with an expression as if it is saying 'Is that so?'" << endl;
			cout << "The parrot begins to squak." << endl;
			cout << "'You have 3 riddles, tourist. Let's see if yer good 'nough.'" << endl;
			cout << "'I have cities, but no houses. I have mountains, but no trees. I have water, but no fish. What am I?'" << endl;
			cout << "'Make sure your answer is in all capitals. For example, CANDLE.'" << endl << endl;
			getline(cin, riddle1);
			while (riddle1 != "MAP") {
				if (riddle1 != "MAP") {
					cout << "The parrot yells: WRONG." << endl;
					getline(cin, riddle1);
				}
			}
			cout << "'So ya gussed MAP, huh? How long did that take you?'" << endl;
			//riddle2//
			cout << "'Next riddle.'" << endl;
			cout << "'Only one color, but not one size. Stuck at the bottom, yet easily flies. Present in sun, but not in rain. Doing no harm, and feeling no pain. What is it?'" << endl << endl;
			getline(cin, riddle2);
			while (riddle2 != "SHADOW") {
				if (riddle2 != "SHADOW") {
					cout << "The parrot hollars: WRONG." << endl;
					getline(cin, riddle2);
				}
			}
			//riddle3//
			cout << "'So it seems this tourist is smarter than he/she looks. Last one, child.'" << endl;
			cout << "'It can't be seen, can't be felt. Can't be heard and can't be smelt. It lies behind stars and under hills and empty holes it fills. It comes first and follows after, ends life and kills laughter. What is it?'" << endl << endl;
			getline(cin, riddle3);
			while (riddle3 != "DARK") {
				if (riddle3 != "DARK") {
					cout << "The parrot claws: WRONG." << endl;
					getline(cin, riddle3);
				}
			}
			//ending//
			cout << name << " gets the last riddle correct. The pirate and parrot and whatever came with it vanished." << endl;
			cout << name << " looks around. Nothing. Darkness. What would be left would be a few lines of code stating that the program finished with exit code 0." << endl;
			cout << "It's been fun, " << name << ". It's been a lot of fun.";
			runGame = false;
			break;
		default:
			cout << "Please Enter A Valid Number.";
			cin >> choice;
			break;
		}
	}
}


