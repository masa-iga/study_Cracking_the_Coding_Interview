/*

Design a musical jukebox using object-oriented principles.

How to approach OOD questions

Handle ambiguity
Define the core objects
Analyze relationships
investigate actions


              ,-----------------------------------------------------------------------------.  
              |Jukebox                                                                      |  
              |-----------------------------------------------------------------------------|  
              |-CDPlayer cdPlayer                                                           |  
              |-User user                                                                   |  
              |-set<CD> cdCollection                                                        |  
              |-SongSelector ts                                                             |  
              |-----------------------------------------------------------------------------|  
              |+Jukebox(CDPlayer cdPlayer, User user, set<CD> cdCollection, SongSelector ts)|  
              |+Song getCurrentSong()                                                       |  
              |+void setUser(User u)                                                        |  
              `-----------------------------------------------------------------------------'  
                                                      |                                        
                                                      |                                        
                  ,-----------------------------.     |   ,-----------------------------------.
                  |CDPlayer                     |     |   |User                               |
                  |-----------------------------|     |   |-----------------------------------|
                  |-Playlist p                  |     |   |-string name                       |
                  |-CD c                        |     |   |-long id                           |
                  |-----------------------------|     |   |-----------------------------------|
                  |+CDPlayer(CD c, Playlist p)  |     |   |+User(string name, long id)        |
                  |+CDPlayer(Playlist p)        |     |   |+string getName()                  |
                  |+CDPlayer(CD c)              |     |   |+void setName(string name)         |
                  |+void playSong(Song s)       |     |   |+long getID()                      |
                  |+Playlist getPlaylist()      |     |   |+void setID(long id)               |
                  |+void setPlaylist(Playlist p)|     |   |+User getUser()                    |
                  |+CD getCD()                  |     |   |+User addUser(String name, long id)|
                  |+void setCD(CD c)            |     |   `-----------------------------------'
                  `-----------------------------'     |                                        
                                                      |                                        
,---------------------------------------.             |                                        
|Playlist                               |  ,-------------------.                               
|---------------------------------------|  |CD                 |                               
|-Song song                             |  |-------------------|                               
|-queue<Song> queue                     |  |-long id           |                               
|---------------------------------------|  |-string artist     |                               
|+Playlist(Song song, queue<Song> queue)|  |-vector<Song> songs|                               
|+Song getNextSToPlay()                 |  |-------------------|                               
|+void queueUpSong(Song s)              |  `-------------------'                               
`---------------------------------------'             |                                        
                                                      |                                        
                                                                                               
                                              ,-------------.                                  
                                              |Song         |                                  
                                              |-------------|                                  
                                              |-long id     |                                  
                                              |-string title|                                  
                                              |-int length  |                                  
                                              |-------------|                                  
                                              `-------------'                                  


@startuml

class Jukebox {
    - CDPlayer cdPlayer
    - User user
    - set<CD> cdCollection
    - SongSelector ts
    + Jukebox(CDPlayer cdPlayer, User user, set<CD> cdCollection, SongSelector ts)
    + Song getCurrentSong()
    + void setUser(User u)
}

Jukebox *-- CDPlayer
class CDPlayer {
    + CDPlayer(CD c, Playlist p)
    + CDPlayer(Playlist p)
    + CDPlayer(CD c)
    - Playlist p
    - CD c
    + void playSong(Song s)
    + Playlist getPlaylist()
    + void setPlaylist(Playlist p)
    + CD getCD()
    + void setCD(CD c)
    
}

CDPlayer *-- Playlist
class Playlist {
    + Playlist(Song song, queue<Song> queue)
    - Song song
    - queue<Song> queue
    + Song getNextSToPlay()
    + void queueUpSong(Song s)
}

Jukebox *-- CD
CDPlayer *-- CD
class CD {
    - long id
    - string artist
    - vector<Song> songs
}

CD *-- Song
class Song {
    - long id
    - string title
    - int length
}

Jukebox *-- User
class User {
    + User(string name, long id)
    - string name
    + string getName()
    + void setName(string name)
    + long getID()
    + void setID(long id)
    - long id
    + User getUser()
    + {static} User addUser(String name, long id)
    
}

@enduml

*/