/*
  Question:
    Othello is played as follows: Each Othello piece is white on one side and black on the
    other. When a piece is surrounded by its opponents on both the left and right sides,
    or both the top and bottom, it is said to be capture and its color is flipped. On your
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
    - Count pieces
*/
