/*
  Question:
    Explain how you would design a chat server. In particular, provide detail about the various backend components, classes, and methods. What would be the hardest problem to solve?

  How to approach:
    1. Handle ambiguity
    2. Define core classes
    3. Analyize relashinships
    4. Investigate actions
*/

/*
  Let's make assumption like these:
    - Imagine Skype
    -- Need a client software
    -- Login via account
    -- Friend/contact list
    -- Suppots not only one-on-one chat (private), but also group chats

  Core classes
    - Server
    - View
    - Controller
*/

/*
  [Answer]
  What specific actions does it need to support?
    - Signing online and offline
    - Add requests (sending, accepting, and rejecting)
    - Updating a status message
    - Creating private and group chats
    - Adding new messages to private and group chats
    
  What are the core components of the system?
    a database, a set of clients, and a set of servers, but we won't include these parts in our OOD here.
    
  What are the key objects and methods?
    a concept of users, conversations, and status messages.
*/
