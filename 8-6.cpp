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

  // Try to solve from outside to inside
  uint32_t numOfPerimeter = puzzle.getNumOfPerimeter();
  for (uint32_t i = 0; i < numOfPerimeter; i++) {
    // Let's take a left-upper corner in the perimeter
    Piece* piece = puzzle.getPieceAt(i, i); // TODO: Puzzle class内でのxy座標と正解のxy座標をどうやって表現するか
    if (piece == NULL) {
      ASSERT(TRUE);
      return;
    }
    puzzle.setAt(i, i, piece);
    piece.setFitted(TRUE);

    const uint32_t width = puzzle.getWidth() - 2*i;
    const uint32_t height = puzzle.getHeight() - 2*i;

    // Walk through upper edge
    for (uint32_t j = i+1; j < width; j++) {
      for (uint32_t k = 0; k < puzzle.numOfPieces(); k++) {
        Piece tryPiece = puzzle.getPieceOf(k);
        if (tryPiece.isFitted())
          continue;
        if (fitsWidh(piece, tryPiece)) {
          puzzle.setAt(j, height);
          tryPiece.setFitted(TRUE);
        }
      }
    }
    
    // Walk through right side edge
    // Walk through bottom edge
    // Walk through left side edge
  }
}

/*

class puzzle {
    Piece[] pieces
    Piece[][] solution

    Edge[] inners
    Edge[] outers
    Edge[] flats
    Piece[] corners
    
    void sort()
    void solve()
}

class Piece {
    Edge[] edges
    bool isCorner()
}

class Edge {
    
}

*/
