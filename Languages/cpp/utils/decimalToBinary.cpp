

string toHex(int num) {
    unsigned int ourNum = num; //handle negative numbers
    string binary = "";
    char hexArray[17] = "0123456789abcdef";
    int base = 16; //change base
    do{
        binary += hexArray[ourNum%base];
        ourNum /= base;
    }while(ourNum);
    
    return {binary.rbegin(),binary.rend()};
}


long long convertToBinary(int n) {
  long long bin = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}

void convertToBinary(int n, string& temp){
    if(n/2!=0){
        convertToBinary(n/2, temp); 
    } 
    temp += to_string(n%2);
}


