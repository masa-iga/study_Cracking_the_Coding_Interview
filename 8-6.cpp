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

@startuml

class JigsawPuzzle {
    - Piece[][] pieces
    - const uint32_t numOfWidth
    - const uint32_t numOfHeight
    
    + bool fitsWith(Piece* a, Piece* b)
    + void generatePuzzle()
}

class Piece {
    - Point correctPos
    - Edge leftEdge
    - Edge upperEdge
    - Edge rightEdge
    - Edge lowerEdge
    - Texture texture
    - Point currentPos
    - int currentAngle
    - bool fitted
    
    + Piece(Point correctPos, Edge l, Edge u, Edge r, Edge l)
    + bool setTexture(Texture tex)
    + bool setCurrentPos(Point p)
    + bool setAngle(int angle)
    + bool isFitted()
}

enum Edge {
    dint, convex, edge
}

JigsawPuzzle *-- Piece

@enduml

*/

int main() {
  JigsawPuzzle puzzle;
  puzzle.generate();
  if (fitsWith(a, b))
    // TODO fitsWithの引数を足すべきか？ pos1, pos2を足してもいいが、そもそもこの関数は二つのピースがハマるか、どうかを確認するだけなので不適当か？
  return 0;
}
