

#include "Logger.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <stdio.h>

Logger::Logger (const char* file){
    this->file = fopen(file, "a");
    if (this->file == NULL){
        this->file = fopen(file, "w");
    }
}
Logger::Logger (std::string file){
    this->file = fopen(file.c_str(), "a");
    if (this->file == NULL){
        this->file = fopen(file.c_str(), "w");
    }
}
Logger::~Logger (){
    fclose(this->file);
    this->file = NULL;
}

const char* Logger::GetCurrentTimeOfDay(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%I:%M:%S",timeinfo);
    const char* res = buffer;
    return res;
}

void Logger::Log(std::string message, LogType type){
    this->Log(message.c_str(), type);
}
void Logger::Log(const char* message, LogType type){
    std::string tag;
    switch (type) {
        case INFO:
            tag = "[   INFO   ] -> ";
            break;
        case WARNING:
            tag = "[   WARN   ] -> ";
            break;
        case ERROR:
            tag = "[   ERRO   ] -> ";
            break;
        default:
            tag = "[   INFO   ] -> ";
            break;
    }
    printf("[%s]%s%s\n", this->GetCurrentTimeOfDay(), tag.c_str(), message);
}

void Logger::LogToFile(std::string message, LogType type){
    this->Log(message.c_str(), type);
}
void Logger::LogToFile(const char* message, LogType type){
    std::string tag;
    switch (type) {
        case INFO:
            tag = "[   INFO   ] -> ";
            break;
        case WARNING:
            tag = "[   WARN   ] -> ";
            break;
        case ERROR:
            tag = "[   ERRO   ] -> ";
            break;
        default:
            tag = "[   INFO   ] -> ";
            break;
    }
    printf("[%s]%s%s\n", this->GetCurrentTimeOfDay(), tag.c_str(), message);
    fprintf(this->file, "[%s]%s%s\n", this->GetCurrentTimeOfDay(), tag.c_str(), message);
    fflush(this->file);
}

int main(){
    Logger* lo = new Logger("teste.txt");
    lo->Log("oie");

    delete lo;
}
