#pragma once

#include <vector>
#include <string>
#include <map>


extern std::string alf1;
extern std::string alf2;
extern std::string mainsymbols;
extern std::map <int, std::vector <std::string>> mainmap;
extern std::vector <int> indexs;
extern std::vector <char> str;
extern int r;
extern int l;
extern int call;
extern std::string alf;
extern int turing;
extern std::map <int, std::vector <std::string> > newmainmap;

void getalf(std::string, std::string);

bool addvector(int, std::vector <std::string>);

