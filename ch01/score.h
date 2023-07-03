#pragma once

class Score {
    public:
        Score(float data[]) {
            set_values(data);
            set_avg_value();
        }

        float get_avg() {
            return avg_value;
        }
        

    private:
        float values[3];
        float avg_value;

        void set_values(float score_set[]) {
                    for (int i=0; i<3; i++) {
                        values[i] = score_set[i];
                    }
                }

        void set_avg_value() {
            float total = 0;
            for (auto value: values) {
                total += value;
            }

            avg_value = total / 3;
        }
};