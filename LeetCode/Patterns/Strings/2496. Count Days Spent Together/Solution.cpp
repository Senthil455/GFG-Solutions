class Solution {
public:
    int toDay(const string& date) {
        static const int prefix[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        return prefix[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end = min(toDay(leaveAlice), toDay(leaveBob));
        return max(0, end - start + 1);
    }
};