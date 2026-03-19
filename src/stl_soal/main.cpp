#include <cstdio>
#include <map>
#include <vector>

using namespace std;

class Robot {
    public:
        Robot(vector<int> categories_input) {
            for (int i = 0; i < static_cast<int>(categories_input.size()); i++) {
                if (packets.count(categories_input[i]) == 0) {
                    packets[categories_input[i]] = 0;
                }
                packets[categories_input[i]]++;
            }
        }

        int getMaxPickupCount() { return packets.size(); }

    private:
        map<int, int> packets;
};

int main() {
    int package_count;
    int temp;
    scanf("%d", &package_count);

    vector<int> categories(package_count);

    for (int i = 0; i < package_count; ++i) scanf("%d", &temp);
    for (int i = 0; i < package_count; ++i) scanf("%d", &categories[i]);

    Robot robot_i = Robot(categories);
    printf("%d\n", robot_i.getMaxPickupCount());
    return 0;
}