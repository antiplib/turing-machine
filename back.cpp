#include <string>
#include <vector>
#include <map>
#include "form.h"

std::string alf1;
std::string alf2;
std::string mainsymbols;
std::map <int, std::vector <std::string>> mainmap;
std::map <int, std::vector <std::string>> newmainmap;
std::vector <int> indexs;
std::vector <char> str;
int r = 10;
int l = 0;
int call;
std::string alf;
int turing = 0;

bool addvector(int a, std::vector <std::string> array){
    bool stop = false;
    for(int k = 0; k < array.size(); ++k){
        for(int i = 0; i < array[k].size(); ++i) {
            bool is = false;
            if(array[k][i] != ',' && array[k][i] != ' '){
                for(int j = 0; j < alf1.size(); ++j){
                    if(array[k][i] == alf1[j]){
                        is = true;
                    }
                }
                for(int j = 0; j < alf2.size(); ++j){
                    if(array[k][i] == alf2[j]){
                        is = true;
                    }
                }
                if(array[k][i] == '<' || array[k][i] =='>' || array[k][i] == '/'
                    || array[k][i] == '!' || (array[k][i] - '0' >= 0 && array[k][i]- '0' <= 9)){
                    is = true;

                }
                if(!is){
                    std::string ch;
                    while((array[k][i] != ','  || array[k][i] != ' ')&& i < array[k].size()){
                        ch += array[i];
                        ++i;
                    }
                    int chint = 0;
                    for(int j = 0; j <ch.size(); ++j){
                        chint += ch[j] - '0';
                        chint*=10;
                    }
                    chint /=10;
                    for(int j = 0; j < indexs.size(); ++j){
                        if(indexs[j] == chint){
                            is = true;
                        }
                    }
                }
                if(!is){
                    return 0;
                }
            }
        }
    }
    indexs.push_back(a);
    mainmap[a] = array;
    return 1;
}
