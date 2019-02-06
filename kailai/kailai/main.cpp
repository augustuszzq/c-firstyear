// Knuth's algorithm is to select a number which makes the left possibilities as small as possible;
// what we can do is base on each times' feedback, generate a new guess which meet all the conditions before;
// the simplest way to imply is rand(), compare with the conditions, if not as required, clear that vector, try again;
// for first attempts, it is pretty quick, however, when the conditions are increasing and the capable values are decreasing, it takes a signaficantly long time to do that;
// I should implement this first, clearly, it works fine and easy;
// what I should figure out is to accelerate the rand() process;
// At current stage, I think the most time-consuming part of the algorithm is the repeated checking and rand() generation;
// one way of doing is narrow down the random range;
// the second way I come up is to kind of calculate the number I want for the next test;
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
        //check black_hits
        black_hits=0;
        white_hits=0;
        for(int i=0;i<attempt.size();i++){
            if(attempt[i]==sequence[i]){
                black_hits++;
            }
        }
        
        int totalhits=0;
        //calculate total hits
        for(int i=0;i<num;i++){
            int nsequence=0;
            int nattempt=0;
            for(int j=0;j<sequence.size();j++){
                if(sequence[j]==i){
                    nsequence++;
                }
            }
            for(int j=0;j<attempt.size();j++){
                if(attempt[j]==i){
                    nattempt++;
                }
            }
            if(nattempt>nsequence){
                totalhits=totalhits+nsequence;
            }
            else{
                totalhits=totalhits+nattempt;
            }
        }
        
        white_hits=totalhits-black_hits;
    }
    
    
    std::vector<int> sequence;
    
    int length;
    int num;
};

struct mm_solver{
    
    void init(int i_length, int i_num){
        length = i_length;
        num = i_num;
    }
    
    //change numerical base of the number !!!CORRECT!!!!
    int numbase(int input, int base){
        int powers1=0;
        int output=0;
        int reminder=0;
        do{
            reminder=input%base;
            input=input/base;
            output=output+reminder*pow(10,powers1);
            powers1++;
        }while(input!=0);
        return output;
    }
    
    //generate all the possible answers !!!CORRECT!!!!
    void ALLPOSS(std::vector<int> & TotalComb,int num, int length){
        int size=pow(num,length);
        for(int i=0;i<size;i++){
            TotalComb.push_back(numbase(i,num));
        }
    }
    
    //same with give_feedback in mm_code_maker; !!!CORRECT!!!!
    void PREfeedback(const std::vector<int>& attempt, const std::vector<int>& sequence,int& black_hits, int& white_hits,int num){
        //check black_hits
        black_hits=0;
        white_hits=0;
        for(int i=0;i<attempt.size();i++){
            if(attempt[i]==sequence[i]){
                black_hits++;
            }
        }
        
        int totalhits=0;
        //calculate total hits
        for(int i=0;i<num;i++){
            int nsequence=0;
            int nattempt=0;
            for(int j=0;j<sequence.size();j++){
                if(sequence[j]==i){
                    nsequence++;
                }
            }
            for(int j=0;j<attempt.size();j++){
                if(attempt[j]==i){
                    nattempt++;
                }
            }
            if(nattempt>nsequence){
                totalhits=totalhits+nsequence;
            }
            else{
                totalhits=totalhits+nattempt;
            }
        }
        
        white_hits=totalhits-black_hits;
    }
    
    
    //self-check feedback;
    void Myfeedback(std::vector<int> & PossComb, std::vector<int> & TotalComb,int number, std::vector<int> attempt,int BH, int WH ){
        std::vector<int>sequence2;
        int remainde=number;
        int sesize=attempt.size();
        while(sesize>0){
            sequence2.push_back(remainde%10);
            remainde=remainde/10;
            sesize--;
        }
        std::vector<int>sequence2_inverse;
        for(int j=sequence2.size()-1;j>=0;j--){
            sequence2_inverse.push_back(sequence2[j]);
        }
        int black_hits_MF;
        int white_hits_MY;
        PREfeedback(attempt,sequence2_inverse,black_hits_MF,white_hits_MY,num);
        //std::cout<<white_hits_MY<<"\t"<<black_hits_MF<<"\n";
        if (BH==black_hits_MF&&WH==white_hits_MY){
            PossComb.push_back(number);
        }
    }
    
    void create_attempt(std::vector<int>& attempt){
        attempt.clear();
        if(tries==0){
            tries=-1;
            attempt.push_back(0);
            attempt.push_back(0);
            attempt.push_back(1);
            attempt.push_back(1);
            ALLPOSS(TotalComb,num,length);
            /*  int counter1=0;
             if(length>num/2){
             if(length%2==0){
             for(int i=0;i<length;i=i+2){
             attempt.push_back(counter1);
             attempt.push_back(counter1);
             counter1++;
             }
             }
             else{
             for(int i=0;i<length-1;i=i+2){
             attempt.push_back(counter1);
             attempt.push_back(counter1);
             counter1++;
             }
             attempt.push_back(counter1);
             }
             }
             else{
             if(length%num==0){
             int factor1=length/num;
             for(int i=0;i<length;i=i+factor1){
             for(int j=0; j<factor1;j++){
             attempt.push_back(counter1);
             }
             counter1++;
             }
             }
             else{
             int factor2=length/num;
             factor2++;
             for(int i=0;i<length-factor2;i=i+factor2){
             for(int j=0; j<factor2;j++){
             attempt.push_back(counter1);
             }
             counter1++;
             }
             for(int k=0;k<length-1;k++){
             attempt.push_back(counter1);
             }
             }
             }
             ALLPOSS(TotalComb,num,length);*/
        }
        else{ // attempts!=0;
            int attemptnumber=TotalComb[randn(TotalComb.size())];
            int remainde=attemptnumber;
            std::vector<int>attempt_inverse;
            int sesize=length;
            attempt.clear();
            while(sesize>0){
                attempt_inverse.push_back(remainde%10);
                remainde=remainde/10;
                sesize--;
            }
            for(int j=attempt_inverse.size()-1;j>=0;j--){
                attempt.push_back(attempt_inverse[j]);
            }
        }
    }
    
    void learn(std::vector<int>& attempt, int black_hits, int white_hits){
        /*
         std::cout<<black_hits<<"\t"<<white_hits<<"\n";
         for(int j=0; j<attempt.size();j++){
         std::cout<<attempt[j]<<"\t";
         }
         std::cout<<"fuck"<<"\n";*/
        for(int i=0;i<TotalComb.size();i++){
            Myfeedback(PossComb,TotalComb,TotalComb[i],attempt,black_hits,white_hits);
        }
        TotalComb.clear();
        for(int i=0;i<PossComb.size();i++){
            TotalComb.push_back(PossComb[i]);
        }
        PossComb.clear();
        std::cout<<"fuck"<<"\n";
        
        for(int i=0;i<TotalComb.size();i++){
            std::cout<<TotalComb[i]<<"\t";
        }
        
        std::cout << '\n';
        std::cout<<"fuck"<<"\n";
    }
    
    std::vector<int> TotalComb;
    std::vector<int> PossComb;
    
    int length;
    int num;
    int tries=0;
};

/// the main is the same as in the previous example

int main(){
    /// write the code for the main here in order to test your functions
    /// our program uses random features so we need to call the function setting a random seed
    set_random_seed();
    int length, num;
    std::cout << "enter length of sequence and number of possible values:" << std::endl;
    std::cin >> length >> num;
    double count_all=0;
    //std::cout << "你要皮几次？" << std::endl;
    std::cout << "How many times？" << std::endl;
    int turns,max=0;
    std::cin >> turns;
    /*if (pow(num, length)>20000000){
     int Yes=99;
     std::cout << "吃屎吧 算不过来,输入0继续" << std::endl;
     std::cout << "Eat shit,enter 0 to continue" << std::endl;
     std::cin >> Yes ;
     if(Yes!=0){
     exit(EXIT_FAILURE);
     }
     }
     if (turns>10000){
     int Yes=99;
     std::cout << "皮一下可以，皮几万不行,输入0继续" << std::endl;
     std::cout << "Pi yi xia ok, PGONE not ok,enter 0 to continue" << std::endl;
     std::cin >> Yes ;
     if(Yes!=0){
     exit(EXIT_FAILURE);
     }
     }*/
    clock_t start_time=time(NULL);
    for(int n=0;n<turns;n++){
        mm_solver solver;
        /// we declare an object of type mm_solver
        solver.init(length, num);
        /// we initialise the values for length and num
        
        mm_code_maker maker;
        /// we declare an object of type mm_code_maker
        maker.init(length, num);
        /// we initialise the values for length and num
        
        maker.generate_sequence();
        /// we generate a random sequence
        
        int black_hits=0, white_hits=0;
        /// just some number to limit the number of attempts
        int attempts_limit = 5000;
        int attempts = 0;
        while((black_hits < length) && (attempts < attempts_limit)){
            std::vector<int> attempt;
            solver.create_attempt(attempt);
            /// the solver creates an attempt
            maker.give_feedback(attempt, black_hits, white_hits);
            /// we ask for feedback for the attempt
            
            /// we print the attempt
            std::cout << "attempt: " << std::endl;
            for(int i = 0; i < attempt.size(); i++){
                std::cout << attempt[i] << " ";
            }
            std::cout << std::endl;
            /// we print the feedback
            std::cout << "black pegs: " << black_hits << " " << " white pegs: " << white_hits << std::endl;
            /// we give the feedback to the solver so that it can learn
            solver.learn(attempt, black_hits, white_hits);
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
        count_all=count_all+attempts;
        if (attempts>max) {
            max=attempts;
        }
    }
    clock_t end_time=time(NULL);
    double time=(double)(end_time-start_time);
    //std::cout << "皮了 "<<turns <<" 次之后，发现" << std::endl;
    std::cout << "total attempts: " << count_all<< std::endl;
    double average=count_all;
    average=count_all/turns;
    std::cout << "average attempts: " << average<< std::endl;
    std::cout << "max attempt number: " << max<< std::endl;
    std::cout << "总时间 " << time<< " 秒"<< std::endl;
    return 0;
}


void set_random_seed(){
    std::srand(std::time(0));
}

int randn(int n){
    return std::rand() % n;
}
