/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static inline bool is_duplicate(char*s, char**list,int size){

    for(int i = 0; i < size; i++){
        if(strcmp(s, list[i]) == 0)     return true;
        else 
            return false;
    }
    return false;
}
static int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}
static void dfs(char*s,int len, int*returnSize, int pos,int depth, char***page, char path[26], int open, int close,int* max, int**returnColumnSizes, int*cap){


    if(pos == len && open == close){
        if(depth >= *max){

            if(*returnSize >= *cap){
                *cap *= 2;
                *page = realloc(*page, (*cap) * sizeof(char**));
                *returnColumnSizes = realloc(*returnColumnSizes,(*cap) * sizeof(int));
            }

            path[depth] = '\0';
            (*page)[*returnSize] = strdup(path);
            (*returnColumnSizes)[*returnSize] = depth;
            (*returnSize)++;
            *max = depth;
        }
        return;
    }
    if (open < close) return; // early reject bei unbalancierten Präfixen


    char c = s[pos];
    if(c == '('){//Behalte offen
        path[depth] = c;
        dfs(s,len,returnSize,pos+1,depth+1,page,path, open+1,close,max,returnColumnSizes,cap);
        //verwerfe
        dfs(s,len,returnSize,pos+1,depth,page,path,open,close,max,returnColumnSizes,cap);

    }else if(c == ')' ){
        if(close < open){ //Behalte nur wenn schon mehr offene vorausgingen
            path[depth] = c;
            dfs(s,len,returnSize,pos+1,depth+1,page,path, open,close+1,max,returnColumnSizes,cap);
        }
        //Verwerfe
        dfs(s,len,returnSize,pos+1,depth,page,path,open,close,max,returnColumnSizes,cap);


    }else if(isalpha(c)){//Immer behalten
        path[depth] = c;
        dfs(s,len,returnSize,pos+1,depth+1,page,path, open,close,max,returnColumnSizes,cap);
    }

}
char** removeInvalidParentheses(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = 0;
    int cap = 200;
    char** page = malloc(cap * sizeof(char*));
    int*returnColumnSizes = malloc(cap* sizeof(int));
    *page = "";
    char path[26];
    int max = 0;
    dfs(s,n,returnSize,0,0,&page,path,0,0,&max,&returnColumnSizes,&cap);

    int k = 0;
    char** res = malloc(cap* sizeof(char*));
    res[0] = "";
    qsort(page, *returnSize,sizeof(char*),cmp);

    for(int i = 0; i < *returnSize;i++){
        if(returnColumnSizes[i] != max)     continue;

        if(k == 0 || strcmp(res[k-1], page[i]) != 0)
            res[k++] = strdup(page[i]);
    }


    *returnSize = k*2?k:1;
    return res;
}