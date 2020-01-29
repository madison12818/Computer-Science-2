/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2019 Kent State University. All rights reserved.
 *  Spring 2019
 *  Modified by:
 *
 */

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    tree   = new AST(*(actual.tree));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(const std::vector<std::string>& profileName) {
    tree->mainHeader(profileName);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profileName) {
    tree->funcCount(profileName);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

    

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


/////////////////////////////////////////////////////////////////////
// Destructor for AST
//
AST::~AST() {
    //NEED TO IMPLEMENT
    //Recursively traverse tree and delete from bottom up
  if (!child.empty()) {
    for (auto it = child.begin(); it != child.end(); ++it) {
      delete *it;
    }
  }
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //NEED TO IMPLEMENT
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
  if (!actual.child.empty()) {
    for (auto it = actual.child.begin(); it != actual.child.end(); ++it) {
      child.push_back(new AST(*(*it)));
    }
  }
 
  // inputting
  nodeType = actual.nodeType;
  tag = actual.tag;
  closeTag = actual.closeTag;
  text = actual.text;
}


/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& b) {
    //NEED TO IMPLEMENT
    //Swap all the top level childern (pointers to AST)
  AST tmp = b;
  b = *this;
  *this = tmp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for milestone 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//  There are two types of names.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from an AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//
void AST::mainHeader(const std::vector<std::string>& profileName) {

    //NEED TO IMPLEMENT
    //Skip down a couple lines or find main and put it before that.
    //Add #include "profile.hpp"
    //For each file profile name, add a new node with a profile 
    //   declaration "profile foo_cpp("foo.cpp");"

  // ADDING #include "profile.hpp"
  // structure looks like:
  // ------------------------------------------------
  // <cpp:include>
  //    #
  //    <cpp:directive>
  //       include
  //    </cpp:directive>
  //    <cpp:file>
  //       "profile.hpp"
  //    </cpp:file>
  // </cpp:include>

  AST* subtree = new AST(category, "cpp:include");
  subtree->closeTag = "/cpp:include";

  AST* whitespace5 = new AST(whitespace, "\n");
  subtree->child.push_back(whitespace5);

  AST* token1 = new AST(token, "#");
  subtree->child.push_back(token1);

  AST* subsubtree1 = new AST(category, "cpp:directive");
  subsubtree1->closeTag = "/cpp:directive";

  AST* token2 = new AST(token, "include");
  subsubtree1->child.push_back(token2);
  subtree->child.push_back(subsubtree1);

  AST* whitespace1 = new AST(whitespace, " ");
  subtree->child.push_back(whitespace1);

  AST* subsubtree2 = new AST(category, "cpp:file");
  subsubtree2->closeTag = "/cpp:file";

  AST* token3 = new AST(token, "\"profile.hpp\"");
  subsubtree2->child.push_back(token3);
  subtree->child.push_back(subsubtree2);

  AST* whitespace2 = new AST(whitespace, "\n");
  subtree->child.push_back(whitespace2);

  // find the first function and place it right before
  auto placement = child.begin();
  while ((*placement)->tag != "function") {
     ++placement;
  }
  --placement;

  child.insert(placement, subtree);

  // ADDING profile foo_cpp("foo.cpp");
  // structure looks like:
  // ------------------------------------------------
  // <decl_stmt>
  //    <decl>
  //       <type>
  //          <name>
  //             profile
  //          </name>
  //       </type>
  //       <name>
  //          profileName[i]
  //       </name>
  //       <constructor>
  //          <argument_list>
  //             (
  //             <argument>
  //                <expr>
  //                   <name>
  //                      profileName[i] (need to change _ for .)
  //                   </name>
  //                </expr>
  //             </argument>
  //             )
  //          </argument_list>
  //       </constructor>
  //    </decl>
  //    ;
  // </decl_stmt>
  int size =  profileName.size();
  for (int i = 0; i != size; ++i) {

      AST* subtree2 = new AST(category, "decl_stmt");
      subtree2->closeTag = "/decl_stmt";
      
      AST* subsubtree3 = new AST(category, "decl");
      subsubtree3->closeTag = "/decl";
      
      AST* subsubsubtree1 = new AST(category, "type");
      subsubsubtree1->closeTag = "/tag";
      
      AST* subsubsubsubtree1 = new AST(category, "name");
      subsubsubtree1->closeTag = "/name";
      
      AST* token4 = new AST(token, "profile");
      subsubsubsubtree1->child.push_back(token4);
      subsubsubtree1->child.push_back(subsubsubsubtree1);
      subsubtree3->child.push_back(subsubsubtree1);
      
      AST* whitespace3 = new AST(whitespace, " ");
      subsubtree3->child.push_back(whitespace3);
      
      AST* subsubsubtree2 = new AST(category, "name");
      subsubsubtree2->closeTag = "\name";
      
      AST* token5 = new AST(token, profileName[i]);
      subsubsubtree2->child.push_back(token5);
      subsubtree3->child.push_back(subsubsubtree2);
      
      AST* subsubsubtree3 = new AST(category, "constructor");
      subsubsubtree3->closeTag = "/constructor";
      
      AST* subsubsubsubtree2 = new AST(category, "argument_list");
      subsubsubsubtree2->closeTag = "/argument_list";
      
      AST* token6 = new AST(token, "(");
      subsubsubsubtree2->child.push_back(token6);
      
      AST* subsubsubsubsubtree1 = new AST(category, "argument");
      subsubsubsubsubtree1->closeTag = "/argument";
      
      AST* subsubsubsubsubsubtree1 = new AST(category, "expr");
      subsubsubsubsubsubtree1->closeTag = "/expr";
      
      AST* subsubsubsubsubsubsubtree1 = new AST(category, "name");
      subsubsubsubsubsubsubtree1->closeTag = "/name";
      
      // changing foo_cpp to foo.cpp
      std::string tmp = profileName[i];
      tmp.replace(profileName[i].find("_"), 1, ".");
      AST* token7 = new AST(token, std::string("\"") + tmp + std::string("\""));
      subsubsubsubsubsubsubtree1->child.push_back(token7);
      subsubsubsubsubsubtree1->child.push_back(subsubsubsubsubsubsubtree1);
      subsubsubsubsubtree1->child.push_back(subsubsubsubsubsubtree1);
      subsubsubsubtree2->child.push_back(subsubsubsubsubtree1);
      
      AST* token8 = new AST(token, ")");
      subsubsubsubtree2->child.push_back(token8);
      subsubsubtree3->child.push_back(subsubsubsubtree2);
      subsubtree3->child.push_back(subsubsubtree3);
      subtree2->child.push_back(subsubtree3);

      AST* token9 = new AST(token, ";");
      subtree2->child.push_back(token9);

      AST* whitespace4 = new AST(whitespace, "\n");
      subtree2->child.push_back(whitespace4);

      // find the first function and place it right before
      placement = child.begin();
      while ((*placement)->tag != "function") {
 	 ++placement;
      }
      --placement;

      child.insert(placement, subtree2);
    }
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {

    //NEED TO IMPLEMENT
    //Skip down a couple lines or find first function and put it before that.
    //Add #include "profile.hpp"
    //Add in the external declaration for that file "extern profile foo_cpp;"
  
  // ADDING #include "profile.hpp"
  // structure looks like:
  // ------------------------------------------------
  // <cpp:include>
  //    #
  //    <cpp:directive>
  //       include
  //    </cpp:directive>
  //    <cpp:file>
  //       "profile.hpp"
  //    </cpp:file>
  // </cpp:include>

  AST* subtree = new AST(category, "cpp:include");
  subtree->closeTag = "/cpp:include";

  AST* whitespace1 = new AST(whitespace, "\n");
  subtree->child.push_back(whitespace1);

  AST* token1 = new AST(token, "#");
  subtree->child.push_back(token1);

  AST* subsubtree1 = new AST(category, "cpp:directive");
  subsubtree1->closeTag = "/cpp:directive";

  AST* token2 = new AST(token, "include");
  subsubtree1->child.push_back(token2);
  subtree->child.push_back(subsubtree1);

  AST* whitespace2 = new AST(whitespace, " ");
  subtree->child.push_back(whitespace2);

  AST* subsubtree2 = new AST(category, "cpp:file");
  subsubtree2->closeTag = "/cpp:file";

  AST* token3 = new AST(token, "\"profile.hpp\"");
  subsubtree2->child.push_back(token3);
  subtree->child.push_back(subsubtree2);

  AST* whitespace3 = new AST(whitespace, "\n");
  subtree->child.push_back(whitespace3);

  // find the first function and place it right before
  auto placement = child.begin();
  while ((*placement)->tag != "function") {
     ++placement;
  }
  --placement;

  child.insert(placement, subtree);

  // ADDING extern profile foo_cpp;
  // structure looks like:
  // ------------------------------------------------
  // <decl_stmt>
  //    <decl>
  //       <specifier>
  //          extern
  //       </specifier> 
  //       <type>
  //          <name>
  //             profile
  //          </name>
  //       </type> 
  //       <name>
  //          profileName
  //       </name>
  //    </decl>
  //    ;
  // </decl_stmt>

  AST* subtree2 = new AST(category, "decl_stmt");
  subtree2->closeTag = "/decl_stmt";

  AST* subsubtree3 = new AST(category, "decl");
  subsubtree3->closeTag = "/decl";

  AST* subsubsubtree1 = new AST(category, "specifier");
  subsubsubtree1->closeTag = "/specifier";

  AST* token4 = new AST(token, "extern");
  subsubsubtree1->child.push_back(token4);
  subsubtree3->child.push_back(subsubsubtree1);

  AST* whitespace4 = new AST(whitespace, " ");
  subsubtree3->child.push_back(whitespace4);

  AST* subsubsubtree2 = new AST(category, "type");
  subsubsubtree2->closeTag = "/type";

  AST* subsubsubsubtree1 = new AST(category, "name");
  subsubsubsubtree1->closeTag = "/name";

  AST* token5 = new AST(token, "profile");
  subsubsubsubtree1->child.push_back(token5);
  subsubsubtree2->child.push_back(subsubsubsubtree1);
  subsubtree3->child.push_back(subsubsubtree2);

  AST* whitespace5 = new AST(whitespace, " ");
  subsubtree3->child.push_back(whitespace5);

  AST* subsubsubtree3 = new AST(category, "name");
  subsubsubtree3->closeTag = "/name";

  AST* token6 = new AST(token, profileName);
  subsubsubtree3->child.push_back(token6);
  subsubtree3->child.push_back(subsubsubtree3);
  subtree2->child.push_back(subsubtree3);
  
  AST* token7 = new AST(token, ";");
  subtree2->child.push_back(token7);

  AST* whitespace6 = new AST(whitespace, "\n");
  subtree2->child.push_back(whitespace6);

  // find the first function and place it right before
  placement = child.begin();
  while ((*placement)->tag != "function") {
     ++placement;
  }
  --placement;

  child.insert(placement, subtree2);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(const std::vector<std::string>& profileName) {
    
    //NEED TO IMPLEMENT
    
    //Find the main - function with name of "main"
    //Then start from the end() of this function and iterate
    // backwards until you find a return stmt.   You'll want
    // to insert the report statements before this return.
    
  // finding where to insert the lines
  // setting up tags to traverse tree to find main function
  std::vector<std::string> tagsToFindMain = 
    {"function", "name", "main"};

  // finding main
  std::vector<std::list<AST*>::iterator> startingPositions
    (tagsToFindMain.size());
  std::vector<AST*> parents
    (tagsToFindMain.size() - 1, nullptr);

  AST* current = this;
  int i = 0;
  startingPositions[i] = current->child.begin();
  do {

      bool found = false;
      for (auto it = startingPositions[i]; 
	   it != current->child.end() && !found; ++it) {

	  if ((*it)->tag == tagsToFindMain[i]) {

	      found = true;
	      parents[i] = current;
	      current = *it;
	      ++i; 
	      
	      // storing starting positions
	      ++it;
	      startingPositions[i - 1] = it;
	      startingPositions[i] = current->child.begin();
	    }

	  else if ((*it)->text == tagsToFindMain.back()) {

	      found = true;
	      parents[i] = current;
	      current = *it;
	      ++i;
	    }
	}
      
      // if it wasn't found then go back to the previous
      // level of tree and search from starting point
      if (!found && i != 0) {

	  --i;
	  current = parents[i];
	}

    } while (current->text != tagsToFindMain.back());
  // parent now contains the AST to find the block return is in

  // find block
  current = parents[i - 2];
  bool found = false;
  for (auto it = current->child.begin(); it != current->child.end() && !found; ++it) {

    if ((*it)->tag == "block") {

	found = true;
	current = *it;
    }
  }
  
  // find return
  auto it = --(current->child.end());
  for (; it != current->child.begin() && !found; --it) {
   
    if ((*it)->tag == "return") {
      found = true; 
    }

  }
  // *it now holds the position of return
 
  // ADDING std::cout << profileName[i] << std::endl;
  // structure looks like:
  // ------------------------------------------------
  // <expr_stmt>
  //    <expr>
  //       <name>
  //          std::cout << profileName[i] << std::endl
  //       </name>
  //    </expr>
  //    ;
  // </expr_stmt>

  --it; --it;
  int size = profileName.size();
  for (int j = 0; j != size; ++j) {

      AST* subtree = new AST(category, "decl_stmt");
      subtree->closeTag = "/decl_stmt";

      AST* subsubtree = new AST(category, "expr");
      subsubtree->closeTag = "/expr";

      AST* subsubsubtree = new AST(category, "name");
      subsubsubtree->closeTag = "/name";

      AST* token1 = new AST(token, std::string("std::cout << ") + 
			    profileName[j] + std::string(" << std::endl"));
      subsubsubtree->child.push_back(token1);
      subsubtree->child.push_back(subsubsubtree);
      subtree->child.push_back(subsubtree);

      AST* token2 = new AST(token, ";");
      subtree->child.push_back(token2);

      AST* whitespace2 = new AST(whitespace, "\n");

      // now that the statement is made, insert it
      current->child.insert(it, subtree);
      current->child.insert(it, whitespace2);
    } 
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//
void AST::funcCount(const std::string& profileName) {
    
    //NEED TO IMPLEMENT
    
    // for all children
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find block and insert count as first line in block
    //

  for (auto it = child.begin(); it != child.end(); ++it) {

      if ((*it)->tag == "function" || (*it)->tag == "constuctor" || (*it)->tag == "destructor") {

	  AST* subtree = *it;

	  // iterate forward to find "name"
	  bool found = false;
	  auto it2 = subtree->child.begin();
	  for (; it2 != subtree->child.end() && !found; ++it2) {
	    if ((*it2)->tag == "name") {
	      found = true;
	    }
	  }
	  --it2;

	  std::string funcName = (*it2)->getName();

	  // iterate forward again to find "block"
	  found = false;
	  for (; it2 != subtree->child.end() && !found; ++it2) {
            if ((*it2)->tag == "block") {
              found = true;
	    }
	  }

	  AST* block = *(--it2);
	  
	  // ADDING profileName.count(__LINE__, funcName);
	  AST* subtree2 = new AST(category, "decl_stmt");
	  subtree2->closeTag = "/decl_stmt";

	  AST* token1 = new AST(token, profileName +
			       std::string(".count(__LINE__, \"") +
			       funcName + std::string("\");"));
	  subtree2->child.push_back(token1);

	  block->child.insert(++(block->child.begin()), subtree2); 
	}
    }
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//
void AST::lineCount(const std::string& profileName) {
    
    //NEED TO IMPLEMENT
    
    // Recursively check for expr_stmt within all blocks
    // The basis is when isStopTag is true.
    
  for (auto it = child.begin(); it != child.end(); ++it) {

      if ((*it)->tag == "expr_stmt") {

	  // ADDING profileName.count(__LINE__);
          AST* subtree1 = new AST(category, "expr_stmt");
          subtree1->closeTag = "/expr_stmt";

          AST* token1 = new AST(token, profileName +
				std::string(".count(__LINE__ );"));
          subtree1->child.push_back(token1);

	  child.insert(++it, subtree1);
      }

      // recursively go through all lines
      if (!isStopTag((*it)->tag)) {
	(*it)->lineCount(profileName);
      }

  }
}

/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an AST 
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
       
      switch ((*i)->nodeType) {
            case category:
                (*i)->print(out);
                break;
            case token:
                out << (*i)->text;
                break;
            case whitespace:
                out << (*i)->text;
                break;
        }
    }
    return out;
}

    

/////////////////////////////////////////////////////////////////////
// Utilities
//


/////////////////////////////////////////////////////////////////////
// This returns true if a syntactic category is encountered that
//  will not be profiled.
//
// This is IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}


/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

