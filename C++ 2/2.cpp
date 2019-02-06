#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
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

    //this part of the code is correct now
    std::vector<int> sequence;

    int length;
    int num;
};
struct mm_solver{
    std::vector<std::vector<int> >useless;
    std::vector<std::vector<int> >all;
    std::vector<std::vector<int> >newall;
    std::vector<int>attempt;
    void allcase(std::vector<int>& attempt){//随机生成一种情况并判断
        bool ready = false;
        while(!ready){
            for(int i = 0; i < length; i++){
                attempt.push_back(randn(num));
            }
            bool found = false;
            for(int i = 0; i < useless.size() && !found; i++){
                if(attempt == useless[i]){
                    found = true;
                }
            }
            if(found){
                attempt.clear();
            }
            else{
                all.push_back(attempt);
                useless.push_back(attempt);
                ready = true;
            }
        }
    }
    void creatallvector(std::vector<int>attempt,long p){//创建所有情况
        while(all.size()!=p){
            attempt.clear();
            allcase(attempt);
        }
    }
    void myfeedback(const std::vector<int>& attempt, const std::vector<int>& real,int& black_hits, int& white_hits){//比较是否为真实的vector
        white_hits=0;
        black_hits=0;
        int total=0, min=0;
        for(int i=0; i<real.size(); i++){
            if(attempt[i]==real[i]){
                black_hits++;
            }
        }
        for(int i=0; i<num; i++){
            int n=0, m=0;
            for(int j=0; j<length; j++){
                if(i==real[j]){
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
    void init(int i_length, int i_num){
        length = i_length;
        num = i_num;
    }
    void create_attempt(std::vector<int>& attempt){
        int n=randn(all.size());
        attempt.clear();
        for(int i=0;i<length;i++){
            attempt.push_back(all[n][i]);
        }
    }
    void learn(std::vector<int>& attempt, int black_hits, int white_hits){//将所有可能的情况归为一个vector；
        long p=pow(num,length);//确定p的值
        creatallvector(attempt, p);//建立所有情况
        for(int k=0;k<all.size();k++){
            int b=0;
            int w=0;
            myfeedback(all[k], attempt, b, w);
            if((b==black_hits)&&(w==white_hits)){
                newall.push_back(all[k]);
            }
        }//建立新的 newall
        all.clear();
        for(int i=0;i<newall.size();i++){
            all.push_back(newall[i]);
        }
        newall.clear();
        //if(black_hits != attempt.size()){
        //  not_correct.push_back(attempt);
        //}
    }
    std::vector<std::vector<int> > not_correct;
    int length;
    int num;
};
/// the main is the same as in the previous example
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
        else
        {
            attempt.clear();
            solver.create_attempt(attempt);
        }
            maker.give_feedback(attempt, black_hits, white_hits);
            solver.learn(attempt, black_hits, white_hits);
            std::cout << "attempt: " << std::endl;
            for(int i = 0; i < attempt.size(); i++){
                std::cout << attempt[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "black hits: " << black_hits << " " << " white hits: " << white_hits << std::endl;
            attempts++;

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
