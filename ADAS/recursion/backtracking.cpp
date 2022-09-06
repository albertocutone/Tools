//pseudo-code
bool Solve(configuration conf){
    if(no more choices) //BASE CASE
        return (conf is goal state);
    for(all available choices){
        try one choice c:
            //solve from here, if works out, you're done
        if(Solve(conf with choice c made)) return true;
        unmake choice c;
    }
    return false; //tried all choices, no sln found -> backtrack and edit previous choice, then try again
}