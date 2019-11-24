// Generated by Bisonc++ V6.01.00 on Wed, 13 Nov 2019 10:25:59 +0300

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "Parserbase.h"
// $insert scanner.h
#include "Scanner.h"
#include <map>

#undef Parser
    // CAVEAT: between the baseclass-include directive and the 
    // #undef directive in the previous line references to Parser 
    // are read as ParserBase.
    // If you need to include additional headers in this file 
    // you should do so after these comment-lines.


class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner& d_scanner;
        
    public:
        unsigned stringCounter = 0;
        std::map<std::string, unsigned> stringsMap;
        std::map<std::string, long long int> consts;
        std::ostream& out;

        Parser(Scanner& d_scanner, std::ostream& out);
        int parse();
        void writeFooter();        

    private:
        void error();                   // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc
        void exceptionHandler(std::exception const &exc);

    // support functions for parse():
        void executeAction__(int ruleNr);
        void errorRecovery__();
        void nextCycle__();
        void nextToken__();
        void print__();
        void nextLine(unsigned lineNr, const std::string &lineText);
        unsigned allocString(const std::string& str);

        long long int lc = 0;
        unsigned hack_else = 0;
};


#endif
