char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0){
        return "";
    }
    
    int flag = 1;
    int index = 0;
    char* ret;
    while(flag){
        for(int i = 0;i < strsSize;++i){
            if(strs[i][index] == '\0' || strs[i][index] != strs[0][index]){
                flag = 0;
                break;
            }
        }
        
        ++index;
    }
    strs[0][index-1]='\0';
    return strs[0];
}