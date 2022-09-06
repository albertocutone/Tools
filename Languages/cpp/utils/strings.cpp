// find in string
void removeOccurrences(char ch, string &s){
    int found = 0;
    while((found = s.find(ch,found))!=string::npos){ //find ch in string s
        s.erase(found,1);
    }
}

//Parser/Tokenizer/Scanner
