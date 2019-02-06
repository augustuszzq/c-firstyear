#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

int count_occurrences(std::vector<std::string>words,std::string w);

int main(){
    std::string textfilename, wordsfilename;
    
    std::cout<<"please enter the names of the input files :"<<std::endl;
    
    std::cin>>textfilename>>wordsfilename;
    std::ifstream infile;
    
    infile.open(textfilename.c_str());
    
    if (!infile.is_open()) {
        std::cout<<"error opening"<<textfilename<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::vector<std::string>words;
    std::string word;
    
    
    while (infile>>word) {
        words.push_back(word);
    }
    
    infile.close();
    
    infile.open(wordsfilename.c_str());
    
    if (!infile.is_open()) {
        std::cout<<"error opening"<<wordsfilename<<std::endl;
        exit(EXIT_FAILURE);
    }

    std::ofstream outfile;
    
    std::string outffilename="out"+wordsfilename;
    
    outfile.open(outffilename.c_str());
    
    if (!outfile.is_open()) {
        std::cout<<"error opening"<<outffilename<<std::endl;
        exit(EXIT_FAILURE);
        
    }

    while (infile>>word) {
        int occ=count_occurrences(words, word);
        
        outfile<<word<< ":"<<occ<<std::endl;
    }
    
    
    
    infile.close();
    outfile.close();
    
    return 0;
}
int count_occurrences(std::vector<std::string>words,std::string w){
    int occurences=0;
    for (int i=0; i<words.size(); i++) {
        if (words[i]==w) {
            occurences++;
        }
    }
    return occurences;
}

