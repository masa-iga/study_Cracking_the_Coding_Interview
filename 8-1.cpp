/*
                         ,----------------------.                                     
   ,------------------.  |Deck                  |   ,--------------------------------.
   |BlackJackCard     |  |----------------------|   |BlackJackHand                   |
   |------------------|  |-ArrayList<T> cards   |   |--------------------------------|
   |------------------|  |-int dealtIndex       |   |--------------------------------|
   |+int value()      |  |----------------------|   |+int score()                    |
   |+int minValue()   |  |+void setDeckOfCards()|   |-ArrayList<int> possibleScores()|
   |+int maxValue()   |  |+void shuffle()       |   |+bool busted()                  |
   |+bool isAce()     |  |+int remainingCards() |   |+bool is21()                    |
   |+bool isFaceCard()|  |+T[] dealHand()       |   |+bool isBlackJack()             |
   `------------------'  |+T dealCard()         |   `--------------------------------'
             |           `----------------------'                    |                
             |                                                       |                
             |                                                       |                
,-----------------------.                                            |                
|Card                   |                                            |                
|-----------------------|                                  ,-------------------.      
|-bool available        |                                  |Hand               |      
|#int faceValue         |                                  |-------------------|      
|#Suit suit             |                                  |#ArrayList<T> cards|      
|-----------------------|                                  |-------------------|      
|+int value()           |                                  |+int score()       |      
|+Suit suit()           |                                  |+void addCard()    |      
|+bool isAvailable()    |                                  `-------------------'      
|+void markUnavailable()|                                                             
|+void markAvailable()  |                                                             
`-----------------------'                                                             
             |                                                                        
,------------------------.                                                            
|Suit                    |                                                            
|------------------------|                                                            
|Club                    |                                                            
|Diamond                 |                                                            
|Heart                   |                                                            
|Spade                   |                                                            
|--                      |                                                            
|-int value              |                                                            
|--                      |                                                            
|------------------------|                                                            
|+int getValue()         |                                                            
|+Suit getSuitFromValue()|                                                            
`------------------------'   

/////////////////////////////////////////////////////////////////////
Go to https://www.planttext.com/ to visualize as class diagram

@startuml
enum Suit {
    Club
    Diamond
    Heart
    Spade
--
    - int value
--
    + int getValue()
    + {static} Suit getSuitFromValue()
}

Card *-- Suit
class Card {
    - bool available
    # int faceValue
    # Suit suit
    + {abstract} int value()
    + Suit suit()
    + bool isAvailable()
    + void markUnavailable()
    + void markAvailable()
}

class Deck < T extends Card > {
    - ArrayList<T> cards
    - int dealtIndex
    + void setDeckOfCards()
    + void shuffle()
    + int remainingCards()
    + T[] dealHand()
    + T dealCard()
}

BlackJackCard --|> Card
class BlackJackCard {
    + int value()
    + int minValue()
    + int maxValue()
    + bool isAce()
    + bool isFaceCard()
}

class Hand < T extends Card > {
    # ArrayList<T> cards
    + int score()
    + void addCard()
}

BlackJackHand --|> Hand
class BlackJackHand < BlackJackCard > {
    + int score()
    - ArrayList<int> possibleScores()
    + bool busted()
    + bool is21()
    + bool isBlackJack()
}
@enduml

*/

