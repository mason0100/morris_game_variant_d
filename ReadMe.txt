The program runs wit 4 parameters


	*argv[1] == input board
	*argv[2] == output board
	*argv[3] == depth to be evaluated
	*argv[4] == which program is to be ran, see ReadMe
	

	Below are the selectio options which are 0 through 7

	int minimaxOpening(string boardPosition, bool whiteTurn, int depth);//case 0
	int minimaxGame(string boardPosition, bool whiteTurn, int depth);//case1 
	int ABOpening(string boardPosition, bool whiteTurn, int depth, int alpha, int beta);// case 2
	int ABGame(string boardPosition, bool whiteTurn, int depth, int alpha, int beta);//case 3
	int minimaxOpeningBlack(string boardPosition, bool whiteTurn, int depth);//case 4
	int minimaxGameBlack(string boardPosition, bool whiteTurn, int depth);//case 5
	int minimaxOpeningImproved(string boardPosition, bool whiteTurn, int depth);//case 6
	int minimaxGameImproved(string boardPosition, bool whiteTurn, int depth);//case 7