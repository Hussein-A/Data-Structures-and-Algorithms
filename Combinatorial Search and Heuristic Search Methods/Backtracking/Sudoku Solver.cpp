/*
This program's goal is to solve a given Sudoku puzzle (9x9). It is based on the backtracking implementation
used for finding allsubsets/permutations found in this repo. as well as in Skiena Algorithm Design Manual, 2ed. pg. 242
Two example sudoku puzzles are given at the end 1 of hard difficulty and the other easy. Please note the former
takes some time with this implementation.
*/

#include<vector>
#include<iostream>
using namespace std;

#define DIMENSION 9 //9x9 sudoku puzzle
#define NCELLS DIMENSION*DIMENSION //how many possible squares
bool finished = false; //to stop searching for other solutions once unique soln is found

struct point {
	//coordinate of squares (0,0) starts from top left corner of puzzle
	int x;
	int y;
};

struct board {
	vector<vector<int>> config = vector<vector<int>> (DIMENSION, vector<int> (DIMENSION,0)); //9x9 config square all 0. ie. empty
	int freespace{ NCELLS }; //how many squares are yet to be filled, used to end process when 0
	vector<point> move{NCELLS}; //holds the ith move made
};


bool is_solution(board& puzzle) {
	
	if (puzzle.freespace == 0) {
		finished = true;
		return finished;
	}
	else return false;
}

void process_solution(const board& puzzle){
	/*Ex. of output:
	1 2 3 | 4 5 6 | 7 8 9
	9 8 7 | 6 5 4 | 3 2 1
	1 2 3 | 4 5 6 | 7 8 9
	- - -   - - -   - - -
	etc.
	*/
	for (int row = 0; row < DIMENSION; ++row) {
		if (row == 3 || row == 6) cout << " - - -    - - -    - - -\n";
		for (int clmn = 0; clmn < DIMENSION; ++clmn) {
			if (clmn == 3 || clmn == 6) cout << " | ";
			cout << " " << puzzle.config[row][clmn];
		}
		cout << "\n";
	}
}

point next_square(board& puzzle) {
	//simply picks the next open square in order from left to right, top to bottom first
	for (int row = 0; row < DIMENSION; ++row) {
		for (int clmn = 0; clmn < DIMENSION; ++clmn) {
			if (puzzle.config[row][clmn] == 0) return point{ row, clmn };
		}
	}
	return point{ -1, -1 }; //no open positions found
}

point get_sector(const point& square) {
	/*returns the upper left point of the sector that the given square rests in
	ie. identifies which 3x3 subsquare the given square lies in*/
	int row, clmn;
	for (int j = 6; j >= 0; j -= 3) {
		if (j <= square.y) { clmn = j; break; }
	}
	for (int i = 6; i >= 0; i -= 3) {
		if (i <= square.x) { row = i; break; }
	}
	return point{ row, clmn };
}

void possible_nums(const board& puzzle, const point& square, vector<bool>& is_in) {
	//check entered nums along row
	int x = square.x;
	for (int clmn = 0; clmn < DIMENSION; ++clmn) {
		int val = puzzle.config[x][clmn];
		if (val == 0) continue;
		else is_in[val - 1] = true;
	}
	
	//check entered nums along column (clmn)
	int y = square.y;
	for (int row = 0; row < DIMENSION; ++row) {
		int val = puzzle.config[row][y];
		if (val == 0) continue; //empty square
		else is_in[val - 1] = true; //values of square are 1-9 not 0-8
	}

	//check sector (ie. what 3x3 subsquare is square sitting in)
	point sector = get_sector(square);
	for (int row = sector.x; row < sector.x + 3; ++row) {
		for (int clmn = sector.y; clmn < sector.y + 3; ++clmn) {
			int val = puzzle.config[row][clmn];
			if (val == 0) continue;
			else is_in[val - 1] = true;
		}
	}

}

vector<int> construct_candidates(board& puzzle, int count) {
	vector<bool> is_in(DIMENSION, false);
	vector<int> candidates;
	point square  = next_square(puzzle);
	
	if (square.x < 0 || square.y < 0) return candidates;
	else puzzle.move[count] = square; //record square chosen

	possible_nums(puzzle, square, is_in);
	for (int i = 0; i < DIMENSION; ++i) {
		if (!is_in[i]) candidates.push_back(i + 1);
	}
	return candidates;
}

void make_move(board& puzzle, point& square, int val) {
	puzzle.config[square.x][square.y] = val;
	--puzzle.freespace;
}

void unmake_move(board& puzzle, point& square) {
	puzzle.config[square.x][square.y] = 0;
	++puzzle.freespace;
}

void backtrack(board& puzzle, int count) {
	if (is_solution(puzzle)) process_solution(puzzle);
	else if (finished) return;
	else {
		++count;
		vector<int> candidates = construct_candidates(puzzle, count);
		for (int i = 0; i < candidates.size(); ++i) {
			//make move here
			int val = candidates[i];
			make_move(puzzle, puzzle.move[count], val);
			backtrack(puzzle, count);
			//unmake move here
			unmake_move(puzzle, puzzle.move[count]);
		}
	}
}

void solve_sudoku(board& puzzle) {
	backtrack(puzzle, 0);
}

int main() {
	std::ios::sync_with_stdio(false);
	board puzzle;
	puzzle.config = { //hard
		{0,0,0,0,0,0,0,1,2}, {0,0,0,0,3,5,0,0,0}, {0,0,0,6,0,0,0,7,0},
		{7,0,0,0,0,0,3,0,0}, {0,0,0,4,0,0,8,0,0}, {1,0,0,0,0,0,0,0,0},
		{0,0,0,1,2,0,0,0,0}, {0,8,0,0,0,0,0,4,0}, {0,5,0,0,0,0,6,0,0}
	};
	puzzle.freespace = NCELLS - 17;
	solve_sudoku(puzzle);
}

/*
		
		//easy, please do not forget to change puzzle.freespace
		{5,0,4,8,0,0,7,2,0}, {8,0,6,2,0,5,0,9,0}, {9,0,1,0,3,0,0,0,6},
		{0,0,0,0,0,0,0,0,5}, {7,0,0,1,0,0,0,3,8}, {1,0,8,3,5,0,2,0,4},
		{2,0,3,0,8,6,0,4,7}, {0,0,0,0,2,0,0,0,0}, {0,0,9,5,7,0,0,1,0} //freespace = NCELLS - 36
*/