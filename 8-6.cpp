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
  if (fitsWith(a, b))
    // TODO fitsWithの引数を足すべきか？ pos1, pos2を足してもいいが、そもそもこの関数は二つのピースがハマるか、どうかを確認するだけなので不適当か？
  return 0;
}
