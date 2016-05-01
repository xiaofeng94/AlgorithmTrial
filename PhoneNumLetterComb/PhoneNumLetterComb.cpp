class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        return cartesianProd(res,digits,0);
    }
    
    vector<string> cartesianProd(vector<string> lastRes,const string& digits,int pos){
        if(pos >= digits.size()){
            return lastRes;
        }
        vector<string> res;
        
        if(digits[pos] == '2'){
            vector<string> temp({"a","b","c"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        if(digits[pos] == '3'){
            vector<string> temp({"d","e","f"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        if(digits[pos] == '4'){
            vector<string> temp({"g","h","i"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        if(digits[pos] == '5'){
            vector<string> temp({"j","k","l"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        if(digits[pos] == '6'){
            vector<string> temp({"m","n","o"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        if(digits[pos] == '7'){
            vector<string> temp({"p","q","r","s"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        if(digits[pos] == '8'){
            vector<string> temp({"t","u","v"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        if(digits[pos] == '9'){
            vector<string> temp({"w","x","y","z"});
            for(int i = 0;i < temp.size();++i){
                if(lastRes.size() == 0){
                    res.push_back(temp[i]);
                }else
                {
                    for(int j = 0;j < lastRes.size();++j){
                        res.push_back(lastRes[j]+temp[i]);
                    }
                }
            }
        }
        lastRes.clear();
        
        return cartesianProd(res,digits,pos+1);
    }
};