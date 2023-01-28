
#include <iostream>
#include <tuple>
using namespace std;

class TicTacToeGame{
public:
    TicTacToeGame();
    virtual ~TicTacToeGame();
    void play();

private:
    void intializeGrid();
    void displayGrid();
    std::tuple<int, int> findFirstUnoccupiedGridSquare();
    std::tuple<int, int> promptforGridCoord();
    bool checkForDraw();
    bool checkForWin();
private:
    char** grid = nullptr;
};
TicTacToeGame::TicTacToeGame(){
    this->grid = new char*[3];  // array of 3 pointers to char
    for (int Row = 0; Row < 3; Row++){
        grid[Row] = new char[3];  // makes an array for each pointer in the array
        
    }
    intializeGrid();
}
TicTacToeGame::~TicTacToeGame(){
    for (int Row = 0; Row < 3; Row++){
        delete[] grid[Row]; // Deletes each array within the array of pointers
    }
    delete[] grid;  // deletes the array of pointers
    grid = nullptr;
}
void TicTacToeGame::intializeGrid(){ 
    for (int Row = 0; Row < 3; Row++){
        for (int Column = 0; Column < 3; Column++){
            grid[Row][Column] = '~';
        }
    }
}
void TicTacToeGame::displayGrid(){
    for (int Row = 0; Row < 3; Row++){
        for (int Column = 0; Column < 3; Column++){
            cout << grid[Row][Column] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
tuple<int, int>TicTacToeGame::promptforGridCoord(){
    int Row = 0;
    int Column = 0;
    cout << "Please enter grid row number:" << endl;
    cin >> Row;

    cout << "Please enter grid column number: " << endl;
    cin >> Column;
    tuple<int, int> tupleCoord = make_tuple(Row, Column);
    return tupleCoord;
}
tuple<int, int>TicTacToeGame::findFirstUnoccupiedGridSquare(){
    int RowUnoccupied = -1;
    int ColumnUnoccupied = -1;
    bool bFound = false;
    for (int Row = 0; (Row < 3) && !bFound; Row++){
        for (int Column = 0; (Column < 3) && !bFound; Column++){
            if (this->grid[Row][Column] == '~'){
                RowUnoccupied = Row;
                ColumnUnoccupied = Column;
                bFound = true;
            }
        }
    }
    tuple<int, int> tupleUnoccupiedGridSquare(RowUnoccupied, ColumnUnoccupied);
    return tupleUnoccupiedGridSquare;
}
bool TicTacToeGame::checkForDraw(){
    bool bContinue = false;
    for (int Row = 0; Row < 3; Row++){
        for (int Column = 0; Column < 3; Column++){
            if ((this->grid[Row][Column] != 'X') && (this->grid[Row][Column] != 'O')){
                bContinue = true;
            }
        }
    }
    return !bContinue;
}
bool TicTacToeGame::checkForWin(){
    bool bWin = false;

    for (int iRow = 0; (iRow < 3) && !bWin; iRow++){
        if (grid[iRow][0] != '~'){
            if ((grid[iRow][0] == grid[iRow][1]) && (grid[iRow][0] == grid[iRow][2])){
                bWin = true;
                cout << "WINNER: " << grid[iRow][0] << "!" << endl;
            }
        }
    }

    for (int iColumn = 0; (iColumn < 3) && !bWin; iColumn++){
        if (grid[0][iColumn] != '~'){
            if ((grid[0][iColumn] == grid[1][iColumn]) && (grid[0][iColumn] == grid[2][iColumn])){
                bWin = true;
                cout << "WINNER: " << grid[0][iColumn] << "!" << endl;
            }
        }
    }

    if (grid[0][0] != '~'){ // check for three in left-to-right diagonal{
        if ((grid[0][0] == grid[1][1]) && (grid[0][0] == grid[2][2])){
            bWin = true;
            cout << "WINNER: " << grid[0][0] << "!" << endl;
        }
    }

    if (grid[0][2] != '~'){ // check for three in right-to-left diagonal{
        if ((grid[0][2] == grid[1][1]) && (grid[0][2] == grid[2][0])){
            bWin = true;
            cout << "WINNER: " << grid[0][2] << "!" << endl;
        }
    }

    return bWin;
}



void TicTacToeGame::play(){
    bool bWin = false;
    bool bDraw = false;
    int Row = 0;
    int Column = 0;

    cout << "Tic Tac Toe" << endl;
    cout << endl;
    displayGrid();

    while (!bWin && !bDraw){
        // Human Player Turn
        tie(Row, Column) = promptforGridCoord();
        grid[Row][Column] = 'X';

        displayGrid();
        bWin = checkForWin();
        bDraw = checkForDraw();
        // Computer Player Turn
        if (!bWin and !bDraw){
            tie(Row, Column) = findFirstUnoccupiedGridSquare();
            grid[Row][Column] = 'O';
            displayGrid();
            bWin = checkForWin();
            bDraw = checkForDraw();
        }
        if (bDraw && !bWin){
            cout << "Draw! " << endl;
        }
    }
    cout << "Game over." << endl;
    return;
}


int main(){
    
    
    TicTacToeGame* p_game = new TicTacToeGame();
    p_game->play();
    delete p_game;
    return 0;
}