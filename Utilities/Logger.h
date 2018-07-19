
#include <string>
#include <vector>

class Logger {
public:
    enum LogType{
        INFO = 0,
        WARNING,
        ERROR
    };

private:
    FILE *file;

public:
    Logger (const char* file);
    Logger (std::string file);
    virtual ~Logger ();

    const char* GetCurrentTimeOfDay();

    void Log(std::string message, LogType type = INFO);
    void Log(const char* message, LogType type = INFO);

    void LogToFile(std::string message, LogType type = INFO);
    void LogToFile(const char* message, LogType type = INFO);
};
