#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

int n;
int m;
vector<vector<char>> boardState;

struct Move
{
	int row;
	int col;
	int score;

	Move(int r, int c, int sc = 0) :row(r), col(c), score(sc) {}
};

bool hasWon(int player)
{
	//Check vertically
	if (player == 0) //computer
	{
		for (int col = 0; col < n; col++)
		{
			int adjCount = 0;
			for (int row = 0; row < n; row++)
			{
				if (boardState[row][col] == 'X')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}
	else
	{
		for (int col = 0; col < n; col++)
		{
			int adjCount = 0;
			for (int row = 0; row < n; row++)
			{
				if (boardState[row][col] == 'O')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}

	//Check horizontally
	if (player == 0)
	{
		for (int row = 0; row < n; row++)
		{
			int adjCount = 0;
			for (int col = 0; col < n; col++)
			{
				if (boardState[row][col] == 'X')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}
	else
	{
		for (int row = 0; row < n; row++)
		{
			int adjCount = 0;
			for (int col = 0; col < n; col++)
			{
				if (boardState[row][col] == 'O')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}

	//Check Left Main Diagonal
	if (player == 0)
	{
		int adjCount = 0;
		for (int i = 0; i < n; i++)
		{
			if (boardState[i][i] == 'X')
			{
				adjCount++;
				if (adjCount == m)
				{
					return true;
				}
			}
			else
			{
				adjCount = 0;
			}
		}
	}
	else
	{
		int adjCount = 0;
		for (int i = 0; i < n; i++)
		{
			if (boardState[i][i] == 'O')
			{
				adjCount++;
				if (adjCount == m)
				{
					return true;
				}
			}
			else
			{
				adjCount = 0;
			}
		}
	}

	//Check Left Lower Diagonal(s)
	if (player == 0)
	{
		for (int row = 1; row <= n - m; row++)
		{
			int adjCount = 0;
			for (int col = 0; col < n - row; col++)
			{
				if (boardState[row + col][col] == 'X')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}
	else
	{
		for (int row = 1; row <= n - m; row++)
		{
			int adjCount = 0;
			for (int col = 0; col < n - row; col++)
			{
				if (boardState[row + col][col] == 'O')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}


	//Check Left Upper Diagonal(s)
	if (player == 0)
	{
		for (int col = 1; col <= n - m; col++)
		{
			int adjCount = 0;
			for (int row = 0; row < n - col; row++)
			{
				if (boardState[row][col + row] == 'X')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}
	else
	{
		for (int col = 1; col <= n - m; col++)
		{
			int adjCount = 0;
			for (int row = 0; row < n - col; row++)
			{
				if (boardState[row][col + row] == 'O')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}


	//Check right main diagonal
	if (player == 0)
	{
		int adjCount = 0;
		for (int i = 0; i < n; i++)
		{
			if (boardState[i][n - 1 - i] == 'X')
			{
				adjCount++;
				if (adjCount == m)
				{
					return true;
				}
			}
			else
			{
				adjCount = 0;
			}
		}
	}
	else
	{
		int adjCount = 0;
		for (int i = 0; i < n; i++)
		{
			if (boardState[i][n - 1 - i] == 'O')
			{
				adjCount++;
				if (adjCount == m)
				{
					return true;
				}
			}
			else
			{
				adjCount = 0;
			}
		}
	}

	//Check right lower diagonal(s)
	if (player == 0)
	{
		for (int row = 1; row <= n - m; row++)
		{
			int adjCount = 0;
			for (int col = 0; col < n - row; col++)
			{
				if (boardState[row + col][n - col - 1] == 'X')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}
	else
	{
		for (int row = 1; row <= n - m; row++)
		{
			int adjCount = 0;
			for (int col = 0; col < n - row; col++)
			{
				if (boardState[row + col][n - col - 1] == 'O')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}

	//Check right upper diagonal(s)
	if (player == 0)
	{
		for (int col = 1; col <= n - m; col++)
		{
			int adjCount = 0;
			for (int row = 0; row < n - col; row++)
			{
				if (boardState[row][n - col - row - 1] == 'X')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}
	else
	{
		for (int col = 1; col <= n - m; col++)
		{
			int adjCount = 0;
			for (int row = 0; row < n - col; row++)
			{
				if (boardState[row][n - col - row - 1] == 'O')
				{
					adjCount++;
					if (adjCount == m)
					{
						return true;
					}
				}
				else
				{
					adjCount = 0;
				}
			}
		}
	}

	//check no moves - stale

	return false;
}

void initializeBoard()
{
	vector<char> initVector;
	for (int i = 0; i < n; i++)
	{
		initVector.push_back('-');
	}
	for (int i = 0; i < n; i++)
	{
		boardState.push_back(initVector);
	}
}

int evaluateBoard(vector<vector<char>> evaluationBoard)
{
	int overallScore = 0;
	int score;

	//vertical evaluation
	for (int col = 0; col < n; col++)
	{
		score = 0;
		int XCount = -1;
		int OCount = -1;
		for (int row = 0; row < n; row++)
		{
			if (evaluationBoard[row][col] == 'X') //My Seed
			{
				if (OCount >= 0)
				{
					overallScore += score;
					OCount = -1;
				}
				XCount++;
				score = (int)pow(10, XCount);
			}
			else if (evaluationBoard[row][col] == 'O') //Opponet Seed
			{
				if (XCount >= 0)
				{
					overallScore += score;
					XCount = -1;
				}
				OCount++;
				score = -(int)pow(10, OCount);
			}
			else
			{
				overallScore += score;
				XCount = -1;
				OCount = -1;
				score = 0;
			}
		}

		overallScore += score;
	}
	
	//horizontal evaluation
	for (int row = 0; row < n; row++)
	{
		score = 0;
		int XCount = -1;
		int OCount = -1;
		for (int col = 0; col < n; col++)
		{
			if (evaluationBoard[row][col] == 'X') //My Seed
			{
				if (OCount >= 0)
				{
					overallScore += score;
					OCount = -1;
				}
				XCount++;
				score = (int)pow(10, XCount);
			}
			else if (evaluationBoard[row][col] == 'O') //Opponet Seed
			{
				if (XCount >= 0)
				{
					overallScore += score;
					XCount = -1;
				}
				OCount++;
				score = -(int)pow(10, OCount);
			}
			else
			{
				overallScore += score;
				XCount = -1;
				OCount = -1;
				score = 0;
			}
		}

		overallScore += score;
	}

	//Left diagonal evaluation
	score = 0;
	int XCount = -1;
	int OCount = -1;
	for (int i = 0; i < n; i++)
	{
		if (evaluationBoard[i][i] == 'X') //My Seed
		{
			if (OCount >= 0)
			{
				overallScore += score;
				OCount = -1;
			}
			XCount++;
			score = (int)pow(10, XCount);
		}
		else if (evaluationBoard[i][i] == 'O') //Opponet Seed
		{
			if (XCount >= 0)
			{
				overallScore += score;
				XCount = -1;
			}
			OCount++;
			score = -(int)pow(10, OCount);
		}
		else
		{
			overallScore += score;
			XCount = -1;
			OCount = -1;
			score = 0;
		}
	}

	overallScore += score;

	//Left lower diagonal(s) evaluation
	for (int row = 1; row <= n - m; row++)
	{
		int score = 0;
		int XCount = -1;
		int OCount = -1;
		for (int col = 0; col < n - row; col++)
		{
			if (evaluationBoard[row + col][col] == 'X') //My Seed
			{
				if (OCount >= 0)
				{
					overallScore += score;
					OCount = -1;
				}
				XCount++;
				score = (int)pow(10, XCount);
			}
			else if (evaluationBoard[row + col][col] == 'O') //Opponent Seed
			{
				if (XCount >= 0)
				{
					overallScore += score;
					XCount = -1;
				}
				OCount++;
				score = -(int)pow(10, OCount);
			}
			else
			{
				overallScore += score;
				XCount = -1;
				OCount = -1;
				score = 0;
			}
		}

		overallScore += score;
	}

	//Left upper diagonal evaluation
	for (int col = 1; col <= n - m; col++)
	{
		int score = 0;
		int XCount = -1;
		int OCount = -1;
		for (int row = 0; row < n - col; row++)
		{
			if (evaluationBoard[row][col + row] == 'X') //My Seed
			{
				if (OCount >= 0)
				{
					overallScore += score;
					OCount = -1;
				}
				XCount++;
				score = (int)pow(10, XCount);
			}
			else if (evaluationBoard[row][col + row] == 'O') //Opponet Seed
			{
				if (XCount >= 0)
				{
					overallScore += score;
					XCount = -1;
				}
				OCount++;
				score = -(int)pow(10, OCount);
			}
			else
			{
				overallScore += score;
				XCount = -1;
				OCount = -1;
				score = 0;
			}
		}

		overallScore += score;
	}

	//Right main diagonal evaluation
	score = 0;
	XCount = -1;
	OCount = -1;
	for (int i = 0; i < n; i++)
	{
		if (evaluationBoard[i][n-1-i] == 'X') //My Seed
		{
			if (OCount >= 0)
			{
				overallScore += score;
				OCount = -1;
			}
			XCount++;
			score = (int)pow(10, XCount);
		}
		else if (evaluationBoard[i][n-1-i] == 'O') //Opponet Seed
		{
			if (XCount >= 0)
			{
				overallScore += score;
				XCount = -1;
			}
			OCount++;
			score = -(int)pow(10, OCount);
		}
		else
		{
			overallScore += score;
			XCount = -1;
			OCount = -1;
			score = 0;
		}
	}

	overallScore += score;

	//Right lower diagonal evaluation
	for (int row = 1; row <= n - m; row++)
	{
		int score = 0;
		int XCount = -1;
		int OCount = -1;
		for (int col = 0; col < n - row; col++)
		{
			if (evaluationBoard[row + col][n - col - 1] == 'X') //My Seed
			{
				if (OCount >= 0)
				{
					overallScore += score;
					OCount = -1;
				}
				XCount++;
				score = (int)pow(10, XCount);
			}
			else if (evaluationBoard[row + col][n - col - 1] == 'O') //Opponet Seed
			{
				if (XCount >= 0)
				{
					overallScore += score;
					XCount = -1;
				}
				OCount++;
				score = -(int)pow(10, OCount);
			}
			else
			{
				overallScore += score;
				XCount = -1;
				OCount = -1;
				score = 0;
			}
		}

		overallScore += score;
	}


	//Right upper diagonal evaluation
	for (int col = 1; col <= n - m; col++)
	{
		int score = 0;
		int XCount = -1;
		int OCount = -1;
		for (int row = 0; row < n - col; row++)
		{
			if (evaluationBoard[row][n - col - row - 1] == 'X') //My Seed
			{
				if (OCount >= 0)
				{
					overallScore += score;
					OCount = -1;
				}
				XCount++;
				score = (int)pow(10, XCount);
			}
			else if (evaluationBoard[row][n - col - row - 1] == 'O') //Opponet Seed
			{
				if (XCount >= 0)
				{
					overallScore += score;
					XCount = -1;
				}
				OCount++;
				score = -(int)pow(10, OCount);
			}
			else
			{
				overallScore += score;
				XCount = -1;
				OCount = -1;
				score = 0;
			}
		}

		overallScore += score;
	}


	return overallScore;
}

vector<Move> generateMoves(int player)
{
	vector<Move> moveList;
	vector<vector<char>> currentMove;

	if (hasWon(0) || hasWon(1))
	{
		return moveList;
	}

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (boardState[row][col] == '-')
			{
				if (player == 0) //computer
				{
					currentMove = boardState;
					currentMove[row][col] = 'X';
					int moveScore = evaluateBoard(currentMove);
					moveList.push_back(Move(row, col, moveScore));
				}
				else //opponent
				{
					currentMove = boardState;
					currentMove[row][col] = 'O';
					int moveScore = evaluateBoard(currentMove);
					moveList.push_back(Move(row, col, moveScore));
				}
			}
		}
	}

	return moveList;
}

Move minmax(int depth, int player, int alpha, int beta)
{
	vector<Move> nextMoves = generateMoves(player);

	int score;
	int bestRow = -1;
	int bestCol = -1;

	if (nextMoves.empty() || depth == 0)
	{
		score = evaluateBoard(boardState);
		return Move(bestRow, bestCol, score);
	}
	else
	{
		for (Move m : nextMoves)
		{
			//play the move
			if (player == 0) //computer
			{
				boardState[m.row][m.col] = 'X';
			}
			else
			{
				boardState[m.row][m.col] = 'O';
			}

			if (player == 0) //computer
			{
				score = minmax(depth - 1, 1, alpha, beta).score;

				if (score > alpha)
				{
					alpha = score;
					bestRow = m.row;
					bestCol = m.col;
				}
			}
			else
			{
				score = minmax(depth - 1, 0, alpha, beta).score;
				if (score < beta)
				{
					beta = score;
					bestRow = m.row;
					bestCol = m.col;
				}
			}

			//undo move
			boardState[m.row][m.col] = '-';

			if (alpha >= beta)
			{
				break;
			}
		}

		return Move(bestRow, bestCol, (player == 0) ? alpha : beta);
	}
}

int main()
{
	n = 12;
	m = 6;

	initializeBoard();

	boardState[3][3] = 'X';

	Move m = minmax(2, 1, -100000, 100000);

	boardState[m.row][m.col] = 'O';

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << boardState[i][j] << " ";
		}
		cout << endl;
	}

	boardState[2][1] = 'X';

	m = minmax(2, 1, -100000, 100000);

	boardState[m.row][m.col] = 'O';

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << boardState[i][j] << " ";
		}
		cout << endl;
	}

	/*boardState[0][1] = 'X';

	m = minmax(4, 1, -100000, 100000);

	boardState[m.row][m.col] = 'O';

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << boardState[i][j] << " ";
		}
		cout << endl;
	}

	boardState[1][0] = 'X';

	m = minmax(4, 1, -100000, 100000);

	boardState[m.row][m.col] = 'O';

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << boardState[i][j] << " ";
		}
		cout << endl;
	}*/

}