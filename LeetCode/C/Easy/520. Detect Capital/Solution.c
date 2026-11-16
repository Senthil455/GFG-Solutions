bool detectCapitalUse(char* word) {
    bool out = true;
    int n=strlen(word);
    if(word[0]>= 'A' && word[0] <'a'){
        if(word[1]>= 'a'){
            for(int i=1; i<n; i++){
                if(word[i] <'a'){
                    out=false;
                    break;
                }
            }
        }
        else{
            for(int i=1; i<n; i++){
                if(word[i] >='a'){
                    out=false;
                    break;
                }
            }
        }

    }
    else{
        for(int i=0; i<n; i++){
            if(word[i] <'a'){
                out=false;
                break;
            }
        }
    }
    return out;
}