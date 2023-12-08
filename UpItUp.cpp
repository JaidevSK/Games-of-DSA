#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <cstdio>

/*
if (obj == ' '){char o = '0';}
else if (obj == 'A'){char o = '1';}
else if (obj == 'v'){char o = '2';}
else if (obj == '^'){char o = '3';}
else if (obj == '<'){char o = '4';}
else if (obj == '>'){char o = '5';}
else if (obj == 'B'){char o = '6';}
*/


using namespace std;

// Structure to represent the state of the puzzle
struct PuzzleState {
    vector<vector<int>> board;
    int zeroRow;
    int zeroCol;
    string index;
    string path;
};

// Function to check if the current state is the goal state
bool isGoalState(const PuzzleState& state) {
    vector<vector<int>> goalBoard = {{6, 6, 6}, {6, 0, 6}, {6, 6, 6}};
    return state.board == goalBoard;
}


string make_str(const PuzzleState& state){
char ret[9];
for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
            if (state.board[i][j]==0){
                    ret[i*3+j] = ' ';
            }
            else if (state.board[i][j]==1){
                ret[i*3+j] = 'A';
            }
            else if (state.board[i][j]==2){
                ret[i*3+j] = 'v';
            }
            else if (state.board[i][j]==3){
                ret[i*3+j] = '^';
            }
            else if (state.board[i][j]==4){
                ret[i*3+j] = '<';
            }
            else if (state.board[i][j]==5){
                ret[i*3+j] = '>';
            }
            else if (state.board[i][j]==5){
                ret[i*3+j] = 'B';
            }
    }
}
return ret;
}


// Function to generate the next possible states from the current state
vector<PuzzleState> generateNextStates(const PuzzleState& currentState) {
    vector<PuzzleState> nextStates;
    int row = currentState.zeroRow;
    int col = currentState.zeroCol;

    // Move the empty space (0) to the left
    if (col > 0) {
        PuzzleState nextState = currentState;
        int init_val = currentState.board[row][col - 1];
        nextState.board[row][col - 1]=0;
        if (init_val == 1){nextState.board[row][col] = 5;}
        else if (init_val == 4){nextState.board[row][col] = 1;}
        else if (init_val == 5){nextState.board[row][col] = 6;}
        else if (init_val == 2){nextState.board[row][col] = 2;}
        else if (init_val == 3){nextState.board[row][col] = 3;}
        else if (init_val == 6){nextState.board[row][col] = 4;}
        nextState.zeroCol = col - 1;
        nextState.path += "L";
        nextState.index = make_str(nextState);
        nextStates.push_back(nextState);
    }

    // Move the empty space (0) to the right
    if (col < 2) {
        PuzzleState nextState = currentState;
        int init_val = currentState.board[row][col + 1];
        nextState.board[row][col + 1]=0;
        if (init_val == 1){nextState.board[row][col] = 4;}
        else if (init_val == 4){nextState.board[row][col] = 6;}
        else if (init_val == 5){nextState.board[row][col] = 1;}
        else if (init_val == 2){nextState.board[row][col] = 2;}
        else if (init_val == 3){nextState.board[row][col] = 3;}
        else if (init_val == 6){nextState.board[row][col] = 5;}
        nextState.zeroCol = col + 1;
        nextState.path += "R";
        nextState.index = make_str(nextState);
        nextStates.push_back(nextState);
    }

    // Move the empty space (0) upwards
    if (row > 0) {
        PuzzleState nextState = currentState;
        int init_val = currentState.board[row - 1][col];
        nextState.board[row - 1][col]=0;
        if (init_val == 1){nextState.board[row][col] = 2;}
        else if (init_val == 4){nextState.board[row][col] = 4;}
        else if (init_val == 5){nextState.board[row][col] = 5;}
        else if (init_val == 2){nextState.board[row][col] = 6;}
        else if (init_val == 3){nextState.board[row][col] = 1;}
        else if (init_val == 6){nextState.board[row][col] = 3;}
        nextState.zeroRow = row - 1;
        nextState.path += "U";
        nextState.index = make_str(nextState);
        nextStates.push_back(nextState);
    }

    // Move the empty space (0) downwards
    if (row < 2) {
        PuzzleState nextState = currentState;
        int init_val = currentState.board[row + 1][col];
        nextState.board[row + 1][col]=0;
        if (init_val == 1){nextState.board[row][col] = 3;}
        else if (init_val == 4){nextState.board[row][col] = 4;}
        else if (init_val == 5){nextState.board[row][col] = 5;}
        else if (init_val == 2){nextState.board[row][col] = 1;}
        else if (init_val == 3){nextState.board[row][col] = 6;}
        else if (init_val == 6){nextState.board[row][col] = 2;}
        nextState.zeroRow = row + 1;
        nextState.path += "D";
        nextState.index = make_str(nextState);
        nextStates.push_back(nextState);
    }

    return nextStates;
}

// Function to solve the Puzzle Up it Up using BFS
string solveUpitUp(const vector<vector<int>>& initialBoard) {
    PuzzleState initialState;
    initialState.board = initialBoard;
    initialState.path = "";

    // Find the position of the empty space (0)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (initialState.board[i][j] == 0) {
                initialState.zeroRow = i;
                initialState.zeroCol = j;
                break;
            }
        }
    }

    queue<PuzzleState> q;
    unordered_set<string> visited;

    q.push(initialState);
    visited.insert(initialState.index);

    while (!q.empty()) {
        PuzzleState currentState = q.front();
        q.pop();

        if (isGoalState(currentState)) {
            return currentState.path;
        }

        vector<PuzzleState> nextStates = generateNextStates(currentState);

        for (const auto& nextState : nextStates) {
            if (visited.find(nextState.index) == visited.end()) {
                q.push(nextState);
                visited.insert(nextState.index);
            }
        }
    }

    return "No solution found.";
}

int main() {
    vector<vector<int>> initialBoard = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            int ip;
            printf("Input the Initial Board Element at Position (%d, %d):", i, j);
            scanf("%d", &ip);
            initialBoard[i][j]=ip;
        }
    }

    printf("The Target Board is:\n");
    vector<vector<int>> goalBoard = {{6, 6, 6}, {6, 0, 6}, {6, 6, 6}};
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            int ip;
            printf(" %d ", goalBoard[i][j]);
        }
        printf("\n");
    }


    printf("The Initial Board is:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            int ip;
            printf(" %d ", initialBoard[i][j]);
        }
        printf("\n");
    }


    printf("Solving...\n\n");
    string solution = solveUpitUp(initialBoard);

    cout << "Solution Steps: " << solution << endl;

    return 0;
}

