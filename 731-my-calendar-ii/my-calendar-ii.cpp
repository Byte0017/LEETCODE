class MyCalendarTwo {
private:
    map<int, int> bookings;

public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        bookings[start]++;
        bookings[end]--;

        int count = 0;
        for(auto& [time, bookingCount] : bookings) {
            count += bookingCount;
            if (count > 2) {
                bookings[start]--;
                bookings[end]++;
                return false;
            }
        }
        return true;
    }
};

