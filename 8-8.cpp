/*
  Question:
    Othello is played as follows: Each Othello piece is white on one side and black on the
    other. When a piece is surrounded by its opponents on both the left and right sides,
    or both the top and bottom, it is said to be captured and its color is flipped. On your
    turn, you must capture at least one of your opponent's pieces. The game ends when
    either user has no more valid moves. The win is assigned to the person with the most
    pieces. Implement the object-oriented design for Othello.
  
  How to approach:
    1. Handle ambiguity
    2. Define core objects
    3. Analyize relationships
    4. Investigate actions
*/



/*
  1. Ambiguity
    - How many pieces?
    - Which one is taking the first turn?
    - 
  
  2. Core objects
    - Othello
      - Pieces
        - Piece
      - Points
        - Point
  
  4. Actions
    - find if there are valid moves or not
    - Place a piece at a point
    - Flip a piece which is surrounded by the opponent
    - Turn to the opponent
    - If the game ends, count valid pieces
*/



/*
class Game {
    Board : board
    State : currentTurn
    
    void : initialize()
    void : processInput(Player)
}

class Board {
    map<Point, Piece> : pieces
    
    bool : haveValidMove(State)
    void : place(Piece, Point)
}

class Piece {
    State : state
    
    void : flip()
}

class Point {
    Point(int x, int y)
    
    int : x
    int : y
}

Enum State {
    White, Black
}

Game *-- Board
Board o-- "*" Piece
Board *-- "*" Point
*/



/*
Points to be discussed with an interviewer:

  Should BlackPiece and WhitePiece be classes?
    Each piece may flip back and force between colors frequently, so continuously destroying and creating
    what is really the same object is propably not wise. It may be better to just
    have a Piece class, with a flag in it representing the current color.

  Do we need separate Board and Game classes?
    Keeping the objects separate allows us to have a logical separation between the board and the game.
    However, the drawback is that we are adding extra layers to our program.
    A function may call out to a method in Game, only to have it immediately call Board.
  
  Who keeps score?
    We should propably have some sort of score keeping for the number of black and white pieces.
    We have implemented this with Board holding this information, since it can be logically grouped with the board.
  
  Should Game be a Singleton class?
    Implementing Game as a singleton class have the advantage of making it easy for anyone to call a method within Game,
    without haveing to pass around references to the Game object.
    Making Game a singleton, though, means that it can only be instantiated once.
  
*/



/*
Enum Direction {
    left, right, up, down
}

Enum Color {
    White, Black
}

class Game {
    Player[] players
    {static} Game instance
    Board board
    
    Game()
    {static} Game getInstance()
    Board getBoard()
}

class Board {
    Piece[][] : board
    int : blackCount
    int : whiteCount
    
    Board(int rows, int columns)
    void : initialize()
    bool : placeColor(int row, int column, Color color)
    - int : flipSection(int row, int column, Color color, Direction d)
    int : getScoreForColor(Color c)
    void : updateScore(Color newColor, int newPieces) 
}

class Piece {
    Color : color
    
    void : flip()
    Color : getColor()
}

class Player {
    Color color
    
    Player(Color)
    int : getScore()
    bool playPiece(int r, int c)
    Color : getColor()
}

Game *-- Board
Game *-- "*" Player
Board *-- "*" Piece
*/



bool Player::playPiece(int r, int c) {
  return Game.getInstance().getBoard.playColor(r, c, color);
}
