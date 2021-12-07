#include <iostream>
#include <vector>

struct value_pair {
    unsigned char one : 4;
    unsigned char two : 4;
};

value_pair *fish_list;

static void set_fish(unsigned long fish_index, unsigned char value) {
    value_pair *pair = fish_list + (fish_index / 2);

    if (fish_index % 2 == 0) {
        pair->one = value;
    } else {
        pair->two = value;
    }
}

static unsigned char get_fish(unsigned long fish_index) {
    value_pair *pair = fish_list + (fish_index / 2);

    if (fish_index % 2 == 0) {
        return pair->one;
    } else {
        return pair->two;
    }
}

int main() {
    constexpr long long fish_count = 26984457539 / 2;

    unsigned char input[] = {3, 4, 3, 1, 2};
    fish_list = new value_pair[fish_count];
    unsigned long long current_fish_count = 0;

    for (const auto &item: input) {
        // Setting each number one higher than it should be because we can't go lower than 0
        set_fish(current_fish_count, item + 1);
        current_fish_count++;
    }

    int days_to_calculate = 256;

    for (int i = 0; i < days_to_calculate; ++i) {
        {
            for (long long j = 0; j < current_fish_count; ++j) {
                set_fish(j, get_fish(j) - 1);

                if (get_fish(j) == 0) {
                    set_fish(j, 7);
                    // Setting this one even higher because we're going to decrement it this loop.
                    set_fish(current_fish_count, 10);
                    current_fish_count++;
                }
            }

            std::cout << "Day " << i + 1 << ": " << current_fish_count << std::endl;
        }
    }


    std::cout << "After " << days_to_calculate << " there are " << current_fish_count << " fishes" << std::endl;

    return 0;
}
