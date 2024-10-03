#include <iostream>
#include <bitset>
#include <stack>

void dec2bin(int number){

    std::cout<<"Decimal to binary number: "<<std::bitset<8>(number)<<std::endl;

}
void dec2oct(int number){

    bool flag = true;
    std::stack<char> octNumbers;

    if(number<0){
        flag = false;
    }
        
    while(number!=0){
        
        if(abs(number%8)<10)
        {
            octNumbers.push(abs(number%8)+48);
        }
        else{
            octNumbers.push(abs(number%8)+55);
        }
        number/=8;
    }

    if(!flag){
        
        octNumbers.push('-');
    }

    std::cout<<"Decimal to octal number: ";

    while(!octNumbers.empty()){

        std::cout<<octNumbers.top();
        octNumbers.pop();
    }
    std::cout<<std::endl;
}
void dec2hex(int number){

    std::cout<<"Decimal to hexadecimal number: "<<std::hex<<number<<std::endl;

}


int main(){
    
    dec2bin(-44);
    dec2oct(-44);
    dec2hex(-44);

    return 0;
}