class Bank {
public:
    vector<long long> bal;
    bool valid(int acc) {
        return acc>=1 && acc<=(int)bal.size();
    }

    Bank(vector<long long>& balance) {
        this->bal=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!valid(account1) || !valid(account2)){
            return false;
        }
        long long &src=bal[account1-1];
        long long &dst=bal[account2-1];
        if(src<money){
            return false;
        }
        src-=money;
        dst+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!valid(account)){
            return false;
        }
        bal[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!valid(account)){
            return false;
        }
        long long &cur=bal[account-1];
        if(cur<money){
            return false;
        }
        cur-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */