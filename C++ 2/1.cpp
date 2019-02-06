#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
void set_random_seed();
int randn(int n);
struct mm_code_maker{
    void init(int i_length, int i_num){
        length = i_length;
        num = i_num;
    }
    void generate_sequence(){
        for(int i = 0; i < length; i++){
            sequence.push_back(randn(num));
        }
    }
    void give_feedback(const std::vector<int>& attempt, int& black_hits, int& white_hits){
        white_hits=0;//initialize
        black_hits=0;
        int total=0, min=0;
        for(int i=0; i<sequence.size(); i++){
            if(attempt[i]==sequence[i]){
                black_hits++;
            }
        }
        for(int i=0; i<num; i++){
            int n=0, m=0;
            for(int j=0; j<length; j++){
                if(i==sequence[j]){
                    n++;
                }
                if(i==attempt[j]){
                    m++;
                }
            }
            if(n<=m){
                min=n;
            }
            else{
                min=m;
            }
            total = total+min;
        }

        white_hits=total-black_hits;
    }
    /*void give_feedback(const std::vector<int>& attempt, int& black_hits, int& white_hits){
        black_hits=0;
        white_hits=0;
        std::vector<int>vt;
        std::vector<int>va;
        std::vector<int>va1;
        for(int i=0; i<sequence.size();i++){
            if(sequence[i]==attempt[i]){
                black_hits++;
            }
            else{
                vt.push_back(sequence[i]);
                va1.push_back(attempt[i]);
                va.push_back(attempt[i]);
            }
        }
        int p=va.size();
        for (int i=0; i<vt.size(); i++) {
            for (int k=0; k<p; k++) {
                if (vt[i]==va[k]){
                    int o=k;
                    va.clear();
                    for (int m=0; m<o; m++) {
                        va.push_back(va1[m]);
                    }
                    for (int m=o+1; m<va1.size(); m++) {
                        va.push_back(va1[m]);
                    }
                    std::cout<<std::endl;
                    white_hits++;
                    k=p;
                    va1.clear();
                    for (int t=0; t<va.size(); t++) {
                        va1.push_back(va[t]);
                    }
                }
            }
        }
    }*/
    std::vector<int> sequence;
    int length;
    int num;
};
struct mm_solver{
    void init(int i_length, int i_num){
        length = i_length;
        num = i_num;
    }
    void give_feedback1(const std::vector<int>& attempt,std::vector<int>store, int& black_hits, int& white_hits){
        white_hits=0;//initialize
        black_hits=0;
        int total=0, min=0;
        for(int i=0; i<store.size(); i++){
            if(attempt[i]==store[i]){
                black_hits++;
            }
        }
        for(int i=0; i<num; i++){
            int n=0, m=0;
            for(int j=0; j<length; j++){
                if(i==store[j]){
                    n++;
                }
                if(i==attempt[j]){
                    m++;
                }
            }
            if(n<=m){
                min=n;
            }
            else{
                min=m;
            }
            total = total+min;
        }
        white_hits=total-black_hits;
    }
    /*void give_feedback1(const std::vector<int>& attempt, std::vector<int>store,int& black_hits, int& white_hits,int k1){
        black_hits=0;
        white_hits=0;
        std::vector<int>vt;
        std::vector<int>va;
        std::vector<int>va1;
        for(int i=0; i<store[i].size();i++){
            if(store[k1][i]==attempt[i]){
                black_hits++;
            }
            else{
                vt.push_back(store[k1][i]);
                va1.push_back(attempt[i]);
                va.push_back(attempt[i]);
            }
        }
        int p=va.size();
        for (int i=0; i<vt.size(); i++) {
            for (int k=0; k<p; k++) {
                if (vt[i]==va[k]){
                    int o=k;
                    va.clear();
                    for (int m=0; m<o; m++) {
                        va.push_back(va1[m]);
                    }
                    for (int m=o+1; m<va1.size(); m++) {
                        va.push_back(va1[m]);
                    }
                    std::cout<<std::endl;
                    white_hits++;
                    k=p;
                    va1.clear();
                    for (int t=0; t<va.size(); t++) {
                        va1.push_back(va[t]);
                    }
                }
            }
        }
    }*/
    void create_attempt(std::vector<int>& attempt){
        bool ready = false;
        while(!ready){
            for(int i = 0; i < length; i++){
                attempt.push_back(randn(num));
            }
            bool found = false;
            for(int i = 0; i < not_correct.size()&& !found; i++){
                if(attempt == not_correct[i]){
                    found = true;
                }
            }
            if(found){
                attempt.clear();
            }
            else{
                ready = true;
            }
        }
    }
    void learn(std::vector<int>& attempt, int black_hits, int white_hits){
        int b=0;
        int w=0;
        int n=0;
        int b1=0;
        int w1=0;
        std::vector<int>v1;
        for(int k=0;k<store.size();k++)
        {
            int n=0;
            for(int i=0;i<length;i++)
            {
                if(store[k][i]==attempt[i])
                {
                    n=n;
                }
                else
                {
                    n++;
                }
            }
            if(n==length)
            {
                k=store.size();
            }
        }
        v1.push_back(n);
        for(int i=0;i<store.size();i++){
                give_feedback1(attempt,store[i],b,w);
                if(b!=black_hits)
                {
                    b1=b1;
                }
                if(w!=white_hits){
                    w1=w1;
                }
                else{
                    b1++;
                    w1++;
                }
            }
        attempt.push_back(v1[0]);
        attempt.push_back(b1);
        attempt.push_back(w1);
    }
    void learn2(std::vector<int>& attempt, int black_hits, int white_hits){
         if(black_hits != attempt.size()){
        not_correct.push_back(attempt);
        }
    }
    std::vector<std::vector<int> > not_correct;
    std::vector<std::vector<int> > store;
    void check(int &m ,std::vector<int>v,int i){
        if((v[i]==m)&&(i<v.size())){
            m=randn(length);
            return check(m, v, 0);
        }
        if((v[i]!=m)&&(i<v.size()))
            {
            return check(m, v, i+1);
            }
        else
            {
            m=m;
            }
    }
    int length;
    int num;
};
int main(){
    set_random_seed();
    std::vector<int>b;
    std::vector<int>w;
    std::vector<int>v;
    std::vector<int>tmp;
    int length, num;
    std::cout << "enter length of sequence and number of possible values:" << std::endl;
    std::cin >> length >> num;
    mm_solver solver;
    solver.init(length, num);
    mm_code_maker maker;
    maker.init(length, num);
    maker.generate_sequence();
    int black_hits=0;
    int white_hits=0;
    int attempts_limit = 5000;
    int attempts = 0;
    std::vector<int> attempt;
    while((black_hits < length) && (attempts < attempts_limit))
    {
        if (attempts==0)
        {
            attempt.push_back(0);
            attempt.push_back(0);
            attempt.push_back(1);
            attempt.push_back(1);
        }
        else{
            attempt.clear();
            solver.create_attempt(attempt);
            while (((attempt[length+1]!=length)||(attempt[length+2]!=b.size())||attempt[length+3]!=w.size())||(attempt.size()==length))//这个循环条件是应该为均不满足才能跳出循环 即 当没有找到xiang tong
            {
            solver.create_attempt(attempt);
            for (int l=0; l<b.size(); l++)
                {
                    solver.learn(attempt, b[l], w[l]);
                }
            }
            for (int i=0; i<length; i++)
            {
                tmp.push_back(attempt[i]);
            }
            attempt.clear();
            for (int i=0; i<length; i++)
            {
                attempt.push_back(tmp[i]);
            }
        solver.store.push_back(attempt);
        maker.give_feedback(attempt, black_hits, white_hits);
        solver.learn2(attempt, black_hits, white_hits);
        b.push_back(black_hits);
        w.push_back(white_hits);
        std::cout << "attempt: " << std::endl;
        for(int i = 0; i < attempt.size(); i++){
        std::cout << attempt[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "black hits: " << black_hits << " " << " white hits: " << white_hits << std::endl;
        attempts++;
        }
    }
    if(black_hits == length){
        std::cout << "the solver has found the sequence in " << attempts << " attempts" << std::endl;
    }
    else{
        std::cout << "after " << attempts << " attempts still no solution" << std::endl;
    }
    std::cout << "the sequence generated by the code maker was:" << std::endl;
    for(int i = 0; i < maker.sequence.size(); i++){
        std::cout << maker.sequence[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
void set_random_seed(){
    std::srand(std::time(0));
}
int randn(int n){
    return std::rand() % n;
}
