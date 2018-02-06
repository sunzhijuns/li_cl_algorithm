//
// Created by sunzhijun on 18-2-6.
//

#ifndef SUANFA_FILEOPS_H
#define SUANFA_FILEOPS_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

namespace FileOps{
    int FirstCharacterIndex(const std::string& s, int start){
        for (int i = start; i < s.length(); ++i) {
            if(isalpha(s[i])){
                return i;
            }
        }
        return s.length();
    }

    std::string Lower(const std::string s){
        std::string ret = "";
        for (int i = 0; i < s.length(); ++i) {
            ret += tolower(s[i]);
        }
        return ret;
    }

    bool ReadFile(const std::string filename, std::vector<std::string> & words){
        std::string line;
        std::string contents = "";
        std::ifstream file(filename);
        if(file.is_open()){
            while(std::getline(file,line)){
                contents += (line + "\n");
            }
            file.close();
        }
        else{
            std::cout<<"Can not open "<<filename<<" !!"<<std::endl;
            return false;
        }

        int start = FirstCharacterIndex(contents, 0);
        for (int i = start + 1; i <= contents.length();) {
            if(i == contents.length() || !isalpha(contents[i])){
                words.push_back(Lower(contents.substr(start,i-start)));
                start = FirstCharacterIndex(contents, i);
                i = start + 1;
            }
            else{
                i++;
            }
        }

        return true;
    }
}

#endif //SUANFA_FILEOPS_H
