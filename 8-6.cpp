/*
  Question:
    Implement a jigsaw puzzle. Design the data structures and explain an algorithm to solve the puzzle.
    You can assume that you have a fitsWith method which, when passed two puzzle pieces,
    returns true if the two pieces belong together.
*/

/*
  How to approach:
    1. Handle ambiguity
    2. Define core objects
    3. Analyze relationships
    4. Investigate actions
*/

/*

class JigsawPuzzle {
    - Piece *pPiece
    - uint32_t numOfPieces
    - uint32_t numOfWidth
    - uint32_t numOfHeight
    
    + JigsawPuzzle(int num)
    + bool fitsWith(Piece* a, Piece* b)
    + void generatePuzzle()
}

class Piece {
    - Edges edges
    - Point correctPos
    - Texture texture
    - Point currentPos
    - int currentAngle
    - bool fitted
    
    + Piece(Point correctPos, Edges edges)
    + bool setTexture(Texture tex)
    + bool setCurrentPos(Point p)
    + bool setAngle(int angle)
    + bool isFitted()
}

class Edges {
    - Edge left
    - Edge uppder
    - Edge right
    - Edge lower
    
    + Edges(Edge l, Edge u, Edge r, Edge l)
}

enum Edge {
    dint, convex, edge
}

JigsawPuzzle *-- Piece
Piece *-- Edges

*/

int main() {
  JigsawPuzzle puzzle;
  puzzle.generate();
  solve(puzzle);
  return 0;
}

void solve(JigsawPuzzle puzzle) {
  if (puzzle == NULL)
    return ;
  
  findLeftUpperCorner(puzzle.getPieces())
  Piece* leftUpperCorner = findPieceAt(0, 0); // TODO: Puzzle class内でのxy座標と正解のxy座標をどうやって表現するか
  if (leftUpperCorner == NULL) {
    ASSERT();
    return;
  }
  leftUpperCorner.setFitted(TRUE);
  
  for (uint32_t i=0; i < puzzle.numOfPiece(); i++) {
    onePiece = puzzle.getUnfittedPiece(i);
    if (fitsWith(leftUpperCorner, onePiece)) {
      ;
    }
  }
}
