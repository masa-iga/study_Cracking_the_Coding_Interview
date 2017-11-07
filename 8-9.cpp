/*
  Question:
    Explain the data structures and algorithm that you would use to design an
    in-memory file system. Illustrate with an example in code where possible.
 
  Approach:
    1. Handle ambiguity
    2. Define core objects
    3. Analyize relationships
    4. Investigate actions
 */
 
 
 
 /*
 
 abstract class Entry {
    # Directory : parent
    # long : created
    # long : lastUpdated
    # long : lastAccessed
    # string : name
    
    Entry(string, Directory)
}

class File {
}

class Directory {
}

Entry <|-- File
Entry <|-- Directory

*/

int Directory::size() {
  int size = 0;
  for (Entry e : contents) {
    size += e.size();
  }
}

int Directory::numberOfFiles() {
  int count = 0;
  for (Entry e : contents) {
    if (e instanceof Directory) {
      count++;
      Directory d = (Directory) e;
      count += d.numberOfFiles();
    } else if (e instanceof File) {
      count++;
    }
  }
  return count;
}

/*
  Alternatively, we could have implemented Directory such that it contains separate list for files and subdirectories.
  This makes the numberOfFiles() method a bit cleaner, since it doesn't need to use the instanceof operator,
  but it does prohitit us from cleanly sorting files and directories by dates or names.
*/
