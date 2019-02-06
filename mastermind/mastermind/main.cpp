#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
void set_random_seed();
int randn(int n);
struct mm_code_maker
{
    void init(int i_length, int i_num)
    {
        length = i_length;
        num = i_num;
    }
    void generate_sequence()
    {
        for(int i = 0; i < length; i++)
        {
            sequence.push_back(randn(num));
        }
    }
    void give_feedback(const std::vector<int>& attempt, int& black_hits, int& white_hits)
    {
        white_hits=0;
        black_hits=0;
        int total=0, minimal=0;
        for(int i=0; i<sequence.size(); i++)
        {
            if(attempt[i]==sequence[i])
            {
                black_hits++;
            }
        }
        for(int i=0; i<num; i++)
        {
            int n=0, m=0;
            for(int j=0; j<length; j++)
            {
                if(i==sequence[j])
                {
                    n++;
                }
                if(i==attempt[j])
                {
                    m++;
                }
            }
            if(n>m)
            {
                minimal=m;
            }
            else
            {
                minimal=n;
            }
            total = total+minimal;
        }
        white_hits=total-black_hits;
    }
    std::vector<int> sequence;
    int length;
    int num;
};
struct mm_solver
{
    int times=0;
    std::vector<std::vector<int> >useless;
    std::vector<std::vector<int> >all;
    std::vector<std::vector<int> >newall;
    std::vector<int>newint;
    std::vector<int>attempt;
    void creatallvector(std::vector<int>attempt,long p)
    {
        for(long l=0;l<p;l++)
        {
            newint.clear();
            change(l, num, length, newint);
            all.push_back(newint);
        }
    }
    void change(long n,long num,int m,std::vector<int> &k)
    {
        for (int i=m-1; i>=0; i--)
        {
            int p=n/(pow(num, i));
            k.push_back(p);
            n=n-p*pow(num, i);
        }
    }
    void myfeedback(const std::vector<int>& attempt, const std::vector<int>& real,int& black_hits, int& white_hits)
    {
        white_hits=0;
        black_hits=0;
        int total=0, minimal=0;
        for(int i=0; i<real.size(); i++)
        {
            if(attempt[i]==real[i])
            {
                black_hits++;
            }
        }
        for(int i=0; i<num; i++)
        {
            int n=0, m=0;
            for(int j=0; j<length; j++)
            {
                if(i==real[j])
                {
                    n++;
                }
                if(i==attempt[j])
                {
                    m++;
                }
            }
            if(n<=m)
            {
                minimal=n;
            }
            else
            {
                minimal=m;
            }
            total = total+minimal;
        }
        white_hits=total-black_hits;
    }
    void init(int i_length, int i_num)
    {
        length = i_length;
        num = i_num;
    }
    void create_attempt(std::vector<int>& attempt)
    {
        if(times==0){
            long p=pow(num,length);
            creatallvector(attempt, p);
            for(int u=0;u<length;u++)
            {
                attempt.push_back(randn(num));
            }
            times++;
        }
        else{
            int n=randn(all.size());
            attempt.clear();
            for(int i=0;i<length;i++)
            {
                attempt.push_back(all[n][i]);
            }
        }
    }
    void learn(std::vector<int>& attempt, int black_hits, int white_hits){
        for(int k=0;k<all.size();k++){
            int b;
            int w;
            myfeedback(all[k], attempt, b, w);
            if((b==black_hits)&&(w==white_hits))
            {
                newall.push_back(all[k]);
            }
        }
        all.clear();
        for(int i=0;i<newall.size();i++)
        {
            all.push_back(newall[i]);
        }
        newall.clear();
        
    }
    std::vector<std::vector<int> > not_correct;
    int length;
    int num;
};

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
void set_random_seed()
{
    std::srand(std::time(0));
}

int randn(int n)
{
    return std::rand() % n;
}
