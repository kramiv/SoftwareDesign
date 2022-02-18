#include<iostream>

int main(int argc, char **argv) {//argc is current #?
    //bool a = true;
    if ((argc-1) == 2) {
        std::cerr << "Usage: ./chat1 username " << "\n"; 
    } else {
    unsigned char num_messages = 0;//keep track of # of messages using an unsigned char "num_messages"
        while (true) {
    //unsigned char *num_pointer = &num_messages;
        char message[80];//create array of legnth 80
        char *username = argv[1];
        std::cerr <<  username << "> ";
        std::cin.getline(message, 80);
        //std::cerr << "message was" << message << "\n";
        num_messages++;
        std::cerr << static_cast<int>(num_messages) << "\n";//convert char to int for printing
        }
    }
}
