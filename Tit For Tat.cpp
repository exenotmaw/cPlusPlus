#include <iostream>

using namespace std;

struct options {
	int decision = 0;
	int count = 0;
	bool enemy = true;
};

struct scores {
	int scoreOne = 0;
	int scoreTwo = 0;
};

struct strategies {
	int steal = 0;
	int share = 1;
};

options option;
strategies strategy;
scores score;

int choices() {

	cout << "STEAL OR SHARE [TYPE 1 FOR SHARE AND 0 FOR STEAL]" << endl << endl;
	cout << "Player 1 Score: " << score.scoreOne << "\tEnemy Score: " << score.scoreTwo << endl;

	cout << endl << "TYPE YOUR DECISION: ";
	cin >> option.decision;
	cin.ignore();

	return option.decision;
}

int scoring() {

	if (option.enemy == true && option.decision == strategy.share) {
		cout << endl << "BOTH PLAYER CHOOSE SHARE, BOTH GOT 3 POINTS" << endl;
		score.scoreOne = score.scoreOne + 3;
		score.scoreTwo = score.scoreTwo + 3;
	}
	else if (option.enemy == false && option.decision == strategy.share) {
		cout << endl << "ENEMY PLAYER CHOOSE STEAL, AND PLAYER CHOOSE SHARE, ENEMY PLAYER GET 5 POINTS" << endl;
		score.scoreTwo = score.scoreTwo + 5;
	}
	else if (option.enemy == true && option.decision == strategy.steal) {
		cout << endl << "ENEMY PLAYER CHOOSE SHARE, AND PLAYER CHOOSE STEAL, PLAYER GET 5 POINTS" << endl;
		score.scoreOne = score.scoreOne + 5;
	}
	else if (option.enemy == false && option.decision == strategy.steal) {
		cout << endl << "BOTH PLAYER CHOOSE STEAL, BOTH GOT 1 POINTS" << endl;
		score.scoreOne = score.scoreOne + 1;
		score.scoreTwo = score.scoreTwo + 1;
	}

	return score.scoreOne, score.scoreTwo;
}

bool enemies() {
	if (option.count == 2) {
		option.enemy = false;
		option.count = 0;
	}
	else {
		option.enemy = true;
		option.count++;
	}

	return option.enemy;
}

int main()
{
	while (true) {
		system("cls");
		
		choices();

		scoring();

		enemies();

		system("pause");
	}
}
