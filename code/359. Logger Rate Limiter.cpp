// https://leetcode.com/problems/logger-rate-limiter/

class Logger {
    unordered_map<string, int> lastPrinted;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(lastPrinted.find(message) == lastPrinted.end() || timestamp - lastPrinted[message] >= 10){
            lastPrinted[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */