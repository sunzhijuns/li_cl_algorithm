#include <string>
#include <vector>
#include "FileOps.h"
#include "BST.h"
#include "SequenceST.h"

int main(){

    std::string filename = "bible.txt";
    std::vector<std::string> words;
    if(FileOps::ReadFile(filename, words)){
        std::cout << "There are totally "
                  <<words.size()
                  <<" words in "
                  <<filename
                  <<std::endl;
        std::cout << std::endl;
        {
            time_t start_time = clock();
            BST<std::string,int> bst = BST<std::string, int>();
            for (std::vector<std::string>::iterator iterator = words.begin();
                 iterator!= words.end() ; iterator++) {

//                std::cout<<*iterator << "--"<<std::endl;
                int *res = bst.Search(*iterator);
                if(res == NULL){
                    bst.Insert(*iterator,1);
                }
                else{
                    (*res)++;
                }
            }

            if(bst.Contain("god")){
                std::cout<<"'god' : "<<*bst.Search("god")<<std::endl;
            }
            else{
                std::cout<<"No word 'god' in "<<filename<<std::endl;
            }
            time_t end_time = clock();
            std::cout<<"BST, time: "<<double(end_time - start_time)/CLOCKS_PER_SEC<<" s."<<std::endl;
            std::cout<<std::endl;
        }
        {
            time_t start_time = clock();
            SequenceST<std::string,int> sst = SequenceST<std::string, int>();
            for (std::vector<std::string>::iterator iterator = words.begin();
                 iterator!= words.end() ; iterator++) {
                int *res = sst.Search(*iterator);
                if(res == NULL){
                    sst.Insert(*iterator,1);
                }
                else{
                    (*res)++;
                }
            }

            if(sst.Contain("god")){
                std::cout<<"'god' : "<<*sst.Search("god")<<std::endl;
            }
            else{
                std::cout<<"No word 'god' in "<<filename<<std::endl;
            }
            time_t end_time = clock();
            std::cout<<"SST, time: "<<double(end_time - start_time)/CLOCKS_PER_SEC<<" s."<<std::endl;
            std::cout<<std::endl;
        }
    }
    return 0;
}

